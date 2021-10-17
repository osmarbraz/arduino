/*
 * Acende o LED incorporado(LED_BUILTIN) e o faz piscar
 * 
 */

void setup()
{
	//Porta 13 (LED_BUILTIN) em modo de saída(escrita)
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	// Aguardamos 1000 milésimos de segundo
	delay(1000); 
	
	// Escrevemos LOW(0) no pino digital 13
	digitalWrite(LED_BUILTIN, LOW);
	
	// Aguardamos 1000 milésimos de segundo
	delay(1000); 
		
	// Escrevemos HIGH(1) no pino digital 13
	digitalWrite(LED_BUILTIN, HIGH);
}