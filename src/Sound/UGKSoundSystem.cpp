/*	Definition of the class Sound System

	Prefix: UGKCSNDS_

	@author Ramon Molla
	@version 2014-05

*/

#include <UGKSoundSystem.h>

#ifdef UGKSND_FMOD375
	#include <stdio.h> //Required because of the NULL definition
#endif

#ifdef UGKSND_FMOD375
char UGKCSNDS_ErrorString[FMOD_ERR_MAX][UGKCSNDS_ERR_MAX_LONG] = 
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
    "An error occured trying to open the specified CD device."
};
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
#elif defined(UGKSND_SDL)
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#elif defined(UGKSND_FMODStudio)
#endif

using namespace UGK;

void CSoundSystem::Init (void)
{
	#ifdef UGKSND_FMOD375
		OscBuffer	= NULL;
		OscBlock	= 0;
	#elif defined(UGKSND_FMODEx)
	#elif defined(UGKSND_OAL)
	#elif defined(UGKSND_SDL)
	// Initialize SDL audio
    if (SDL_Init(SDL_INIT_AUDIO))
	{
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        return ;
    }
	#elif defined(UGKSND_FMODStudio)
	#endif
}


char *CSoundSystem::ErrorMsg(unsigned int errcode)
{
#ifdef UGKSND_FMOD375
	if (FMOD_ERR_MAX <= errcode || errcode < 0)
		return "Unknown error";
	else return UGKCSNDS_ErrorString[errcode];
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
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
	return Mix_GetError();
#elif defined(UGKSND_FMODStudio)
	return "FMOD_Studio error";
#endif
}