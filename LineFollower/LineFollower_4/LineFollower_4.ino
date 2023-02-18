// Standby pin is used to turn on and off the motor driver
const int STBY = 3;
// PWM Channel A and B are used to control the speed of the motors
const int PWMA = 5;
const int PWMB = 6;
// Input Channels A and B are used to control the direction of the motors
const int AIN1 = 7;
const int BIN1 = 8;

// Line Tracker Sensor Pins
const int LTleftSensor = A2;
const int LTmiddleSensor = A1;
const int LTrightSensor = A0;

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

    // Line sensor on the 4.0 is analog so no need to use pinMode

    // Start serial monitor
    Serial.begin(9600);
}

// Track and follow a dark line
void loop() {
    // Start by printing the sensor values - tune them to your environment
    int threshold = 500;
    if (analogRead(LTleftSensor) > threshold) {
        Serial.println("Left Sensor is above threshold");
    }
    // Once you have tuned the sensors, you can use the movement functions
    // to move your robot!

    // Challenge: Have your robot only track lines for 10 seconds, then stop

    // Challenge: How will your robot handle intersections?
}
