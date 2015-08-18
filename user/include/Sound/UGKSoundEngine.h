/**	Definition of the sound engine

*	Prefix: UGKSNDENG_

*	@author Leopoldo Pla 
*	@version 2015-01
*/

#ifndef UGKSNDENG_SOUNDENGINE
#define UGKSNDENG_SOUNDENGINE

// Be careful, use only one API every time
// The value in the definition is used to correctly identify the definition, if you
// remove the value VS generates error c1017
//#define UGKSND_FMOD375 1
//#define UGKSND_FMODEx 2
//#define UGKSND_OAL 3
//#define UGKSND_SDL 4
#define UGKSND_FMODStudio 5

#ifdef UGKSND_FMOD375
	#include <fmod.h>
	#define FMOD_ERR_UNKNOWN	FMOD_ERR_CDDEVICE + 1
	#define FMOD_ERR_MAX		FMOD_ERR_UNKNOWN + 1
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
	#include <AL/al.h>
	#include <AL/alc.h>
	#include "vorbis/vorbisfile.h"
#elif defined(UGKSND_SDL)
	#include <SDL_mixer.h>
	#include <SDL.h>
#elif defined(UGKSND_FMODStudio)
	#include "fmod.hpp"
	#include "fmod_errors.h"
#endif

#endif
