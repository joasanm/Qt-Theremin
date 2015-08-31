/**	Definition of the class Sound for the UPV Game Kernel

*	Prefix: UGKSND_

*	@author Ramon Molla, Carlos Martinez Perez
*	@version 2011-07
*	@NewVersion Alfonso Pérez 2013-03
	@NewVersion Ramón Mollá 2014-05 - API conversion and refactoring
*/

#ifndef UGKSND_SOUND
#define UGKSND_SOUND

#include <stdlib.h>

#include <UGKSoundEngine.h>

#include <UGK.h>

//#include <UGKAudioHardware.h>



/**
*	Predefined sound volumes
*	In SDL the max vol level is half the max vol level in FMOD so the volumes need to be redefined
*/
#ifdef UGKSND_FMOD375
	#define UGKSND_DEFAULT_VOLUME		 -1		///< Default volume of the sound.
	#define UGKSND_MUTE					  0		///< Volume muted
	#define UGKSND_VOLUME_INCREMENT		  5		///< Increment of volume for ramp fading in or out
	#define UGKSND_ULTRA_LOW_VOLUME	     16		///< A VERY low value of volume
	#define UGKSND_LOW_VOLUME			 32		///< The low value of volume
	#define UGKSND_LOW_MED_VOLUME		 90		///< Low to medium value of volume
	#define UGKSND_MEDIUM_VOLUME		128     ///< The medium value of volume
	#define UGKSND_VOLUME_60			153     ///< 60% of the maximun volume
	#define UGKSND_VOLUME_80			204     ///< 80% of the maximun volume
	#define UGKSND_MAX_VOLUME			255		///< The maximun value a sound can reach at the top of its power
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
	// The volume values will later be converted to a 0.0 - 1.0 scale
	#define UGKCSND_DEFAULT_VOLUME		 255	///< Default volume of the sound.
	#define UGKCSND_MUTE				  0		///< Volume muted
	#define UGKCSND_VOLUME_INCREMENT	  5		///< Increment of volume for ramp fading in or out
	#define UGKCSND_ULTRA_LOW_VOLUME	 16		///< A VERY low value of volume
	#define UGKCSND_LOW_VOLUME			 32		///< The low value of volume
	#define UGKCSND_LOW_MED_VOLUME		 90		///< Low to medium value of volume
	#define UGKCSND_MEDIUM_VOLUME		128     ///< The medium value of volume
	#define UGKCSND_VOLUME_60			153     ///< 60% of the maximun volume
	#define UGKCSND_VOLUME_80			204     ///< 80% of the maximun volume
	#define UGKCSND_MAX_VOLUME			255		///< The maximun value a sound can reach at the top of its power
	#define UGKCSND_MAX_VOLUMEf			255.0f	///< The maximun value a sound can reach at the top of its power
#elif defined(UGKSND_SDL)
	#define UGKSND_DEFAULT_VOLUME		 -1		///< Default volume of the sound.
	#define UGKSND_MUTE					  0		///< Volume muted
	#define UGKSND_VOLUME_INCREMENT		  3		///< Increment of volume for ramp fading in or out
	#define UGKSND_ULTRA_LOW_VOLUME	      8		///< A VERY low value of volume
	#define UGKSND_LOW_VOLUME			 16		///< The low value of volume
	#define UGKSND_LOW_MED_VOLUME		 45		///< Low to medium value of volume
	#define UGKSND_MEDIUM_VOLUME		 64     ///< The medium value of volume
	#define UGKSND_VOLUME_60			 77     ///< 60% of the maximun volume
	#define UGKSND_VOLUME_80			102     ///< 80% of the maximun volume
	#define UGKSND_MAX_VOLUME			127		///< The maximun value a sound can reach at the top of its power
#elif defined(UGKSND_FMODStudio)
	#define UGKSND_DEFAULT_VOLUME		 -1		///< Default volume of the sound.
	#define UGKSND_MUTE					  0		///< Volume muted
	#define UGKSND_VOLUME_INCREMENT		  5		///< Increment of volume for ramp fading in or out
	#define UGKSND_ULTRA_LOW_VOLUME	     16		///< A VERY low value of volume
	#define UGKSND_LOW_VOLUME			 32		///< The low value of volume
	#define UGKSND_LOW_MED_VOLUME		 90		///< Low to medium value of volume
	#define UGKSND_MEDIUM_VOLUME		128     ///< The medium value of volume
	#define UGKSND_VOLUME_60			153     ///< 60% of the maximun volume
	#define UGKSND_VOLUME_80			204     ///< 80% of the maximun volume
	#define UGKSND_MAX_VOLUME			255		///< The maximun value a sound can reach at the top of its power
#endif

	#define UGKSND_HAL	F_POSITION 1000
	#define UGKSND_STRD_POSITION 2000

	#define UGKSND_MAX_NAME_LENGTH 256

namespace UGK
{

	/**
	*	\class CSound
	*	Manages a single sound: loads it, unloads, plays, change intensity,...
	*/

	class UGK_API CSound
	{
		#ifndef UGKSND_FMODStudio
		char *Path;	///<Path to the sound.
		char *Name;	///<Name of the sound file.
	
		//UGKAudioHardware* SoundCard;

		void SetVolume2();	///< Internal volume change function specific for every kind of sound management API
		#endif
	public:

		//Atributes
		#ifdef UGKSND_FMOD375
			FSOUND_DSPUNIT* dspUnit;
			#define UGKSND_SoundType FSOUND_SAMPLE*
			int Channel;	///< Sound channel on which the sound will be phisically played
		#elif defined(UGKSND_FMODEx)
		#elif defined(UGKSND_OAL)
			ALuint bufferID;            // The OpenAL sound buffer ID
			ALuint sourceID;            // The OpenAL sound source
			ALenum format;              // The sound data format
			ALsizei freq;               // The frequency of the sound data
			#define UGKSND_SoundType vector<char>
		#elif defined(UGKSND_SDL)
			#define UGKSND_SoundType Mix_Chunk*
		#elif defined(UGKSND_FMODStudio)
			//using namespace FMOD;
			FMOD::System    *sys;
			FMOD::Channel   *channel;
			FMOD::DSP       *dsp;
			FMOD_RESULT      result;
			unsigned int version;		//variable con la informacion de la version de las librerias del FMod
			float DSPfrequency;			//variable necesaria para acualizar la frecuencia del objeto audio
			float DSPvolumen;				//variable necesaria para acualizar el volumen del objeto audio
		#endif

		//UGKSND_SoundType Sound;				///<The sound to be played in fmod type.
		int Volume;							///<The intensity of the sound. 0 no sound, 255 maximun power (in SDL the maximun is 128)
		int Position;						///<The position of the sound.

		//Methods
		/**
		*	\fn void CSound::Init()
		*	Basic constructor
		*/
		#ifndef UGKSND_FMODStudio
		inline void Init() {Path = NULL; Name = NULL; Position = 0; Volume = UGKSND_MAX_VOLUME; SoundCard = NULL;}
		bool		Init(char *name,int vol,char *path);///< Initializes a new sound
	
		CSound(){Init();}						///< Constructor of the class
		CSound(char *name,int vol,char *path);	///< Constructor of the class
		~CSound();

		void SetName (char *name);
		void SetPath (char *path);
		inline char *GetName () {return Name;}
		inline char *GetPath () {return Path;}
		//inline void	SetAudioHardware(UGKAudioHardware* sc){SoundCard = sc;}
		//UGKAudioHardware *GetAudioHardware(){return SoundCard;}
		
		void Load(const unsigned short Resource, const unsigned short Volume);	// The resource that specifies the sound to be loaded
		void Play(int vol);							///< Plays this sound with a determined volume (v can be NULL) 
		void Play();

		//UGKSND_SoundType getStream(); ///< Get the stream of the sound
		#endif
		#ifdef UGKSND_FMOD375
			//void Play (FSOUND_DSPUNIT* dspUnitSounds,int v);///< Plays a sound with a determined volume (v can be NULL)
			inline void Stop(){SoundCard->HaltChannel(Channel);}
		#elif defined(UGKSND_FMODEx)
		#elif defined(UGKSND_OAL)
			bool loadOgg(char *fileName, UGKSND_SoundType &buffer, ALenum &format, ALsizei &freq);
			inline void Stop(){alSourceStop(sourceID);}
		#elif defined(UGKSND_SDL)
			inline void Stop(){SoundCard->DeleteSample(Sound);}
		#elif defined(UGKSND_FMODStudio)
			void DSPInit();
			void FMODErrorCheck(FMOD_RESULT result);
			void setDSPFreq(float freq);
			void setDSPVolumen(float vol);
			void activeDSPSound(char tecla);
			void stopDSPSound();
			int isChannel();
			void adsr(float vinit, float va, float ta, float vd, float td, float ts, float tr);
		#endif

		void SetVolume(int vol); ///< Set new volume
		/**
		*	\fn UGKSND_SoundType CSound::getStream()
		*	gets the stream of the sound
		*/
		//inline UGKSND_SoundType GetSound(){return Sound;}


		/**
		*	\fn void CSound::setPosition(int position)
		*	Sets a new Position to the sound
		*	\param[in] position New position to the sound
		*/
		inline void setPosition(int position) { if(0 > position) Position = 0; else Position=position;}

		void Pause();
		void close(); ///<Close the stream of the sound
	
	};
}

#ifdef UGKSND_FMOD375
	void * F_CALLBACKAPI dspCallbackSounds(void *originalbuffer, void *newbuffer, int length, int param);
	signed char F_CALLBACKAPI metacallback(char *name, char *value, int userdata);
#elif defined(UGKSND_FMODEx)
#elif defined(UGKSND_OAL)
#elif defined(UGKSND_SDL)
#elif defined(UGKSND_FMODStudio)
#endif

#endif
