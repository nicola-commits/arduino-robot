#include <Servo.h>
#define servo_pin 4
#define trigPin 5
#define echoPin 7

Servo myservo;  //servo object

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servo_pin);
}

void go_right(){}

void go_left(){}

int get_distance() {
  int distance;
  long duration; // variable for the duration of sound wave travel
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance;
}

void loop() {
   if(get_distance() < 20){
    int rightd;
    int leftd;
    myservo.write(180);
    delay(500);
    leftd = get_distance();
    myservo.write(0);
    delay(500);
    rightd = get_distance();
    Serial.println("--------------------------------------");
    Serial.println("right distance");
    Serial.println(rightd);
    Serial.println("left distance");
    Serial.println(leftd);
    if(max(rightd, leftd) == leftd){
      Serial.println("Go left!");
      go_left();
    }
    else{
      Serial.println("Go right!");
      go_left();
    }
    myservo.write(90);
    delay(500);
  }
}
