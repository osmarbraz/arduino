/*
  Semáforo simples com 3 LEDs e pisca no vermelho
*/

void setup() {
  //Porta 13 (LED_BUILTIN) em modo de saída(escrita).
  pinMode(13,OUTPUT); //VERMELHO
   
  //Porta 12 em modo de saída(escrita).
  pinMode(12,OUTPUT);  //AMARELO
  
  //Porta 11 em modo de saída(escrita).
  pinMode(11,OUTPUT); //VERD
}

void loop() {  
  // Escrevemos HIGH(1) no pino digital 13
  digitalWrite(13,HIGH); //Vermelho
  
  // Aguardamos 4 milésimo de segundo
  delay(4000);   
  
  // Pisca o LED vermelho 3 vezes
  for (counter = 0; counter < 3; ++counter) {
		// Escrevemos LOW(0) no pino digital 13
		digitalWrite(13, LOW);
		// Aguardamos 500 milésimos de segundo
		delay(500); // Wait for 500 millisecond(s)
		// Escrevemos HIGH(1) no pino digital 13
		digitalWrite(13, HIGH);
		// Aguardamos 500 milésimos de segundo
		delay(500); // Wait for 500 millisecond(s)
  }
  
  // Escrevemos LOW(0) no pino digital 13
  digitalWrite(13,LOW); //Vermelho
      
  //Escrevemos HIGH(1) no pino digital 11
  digitalWrite(11,HIGH); //Verde
  
  //Aguardamos 4 milésimos de segundo
  delay(3000); // Tempo espera em segundos
  //Escrevemos LOW(0) no pino digital 11
  digitalWrite(11,LOW); //Verde
  
  
  //Escrevemos HIGH(1) no pino digital 12
  digitalWrite(12,HIGH); //Amarelo
  delay(1000); // Tempo espera em segundos
  //Escrevemos LOW(0) no pino digital 12
  digitalWrite(12,LOW); //Amarelo
}
