//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "motor_control.h"

//=====[Declaration of private defines]========================================

#define DUTY 0.065         // Duty cycle for motor operation (6.5%)
#define servoPeriod 0.02   // Servo period set to 20ms (50Hz for typical servos)

//=====[Declaration of private data types]=====================================
// No private data types needed for this module

//=====[Declaration and initialization of public global objects]===============

// Motor control using PWM output on pin PB_6
static PwmOut motor(PB_6);

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
 * @brief Initializes the motor.
 * 
 * This function is currently empty because no special initialization is needed.
 */
void motorInit() {
    // No initialization needed for now
}

/**
 * @brief Starts the motor by setting the PWM period and duty cycle.
 * 
 * The motor is controlled via PWM:
 * - The period is set to `servoPeriod` (20ms for a typical servo motor).
 * - The duty cycle is set to `DUTY` (6.5%) to drive the motor.
 * - Set motor to full speed
 */
void motorStart() {
    motor.period(servoPeriod); // Set PWM period
    motor.write(DUTY);         // Set PWM duty cycle
}

/**
 * @brief Stops the motor by setting the duty cycle to zero.
 */
void motorStop() {
    motor.write(0); // Set PWM duty cycle to 0% to stop the motor
}

//=====[Implementations of private functions]==================================
// No private functions implemented
