/**	Definition of the class Sound for the UPV Game Kernel

*	Prefix: UGKSND_

*	@author Ramon Molla
*	@version 2014-05
*	@Upgrade Carlos Martinez Perez - 2012-05
*	@NewVersion Ramón Mollá 2012-07
*	@NewVersion Alfonso Pérez 2013-03
*	@NewVersion Ramón Mollá 2014-05 - API conversion and refactoring
*/

#include <UGKSound.h>

#ifdef UGKOS_WINDOWS
	#include <windows.h>
#elif	defined(UGKOS_LINUX)
#elif	defined(UGKOS_OSX)
#elif	defined(UGKOS_ANDROID)
#endif

#include <math.h>

#define STR_END '\0'

#ifdef UGKSND_FMOD375
#elif defined (UGKSND_FMODEx)
#elif defined (UGKSND_OAL)
#elif defined (UGKSND_SDL)
#elif defined (UGKSND_FMODStudio)
	#include <iostream>
#endif


using namespace UGK;

#ifndef UGKSND_FMODStudio
/**
*	\fn void CSound::CSound(char *P,int v, char *c)
*	Constructor of the class.
*	\param[in] Name Path where the sound is
*	\param[in] Vol Volume of the sound
*	\param[in] Path Path where the sound is
*/
CSound::CSound(char *Name,int Vol, char *Path)
{
	//Init();			//Next instruction assumes that Name and Path attributes are NULL. If this is not done, it crashes
	Init(Name, Vol, Path);
}

/**
*	\fn void CSound::~CSound()
*	Destructor of the Class. Close the Stream.
*/
CSound::~CSound(){}
#endif

#ifdef UGKSND_FMOD375 

void CSound::SetVolume2() { SoundCard->SetChannelVolume(Channel, Volume);}

/**
*	\fn void CSound::Play (int v)
*	Plays a given sound
*	\param[in] v Volume to play this sound (also modify the parameter of the object)
*/
void CSound::Play (int v)
{
	int S;

	Channel = FSOUND_PlaySoundEx(FSOUND_FREE, Sound, dspUnit, false);
	SetVolume (v);
}

#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
	// These functions use the "sourceID" added as a class atribute

	// Plays a sound at 
	void CSound::Play(int vol){
		alSourcePlay(sourceID);
		changeVolume(v);
	}

	void CSound::Play(){
		alSourcePlay(sourceID);
		changeVolume(Volume);
	}

	void CSound::SetVolume2()
	{
		float vol = (float) Volume / UGKCSND_MAX_VOLUMEf;
		alSourcef(sourceID, AL_GAIN, vol);
	}

	void CSound::Pause(){	
		alSourcePause(sourceID);
	}

	bool CSound::loadOGG(char *fileName, UGKSND_SoundType &buffer, ALenum &format, ALsizei &freq){
		int endian = 0;             // 0 for Little-Endian, 1 for Big-Endian
		int bitStream;
		long bytes;
		char array[BUFFER_SIZE];    // Local fixed size array
		FILE *f;
		// Open for binary reading
		f = fopen(fileName, "rb");
		if(!f){
			cout << "Error abriendo '" << fileName << endl;
			return false;
		}

		vorbis_info *pInfo;
		OggVorbis_File oggFile;

		ov_open(f, &oggFile, NULL, 0);
		if(!f) return false;
		// Get some information about the OGG file

		pInfo = ov_info(&oggFile, -1);

		// Check the number of channels... always use 16-bit samples
		if (pInfo->channels == 1)
			format = AL_FORMAT_MONO16;
		else
			format = AL_FORMAT_STEREO16;
		// end if

		// The frequency of the sampling rate
		freq = pInfo->rate;

		do {
			// Read up to a buffer's worth of decoded sound data
			bytes = ov_read(&oggFile, array, BUFFER_SIZE, endian, 2, 1, &bitStream);
			// Append to end of buffer
			buffer.insert(buffer.end(), array, array + bytes);
		} while (bytes > 0);

		ov_clear(&oggFile);
		return true;
	}
#elif defined(UGKSND_SDL)

/**
*	\fn void CSound::Play(Mix_Chunk *Sound, int vol)
*	Plays the own Sound
*	\param[in] vol Volume to play this sound
*/
void CSound::Play(int vol)
{	
	// 1st parameter sets the channel, -1 means the channel is selected by SDL
	// 2nd parameter is the sound to be reproduced
	// 3rd parameter sets the number of the sound replays, -1 for an infinite loop and 0 for only once
	SoundCard->SetVolumeSample(Sound,vol);
	SoundCard->PlayChannel(-1, Sound, 0);
}

/**
*	\fn void CSound::Play()
*	Plays the own Sound with its default volume
*/
void CSound::Play()
{	
	// 1st parameter sets the channel, -1 means the channel is selected by SDL
	// 2nd parameter is the sound to be reproduced
	// 3rd parameter sets the number of the sound replays, -1 for an infinite loop and 0 for only once
	SoundCard->SetVolumeSample(Sound,Volume);
	SoundCard->PlayChannel(-1, Sound, 0);
}
#elif defined(UGKSND_FMODStudio)
	//metodo que inicializa el objeto audio
	void CSound::DSPInit(){
	
		channel=0;

		 //Crear objeto system y inicializarlo

		result = FMOD::System_Create(&sys);
		FMODErrorCheck(result);

		// Comprobar version

		result = sys->getVersion(&version);
		FMODErrorCheck(result);
 
		if (version < FMOD_VERSION){
			std::cout << "Error! You are using an old version of FMOD " << version << ". This program requires " << FMOD_VERSION << std::endl;    
			//return 0; 
		}

		//inicializar FMod

		result = sys->init(32, FMOD_INIT_NORMAL, 0);
		FMODErrorCheck(result);

		//crear un oscilador DSP con la nota A3 -> 440Hz.

		result = sys->createDSPByType(FMOD_DSP_TYPE_OSCILLATOR, &dsp);
		result = dsp->setParameterFloat(FMOD_DSP_OSCILLATOR_RATE, 440.0f);
		FMODErrorCheck(result);

	}

	//metodo para mostrar informacion sobre el error generado
	void CSound::FMODErrorCheck(FMOD_RESULT result){

		if (result != FMOD_OK)
		{
			std::cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << std::endl;
			exit(-1);
		}

	}

	//metodo que asigna una frecuencia al sonido DSP
	void CSound::setDSPFreq(float freq){

		result = channel->getFrequency(&DSPfrequency);
		//FMODErrorCheck(result);
            
		DSPfrequency = freq;
            
		result = channel->setFrequency(DSPfrequency);
		//FMODErrorCheck(result);

	}

	//metodo que asigna un volumen al sonido DSP
	void CSound::setDSPVolumen(float vol){

		 result = channel->getVolume(&DSPvolumen);
		 //FMODErrorCheck(result);

		 DSPvolumen = vol;
           
		 result = channel->setVolume(DSPvolumen);
		 //FMODErrorCheck(result);
	}

	//metodo que activa el sonido DSP con un oscilador de onda senosoidal, cuadrada, triangular o de dientes de sierra
	void CSound::activeDSPSound(char tecla){

		if (!channel){
			result = channel->stop();
			result = sys->playDSP(dsp, 0, true, &channel);
			result = channel->setVolume(0.5f);
			switch(tecla){
			case 's':
				result = dsp->setParameterInt(FMOD_DSP_OSCILLATOR_TYPE, 0);
				break;
			case 'q':
				result = dsp->setParameterInt(FMOD_DSP_OSCILLATOR_TYPE, 1);
				break;
			case 'd':
				result = dsp->setParameterInt(FMOD_DSP_OSCILLATOR_TYPE, 3);
				break;
			case 't':
				result = dsp->setParameterInt(FMOD_DSP_OSCILLATOR_TYPE, 4);
				break;
			}
			result = channel->setPaused(false);
		}

	}

	//metodo que detiene el sonido DSP
	void CSound::stopDSPSound(){

		if (channel){
			result = channel->stop();
			channel = 0;
		}

	}

	//metodo que comprueba si esta activado/desactivado el sonido
	int CSound::isChannel(){
	
		if(channel) return 1;
		else return 0;
	}
#endif

/**
*	\fn void CSound::setVolume(int v)
*	Sets a new Volume
*	\param[in] v New volume to the sound
*/
void CSound::SetVolume(int vol)
{
	if(UGKSND_DEFAULT_VOLUME == vol)
		Volume = UGKSND_MEDIUM_VOLUME;
	else if(vol<UGKSND_MUTE)
		Volume = UGKSND_MUTE;
	else if (vol>UGKSND_MAX_VOLUME)
		Volume = UGKSND_MAX_VOLUME;
	else Volume = vol;

	//SetVolume2();
}

#ifndef UGKSND_FMODStudio
/**
*	\fn void CSound::SetName (char *name)
*	Specifies the name of a sound
*	\param[in] name The name of the sound
*/
void CSound::SetName (char *name)
{
	if(NULL != Name)
		delete Name;
	if (NULL == name)
	{
		Name = NULL;
		return;
	}

	Name = new char[strlen(name)+1];
	//strcpy (Name, name);
}


/**
*	\fn void CSound::SetPath (char *path)
*	Specifies the name of a sound
*	\param[in] path The name of the path of the sound
*/
void CSound::SetPath (char *path)
{
	if(NULL != Path)
		delete Path;
	if (NULL == path)
	{
		Path = NULL;
		return;
	}

	Path = new char[strlen(path)+1];
	//strcpy (Path, path);
}

/**
*	\fn void CSound::Init(char *P,int v, char *c)
*	Loads a given sound
*	\param[in] P The name of the sound
*	\param[in] v The volume of the sound
*	\param[in] c The path to the directory of the sound
*/
bool CSound::Init(char *name, int vol, char *path)
{

	SetName (name);
	SetPath (path);

	SetVolume(vol);
	
	//SoundCard = NULL;

	char aux[UGKSND_MAX_NAME_LENGTH];

	strcpy_s(aux, UGKOS_THIS_DIRECTORY);
	strcat_s(aux, UGKOS_DIRECTORY_SEPARATOR);
	strcat_s(aux,Path);
	strcat_s(aux, UGKOS_DIRECTORY_SEPARATOR);
	strcat_s(aux,Name);

	Position=0; //Reset to the very beginning of the sound

	#ifdef UGKSND_FMOD375 
		//Sound = FSOUND_Stream_Open(aux, 0, Position, 0);
		Sound = FSOUND_Sample_Load(FSOUND_FREE, aux, FSOUND_LOADMEMORY | FSOUND_LOOP_NORMAL, 0, 0);
	#elif defined(UGKSND_FMODEx)
		/// Complete
	#elif defined(UGKSND_OAL)
		// Create sound buffer and source
		alGenBuffers(1, &bufferID);
		alGenSources(1, &sourceID);

		// Set the source and listener to the same location. THIS CAN BE CHANGED TO IMPLEMENT DIFFERENT POSITIONS
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sourceID[j], AL_POSITION, 0.0f, 0.0f, 0.0f);

		if(loadOGG(aux, Sound, format, freq)==false) return false;

		// Upload sound data to buffer
		alBufferData(bufferID, format, &Sound[0], static_cast<ALsizei> (bufferData.size()), freq);
		// Attach sound buffer to source
		alSourcei(sourceID, AL_BUFFER, bufferID);

		// All ready: sourceID will be the main variable now
	#elif defined(UGKSND_SDL)
		Sound = Mix_LoadWAV(aux);
		if(!Sound)
			 // handle error 
			return false;
	#elif defined(UGKSND_FMODStudio)
	#endif
	//Sound loaded. Proceed
	return true;
}
#endif

/**
*	\fn void CSound::close()
*	Close the stream of the sound
*/
void CSound::close(){

	#ifdef UGKSND_FMOD375
		FSOUND_Sample_Free(Sound);
	#elif defined(UGKSND_FMODEx)
		/// Complete
	#elif defined(UGKSND_OAL)
		// Note: this is for normal sound playing (not streaming)
		alDeleteBuffers(1, &bufferID);
		alDeleteSources(1, &sourceID);
	#elif defined(UGKSND_SDL)
		SoundCard->DeleteSample(Sound);
	#elif defined(UGKSND_FMODStudio)
		result = dsp->release();
		FMODErrorCheck(result);
		result = sys->close();
		FMODErrorCheck(result);
		result = sys->release();
		FMODErrorCheck(result);
	#endif
}