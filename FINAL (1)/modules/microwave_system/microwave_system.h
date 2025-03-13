//=====[#include guards - begin]===============================================


#ifndef _MICROWAVE_SYSTEM_H_
#define _MICROWAVE_SYSTEM_H_


//=====[Declaration of public defines]=========================================


#define SYSTEM_TIME_INCREMENT_MS 10


//=====[Declaration of public data types]======================================


//=====[Declarations (prototypes) of public functions]=========================


void microwaveSystemInit();
void microwaveSystemUpdate();
void processKeypadInput(char key);
void startCooking();
void stopCooking();


//=====[#include guards - end]=================================================


#endif
