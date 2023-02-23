#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
#define LEFT_MOTOR_PIN  5
#define RIGHT_MOTOR_PIN 6
#define MAX_SPEED 255
#define MIN_SPEED 100
#define TURN_SPEED 150

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);
}

void loop() {
  delay(50);
  int distance = sonar.ping_cm();
  if (distance <= 15) {
    digitalWrite(LEFT_MOTOR_PIN, LOW);
    digitalWrite(RIGHT_MOTOR_PIN, LOW);
    delay(500);
    digitalWrite(LEFT_MOTOR_PIN, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN, LOW);
    delay(500);
  } else if (distance <= 25) {
    analogWrite(LEFT_MOTOR_PIN, TURN_SPEED);
    analogWrite(RIGHT_MOTOR_PIN, MAX_SPEED);
  } else if (distance <= 35) {
    analogWrite(LEFT_MOTOR_PIN, MAX_SPEED);
    analogWrite(RIGHT_MOTOR_PIN, TURN_SPEED);
  } else {
    analogWrite(LEFT_MOTOR_PIN, MAX_SPEED);
    analogWrite(RIGHT_MOTOR_PIN, MAX_SPEED);
  }
}
