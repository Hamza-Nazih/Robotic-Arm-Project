#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

// Pin Definitions for Water Level LEDs
#define GREEN_LED 4
#define YELLOW_LED 6
#define RED_LED 7
#define BUZZER 10

// HC-06 Bluetooth Module (SoftwareSerial)
SoftwareSerial BTSerial(2, 3);  // RX, TX for HC-06

// Ultrasonic sensor pins
#define TRIGGER_PIN 8
#define ECHO_PIN 9

// IR Sensor and Proximity Sensor
#define IR_SENSOR_PIN A0  // Example, adjust if needed
#define PROXIMITY_SENSOR_PIN 2  // Digital input for proximity

// Water Sensor
#define WATER_SENSOR_PIN A1  // Example analog pin for water sensor

// PCA9685 Servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  // Initialize the PCA9685 servo driver

// Ultrasonic sensor variables
long duration;
int distance;

// Water level detection variables
int waterLevel;

void setup() {
  // Start Serial communication for debugging
  Serial.begin(9600);
  BTSerial.begin(9600); // Start Bluetooth communication
  
  // Pin modes
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PROXIMITY_SENSOR_PIN, INPUT);
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize the PCA9685 servo driver
  pwm.begin();
  pwm.setPWMFreq(60);  // Set PWM frequency for servos (60Hz is common for servos)

  // Initialization complete
  Serial.println("System Initialized");
}

void loop() {
  // Check for proximity sensor
  if (digitalRead(PROXIMITY_SENSOR_PIN) == HIGH) {
    // Obstacle detected, stop the robot and sound the buzzer
    stopRobot();
    digitalWrite(BUZZER, HIGH); // Turn on buzzer
    delay(1000);  // Buzzer sound duration
    digitalWrite(BUZZER, LOW); // Turn off buzzer
  }

  // Read the water level and adjust LEDs
  waterLevel = analogRead(WATER_SENSOR_PIN);
  if (waterLevel < 300) {
    // Low water level, turn on green LED
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
  else if (waterLevel < 700) {
    // Moderate water level, turn on yellow LED
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  else {
    // High water level, turn on red LED and stop robot
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    stopRobot(); // Stop robot due to water risk
  }

  // Measure the distance with the ultrasonic sensor
  distance = measureDistance();
  if (distance < 20) {
    // Object detected too close, stop the robot and sound the buzzer
    stopRobot();
    digitalWrite(BUZZER, HIGH);
    delay(1000); // Buzzer sound duration
    digitalWrite(BUZZER, LOW);
  }

  // Handle Bluetooth Commands (optional: controlling via phone)
  if (BTSerial.available()) {
    char command = BTSerial.read();
    if (command == 'S') {
      // Start sorting operation
      startSorting();
    }
  }

  // Add additional code for controlling servos and performing sorting actions
  // Example: Sorting based on color detection logic with IR sensor
}

void stopRobot() {
  // Stop all servo motors by setting the PWM to 0
  pwm.setPWM(0, 0, 4096);  // Servo 1 to neutral
  pwm.setPWM(1, 0, 4096);  // Servo 2 to neutral
  pwm.setPWM(2, 0, 4096);  // Servo 3 to neutral
  pwm.setPWM(3, 0, 4096);  // Servo 4 to neutral
}

void startSorting() {
  pwm.setPWM(0, 0, 2048);  // Rotate servo 1 to position 1
  delay(1000);  // Wait for servo to move
  pwm.setPWM(0, 0, 4096);  // Return servo 1 to neutral position

  pwm.setPWM(1, 0, 2048);  // Rotate servo 2 to position 1
  delay(1000);
  pwm.setPWM(1, 0, 4096);  // Return servo 2 to neutral position
}

long measureDistance() {
  // Function to measure distance using the ultrasonic sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;  // Distance in cm
}
