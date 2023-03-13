#include <Servo.h>  //servo library

Servo myservo;      // create servo object to control servo

// Speed control pins
const int ENA = 5;
const int ENB = 6;
// Direction control pins
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 11;

// Ultrasonic Sensor Pins
const int Echo = A4;
const int Trig = A5;

// Servo pin
const int servoPin = 3;

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
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
}

/**
 * @brief Moves the robot backwards with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void back(int carSpeed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
}

/**
 * @brief Turns the robot left with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void turnLeft(int carSpeed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
}

/**
 * @brief Turns the robot right with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void turnRight(int carSpeed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
}

/**
 * @brief Stops the robot's drive motors.
 *
 */
void stop() {
    digitalWrite(ENA, 0);
    digitalWrite(ENB, 0);
}

void setup() {
    // Set the motor control pins as outputs
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Set the ultrasonic sensor pins
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);

    // Set the servo pin
    myservo.attach(servoPin);

    // Start serial monitor
    Serial.begin(9600);
}

// Avoid running into walls
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