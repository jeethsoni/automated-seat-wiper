#include <Servo.h>

const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 5;

Servo wiper;

bool userPresent = false;
bool waitingToWipe = false;
unsigned long userLeftTime = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  wiper.attach(servoPin);
  wiper.write(68);  // start position
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse time and convert to cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If user is within 60 cm, they're detected
  if (distance > 0 && distance < 120) {
    userPresent = true;
    waitingToWipe = false;
  }

  // If user was present, but now left
  if (userPresent && distance >= 100 && !waitingToWipe) {
    userLeftTime = millis();
    waitingToWipe = true;
    Serial.println("User left. Wiping in 10 seconds...");
  }

  // After 60 seconds, wipe
  if (waitingToWipe && millis() - userLeftTime >= 10000) {
    wipeSeat();
    userPresent = false;
    waitingToWipe = false;
  }

  delay(200); // Short delay to reduce jitter
}

void wipeSeat() {
  Serial.println("WIPING...");
  wiper.write(180);  // Move to wipe
  delay(2000);
  wiper.write(70);   // Return
  delay(2000);
  wiper.write(68);   // Return

  delay(1000);
}
