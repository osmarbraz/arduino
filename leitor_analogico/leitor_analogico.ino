/*
  Leitor entrada analogica
  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

void setup() {  
  // inicializa comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
}


void loop() {
  // leitura da entrada analogica no pino 0
  int valorSensor = analogRead(A0);
  
  // imprime o valor lido
  Serial.println(valorSensor );
  
  // Atraso entre as leituras para estabilizar
  delay(2);        
}
