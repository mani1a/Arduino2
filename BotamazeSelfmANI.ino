// L298N PINS

#define ENA 11
#define IN1 10
#define IN2 9
#define IN3 8
#define IN4 7
#define ENB 6


// Sensor pins
//center sensor
#define S1Trig A0
#define S1Echo A1
// left sensor
#define S2Trig A2
#define S2Echo A3
//right sensor
#define S3Trig A4
#define S3Echo A5


// speed control
int speed_right = 120;
int speed_left = 120;

// Distance
int dis = 23;

//functions
void Stop();
void forward();
void back();
void left();
void right();

void setup() {
  Serial.begin(9600);

  //Motor one
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  //Motor two
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //output pins
  pinMode(S1Trig, OUTPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S3Trig, OUTPUT);

  //input pins
  pinMode(S1Echo, INPUT);
  pinMode(S2Echo, INPUT);
  pinMode(S3Echo, INPUT);
}

void loop() {

  if ((C_S() > dis) && (L_S() < dis) && (R_S() < dis)) {
    forward();
    Serial.println("Forward");
  } else if ((C_S() < dis) && (L_S() < dis) && (R_S() > dis)) {
    Stop();
    delay(500);
    right();
    Serial.println("RIGHT");
  } else if ((C_S() < dis) && (L_S() > dis) && (R_S() < dis)) {
    Stop();
    delay(500);
    left();
    Serial.println("LEFT");
  } else if ((C_S() > dis) && (L_S() < dis) && (R_S() > dis)) {
    Stop();
    delay(500);
    right();
    Serial.println("RIGHT");
  } else if ((C_S() > dis) && (L_S() > dis) && (R_S() < dis)) {
    Stop();
    delay(500);
    right();
    Serial.println("RIGHT");
  } else if ((C_S() < dis) && (L_S() < dis) && (R_S() < dis)) {
    Stop();
    delay(500);
    right();
    Serial.println("RIGHT");
  } else if ((C_S() < dis) && (L_S() > dis) && (R_S() > dis)) {
    Stop();
    delay(500);
    left();
    Serial.println("LEFT");
  } else {
    Serial.println(" ");
  }
}

// SENSOR Function
int C_S() {

  digitalWrite(S1Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);

  long t = pulseIn(S1Echo, HIGH);
  int cm = (t * 0.034) / 2;
  return cm;
}

int L_S() {

  digitalWrite(S2Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(S2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S2Trig, LOW);

  long t = pulseIn(S2Echo, HIGH);
  int cm = (t * 0.034) / 2;
  return cm;
}

int R_S() {

  digitalWrite(S3Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(S3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S3Trig, LOW);

  long t = pulseIn(S3Echo, HIGH);
  int cm = (t * 0.034) / 2;
  return cm;
}


// Motion Functions
void forward() {
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}

void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void left() {
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
