#include <Servo.h> //servo library

Servo myservo; // create servo object to control servo

// Standby pin is used to turn on and off the motor driver
const int STBY = 3;
// PWM Channel A and B are used to control the speed of the motors
const int PWMA = 5;
const int PWMB = 6;
// Input Channels A and B are used to control the direction of the motors
const int AIN1 = 7;
const int BIN1 = 8;

// Ultrasonic Sensor Pins
const int Echo = 12;
const int Trig = 13;

// Servo pin
const int servoPin = 10;

/**
 * @brief Get the distance (cm) by the ultrasonic sensor
 * 
 * @return int The distance sensed by the ultrasonic sensor
 */
int getDistance() {
    // trigger an ultrasonic wave for 20 microseconds
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig, LOW);
    // calculation converting time until signal returned to distance
    float Fdistance = pulseIn(Echo, HIGH);
    Fdistance = Fdistance / 58;
    // returns an integer as the distance (in cm) sensed
    return (int)Fdistance;
}

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

    // Set the ultrasonic sensor pins
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);

    // Set the servo pin
    myservo.attach(servoPin);

    // Start serial monitor
    Serial.begin(9600);
}

// Track and follow a dark line
void loop() {
    myservo.write(90); // Set the servo to 90 (the middle position)
    delay(500); // Wait a little for the servo to reach the position

    int distance = getDistance(); // Get the distance from the ultrasonic sensor
    Serial.print("Distance: ");
    Serial.println(distance);

    delay(20);
    // Once you know a good obstacle-detecting distance,
    // you can use the movement functions to move your robot accordingly!

    // Challenge: Have your robot move forward until it detects an obstacle, then turn left or right.

    // Challenge: Have your robot move forward until it detects an obstacle, then turn left or right
    // but turn in the direction that has the most space!
}
