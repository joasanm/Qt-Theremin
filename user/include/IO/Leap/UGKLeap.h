/**	
*	Prefix: 
*	@Author: Juan Cerr�n, C�dric Marco
*	@version: 2013-14
**/

#ifndef USELEAP_H
#define USELEAP_H

#include <UGKLeapGestureTreatment.h>

namespace UGK
{
	class UGK_API  UseLeap{

	  public:
		int leapInit();
		int leapExit();
		CGestureTreatment detectorMovimientos;

	private:
		Leap::Controller controller;
		//CGestureTreatment detectorMovimientos;
	};
}
#endif