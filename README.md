# FinalProject

Team Members: Hoang Tran and Kaito Nguyen
<br/>

### Description
This project simulates the functionality of a microwave oven using an LCD display, a matrix keypad, a motor, a buzzer, and LED indicators. The microwave operates based on user input, allowing the user to set cooking time via the keypad.

The system includes the following features:

- Keypad Input: Users can enter cooking time using the keypad.
- Motor Simulation: Represents the microwave’s rotating plate, which spins during operation.
- LCD Display: Displays the entered time, cooking progress, and completion message.
- LED Indicator: Turns on when the microwave is active and blinks upon completion.
- Buzzer Notification: Sounds 2 seconds after cooking is completed.
- System Reset: After completion, the system resets to allow another cooking session.

#### Microwave System Functionality
1. User Input (Keypad Interaction)
- The user inputs cooking time using the keypad.
- Pressing # starts cooking, activating the motor and LED.
2. Cooking Process
- The count-up is displayed on the LCD screen.
- The motor rotates to simulate the microwave’s rotating plate.
3. Completion Phase
- When the time reaches goal time:
- The motor stops.
- The LCD displays "Done!".
- The buzzer sounds 2 seconds.
- The LED blinks six times before turning off.
- The system resets, allowing another cooking session.
- 
## Testing results
- Microwave Cooking Functionality

| Specification | Test Result | Comment |
|----------|----------|----------|
| User can enter cooking time via the keypad. | Pass | Numeric keys input time correctly.|
| Pressing # starts cooking. | Pass | Cooking begins, motor starts, and LED turns on.|
| Display updates with cooking time count-up. | Pass | Time increases correctly on the LCD.|
| Cooking stops when time reaches zero. | Pass | Motor stops, LED blinks, and buzzer sounds.|
| Buzzer sounds after completion. | Pass | Beeps 2 seconds|
| LED blinks six times after cooking. | Pass | LED blinks as expected before turning off.|
| System resets after completion. | Pass | Ready for next user input.|


<br/>

- Display and Interaction

| Specification | Test Result | Comment |
|----------|----------|----------|
| LCD displays "Welcome" when powered on. | Pass | Initial message appears correctly.|
| LCD updates correctly with entered cooking time. | Pass | User input reflects on display.|
| LCD shows "Cooking..." during operation. | Pass | Feedback provided during cooking.|
| LCD shows "Done!" when cooking completes. | Pass | Confirms completion to the user.|
