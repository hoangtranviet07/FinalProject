//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "microwave_system.h"
#include "buzzer.h"
#include "led_control.h"
#include "matrix_keypad.h"
#include "motor_control.h"
#include "display.h"

//=====[Declaration of private defines]========================================

#define ledBlinkTime 500          // LED blink interval (milliseconds)
#define sirenTime 2000            // Buzzer duration (milliseconds)
#define SYSTEM_TIME_INCREMENT_MS 10  // System time step for periodic updates

//=====[Declaration and initialization of private global variables]============

static bool isCooking = false;       // Tracks if cooking is active
static bool cookingDone = false;     // Tracks if cooking is completed
static bool buzzerTurn = false;      // Tracks if the buzzer should sound
static bool doorOpen = true;         // Tracks if the door is open
static int enteredTime = 0;          // Stores user-entered cooking time
static int cookingCount = 0;         // Tracks elapsed cooking time
static char keycheck;                // Stores last pressed key to avoid repetition
static bool welcomeCheck = false;    // Ensures "Welcome" message is displayed only once
static int accumulatedTime = 0;      // Tracks time for LED blinking
static int accumulatedSirenTime = 0; // Tracks time for buzzer duration
static int blinkCount = 0;           // Tracks LED blink cycles

//=====[Implementations of public functions]===================================

/**
 * @brief Initializes the microwave system components.
 */
void microwaveSystemInit() {
    matrixKeypadInit(50);  // Initialize keypad with a 50ms scan interval
    displayInit();         // Initialize the display
    ledInit();             // Initialize LED control
    motorInit();           // Initialize motor control
    buzzerInit();          // Initialize the buzzer
}

/**
 * @brief Updates the microwave system state.
 */
void microwaveSystemUpdate() {
    // Read keypad input
    char key = matrixKeypadUpdate();
    if (key != '\0') {
        processKeypadInput(key);
    }

    // Cooking countdown
    if (isCooking) {
        cookingCount += SYSTEM_TIME_INCREMENT_MS;

        // Display remaining time
        char buffers[30];
        sprintf(buffers, "Start cooking: %d", cookingCount / 200);
        displayCharPositionWrite(0, 0);
        displayStringWrite(buffers);

        // Stop cooking when the countdown reaches zero
        if (cookingCount >= enteredTime * 200) {
            stopCooking();
        }
    }

    // Handle post-cooking events (buzzer and LED blinking)
    if (cookingDone) {
        static bool checkBuzzer = false; // Ensures the buzzer only stops once
        static bool checkLed = false;    // Ensures LED blinking stops after 6 cycles
        static bool systemReset = true;  // Flag to reset the system after cooking

        accumulatedTime += SYSTEM_TIME_INCREMENT_MS;
        accumulatedSirenTime += SYSTEM_TIME_INCREMENT_MS;

        // Turn on the buzzer once
        if (buzzerTurn) {
            buzzerOn();
            buzzerTurn = false;
        }

        // Stop the buzzer after the specified duration
        if (accumulatedSirenTime >= sirenTime) {
            buzzerOff();
            checkBuzzer = true;
        }

        // Blink the LED 6 times
        if (accumulatedTime >= ledBlinkTime && blinkCount < 6) {
            if (blinkCount % 2 != 0) {
                ledOff();
            } else {
                ledOn();
            }
            accumulatedTime = 0;
            blinkCount++;
        }

        if (blinkCount >= 6) checkLed = true;

        // Reset the system after completing buzzer and LED effects
        if (checkBuzzer && checkLed && systemReset) {
            microwaveSystemInit();
            isCooking = false;
            cookingDone = false;
            buzzerTurn = false;
            doorOpen = true;
            enteredTime = 0;
            cookingCount = 0;
            keycheck = '\0';
            welcomeCheck = false;
            accumulatedTime = 0;
            accumulatedSirenTime = 0;
            blinkCount = 0;
            checkBuzzer = false;
            checkLed = false;
            systemReset = true;
        }
    }
    delay(SYSTEM_TIME_INCREMENT_MS);
}

/**
 * @brief Processes user input from the keypad.
 */
void processKeypadInput(char key) {
    // Display "Welcome" message when '*' is pressed
    if (key == '*' && !welcomeCheck) {
        displayCharPositionWrite(0, 0);
        displayStringWrite("Welcome");
        welcomeCheck = true;
    }

    // Reset key tracking
    if (key == '\0') keycheck = '\0';

    // Reset entered cooking time when 'D' is pressed
    if (key == 'D') {
        enteredTime = 0;
        char buffer[35];
        sprintf(buffer, "Time: %d seconds", enteredTime);
        displayCharPositionWrite(0, 0);
        displayStringWrite(buffer);
    }

    // Handle numeric input for cooking time
    if (key >= '0' && key <= '9') {
        if (key != keycheck) {
            enteredTime = (enteredTime * 10) + (key - '0'); // Convert char to int
            keycheck = key;
            char buffer[35];
            sprintf(buffer, "Time: %d seconds", enteredTime);
            displayCharPositionWrite(0, 0);
            displayStringWrite(buffer);
        }
    } 
    // Start cooking when '#' is pressed
    else if (key == '#') {
        if (enteredTime > 0) {
            char buffer[35];
            sprintf(buffer, "Start cooking time: %d seconds", enteredTime);
            displayCharPositionWrite(0, 0);
            displayStringWrite(buffer);
            startCooking();
        }
    }
}

/**
 * @brief Starts the cooking process.
 */
void startCooking() {
    isCooking = true;
    ledOn();
    motorStart();
    displayCharPositionWrite(0, 0);
    displayStringWrite("Cooking...");
}

/**
 * @brief Stops the cooking process and triggers the completion sequence.
 */
void stopCooking() {
    isCooking = false;
    motorStop();
    displayInit();
    displayCharPositionWrite(0, 0);
    displayStringWrite("Done!");
    cookingDone = true;
    buzzerTurn = true;
}
