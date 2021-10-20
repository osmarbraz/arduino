/*
 * Gira o servo motor de 0 a 180 graus.
 * 
 */

#include <Servo.h>

int i = 0;

Servo servo_11;


void setup()
{
  //Porta 11 em modo de saída(escrita).
  servo_11.attach(11, 500, 2500);
}

void loop()
{
  //Gera os ângulos de 0 a 180 para girar o servo motor.
  for (i = 0; i <= 180; i += 1) {
  // Escreve o }angulo  
    servo_11.write(i);
	// Aguarda 30 milésimos de segundo
    delay(30); 
  }
  // Aguardamos 2000 milésimos de segundo
  delay(2000); 
}