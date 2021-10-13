/*
 * Acende um led externo no pino 13 e o faz piscar
 * 
 */

// Preparação do Arduino, este código irá rodar uma única vez
void setup()
{
	//Porta 13 (LED_BUILTIN) em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	// Aguardamos 1 milésimo de segundo
	delay(1000); 
	
	// Escrevemos LOW(0) no pino digital 13
	digitalWrite(LED_BUILTIN, LOW);
	
	// Aguardamos 1 milésimo de segundo
	delay(1000); 
	
	// Escrevemos HIGH(1) no pino digital 13
	digitalWrite(LED_BUILTIN, HIGH);
}