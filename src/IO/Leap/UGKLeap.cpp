/**	
*	Prefix: 
*	@Author: Juan Cerrón, Cédric Marco
*	@version: 2013-14
**/

#include <UGKLeap.h>

using namespace UGK;

	/**
	 * It initializes the controller used by the Leap motion device in
	 * case it is connected. 
	 * -1 is returned with no device detected.
	 */
int UseLeap::leapInit() {
	// Have the sample listener receive events from the controller
	
	// Check if there is atleast one leap motion device connected

	// IT DOESN'T WORK BECAUSE OF THE LEAP API FUNCTIONS 
	/*DeviceList device = controller.devices();

	if (device.isEmpty())
		return -1;
	else{
		controller.addListener(detectorMovimientos);
		return 1;
	}*/

	controller.addListener(detectorMovimientos);
	return 1;
}

int UseLeap::leapExit() {
	// Remove the sample listener when done
	controller.removeListener(detectorMovimientos);
	//std::cout << "Exited" << std::endl;
	return 1;
}

