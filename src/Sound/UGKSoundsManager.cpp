/** Definition of the Class Sound Manager
*  General class to manage all the sounds
*  Prefix: UGKCSM_

*	@author Ramon Molla, Carlos Martinez Perez
*	@version 2014-05
*	@NewVersion Ramón Mollá 2014-05 - API conversion and refactoring

*/

#include <UGKSoundsManager.h>
#include <UGKLog.h>

#ifdef	UGKOS_WINDOWS
	#include <Wininet.h>
	#include <delayimp.h>		// For unloading dll (__FUnloadDelayLoadedDLL2(),...)
#elif	defined(UGKOS_LINUX)
#elif	defined(UGKOS_OSX)
#elif	defined(UGKOS_ANDROID)
#endif

using namespace UGK;

#ifdef UGKSND_FMOD375

char *CSM_ErrorString[FMOD_ERR_MAX] = 
{
    "No errors",
    "Cannot call this command after FSOUND_Init.  Call FSOUND_Close first.",
    "This command failed because FSOUND_Init was not called",
    "Error initializing output device.",
    "The output device is already in use and cannot be reused.",
    "Playing the sound failed.",
    "Soundcard does not support the features needed for this soundsystem (16bit stereo output)",
    "Error setting cooperative level for hardware.",
    "Error creating hardware sound buffer.",
	"File not found",
	"Unknown file format",
	"Error loading file",
    "Not enough memory or resources",
	"The version number of this file format is not supported",
	"An invalid parameter was passed to this function",
	"Tried to use an EAX command on a non EAX enabled channel or output.",
	"Failed to allocate a new channel",
	"Recording is not supported on this machine",
    "Windows Media Player or codec is not installed, so cannot play wma or use internet streaming.",
    "An error occured trying to open the specified CD device.",
	"Unknown error"
};
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
#elif defined(UGKSND_SDL)
char *CSM_ErrorString[UGK::SDL_ERR_MAX] = 
{
    "No errors",
	"Unknown error",
    "Cannot call this command after FSOUND_Init.  Call FSOUND_Close first.",
    "This command failed because FSOUND_Init was not called",
    "Error initializing output device.",
    "The output device is already in use and cannot be reused.",
    "Playing the sound failed.",
    "Soundcard does not support the features needed for this soundsystem (16bit stereo output)",
    "Error setting cooperative level for hardware.",
    "Error creating hardware sound buffer.",
	"File not found",
	"Unknown file format",
	"Error loading file",
    "Not enough memory or resources",
	"The version number of this file format is not supported",
	"An invalid parameter was passed to this function",
	"Tried to use an EAX command on a non EAX enabled channel or output.",
	"Failed to allocate a new channel",
	"Recording is not supported on this machine",
    "Windows Media Player or codec is not installed, so cannot play wma or use internet streaming.",
    "An error occured trying to open the specified CD device."
};
#elif defined(UGKSND_FMODStudio)
#endif

//
/**
*	\fn void CSoundsManager::SupportFiles (int FilesMask)
*	Indicate the file types to support while working on the next session
*/
int	CSoundsManager::SupportFiles	(int FilesMask)
{
	int FilesActivated;

#ifdef UGKSND_FMOD375
	return 0;
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
#elif defined(UGKSND_SDL)
	FilesActivated = Mix_Init(FilesMask);


	if (0 == FilesActivated)
		{			
			MessageBox(0, GetErrorMsg(), "Sound Initialization Error", MB_TOPMOST);
			Close();
		}
	else if (FilesMask != FilesActivated)
		{			
			MessageBox(0, GetErrorMsg(), "Some Sounds Initialization Error", MB_TOPMOST);
			Close();
		}

	return FilesActivated;
#elif defined(UGKSND_FMODStudio)
	return 1;
#endif
}

//
/**
*	\fn void CSoundsManager::Init(void)
*	Initialize the FMOD
*/
void CSoundsManager::Init (void)
{
	//SoundCard->Init();

	#ifdef UGKSND_FMOD375
		//OscBuffer	= NULL;
		//OscBlock	= 0;

		//ACKTUNG: Cambiar los siguientes atributos a medida que se vayan avanzando en el refactoring
		// SCROLL MUSIC TEXT
		scroll_music_x			= 0;	// SCROLL COORD X
		scroll_music_sens		= 1;	// SCROLL SENS DE DEPLACEMENT
		scroll_music_total		= 0;	// SCROLL TOTAL DEPLACEMENT
		MP3SoundChannel				= 0;
		PlayingMusic				= true;

		Volume = UGKSND_MUTE;
	#elif defined(UGKSND_FMODEx)
	#elif defined(UGKSND_OAL)
	#elif defined(UGKSND_SDL)
	#elif defined(UGKSND_FMODStudio)
	#endif
}


/**
*	\fn void CSound::SetTrackPath (char *name)
*	Specifies the name of a TrackPath. It does not include directories slash separator
*	\param[in] name The name of the TrackPath
*/
void CSoundsManager::SetTrackPath (char *name)
{
	if(NULL != TrackPath)
		delete [] TrackPath;

	TrackPath = new char[strlen(name)+1];
	//strcpy(TrackPath, name);
}

/**
*	\fn void CSound::SetMusicPath (char *name)
*	Specifies the name of a MusicPath. It does not include directories slash separator
*	\param[in] name The name of the MusicPath
*/
void CSoundsManager::SetMusicPath (char *name)
{
	if(NULL != MusicPath)
		delete [] MusicPath;

	MusicPath = new char[strlen(name)+1];
	//strcpy (MusicPath, name);
}

/**
*	\fn void CSoundsManager::LoadSounds(void)
*	Loads all the different sounds that can be performed at any time during the playing of the game
*	\param[in] Size Number of sounds to load.
*	\param[in] SoundsFiles Name of the files to load.
*/
void CSoundsManager::LoadSounds(int Size, std::string SoundsFiles[])
{
	CSound *OneSound;
	NSounds=Size;

	for(int i=0;i<NSounds;i++){
		OneSound = new CSound((char*) SoundsFiles[i].c_str(),UGKSND_MAX_VOLUME,TrackPath);
		//OneSound->SetAudioHardware(SoundCard);
		Sound.push_back(*OneSound);
	}
};

// For use with ParsePlaylist() underneath
char *stristr(char *string2, char *string1)
{
    char *s1 = _strdup(string1);
    char *s2 = _strdup(string2);
    char *ret = 0;
    int i, j;
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    for (i=0;s1[i];i++) s1[i] = tolower(s1[i]);
    for (i=0;s2[i];i++) s2[i] = tolower(s2[i]);

    for (j=0;j < (len2 - len1);j++)
    {
        char *a = s1;
        char *b = &s2[j];

        for (i=0;(i < len1) && *a && *b;a++, b++, i++)
        {
            if (*a != *b)
            {
                break;
            }
        }

        if (i == len1)
        {
            ret = &string2[j];
            break;
        }
    }

    free(s1);
    free(s2);
    return ret;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// FONCTIONS => Parse un fichier .pls (Winamp playlist)
//
//
/*Playlist *CSoundsManager::ParsePlaylist(char *name)
{
    char        *filebuf, *p;
    Playlist    *playlist = 0;
	int          count, i;


	// Check if URL null
    if (!name)
    {
        //BOX("Streaming URL is empty");
		return 0;
    }
		
	// Check if URL is a *.pls file
	if (_stricmp((const char *)".pls", (const char *)(&name[strlen(name) - 4])))
    {
		return 0;
    }

    // Create a WinInet session
    //HINTERNET hSession = InternetOpen("", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
    // Prepare a request
	//HINTERNET hRequest = InternetOpenUrl(hSession, name, 0, 0, 0, 0);

    // Send the HTTP request.
    //HttpSendRequest(hRequest, 0, 0, 0, 0);

    // Read the response data.
    DWORD dwNumberOfBytesAvailable = 0;

    do
    {
        // Retrieve size of remote file
		//InternetQueryDataAvailable(hRequest, &dwNumberOfBytesAvailable, 0, 0);

        if (0 < dwNumberOfBytesAvailable)
        {
			// Allocate buffer memory
			filebuf = new char[dwNumberOfBytesAvailable + 1];
            filebuf[dwNumberOfBytesAvailable] = 0;

            DWORD dwBytesRead = 0;

            // Read remote file and put in buffer
			//InternetReadFile(hRequest,
            //                   filebuf,
            //                   dwNumberOfBytesAvailable,
            //                   &dwBytesRead);

			//BOX(filebuf);
        }
    }
    while (0 < dwNumberOfBytesAvailable);

    // Close the request handle.
    //InternetCloseHandle(hRequest);

    // Close the WinInet session.
    //InternetCloseHandle(hSession);

	// Parse the pls file (from Fmod sample)
    p = stristr(filebuf, "NumberOfEntries=");
    if (!p)
    {
		//BOX("Streaming : NumberOfEntries in pls file not found");
		return 0;
    }

    p += 16;
    count = atoi(p);

    if (!count)
    {
		//BOX("Streaming : numeric value for NumberOfEntries not found");
		return 0;
    }

    playlist = (Playlist *)calloc(sizeof(Playlist), 1);
    if (!playlist)
    {
		//BOX("Streaming : can't allocate memory for pls file (playlist)");
		return 0;
    }

    playlist->count = count;

	playlist->name = (void **)calloc(sizeof(char *) * count, 1);
    if (!playlist->name)
    {
		//BOX("Streaming : can't allocate memory for pls file (playlist->name)");
		return 0;
    }

    playlist->displayname = (void **)calloc(sizeof(char *) * count, 1);
    if (!playlist->displayname)
    {
		//BOX("Streaming : can't allocate memory for pls file (playlist->displayname)");
		return 0;
    }

    for (i=0;i < count;i++)
    {
        char tmp[32];
        char *filename, *displayname, *t;

        filename = displayname = 0;

        sprintf_s(tmp, "File%d=", i + 1);
        p = strstr(filebuf, tmp);
        if (p)
        {
            p += strlen(tmp);
            t = p;
            for (;*t && (*t != 0xa) && (*t != 0xd);t++);
            if (*t)
            {
                char tmpc = *t;
                *t = 0;
                filename = _strdup(p);
                *t = tmpc;
            }
        }

        if (strncmp(filename, "http://", 7) && strncmp(filename, "http:\\\\", 7))
        {
            char *tmpname = _strdup(filename);
            p = &tmpname[strlen(tmpname) - 1];
            for (;(p > tmpname) && (*p != '\\') && (*p != '/');p--);
            if ((*p == '\\') || (*p == '/'))
            {
                p++;
            }
            displayname = _strdup(p);
            free(tmpname);
        }

        playlist->name[i] = filename;
        playlist->displayname[i] = displayname;
    }

    free(filebuf);
    return playlist;
}
*/
/**
*	\fn CSoundsManager::~CSoundsManager()
*	Destructor of the SoundManager
*/
CSoundsManager::~CSoundsManager(){
	for(int i=0;i<NSounds;i++){
		//Clean up all the Streams
		Sound.at(i).close();
		//FSOUND_Stream_Close (Sound.at(i).getStream());
	}
	//SoundCard->CloseAudio();
}

/**
*	\fn void CSoundsManager::ErrorMsg(unsigned int errcode)
*	Returns the last error happened in the SoundsManager as a human readable string
*	\param[in] errcode Error code
*/
char *CSoundsManager::ErrorMsg(const int errcode)
{
	#ifdef UGKSND_FMOD375
	if (FMOD_ERR_MAX <= errcode || errcode < 0)
		return CSM_ErrorString[FMOD_ERR_UNKNOWN];
	else return CSM_ErrorString[errcode];
	#elif defined(UGKSND_FMODEx)
	#elif defined(UGKSND_OAL)
		int errcode = alGetError();
		switch (errcode){
			case AL_INVALID_NAME:
				return "Invalid name.";
			case AL_INVALID_ENUM:
				return "Invalid enumeration.";
			case AL_INVALID_VALUE:
				return "Invalid value.";
			case AL_INVALID_OPERATION:
				return "Invalid operation.";
			case AL_OUT_OF_MEMORY:
				return "Out of memory!";
			default:
				return "Unknown OpenAL error.";
		}
	#elif defined(UGKSND_SDL)
	if (SDL_ERR_MAX <= errcode || errcode < 0)
		return CSM_ErrorString[SDL_ERR_UNKNOWN];
	else return Mix_GetError();
	#elif defined(UGKSND_FMODStudio)
		return "error";
	#endif
}

/**
*	\fn void CSoundsManager::StreamFadingIn()
*	Pump up the volume of the music. It has to be executed by a new thread since it uses the sleep function
*/
void CSoundsManager::StreamFadingIn()
{
	int volume = 0;

	do
	{
		volume += UGKCSM_FADING_STEP;

		//SoundCard->SetChannelVolume(MP3SoundChannel, volume);
		Sleep(UGKCSM_FADING_STEP_DURATION);
	}
	while(volume <= UGKSND_MAX_VOLUME);
}


#ifdef UGKSND_FMOD375

	void * F_CALLBACKAPI dspCallbackSounds(void *originalbuffer, void *newbuffer, int length, int param)
	{
		return newbuffer;
	}

	void * F_CALLBACKAPI dspCallbackSpectrum(CSoundsManager *SM, void *originalbuffer, void *newbuffer, int length, int param)
	{
		int             mixertype = FSOUND_GetMixer();
		int             count;
		int             totalblocks; 
		signed short    *dest;

		totalblocks = FSOUND_DSP_GetBufferLengthTotal() / FSOUND_DSP_GetBufferLength(); 
	
		// Convert and downmix into a mono short int buffer.

	dest = &SM->OscBuffer[SM->OscBlock * FSOUND_DSP_GetBufferLength()];

		//char tempstr[255]="";
		//_itoa(*SoundsManager.OscBuffer, tempstr, 10);
		//OutputDebugString(tempstr);

		//if (mixertype == FSOUND_MIXER_QUALITY_FPU)
		if (1)
		{
			float *src = (float *)newbuffer;

			for (count=0; count < length; count++)
			{
				//dest[count] = (signed short)(src[count << 1] + src[(count << 1) + 1] * 0.5f);
				dest[count] = (signed short)(src[count]);
			}
		}
		else
		{
			signed short *src = (signed short *)newbuffer;

			for (count=0; count < length; count++)
			{
				dest[count] = (signed short)(((int)src[count << 1] + (int)src[(count << 1) + 1]) >> 1);
			}
		}    

		SM->OscBlock++;
		if (SM->OscBlock >= totalblocks)
		{
			SM->OscBlock = 0;
		}

		return newbuffer;
	}

char	artist[UGKSND_MAX_NAME_LENGTH]	= "";
char	title[UGKSND_MAX_NAME_LENGTH]	= "";
int		metanum							= 0;

signed char F_CALLBACKAPI metacallback(char *name, char *value, int userdata)
{
    if (!strcmp("ARTIST", name))
    {
        strcpy_s(artist, value);
        return true;
    }

    if (!strcmp("TITLE", name))
    {
        strcpy_s(title, value);
        metanum++;
        return true;
    }
    return true;
}

/**
*	\fn void CSoundsManager::MusicFadingIn(void *dummy)
*	
*/
void CSoundsManager::MusicFadingIn(void )
{
	FMUSIC_SetMasterVolume(FadingModule, UGKSND_MUTE);

	if (!FMUSIC_IsPlaying(FadingModule))
		FMUSIC_PlaySong(FadingModule);
	
	int volume = UGKSND_MUTE;

	do
	{
		volume += UGKSND_VOLUME_INCREMENT;
		FMUSIC_SetMasterVolume(FadingModule,volume);
		Sleep(10);
	}
	while(volume <= UGKSND_MAX_VOLUME);
	//_endthread();
}

/**
*	\fn void CSoundsManager::MusicFadingOut(void *dummy)
*	
*/
void CSoundsManager::MusicFadingOut(void)
{
	int volume = UGKSND_MAX_VOLUME;

	do
	{
		volume -= UGKSND_VOLUME_INCREMENT;
		FMUSIC_SetMasterVolume(FadingModule,volume);
	
		Sleep(10);
	}
	while(volume >= 0);

	FMUSIC_StopSong(FadingModule);
	//_endthread();
}

void CSoundsManager::StopMusic(void)
{
	if (PlayingMusic){
		music->Stop();
		music->close();
		music=NULL;
	}
	PlayingMusic=false;
}

#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)

	void CSoundsManager::MusicFadingIn(){
		if(PlayingMusic==false){
			music->Play(CSND_MUTE);
		}
		do{
			music->changeVolume((music->Volume)+CSND_VOLUME_INCREMENT);
			Sleep(CSM_FADING_STEP_DURATION);
		}while ((music->Volume)<CSND_MAX_VOLUME)
	}

	void CSoundsManager::MusicFadingOut(){
		if (!PlayingMusic) return;
		do{
			music->changeVolume((music->Volume) - CSND_VOLUME_INCREMENT);
			Sleep(CSM_FADING_STEP_DURATION);
		} while ((music->Volume)>CSND_MUTE)
	}

	void CSoundsManager::LoadMusic(const char* file){
		// Loads the music
		music=new CSound(file, CSND_MAX_VOLUME, MusicPath[CSM_MUSIC]);
		music->SoundCard = SoundCard;		
	}

	void CSoundsManager::SetMusicPath(const char* path)
	{
		for (int i = 0; i<CSM_MAX_MUSIC_TRACKS; i++)
		{
			strcpy_s(MusicPath[i], path);
		}
	}

	void CSoundsManager::StopMusic(void)
	{
		if (PlayingMusic){
			music->Stop();
			music->Close();
			music=NULL;
		}
		PlayingMusic=false;
	}

	void CSoundsManager::NextMusicTrack(void)
	{
		if (PlayingMusic){
			StopMusic();
		}
		currentMusicIndex++;
		LoadMusic("music_around_the_world.ogg");
		MusicFadingIn();
	}

#elif defined(UGKSND_SDL)

/**
*	\fn void CSoundsManager::StopMusic(void *dummy)
*	Stops the music and frees the resources
*/
void CSoundsManager::StopMusic(void)
{
	if(PlayingMusic){
		SoundCard->HaltMusic();
		SoundCard->FreeMusic(music);
		music = NULL;
		PlayingMusic = false;
	}
}
#elif defined(UGKSND_FMODStudio)
#endif

/**
*	\fn void CSoundsManager::NextMusicTrack(void)
*	Selects the next track in the track array, loads it into memory and starts the music
*/
void CSoundsManager::NextMusicTrack(void)
{
	currentMusicIndex++;
	
	if(PlayingMusic){
		StopMusic();
		//MusicFadingIn();
	}else{
		//MusicFadingIn();
	}
}

