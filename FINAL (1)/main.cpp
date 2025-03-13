//=====[Libraries]=============================================================


#include "microwave_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    microwaveSystemInit();
    while (true) {
        microwaveSystemUpdate();
    }
}