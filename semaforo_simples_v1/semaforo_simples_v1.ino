/*
  Semáforo simples com 3 LEDs
*/

int tempo = 0;

void setup() {  
  // Porta 13 (LED_BUILTIN) em modo de saída(escrita)
  pinMode(13,OUTPUT); //VERMELHO
   
  // Porta 12 em modo de saída(escrita)
  pinMode(12,OUTPUT);  //AMARELO
  
  // Porta 11 em modo de saída(escrita)
  pinMode(11,OUTPUT); //VERDE
}

void loop() {
	// Definimos tempo com  1000 milésimos de segundo
	tempo = 1000;  
	// Escrevemos HIGH(1) no pino digital 13
	digitalWrite(13,HIGH);  //Vermelho
	// Aguardamos o tempo definido
	delay(tempo); 
	// Escrevemos LOW(0) no pino digital 13
	digitalWrite(13,LOW); 
      
    // Escrevemos HIGH(1) no pino digital 11
	digitalWrite(11,HIGH); //Verde    
	// Aguardamos o tempo definido
	delay(tempo); 
	// Escrevemos LOW(0) no pino digital 11
	digitalWrite(11,LOW);   
  
	// Escrevemos HIGH(1) no pino digital 12
	digitalWrite(12,HIGH); //Amarelo
	// Aguardamos o tempo definido
	delay(tempo); 
	// Escrevemos LOW(0) no pino digital 12
	digitalWrite(12,LOW);
}
