/**	Definition of the class UGKAudioHardware. Base class for all audio hardware in the system
*
*	Prefix: UGKSNDHW_
*
*	@file	UGKAudioHardware.h
*	@brief	Base class for all audio hardware in the system
*	@author Leopoldo Pla
*	@date	2015-01-28
*	
*/

///Include the header of the class
#include <UGKAudioHardware.h>

///We use the UGK namespace to make the code cleaner
using namespace UGK;

UGKAudioHardware::~UGKAudioHardware(){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
		Mix_Quit();

	#endif
}

/**
*	\fn UGKAudioHardware::Init()
*	\brief Initializes the sound system
*/

void UGKAudioHardware::Init(){
	SubTypeHW = CHW_SND_MAX_DEVICE;
	TypeHW = CHW_SOUND;

	Active = true;

	#ifdef UGKSND_FMOD375
	OpenAudio();

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)
	ALCdevice *device = alcOpenDevice(NULL); 
	ALCcontext *context = alcCreateContext(device, NULL); 
	alcMakeContextCurrent(context);
	#elif defined(UGKSND_SDL)

	// start SDL with audio support
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1) {
		printf("SDL_Init: %s\n", SDL_GetError());
		exit(1);
	}
	#endif

}

/**
*	\fn UGKAudioHardware::OpenAudio
*	\brief Open the audio system with default settings
*/

void UGKAudioHardware::OpenAudio(){
	#ifdef UGKSND_FMOD375
	FSOUND_Init(44100, 32, 0);
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	// open 44.1KHz, signed 16bit, system byte order,
	//      stereo audio, using 4096 byte chunks
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096)==-1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		exit(2);
	}
	#endif

}

/**
*	\fn UGKAudioHardware::CloseAudio()
*	\brief Close the audio system
*/

void UGKAudioHardware::CloseAudio(){
	#ifdef UGKSND_FMOD375
	FSOUND_Close();

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)
	ALCcontext *context = alcGetCurrentContext();
	ALCdevice *device = alcGetContextsDevice(context);
	alcDestroyContext(context);
	alcCloseDevice(device);
	#elif defined(UGKSND_SDL)
	Mix_CloseAudio();
	#endif
}

/**
*	\fn UGKAudioHardware::CheckAudioFormat()
*	\brief Print the format of the audio system
*/

void UGKAudioHardware::CheckAudioFormat(){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	// get and print the audio format in use
	int numtimesopened, frequency, channels;
	Uint16 format;
	numtimesopened=Mix_QuerySpec(&frequency, &format, &channels);
	if(!numtimesopened) {
		printf("Mix_QuerySpec: %s\n",Mix_GetError());
	}
	else {
		char *format_str="Unknown";
		switch(format) {
			case AUDIO_U8: format_str="U8"; break;
			case AUDIO_S8: format_str="S8"; break;
			case AUDIO_U16LSB: format_str="U16LSB"; break;
			case AUDIO_S16LSB: format_str="S16LSB"; break;
			case AUDIO_U16MSB: format_str="U16MSB"; break;
			case AUDIO_S16MSB: format_str="S16MSB"; break;
		}
		printf("opened=%d times  frequency=%dHz  format=%s  channels=%d",
				numtimesopened, frequency, format_str, channels);
	}
	#endif

}

/**
*	\fn UGKAudioHardware::GetNumSampleDecoders()
*	\brief Return the number of decoders per sample
*	\return Number of sample decoders
*/

int UGKAudioHardware::GetNumSampleDecoders(){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GetNumChunkDecoders();
	#endif
}

/**
*	\fn UGKAudioHardware::GetSampleDecoder(int num)
*	\brief Gives the name of one sample decoder
*	\param[in] num Number of decoder
*	\return The name of the decoder
*/

const char* UGKAudioHardware::GetSampleDecoder(int num){
	#ifdef UGKSND_FMOD375
	return "";
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GetChunkDecoder(num);

	#endif
}

/**
*	\fn UGKAudioHardware::LoadSample(const char* sampleRoute)
*	\brief Store a sample in memory from a path
*	\param[in] sampleRoute Path of the file to laod
*	\return The sample (pointer)
*/

UGKSND_SoundType UGKAudioHardware::LoadSample(const char* sampleRoute){
	#ifdef UGKSND_FMOD375
	return NULL;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	// load sample.wav in to sample (you must call OpenAudio before this method)
	UGKSND_SoundType sample=Mix_LoadWAV(sampleRoute);
	if(!sample) {
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		// handle error
	}
	return sample;
	#endif

}

/**
*	\fn UGKAudioHardware::SetVolumeSample(UGKSND_SoundType sample, int volume)
*	\brief Setter of the volume of the sample
*	\param[in] sample The sample
*	\param[in] volume The volume
*	\return The previous volume
*/

int UGKAudioHardware::SetVolumeSample(UGKSND_SoundType sample, int volume){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	// set the sample's volume to 1/2
	int previous_volume;
	previous_volume=Mix_VolumeChunk(sample, volume);
	return previous_volume;
	#endif

}

/**
*	\fn UGKAudioHardware::DeleteSample(UGKSND_SoundType sample)
*	\brief Delete the sample from memory
*	\param[in] sample The sample
*/

void UGKAudioHardware::DeleteSample(UGKSND_SoundType sample){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FreeChunk(sample);
	sample=NULL;
	#endif

}

/**
*	\fn UGKAudioHardware::AllocateChannels(int numchannels)
*	\brief Allocate channels
*	\param[in] numchannels Number of channels to allocate
*/

void UGKAudioHardware::AllocateChannels(int numchannels){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_AllocateChannels(numchannels);
	#endif
}

/**
*	\fn UGKAudioHardware::SetChannelVolume(int channel, int volume)
*	\brief Set the volume of one channel
*	\param[in] channel The channel
*	\param[in] volume The volume
*	\return The previous volume
*/

int UGKAudioHardware::SetChannelVolume(int channel, int volume){
	#ifdef UGKSND_FMOD375
	FSOUND_SetVolume(channel, volume);
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_Volume(channel,volume);

	#endif
}

/**
*	\fn UGKAudioHardware::PlayChannel(int channel, UGKSND_SoundType sample, int loops)
*	\brief Plays a sample in a channel
*	\param[in] channel The channel
*	\param[in] sample The sample
*	\param[in] loops The number of loops (0 is none, -1 is infinite, other is the number of loops)
*/

void UGKAudioHardware::PlayChannel(int channel, UGKSND_SoundType sample, int loops){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_PlayChannel(channel, sample, loops);

	#endif
}

/**
*	\fn UGKAudioHardware::PlayChannelTimed(int channel, UGKSND_SoundType sample, int loops, int ticks))
*	\brief Plays a sample in a channel after some time
*	\param[in] channel The channel
*	\param[in] sample The sample
*	\param[in] loops The number of loops
*	\param[in] ticks The number of ticks to wait
*/

void UGKAudioHardware::PlayChannelTimed(int channel, UGKSND_SoundType sample, int loops, int ticks){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_PlayChannelTimed(channel, sample, loops, ticks);

	#endif
}

/**
*	\fn UGKAudioHardware::FadeInChannel(int channel, UGKSND_SoundType sample, int loops, int ms)
*	\brief Plays a channel with a fade in
*	\param[in] channel The channel
*	\param[in] sample The sample
*	\param[in] loops The number of loops
*	\param[in] ms The miliseconds
*/

void UGKAudioHardware::FadeInChannel(int channel, UGKSND_SoundType sample, int loops, int ms){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FadeInChannel(channel, sample, loops, ms);

	#endif
}

/**
*	\fn UGKAudioHardware::FadeInChannelTimed(int channel, UGKSND_SoundType sample, int loops, int ms, int ticks)
*	\brief Plays a channel with a fade in
*	\param[in] channel The channel
*	\param[in] sample The sample
*	\param[in] loops The number of loops
*	\param[in] ms The miliseconds
*	\param[in] ticks The number of ticks to wait
*/

void UGKAudioHardware::FadeInChannelTimed(int channel, UGKSND_SoundType sample, int loops, int ms, int ticks){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FadeInChannelTimed(channel, sample, loops, ms, ticks);

	#endif
}

/**
*	\fn UGKAudioHardware::PauseChannel(int channel)
*	\brief Pause a channel
*	\param[in] channel The channel
*/

void UGKAudioHardware::PauseChannel(int channel){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_Pause(channel);

	#endif
}

/**
*	\fn UGKAudioHardware::ResumeChannel(int channel)
*	\brief Resume a channel
*	\param[in] channel The channel
*/

void UGKAudioHardware::ResumeChannel(int channel){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_Resume(channel);

	#endif
}

/**
*	\fn UGKAudioHardware::HaltChannel(int channel)
*	\brief Halt a channel
*	\param[in] channel The channel
*/

void UGKAudioHardware::HaltChannel(int channel){
	#ifdef UGKSND_FMOD375
	FSOUND_StopSound(channel);
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_HaltChannel(channel);

	#endif
}

/**
*	\fn UGKAudioHardware::ExpireChannel(int channel, int ticks)
*	\brief Expire a channel after some time
*	\param[in] channel The channel
*	\param[in] ticks The number of ticks to wait
*/

void UGKAudioHardware::ExpireChannel(int channel, int ticks){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_ExpireChannel(channel, ticks);

	#endif
}

/**
*	\fn UGKAudioHardware::FadeOutChannel(int channel, int ms)
*	\brief Fade out a channel
*	\param[in] channel The channel
*	\param[in] ms The time in miliseconds
*/

void UGKAudioHardware::FadeOutChannel(int channel, int ms){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FadeOutChannel(channel, ms);

	#endif
}

/**
*	\fn UGKAudioHardware::SetChannelFinishedFunction(void (*channel_finished)(int channel))
*	\brief Set a function to be executed when the channel finishes
*	\param[in] channel_finished The function
*	\param[in] channel The number of channel
*/

void UGKAudioHardware::SetChannelFinishedFunction(void (*channel_finished)(int channel)){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_ChannelFinished(channel_finished);

	#endif
}

/**
*	\fn UGKAudioHardware::IsChannelPlaying(int channel)
*	\brief Return if the channel is playing
*	\param[in] channel The channel
*	\return True or false if the channel is playing something
*/

bool UGKAudioHardware::IsChannelPlaying(int channel){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if(Mix_Playing(channel) > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::IsChannelPaused(int channel)
*	\brief Return if the channel is paused
*	\param[in] channel The channel
*	\return True or false if the channel is paused
*/

bool UGKAudioHardware::IsChannelPaused(int channel){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if(Mix_Paused(channel) > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::ReserveChannels(int num)
*	\brief Reserve some channels
*	\param[in] num Number of channels
*	\return Return the number of reserved channels (can be lower than the input)
*/

int UGKAudioHardware::ReserveChannels(int num){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_ReserveChannels(num);

	#endif
}

/**
*	\fn UGKAudioHardware::GroupChannel(int which, int tag)
*	\brief Group channel into a tag
*	\param[in] which The channel
*	\param[in] tag The tag
*	\return True or false if was all ok
*/

bool UGKAudioHardware::GroupChannel(int which, int tag){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_GroupChannel(which,tag) > 0)
		return true;
	else
		return false;
	#endif
}

/**
*	\fn UGKAudioHardware::GroupChannel(int from, int to, int tag)
*	\brief Group several channels into a group
*	\param[in] from The first channel
*	\param[in] to The last channel
*	\param[in] tag The tag
*	\return The number of elements grouped
*/

int UGKAudioHardware::GroupChannel(int from, int to, int tag){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GroupChannels(from,to,tag);

	#endif
}

/**
*	\fn UGKAudioHardware::GroupCount(int tag)
*	\brief Returns the number of channels with a tag
*	\param[in] tag The tag
*	\return The number of channels
*/

int UGKAudioHardware::GroupCount(int tag){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GroupCount(tag);

	#endif
}

/**
*	\fn UGKAudioHardware::GroupCount(int tag)
*	\brief Returns the number of channels with a tag
*	\param[in] tag The tag
*	\return The number of channels
*/

int UGKAudioHardware::GroupFindAvailable(int tag){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GroupAvailable(tag);

	#endif
}

/**
*	\fn UGKAudioHardware::FadeOutGroup(int tag, int ms)
*	\brief Fade out a group of channels
*	\param[in] tag The tag
*	\param[in] ms The time of fade out
*	\return The number of channels which can do fade out
*/

int UGKAudioHardware::FadeOutGroup(int tag, int ms){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_FadeOutGroup(tag,ms);

	#endif
}

/**
*	\fn UGKAudioHardware::HaltGroup(int tag)
*	\brief Halt a group of channels
*	\param[in] tag The tag
*/

void UGKAudioHardware::HaltGroup(int tag){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_HaltGroup(tag);

	#endif
}

/**
*	\fn UGKAudioHardware::GetNumMusicDecoders()
*	\brief Return the num of decoders for music
*	\return The number of decoders
*/

int UGKAudioHardware::GetNumMusicDecoders(){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GetNumMusicDecoders();

	#endif
}

/**
*	\fn UGKAudioHardware::GetNumMusicDecoders(int index)
*	\brief Return the name of one decoder for music
*	\param[in] index The number of the decoder
*	\return The name of the decoder
*/
const char* UGKAudioHardware::GetMusicDecoder(int index){
	#ifdef UGKSND_FMOD375
	return "";
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_GetMusicDecoder(index);

	#endif
}

/**
*	\fn UGKAudioHardware::LoadMusic(const char* musicRoute)
*	\brief Load music into memory
*	\param[in] musicRoute The music file path
*	\return The music file in memory
*/

UGKSND_MusicType UGKAudioHardware::LoadMusic(const char* musicRoute){
	#ifdef UGKSND_FMOD375
	return NULL;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	UGKSND_MusicType music=Mix_LoadMUS(musicRoute);
	if(!music) {
		printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
		// this might be a critical error...
	}
	return music;
	#endif

}

/**
*	\fn UGKAudioHardware::FreeMusic(UGKSND_MusicType music)
*	\brief Free music from memory
*	\param[in] music The music data
*/

void UGKAudioHardware::FreeMusic(UGKSND_MusicType music){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FreeMusic(music);
	music=NULL;
	#endif

}

/**
*	\fn UGKAudioHardware::PlayMusic(UGKSND_MusicType music, int loops)
*	\brief Play given music
*	\param[in] music The music data
*	\param[in] loops The number of loops (same as sample)
*/

void UGKAudioHardware::PlayMusic(UGKSND_MusicType music, int loops){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_PlayMusic(music,loops);

	#endif
}

/**
*	\fn UGKAudioHardware::FadeInMusic(UGKSND_MusicType music, int loops, int ms)
*	\brief Fade in music
*	\param[in] music The music data
*	\param[in] loops The loop number
*	\param[in] ms The time to fade in
*/

void UGKAudioHardware::FadeInMusic(UGKSND_MusicType music, int loops, int ms){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FadeInMusic(music,loops,ms);

	#endif
}

/**
*	\fn UGKAudioHardware::FadeInMusic(UGKSND_MusicType music, int loops, int ms)
*	\brief Fade in music
*	\param[in] music The music data
*	\param[in] loops The loop number
*	\param[in] ms The time to fade in
*/

void UGKAudioHardware::FadeInMusicPosition(UGKSND_MusicType music, int loops, int ms, double position){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_FadeInMusicPos(music, loops, ms, position);

	#endif
}

/**
*	\fn UGKAudioHardware::HookMusic(void (*mix_func)(void *udata, Uint8 *stream, int len), void *arg)
*	\brief Add your own music player or additional mixer function
*	\param[in] mix_func The function
*	\param[in] arg The arguments
*/

void UGKAudioHardware::HookMusic(void (*mix_func)(void *udata, Uint8 *stream, int len), void *arg){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_HookMusic(mix_func,arg);

	#endif
}

/**
*	\fn UGKAudioHardware::VolumeMusic(int volume)
*	\brief Set music volume
*	\param[in] volume The volume
*	\return The set volume
*/

int UGKAudioHardware::VolumeMusic(int volume){
	#ifdef UGKSND_FMOD375
	return 0;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	return Mix_VolumeMusic(volume);

	#endif
}

/**
*	\fn UGKAudioHardware::PauseMusic()
*	\brief Pause music
*/

void UGKAudioHardware::PauseMusic(){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_PauseMusic();

	#endif
}

/**
*	\fn UGKAudioHardware::ResumeMusic()
*	\brief Resume music
*/

void UGKAudioHardware::ResumeMusic(){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_ResumeMusic();

	#endif
}

/**
*	\fn UGKAudioHardware::RewindMusic()
*	\brief Rewind music
*/

void UGKAudioHardware::RewindMusic(){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_RewindMusic();

	#endif
}

/**
*	\fn UGKAudioHardware::SetMusicPosition(double position)
*	\brief Set music position
*	\param[in] position The position
*/

void UGKAudioHardware::SetMusicPosition(double position){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_SetMusicPosition(position);

	#endif
}

/**
*	\fn UGKAudioHardware::SetMusicCommand(const char* command)
*	\brief Set music command to stop
*	\param[in] command The command
*/

void UGKAudioHardware::SetMusicCommand(const char* command){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_SetMusicCMD(command);

	#endif
}

/**
*	\fn UGKAudioHardware::HaltMusic()
*	\brief Halt music
*/

void UGKAudioHardware::HaltMusic(){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_HaltMusic();

	#endif
}

/**
*	\fn UGKAudioHardware::FadeOutMusic(int ms)
*	\brief Fade out music
*	\param[in] ms The time of fade out
*/

void UGKAudioHardware::FadeOutMusic(int ms){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	while(!Mix_FadeOutMusic(ms) && Mix_PlayingMusic()) {
		// wait for any fades to complete
		SDL_Delay(100);
	}
	#endif


}

/**
*	\fn UGKAudioHardware::SetMusicFinishedFunction(void (*music_finished)())
*	\brief Set a function to be executed when a music finishes
*	\param[in] music_finished The function
*/

void UGKAudioHardware::SetMusicFinishedFunction(void (*music_finished)()){
	#ifdef UGKSND_FMOD375

	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	Mix_HookMusicFinished(music_finished);

	#endif
}

/**
*	\fn UGKAudioHardware::IsMusicPlaying()
*	\brief Return if there is music being played
*	\return True or false if music is being played
*/

bool UGKAudioHardware::IsMusicPlaying(){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_PlayingMusic() > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::IsMusicPaused()
*	\brief Return if there is music paused
*	\return True or false if music is paused
*/

bool UGKAudioHardware::IsMusicPaused(){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_PausedMusic() > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::SetPanning(int channel, Uint8 left, Uint8 right)
*	\brief Set panning to channel
*	\param[in] channel The channel
*	\param[in] left The panning of left speaker
*	\param[in] right The panning of right speaker
*	\return True or false if music is panned after all
*/

bool UGKAudioHardware::SetPanning(int channel, Uint8 left, Uint8 right){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_SetPanning(channel,left,right) > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::SetDistance(int channel, Uint8 distance)
*	\brief Set distance to channel
*	\param[in] channel The channel
*	\param[in] distance The distance
*	\return True or false if music is distanced after all
*/

bool UGKAudioHardware::SetDistance(int channel, Uint8 distance){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_SetDistance(channel, distance) > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::SetPosition(int channel, Sint16 angle, Uint8 distance)
*	\brief Set a relative position in a channel
*	\param[in] channel The channel
*	\param[in] angle The angle
*	\param[in] distance The distance
*	\return True or false if music is positioned after all
*/

bool UGKAudioHardware::SetPosition(int channel, Sint16 angle, Uint8 distance){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_SetPosition(channel, angle, distance) > 0)
		return true;
	else
		return false;
	#endif

}

/**
*	\fn UGKAudioHardware::SetReverseStereo(int channel, int flip)
*	\brief Set a flip of the speakers in a channel
*	\param[in] channel The channel
*	\param[in] flip Nonzero if you want flip.
*	\return True or false if music is flipped after all
*/

bool UGKAudioHardware::SetReverseStereo(int channel, int flip){
	#ifdef UGKSND_FMOD375
	return true;
	#elif defined(UGKSND_FMODEx)

	#elif defined(UGKSND_OAL)

	#elif defined(UGKSND_SDL)
	if( Mix_SetReverseStereo(channel, flip) > 0)
		return true;
	else
		return false;
	#endif

}
