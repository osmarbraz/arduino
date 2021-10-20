/* 
 *  Controlando a velocidade motor dc 
 */
 
//Pino de controle do motor
int motorPin = 3;
 
void setup() 
{ 
  // Coloca o pino 3 do Arduino como OUTPUT (saída)
  pinMode(motorPin, OUTPUT);
  // inicializa comunicação serial a 9600 bits por segundo
  Serial.begin(9600); 
} 
  
void loop() 
{ 
  //Verifica se a saída serial está disponível
  if (Serial.available())
  {    
    // leitura da entrada analogica no pino 0
    int speed = analogRead(A0);
  
    // imprime o valor lido no monitor serial
    Serial.println(speed );

    //Deixa o valor na faixa de 0 a 255
    speed = speed / 4;
    
    //Verifica o intervalo da velocidade do motor  
    if (speed >= 0 && speed <= 255)
    {
      //Escreva no pino do motor dc a velocidade
      analogWrite(motorPin, speed);
    }
    delay(2);
  }
} 
