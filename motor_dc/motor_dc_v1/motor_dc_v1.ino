/* 
 *  Controlando motor dc
 */

//Pino de controle do motor
int motorPin = 3;
 
void setup() 
{ 
  // Coloca o pino 3 do Arduino como OUTPUT (saída)
  pinMode(motorPin, OUTPUT);
  // inicializa comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
  //Aguarda a saida serial 
  while (! Serial);
  //Escreve no monitor serial
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  //Serial disponível
  if (Serial.available())
  {
    //Leitura do valor do monitor serial
    int speed = Serial.parseInt();

    //Verifica o intervalo da velocidade do motor  
    if (speed >= 0 && speed <= 255)
    {
      //Escreva no pino do motor dc a velocidade
      analogWrite(motorPin, speed);
    }
  }
} 
