#include "mbed.h"
#include "arm_book_lib.h"
#include "buzzer.h"

//=====[Declaration of private defines]========================================
// No private defines needed for this module

//=====[Declaration of private data types]=====================================
// No private data types needed for this module

//=====[Declaration and initialization of public global objects]===============

// Define the buzzer as a bidirectional digital pin (input/output)
DigitalInOut buzzer(PE_10);

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
 * @brief Initializes the buzzer by setting it as an OpenDrain input.
 * This prevents the buzzer from activating unintentionally at startup.
 */
void buzzerInit() {
    buzzer.mode(OpenDrain); // Set the buzzer pin to OpenDrain mode
    buzzer.input();         // Set buzzer as an input (initially off)
}

/**
 * @brief Turns on the buzzer by setting it to output mode and pulling it LOW.
 * The buzzer operates in OpenDrain mode, so setting it LOW activates it.
 */
void buzzerOn() {
    buzzer.output(); // Set buzzer as an output
    buzzer = LOW;    // Activate the buzzer (LOW turns it on)
}

/**
 * @brief Turns off the buzzer by setting it to output mode and pulling it HIGH.
 * This stops the buzzer from sounding.
 */
void buzzerOff() {
    buzzer.output(); // Set buzzer as an output
    buzzer = HIGH;   // Deactivate the buzzer (HIGH turns it off)
}

//=====[Implementations of private functions]==================================
// No private functions implemented
