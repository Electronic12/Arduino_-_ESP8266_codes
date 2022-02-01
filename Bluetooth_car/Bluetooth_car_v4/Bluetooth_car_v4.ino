#include <SoftwareSerial.h>
SoftwareSerial portOne(11, 12);
char inByte = 0;

int motor1 = 5;
int motor2 = 6;
int motor3 = 9;
int motor4 = 10;
int lampone = 3;
int lampyz = 4;
int ses = 7;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  portOne.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(lampone, OUTPUT);
  pinMode(lampyz, OUTPUT);
  pinMode(ses, OUTPUT);
 
 }

void loop() {
  portOne.listen();
  while (portOne.available() > 0) {
    inByte = portOne.read();
    Serial.write(inByte);
  }
  Serial.println();
  if (inByte == 'R')
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    Serial.write("saga");
  }
  else if (inByte == 'L')
  {

    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    Serial.write("cepe");
  }

  else if (inByte == 'F')
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    Serial.write("one");

  }

  else if (inByte == 'B')
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    Serial.write("yza");

  }
  else if (inByte == 'W')
  {
    digitalWrite(lampone, LOW);
    Serial.write("lamp");
  }
  
  else if (inByte== 'U')
  {
    digitalWrite(lampyz, LOW);
    Serial.write("yz");
  }
  
  else if (inByte== 'V')
  {
    digitalWrite(ses, LOW);
    Serial.write("juguldewik");
  }

  else if (inByte == 'S')
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    Serial.write("dur");
  }
  
  
}
