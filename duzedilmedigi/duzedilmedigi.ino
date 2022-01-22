#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

 int M1_Speed = 60; // speed of motor 1
 int M2_Speed = 60; // speed of motor 2
 int LeftRotationSpeed = 60;  // Left Rotation Speed
 int RightRotationSpeed = 60; // Right Rotation Speed

 void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

      pinMode(A0, INPUT); // initialize Left sensor as an input
      pinMode(A1, INPUT); // initialize Right sensor as an input
      Serial.begin(9600);
}

void loop() {

  int LEFT_SENSOR = digitalRead(A0);
  int  RIGHT_SENSOR = digitalRead(A1);
  int Sensortable_1 = digitalRead(A2);
  int Sensortable_2 = digitalRead(A3);
  int Sensortable_3 = digitalRead(A4);
  
if(RIGHT_SENSOR==1 && LEFT_SENSOR==1 && Sensortable_1==0 && Sensortable_2==0 && Sensortable_3==0 ) {
    forward(); //FORWARD
    Serial.println("One");
}

  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1 && Sensortable_1==0 && Sensortable_2==0 && Sensortable_3==0) {
    left(); //Move Right
    Serial.println("saga");
 }

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0 && Sensortable_1==0 && Sensortable_2==0 && Sensortable_3==0) {
   right();  //Move Left
    Serial.println("cepe");
}

  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==0 && Sensortable_1==0 && Sensortable_2==0 && Sensortable_3==0) {
    Stop();  //STOP
    Serial.println("saklan");
 }
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1 && Sensortable_1==1 && Sensortable_2==0 && Sensortable_3==0) {
    Stop();  //STOP
    Serial.println("Stol_birde_saklandy");
 }
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1 && Sensortable_1==0 && Sensortable_2==1 && Sensortable_3==0) {
    Stop();  //STOP
    Serial.println("Stol_ikide_saklandy");
 }
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1 && Sensortable_1==0 && Sensortable_2==0 && Sensortable_3==1) {
    Stop();  //STOP
    Serial.println("Stol_ucde_saklandy");
 }
}



void forward()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

               analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void backward()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void right()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void left()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}
