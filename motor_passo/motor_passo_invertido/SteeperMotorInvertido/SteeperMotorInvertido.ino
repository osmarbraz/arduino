#include <Stepper.h>

const int passosPorRevolucao = 500; 
    
int in1Pin = 12;
int in2Pin = 10;
int in3Pin = 11;
int in4Pin = 9;
 
Stepper motor(passosPorRevolucao, in1Pin, in2Pin, in3Pin, in4Pin);  
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  Serial.begin(9600);
  motor.setSpeed(60);
}
 
void loop() {
 //Gira o motor no sentido horario a 90 graus
 for (int i = 0; i<=3; i++) {
    motor.step(-512); 
    motor.setSpeed(50);
    //delay(2000);
 }
  
 //Gira o motor no sentido anti-horario a 120 graus
 for (int i = 0; i<=2; i++) {
     motor.step(682); 
     //delay(2000);
 }
 
 //Gira o motor no sentido horario, aumentando a
 //velocidade gradativamente
 //for (int i = 10; i<=60; i=i+10) {
//     motor.setSpeed(i);
//     motor.step(40*i);
// }
 //delay(2000); 
}
