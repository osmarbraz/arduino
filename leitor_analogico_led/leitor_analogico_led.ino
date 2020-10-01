/*
  Leitor entrada analogica com led
  O sensor muda a velocidade que o led pisca
  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int inPin12 = 12;

void setup() {  
  // inicializa comunicação serial a 9600 bits por segundo
  Serial.begin(9600);

  //Colocamos o pino 12 do Arduino como OUTPUT (saída)
  pinMode(inPin12, OUTPUT);
}


void loop() {
  // leitura da entrada analogica no pino 0
  int valorSensor = analogRead(A0);

  // Ativamos o pino 12 (colocando 5v nele)  
  digitalWrite(inPin12, HIGH);

  // Aguardamos o valor do sensor
  delay(valorSensor);

  // Desligamos o pino 12
  digitalWrite(inPin12, LOW);

  // Aguardamos mais o valor do sensor
  delay(valorSensor);
  
  // imprime o valor lido
  Serial.println(valorSensor );
  
  // Atraso entre as leituras para estabilizar
  delay(1);        
}
