/**	Listener class to detect movements with Leap device
*	Prefix: GR_	Gesture Recognizer
*	@Author: Juan Cerrón, Cédric Marco
*	@version: 2013-14
**/

// If the macro of the Leap is not defined it is declared.
#ifndef CGESTURERECOGNIZER_H
#define CGESTURERECOGNIZER_H

#include <UGKLeapVersion.h>
#include <UGK.h>

typedef enum {
	GR_LEFT_MOVE,	// Code for left move
	GR_STOP_MOVE,	// Code for stop move
	GR_RIGHT_MOVE,	// Code for right move
	GR_TOP_MOVE, // Code for top move
	GR_FORWARD_MOVE, // Code for moving forward
	GR_BACKWARD_MOVE, // Code for moving backward
	GR_BOTTOM_MOVE, // Code for bottom move
	GR_QUICK_SHOOT_MOVE, // Code for normal shooting
	GR_SLOW_SHOOT_MOVE, // Code for special shooting
	GR_MAX_MOVE	// Amount of extra lasers the player has
} GR_GESTURE_TYPE;

using namespace Leap;

namespace UGK
{
class UGK_API CGestureRecognizer : public Listener {
  
private:
	Frame m_lastFrame;

	virtual void onInit(const Controller&);
    virtual void onExit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);

	#ifdef UGKLEAP_V2
		Vector UGKhandsGl[40];			//array con las posiciones x,y,z del comienzo y final de cada hueso de las manos
		Vector UGKpalma[2];				//array con las posiciones x,y,z del centro de las manos
		//float anchuraPalmas[2];		//array con la anchura de la palma de las manos
		Matrix UGKdireccionMano[2];		//array con la direccion de la mano
		Matrix UGKdireccionHuesos[40];	//array con las direcciones de los huesos
		Vector UGKcentroHuesos[40];		//array con las posiciones x,y,z de los huesos
		float UGKlongitudHuesos[40];	//array con las longitudes de los huesos
		float UGKanchuraHuesos[40];		//array con las anchuras de los huesos
		int maxOct;						//valor de la octava a la que se puede llegar a tocar
		int maxVol;						//valor del volumne al que se puede llegar a tocar
		float freq;						//valor de la frecuencia de tono que se debe pasar al objeto audio
		float volumen;					//valor del volumen del tono que se debe pasar al objeto audio
		int UGKnumManos;				//valor con el numero de manos registradas
	#endif

public:

	virtual void GestureTreatment (GR_GESTURE_TYPE GT) = 0;

	#ifdef UGKLEAP_V2

		Vector getHands(int i);
		Vector getPalma(int i);
		Matrix getDireccionHueso(int i);
		Matrix getDireccionMano(int i);
		Vector getPosicionHueso(int i);
		float getLongitudHueso(int i);
		float getAnchuraHueso(int i);
		//float getAnchuraPalma(int i);
		float getFreq();
		float getVolumen();
		int getNumManos();
		void setMaxOct(float i);
		int getMaxOct();
		void setMaxVol(float i);
		int getMaxVol();

	#endif

};
}
#endif