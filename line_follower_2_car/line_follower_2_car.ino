#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

int M1_Speed = 80; // speed of motor 1
int M2_Speed = 80; // speed of motor 2
int LeftRotationSpeed = 60;  // Left Rotation Speed
int RightRotationSpeed = 60; // Right Rotation Speed


int LEFT_SENSOR = A0;
int RIGHT_SENSOR = A1;
int Sensortable_1 = A2;
int Sensortable_2 = A3;
int Sensortable_3 = A4;
int Sensorcashbox = A5;
int table1button = 2;
int table2button = 3;
int table3button = 4;
int resetbutton = 11;
String setted_table = "0";


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);


  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(Sensortable_1, INPUT);
  pinMode(Sensortable_2, INPUT);
  pinMode(Sensortable_3, INPUT);
  pinMode(Sensorcashbox, INPUT);
  
  pinMode(table1button, INPUT_PULLUP);
  pinMode(table2button, INPUT_PULLUP);
  pinMode(table3button, INPUT_PULLUP);
  pinMode(resetbutton, INPUT_PULLUP);


  Serial.begin(9600);
}

void loop() {

  int LEFT_SENSOR_state = digitalRead(LEFT_SENSOR);
  int RIGHT_SENSOR_state = digitalRead(RIGHT_SENSOR);
  int Sensortable_1_state = digitalRead(Sensortable_1);
  int Sensortable_2_state = digitalRead(Sensortable_2);
  int Sensortable_3_state = digitalRead(Sensortable_3);
  int Sensorcashbox_state = digitalRead(Sensorcashbox);
  int table1button_state = digitalRead(table1button);
  int table2button_state = digitalRead(table2button);
  int table3button_state = digitalRead(table3button);
  int resetbutton_state = digitalRead(resetbutton);


  // basic riding:
  if (setted_table != "0"){
	  if (RIGHT_SENSOR_state == 1 && LEFT_SENSOR_state == 1 && Sensortable_1_state == 0 && Sensortable_2_state == 0 && Sensortable_3_state == 0  && Sensorcashbox_state ==0) {
	    forward(); //FORWARD
	    Serial.println("One");
	  }

	  else if (RIGHT_SENSOR_state == 0 && LEFT_SENSOR_state == 1 && Sensortable_1_state == 0 && Sensortable_2_state == 0 && Sensortable_3_state == 0  && Sensorcashbox_state ==0) {
	    left(); //Move Right
	    Serial.println("saga");
	  }

	  else if (RIGHT_SENSOR_state == 1 && LEFT_SENSOR_state == 0 && Sensortable_1_state == 0 && Sensortable_2_state == 0 && Sensortable_3_state == 0  && Sensorcashbox_state ==0) {
	    right();  //Move Left
	    Serial.println("cepe");
	  }

	  else if (RIGHT_SENSOR_state == 0 && LEFT_SENSOR_state == 0 && Sensortable_1_state == 0 && Sensortable_2_state == 0 && Sensortable_3_state == 0  && Sensorcashbox_state ==0) {
	    Stop();  //STOP
	    Serial.println("saklan");
	  }  	
  }


  if (Sensortable_1_state == 1 && setted_table == "1") {
    Stop();
  }
  else if (Sensortable_2_state == 1 && setted_table == "2") {
    Stop();
  }
  else if (Sensortable_3_state == 1 && setted_table == "3") {
    Stop();
  }
  else if (Sensorcashbox_state == 1 && setted_table == "reset") {}



  // Setting table states:
  if (table1button_state == 0) {
  	setted_table = "1";
  }
  else if (table2button_state == 0) {
  	setted_table = "2";
  }
  else if (table3button_state == 0) {
  	setted_table = "3";
  }
  else if (resetbutton_state == 0) {
  	setted_table = "reset";
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
