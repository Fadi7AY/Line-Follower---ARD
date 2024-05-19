// Pin definitions
#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

#define S5 A0
#define S4 A1
#define S3 A2
#define S2 A3
#define S1 A4

// Motor control
void setMotors(int leftSpeed, int rightSpeed) {
  if (leftSpeed > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (leftSpeed < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    leftSpeed = -leftSpeed;
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  if (rightSpeed > 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (rightSpeed < 0) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    rightSpeed = -rightSpeed;
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  analogWrite(ENA, leftSpeed);
  analogWrite(ENB, rightSpeed);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(S5, INPUT);
  pinMode(S4, INPUT);
  pinMode(S3, INPUT);
  pinMode(S2, INPUT);
  pinMode(S1, INPUT);

  Serial.begin(9600); // Optional: for debugging
}

void loop() {
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);
  
  // Default motor speed values
  int leftSpeed = 0;
  int rightSpeed = 0;

  // Check sensor values and determine motor speeds
   if (s1 == HIGH && s2 == HIGH && s3 == HIGH && s4 == HIGH && s5 == HIGH) {
    // All sensors detect the line, stop the robot
    leftSpeed = 0;
    rightSpeed = 0;
  } 
    else if (s3 == HIGH && s2 == LOW && s4 == LOW) {
    // Only middle sensor detects the line
    leftSpeed = 150;
    rightSpeed = 150;
  }
   else if (s1 == HIGH) {
    // Far left sensor detects the line
    leftSpeed = -150;
    rightSpeed = 150;
  } 
   else if (s2 == HIGH) {
    // Left middle sensor detects the line
    leftSpeed = -100;
    rightSpeed = 100;
  }
    else if (s4 == HIGH) {
    // Right middle sensor detects the line
    leftSpeed = 100;
    rightSpeed = -100;
  } 
    else if (s5 == HIGH) {
    // Far right sensor detects the line
    leftSpeed = 150;
    rightSpeed = -150;
  } 
    else {
    // No sensors detect the line, stop the motors
    leftSpeed = 0;
    rightSpeed = 0;
  }

  
  setMotors(leftSpeed, rightSpeed);
  delay(10);
}
