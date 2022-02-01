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
  if (inByte == 'W')
  {
    digitalWrite(lampone, HIGH);
    delay(1000);
    
  }

  else if (inByte == 'U')
  {
    digitalWrite(lampyz, HIGH);
    Serial.println("yz");
  }

  else if (inByte == 'V')
  {
    digitalWrite(ses, HIGH);
    Serial.println("juguldewik");
  }
}
