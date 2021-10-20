/*
 * Acende dois leds e os fazem piscar
 * 
 */

//Tempo em milisegundos para piscar
int tempo;
 

// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
	//Porta 13 (LED_BUILTIN) em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT);  
	//Porta 12 em modo de saída(escrita).
	pinMode(12, OUTPUT); 
}

void loop() {
	// Definimos o tempo de atraso
	tempo = 1000;
	
	// Aguardamos o tempo definido
	delay(tempo);

	// Escrevemos LOW(0) no pino digital 13
	digitalWrite(LED_BUILTIN, LOW);
	
	// Aguardamos o tempo definido
	delay(tempo);
	
	// Escrevemos HIGH(1) no pino digital 13
	digitalWrite(LED_BUILTIN, HIGH);
  
	// Aguardamos o tempo definido
	delay(tempo);
	  
	// Escrevemos LOW(0) no pino digital 12
	digitalWrite(12, LOW);
	
	// Aguardamos o tempo definido
	delay(tempo);
	
	// screvemos HIGH(1) no pino digital 12
	digitalWrite(12, HIGH); 
  
}
