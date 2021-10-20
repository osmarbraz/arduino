/*
 * Exemplo uso LED RGB.
 * 
 */

// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
		
	//Porta 11 em modo de saída(escrita).
	pinMode(11, OUTPUT); // Vermelho
	//Porta 10 em modo de saída(escrita).
	pinMode(10, OUTPUT); // Azul
	//Porta 9 em modo de saída(escrita).
	pinMode(9, OUTPUT) // Verde
}

void loop() {
	
	// Escrevemos 255 no pino digital 11
	digitalWrite(11, 255);
	
	// Aguardamos 1000 milésimo de segundo
	delay(1000);
	
	//Escrevemos 0 no pino digital 11
	digitalWrite(11, 0);  
	
	// Aguardamos 1000 milésimo de segundo
	delay(1000);
	
	// Escrevemos 255 no pino digital 10
	digitalWrite(10, 0);
	
	// Aguardamos 1000 milésimo de segundo
	delay(1000);
	
	//Escrevemos 0 no pino digital 10
	digitalWrite(10, 0);  
	
	// Aguardamos 1000 milésimo de segundo
	delay(1000);
	
	// Escrevemos 255 no pino digital 9
	digitalWrite(9, 255);
	
	// Aguardamos 1000 milésimo de segundo
	delay(1000);
	
	//Escrevemos 0 no pino digital 9
	digitalWrite(9, 0);  
	
	// Aguardamos 1000 milésimo de segundo
	delay(1000);  
}
