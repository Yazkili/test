#define trigPin1 10
#define echoPin1 11

long duration, distance, Sensor ;


#include <IRremote.h>
int delayTime = 10;
IRsend irsend;
#include <Stepper.h>

const int stepsPerRevolution = 22;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 7, 5, 6, 8);

void setup()
{

  Serial.begin(38400);

  myStepper.setSpeed(5);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  Sensor = distance;

  Sensor = map(Sensor, 0, 400, 1000, 1400);

    myStepper.setSpeed(1000);
    for (int j = 1; j < 23; j++) {
      myStepper.step(1);
      SonarSensor(trigPin1, echoPin1);
      delay(20);
      Serial.print(j);
      Serial.print("-");
      Serial.println(distance);
    }

    myStepper.setSpeed(200);
    for (int j = 1; j < 23; j++) {
      myStepper.step(-1);
    }

    delay(3000);
  
  if (Serial.available() > 0) {
    int inByte = Serial.read();

    switch (inByte) {

      case 'f':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5C837, 32);
          delay(delayTime);
        }
        break;

      case 'l':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5F00F, 32);
          delay(delayTime);
        }
        break;

      case 'r':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5E01F, 32);
          delay(delayTime);
        }
        break;


      case 'p':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5807F, 32);
          delay(delayTime);
        }
        break;


      case 'w':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5609F, 32);
          delay(delayTime);
        }
        break;


      case 'a':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD550AF, 32);
          delay(delayTime);
        }
        break;


      case 's':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5D02F, 32);
          delay(delayTime);
        }
        break;


      case 'h':
        for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x2AD5708F, 32);
          delay(delayTime);
        }

    }
    Serial.print(Sensor);
    delay(delayTime);

  }
}

void SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(6);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;
}




