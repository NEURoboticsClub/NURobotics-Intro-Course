// Speed control pins
const int ENA = 5;
const int ENB = 6;
// Direction control pins
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 11;

// Line Tracker Sensor Pins
const int LTleftSensor = 2;
const int LTmiddleSensor = 4;
const int LTrightSensor = 10;

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

    // Set the line tracker sensor pins as inputs
    pinMode(LTleftSensor, INPUT);
    pinMode(LTmiddleSensor, INPUT);
    pinMode(LTrightSensor, INPUT);

    // Start serial monitor
    Serial.begin(9600);
}

// Track and follow a dark line
void loop() {
    // Start by printing the sensor values - tune them to your environment
    if (digitalRead(LTleftSensor) == LOW) {
        Serial.println("Left Sensor reads LOW");
    }
    // Once you have tuned the sensors, you can use the movement functions
    // to move your robot!

    // Challenge: Have your robot only track lines for 10 seconds, then stop

    // Challenge: How will your robot handle intersections?
}