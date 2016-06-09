/**	
*	Prefix: 
*	@Author: Juan Cerrón, Cédric Marco
* 		 Sancho Martínez. Joan
*	@version: 2013-14
**/

#include <iostream>
#include <UGKLeapGestureRecognizer.h>

using namespace UGK;

void CGestureRecognizer::onInit(const Controller& controller) {
  //Note: not dispatched when running in a debugger.
  std::cout << "Initialized" << std::endl;
}

void CGestureRecognizer::onConnect(const Controller& controller) {
  std::cout << "Connected" << std::endl;
#ifdef UGKLEAP_V1
  controller.enableGesture(Gesture::TYPE_CIRCLE);
  controller.enableGesture(Gesture::TYPE_SWIPE);
#endif
}

void CGestureRecognizer::onExit(const Controller& controller) {
  //Note: not dispatched when running in a debugger.
  std::cout << "Exited" << std::endl;
}

void CGestureRecognizer::onDisconnect(const Controller& controller) {
  //Note: not dispatched when running in a debugger.
  std::cout << "Disconnected" << std::endl;
}

#ifdef UGKLEAP_V2

//metodo que devuelve el valor de la posicion de un punto de flexion de la mano
Vector CGestureRecognizer::getHands(int i){return UGKhandsGl[i];}

//metodo que devuelve el valor de la posicion de una palma
Vector CGestureRecognizer::getPalma(int i){return UGKpalma[i];}

//metodo que devuelve la matriz de direccion de un hueso
Matrix CGestureRecognizer::getDireccionHueso(int i){return UGKdireccionHuesos[i];}

//metodo que devuelve la matriz de direccion de una palma
Matrix CGestureRecognizer::getDireccionMano(int i){return UGKdireccionMano[i];}

//metodo que devuelve el valor de la posicion de un hueso de la mano
Vector CGestureRecognizer::getPosicionHueso(int i){return UGKcentroHuesos[i];}

//metodo que devuelve el valor de la longitud de un hueso de la mano
float CGestureRecognizer::getLongitudHueso(int i){return UGKlongitudHuesos[i];}

//metodo que devuelve el valor de la anchura de un hueso de la mano
float CGestureRecognizer::getAnchuraHueso(int i){return UGKanchuraHuesos[i];}

//float leapMotion::getAnchuraPalma(int i){return anchuraPalmas[i];}

//metodo que devuelve el valor de la frecuencia detectada en el ultimo frame registrado
float CGestureRecognizer::getFreq(){return freq;}

//metodo que devuelve el valor del volumen detectado en el ultimo frame registrado
float CGestureRecognizer::getVolumen(){return volumen;}

//metodo que devuelve el numero de manos detectadas en el ultimo frame registrado
int CGestureRecognizer::getNumManos(){return UGKnumManos;}

//metodo que actualiza el valor de octava maxima
void CGestureRecognizer::setMaxOct(float i){maxOct=i;}

//metodo que devuelve el valor de la octava maxima
int CGestureRecognizer::getMaxOct(){return maxOct;}

//metodo que actualiza el valor del volumen maximo
void CGestureRecognizer::setMaxVol(float i){maxVol=i;}

//metodo que devuelve el valor del volumen maximo
int CGestureRecognizer::getMaxVol(){return maxVol;}

#endif

void CGestureRecognizer::onFrame(const Controller& controller) {
  // Get the most recent frame and report some basic information
  const Frame frame = controller.frame();

	#ifdef UGKLEAP_V2

		int j = 0;
		float relNota = pow(2,0.083333333);
		float mejor = 1000;
		float mejorVol = 1000;
		int nada = -1000;
		Vector vNada = Vector(nada,nada,nada);
		Matrix mNada = Matrix(vNada,vNada,vNada);

		HandList hands = frame.hands();
		UGKnumManos = hands.count();

		for(int i=0; i<UGKnumManos; i++){
	
			UGKpalma[i] = hands[i].palmPosition();
			//anchuraPalmas[i] = hands[i].palmWidth();
			UGKdireccionMano[i] = hands[i].basis();

			//calcular distancia de la palma de la mano a la antena de volumen

			float distVol=UGKpalma[i].y;

			if((UGKpalma[i].x/50)<-3 && (UGKpalma[i].x/50)>-7 && distVol<=mejorVol) mejorVol=distVol;

			for (int f = 0; f < hands[i].fingers().count(); f++) {
				Finger finger = hands[i].fingers()[f];
      
				for (int b = 0; b < 4; b++) {
					Bone bone = finger.bone(static_cast<Leap::Bone::Type>(b));
					UGKhandsGl[i*20+f*4+b]=bone.nextJoint();

					//calcular la distancia entre un punto de flexion o el centro del hueso y la antena de tonalidad

					if((UGKhandsGl[i*20+f*4+b].y/50)>2 && (UGKhandsGl[i*20+f*4+b].y/50)<6.5){
						float dist = sqrt(pow(4.125-(UGKhandsGl[i*20+f*4+b].x/50),2)+pow((-0.75)-(UGKhandsGl[i*20+f*4+b].z/50),2));
						if(dist<=mejor) mejor=dist;
					}

					Vector bonePosition = bone.center();
					if((bonePosition.y/50)>2 && (bonePosition.y/50)<6.5){
						float dist = sqrt(pow(4.125-(bonePosition.x/50),2)+pow((-0.75)-(bonePosition.z/50),2));
						if(dist<=mejor) mejor=dist;
					}

					UGKcentroHuesos[i*20+f*4+b]=bone.nextJoint();
					UGKdireccionHuesos[i*20+f*4+b]=bone.basis();
					UGKlongitudHuesos[i*20+f*4+b]=bone.length();
					UGKanchuraHuesos[i*20+f*4+b]=bone.width()/2;
				}
			}
		}

		for(int i=UGKnumManos*20;i<40;i++) UGKhandsGl[i] = vNada;
		for(int i=UGKnumManos; i<2; i++) UGKpalma[i] = vNada;
		//for(int i=numManos; i<2; i++) anchuraPalmas[i] = 0;
		for(int i=UGKnumManos; i<2; i++) UGKdireccionMano[i] = mNada;
		for(int i=UGKnumManos*20; i<40; i++) UGKdireccionHuesos[i] = mNada;
		for(int i=UGKnumManos*20; i<40; i++) UGKcentroHuesos[i] = vNada;
		for(int i=UGKnumManos*20; i<40; i++) UGKlongitudHuesos[i] = 0;
		for(int i=UGKnumManos*20; i<40; i++) UGKanchuraHuesos[i] = 0;

		if(mejor<=0.15) freq=13.75*pow(relNota,12*(maxOct+1)+3); //se supone que al tocar la antena del theremin, se produce una frecuencia de sonido muy alta
		else if(mejor<=5){
			float distancia;
			if (maxOct==1) distancia = 15;
			else if(maxOct>1 && maxOct<=3) distancia = 12*maxOct+4;
			else if(maxOct>3 && maxOct<=5) distancia = 12*maxOct+5;
			else distancia = 12*maxOct+6;
			freq=13.75*pow(relNota,(distancia)-(mejor*distancia/5));
		}
		else freq=0;

		if(mejorVol>=200 && mejorVol<=250) volumen = ((float)maxVol/100)*(((mejorVol-200)*2)/100);
		else if(mejorVol<200) volumen = 0;
		else volumen = (float)maxVol/100;

	#elif defined(UGKLEAP_V1)

	  // Get gestures
	  const GestureList gestures = frame.gestures();

	  for (int g = 0; g < gestures.count(); ++g) {
		Gesture gesture = gestures[g];

		switch (gesture.type()) {
		  case Gesture::TYPE_CIRCLE:
		  {
			CircleGesture circle = gesture;
			std::string clockwiseness;

			if (circle.pointable().direction().angleTo(circle.normal()) <= PI/4) {
			  clockwiseness = "clockwise";
			} else {
			  clockwiseness = "counterclockwise";
			}

			// Calculate angle swept since last frame
			float sweptAngle = 0;
			if (circle.state() != Gesture::STATE_START) {
			  CircleGesture previousUpdate = CircleGesture(controller.frame(1).gesture(circle.id()));
			  sweptAngle = (circle.progress() - previousUpdate.progress()) * 2 * PI;
			}

			/* Utilizamos el movimiento circular de un dedo para saber el tipo de disparo.
			Si es en el sentido de las agujas del reloj, será un disparo normal, y en el 
			sentido contrario a las agujas del reloj, se tratará de un lanzamiento de bomba*/

			if (clockwiseness == "clockwise"){ 
				//std::cout << "DISPARA" << std::endl;
				GestureTreatment(GR_QUICK_SHOOT_MOVE);
			}
			else if (clockwiseness == "counterclockwise"){ 
				//std::cout << "DISPARA BOMBA" << std::endl;
				GestureTreatment(GR_SLOW_SHOOT_MOVE);
			}

			break;
		  }
		  case Gesture::TYPE_SWIPE:
		  {
				SwipeGesture swipe = gesture;
				Leap::Vector direcciones;

				if (swipe.state() != Gesture::STATE_START) {
				
					SwipeGesture previousUpdate = SwipeGesture(controller.frame(1).gesture(gesture.id()));
					direcciones = (swipe.direction() - previousUpdate.direction());
				
				}

				/* Comprobamos la dirección del movimiento, tendremos en cuenta el gesto si su dirección
				en cualquiera de los ejes es mayor que 0.85 */

				// Comprobamos el desplazamiento horizontal
				if (std::abs(swipe.direction().x) > 0.85){ 
					if (swipe.direction().x < 0){
						std::cout << "IZQUIERDA" << std::endl;
						GestureTreatment(GR_LEFT_MOVE);
					}
					else{
						std::cout << "DERECHA" << std::endl;
						GestureTreatment(GR_RIGHT_MOVE);
					}
				}
				// Comprobamos el desplazamiento vertical
				else if (std::abs(swipe.direction().y) > 0.85){ 
					if (swipe.direction().y < 0){
						std::cout << "ABAJO" << std::endl;
						GestureTreatment(GR_BOTTOM_MOVE);
					}
					else{
						std::cout << "ARRIBA" << std::endl;
						GestureTreatment(GR_TOP_MOVE);
					}
				}
				// Comprobamos el desplazamiento en profundidad
				else if (std::abs(swipe.direction().z) > 0.85){ 
					if (swipe.direction().z < 0){
						std::cout << "ADELANTE" << std::endl;
						GestureTreatment(GR_FORWARD_MOVE);
					}
					else{
						std::cout << "ATRAS" << std::endl;
						GestureTreatment(GR_BACKWARD_MOVE);
					}
				}
		

			break;
		  }
   
		  default:
			//std::cout << "Unknown gesture type." << std::endl;
			break;
		}
	  }

	  if (!frame.hands().isEmpty() || !gestures.isEmpty()) {
		//std::cout << std::endl;
	  }
	#endif
	
	m_lastFrame = frame;

}

void CGestureRecognizer::onFocusGained(const Controller& controller) {
  m_lastFrame = controller.frame();
}

void CGestureRecognizer::onFocusLost(const Controller& controller) {
  std::cout << "Focus Lost" << std::endl;
}
