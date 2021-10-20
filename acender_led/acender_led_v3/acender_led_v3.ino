/*
 * Acende dois led e os fazem piscar
 * 
 */

//Tempo em milisegundos para piscar
int tempo = 0;
 
// Preparação do Arduino, este código irá rodar uma única vez
void setup() 
{
	//Porta 13 (LED_BUILTIN) em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	// Definimos o tempo de atraso
	tempo = 1000
	
	// Aguardamos o tempo definido
	delay(tempo);
	
	// Escrevemos LOW(0) no pino digital 13
	digitalWrite(LED_BUILTIN, LOW);
	
	// Aguardamos o tempo definido
	delay(tempo);
 
	// Escrevemos HIGH(1) no pino digital 13
	digitalWrite(LED_BUILTIN, HIGH);
}
