//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "led_control.h"

//=====[Declaration of private defines]========================================
// No private defines needed for this module

//=====[Declaration of private data types]=====================================
// No private data types needed for this module

//=====[Declaration and initialization of public global objects]===============

// Digital output for the LED, connected to pin D15
DigitalOut led(D15);

//=====[Declaration of external public global variables]=======================
// No external public global variables declared

//=====[Declaration and initialization of public global variables]=============
// No public global variables declared

//=====[Declaration and initialization of private global variables]============
// No private global variables declared

//=====[Declarations (prototypes) of private functions]========================
// No private function prototypes declared

//=====[Implementations of public functions]===================================

/**
 * @brief Initializes the LED by setting it to the default state (OFF).
 */
void ledInit() {
    led = 1; // 1 means OFF
}

/**
 * @brief Turns the LED ON.
 */
void ledOn() {
    led = 0; // 0 means ON
}

/**
 * @brief Turns the LED OFF.
 */
void ledOff() {
    led = 1; // 1 means OFF
}

//=====[Implementations of private functions]==================================
// No private functions implemented
