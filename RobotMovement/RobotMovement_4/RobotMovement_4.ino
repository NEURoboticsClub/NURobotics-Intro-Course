// Standby pin is used to turn on and off the motor driver
const int STBY = 3;
// PWM Channel A and B are used to control the speed of the motors
// PWMA is for the left side
// PWMB is for the right side
const int PWMA = 5;
const int PWMB = 6;
// Input Channels A and B are used to control the direction of the motors
// AIN1 is for the left side
// BIN1 is for the right side
const int AIN1 = 7;
const int BIN1 = 8;

// Left motor truth table
// Here are some handy tables to show the various modes of operation.
// STBY         AIN1            Description
// LOW      Not Applicable      Motor is off
// HIGH         LOW             Motor is on and turning backwards
// HIGH         HIGH            Motor is on and turning forwards

// Right motor truth table
// Here are some handy tables to show the various modes of operation.
// STBY         BIN1            Description
// LOW      Not Applicable      Motor is off
// HIGH         LOW             Motor is on and turning backwards
// HIGH         HIGH            Motor is on and turning forwards

/**
 * @brief Moves the robot forward with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void forward(int carSpeed) {
    // Enable the motor driver
    digitalWrite(STBY, HIGH);
    // Set the direction of the motors
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);

    // Write speed to 'A' and 'B' MotorGroups
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Moves the robot backwards with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void back(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Turns the robot left with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void turnLeft(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, LOW);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Turns the robot right with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void turnRight(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, HIGH);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Moves the robot in a swing turn to the left. A swing turn is when only one side of the robot's drivebase is powered.
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void swingTurnLeft(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);
    analogWrite(PWMA, 0.25 * carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Moves the robot in a swing turn to the right. A swing turn is when only one side of the robot's drivebase is powered.
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void swingTurnRight(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, 0.25 * carSpeed);
}

/**
 * @brief Stops the robot's drive motors.
 */
void stop() {
    digitalWrite(STBY, LOW);
}

void setup() {
    // Configure all of these pins as outputs
    pinMode(STBY, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(BIN1, OUTPUT);
}

void loop() {
    // put your code here!

    // here, we're moving the bot forward at speed 250...
    forward(250);
    // and continuing to move for 2 seconds
    delay(2000);
    // stopping the bot...
    stop();
    // wait for 5 seconds before running again
    delay(5000);
    // try writing code to move the bot in a square and stop!
    // make it go fast on two sides and slow on the other two
    // and challenge yourselves to make it a square and not a weirdly shaped rectangle!

    delay(20);
}
