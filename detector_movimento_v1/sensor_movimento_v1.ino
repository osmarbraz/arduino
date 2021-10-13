/*
 * Detector de movimento
 * 
 */

// Preparação do Arduino, este código irá rodar uma única vez
void setup()
{
	// Porta 13 (LED_BUILTIN) em modo de entrada(leitura).
	pinMode(12, INPUT);
    
	// Porta 13 (LED_BUILTIN) em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	// Leitura do sensor da porta 12
	estadoSensor = digitalRead(12);
	// Se o sensor é igual a 1
	if (estadoSensor == HIGH) {
		// Escrevemos HIGH(1) no pino digital 13
		digitalWrite(LED_BUILTIN, HIGH);
	} else {
		// Escrevemos LOW(0) no pino digital 13
		digitalWrite(LED_BUILTIN, LOW);
	}
	
	// Atrase um pouco para melhorar o desempenho da simulação
	delay(10); 	
}