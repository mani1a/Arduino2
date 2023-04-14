#define ENA 11
#define IN1 10     
#define IN2 9  
#define IN3 8
#define IN4 7
#define ENB 6

#define S1Trig A0 // centerSensor
#define S1Echo A3

#define S2Trig A1 // rightSensor
#define S2Echo A4

#define S3Trig A2 // leftSensor
#define S3Echo A5

int distance_arr[3] = {0,0,0};
int centerSensor();
int rightSensor();
int leftSensor();

int speed_left  = 60;     // changing the values will change the speed of the motors
int speed_right = 60;

void Stop();
void forward();
void back();
void left();
void right();

void setup() {
  
  //Motor one
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Motor two
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(S1Trig, OUTPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S3Trig, OUTPUT);
  
  pinMode(S1Echo, INPUT);
  pinMode(S2Echo, INPUT);
  pinMode(S3Echo, INPUT);

}

void loop() {

  int cen_dis[0] = centerSensor();
  int rig_dis[1] = rightSensor();
  int lef_dis[2] = leftSensor();
  int distance_arr[3] = {};

  Serial.print("Distance :");
  Serial.println(distance_arr[3]);
  if (centerSensor >= 10) {   
    forward();
    }
    else if(centerSensor <10 ){
      left();
    }
    else{
      forward();
    }

  }


  int centerSensor() {
  
  digitalWrite(S1Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);

  long t = pulseIn(S1Echo, HIGH);
  int center_dis = (t*0.034)/2; 
  return center_dis; 
}

int rightSensor() {
  
  digitalWrite(S2Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S2Trig, LOW);

  long t = pulseIn(S2Echo, HIGH);
  int right_dis = (t*0.034)/2; 
  return right_dis; 
}

int leftSensor() {
  
  digitalWrite(S3Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S3Trig, LOW);

  long t = pulseIn(S3Echo, HIGH);
  int left_dis = (t*0.034)/2; 
  return left_dis; 
}

 void forward() {
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back(){
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
void left(){
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void right(){
  analogWrite(ENA, speed_right);
  analogWrite(ENB, speed_left);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
} 