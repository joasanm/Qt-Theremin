#ifndef UGKLEAP_VERSION
#define UGKLEAP_VERSION

// Be careful, use only one API every time
// The value in the definition is used to correctly identify the definition, if you
// remove the value VS generates error c1017
//#define UGKLEAP_V1 1
#define UGKLEAP_V2 2

#ifdef UGKLEAP_V1
	#include <Leap.h>
#elif defined(UGKLEAP_V2)
	#include <Leap.h>
#endif

#endif