#include <Stepper.h>

const int passosPorRevolucao = 512; 

// Com inversão    
int in1Pin = 12;
int in2Pin = 10;
int in3Pin = 11;
int in4Pin = 9;

// Sem inversão
//int in1Pin = 12;
//int in2Pin = 11;
//int in3Pin = 10;
//int in4Pin = 9;
 
Stepper motor(passosPorRevolucao, in1Pin, in2Pin, in3Pin, in4Pin);  
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  Serial.begin(9600);
  motor.setSpeed(20);
}
 
void loop(){
  if (Serial.available()) {
    //Abrir o monitor serial (Ctrl+Shift+M)para a entrada de dados
    int passos = Serial.parseInt();
    
    motor.step(passos);
  }
}
