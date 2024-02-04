//Servo goes from 0-180

#include<Servo.h>
#include <Keypad.h>


//Declaration
const int servo_pin = 13;

char dugmici[4][4]={
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

Servo servo;

byte pinovi_vrsta[4] = {4,5,6,7};
byte pinovi_kolona[4] = {8,9,10,11};
int ugao = 0;
bool ok = false;
char taster;
int broj =0;

Keypad key = Keypad(makeKeymap(dugmici),pinovi_vrsta,pinovi_kolona,4,4);

//Setup
void setup() {
  pinMode(servo_pin, OUTPUT);
  Serial.begin(9600);
  servo.attach(servo_pin);
  servo.write(ugao);
}

//Pressed button
void Pritisnut_Taster(){
  if (taster == 'C') {
    broj =0;
    ugao =0;
    return Serial.println("Cancel ");
  }

  if (taster == '1') {
    broj = 1;
    ugao = ugao *10 + broj;
  } if (taster == '2') {
    broj = 2;
    ugao = ugao *10 + broj;
  }  if (taster == '3') {
    broj = 3;
    ugao = ugao *10 + broj;
  } if (taster == '4') {
    broj = 4;
    ugao = ugao *10 + broj;
  }  if (taster == '5') {
    broj = 5;
    ugao = ugao *10 + broj;
  } if (taster == '6') {
    broj = 6;
    ugao = ugao *10 + broj;
  } if (taster == '7') {
    broj = 7;
    ugao = ugao *10 + broj;
  } if (taster == '8') {
    broj = 8;
    ugao = ugao *10 + broj;
  }  if (taster == '9') {
    broj = 9;
    ugao = ugao *10 + broj;
  }  if (taster == '#') {
    Serial.println("Moving");
    broj = 0;
    servo.write(ugao);
    delay(2000);
    servo.write(0);
    ugao = 0;
  } 
  Serial.println(ugao);
}

//Main loop
void loop() {
  taster = key.getKey();
  if (taster!=NO_KEY) {
    Serial.println("Type");
    Pritisnut_Taster();
  } 
}
