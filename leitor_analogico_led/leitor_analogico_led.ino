/*
  Leitor entrada analogica com led
  O sensor muda a velocidade que o led pisca
  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int inPin13 = 13;

void setup() {  
  // inicializa comunicação serial a 9600 bits por segundo
  Serial.begin(9600);

  //Colocamos o pino 13 do Arduino como OUTPUT (saída)
  pinMode(inPin13, OUTPUT);
}


void loop() {
  // leitura da entrada analogica no pino 0
  int valorSensor = analogRead(A0);

  // Ativamos o pino 13 (colocando 5v nele)  
  digitalWrite(inPin13, HIGH);

  // Aguardamos o valor do sensor
  delay(valorSensor);

  // Desligamos o pino 13
  digitalWrite(inPin13, LOW);

  // Aguardamos mais o valor do sensor
  delay(valorSensor);
  
  // imprime o valor lido
  Serial.println(valorSensor );
  
  // Atraso entre as leituras para estabilizar
  delay(1);        
}
