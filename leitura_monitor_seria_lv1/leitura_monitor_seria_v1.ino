/*
 * Controla o LED pelo monitor serial. 
 * Onde 1 liga o  LED  e qualquer outra coisa apaga.
 * 
 */
 
int ligar = 0;

// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
	
	Serial.begin(9600);		
		
	//Porta LED_BUILTIN em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT); 	
}

void loop() {
	
	// Verifica se o monitorial serial está disponível.
	if (Serial.available() != 0) {
		// Descontamos 48 na variável lida pois o número 1
		// é o caracter decimal 49 na tabela ASCII
		ligar = (Serial.read() - 48);
		Serial.println(ligar);
		if (ligar == 1) {
			digitalWrite(LED_BUILTIN, HIGH);
		} else {
			digitalWrite(LED_BUILTIN, LOW);
		}
	} else {
		Serial.println("Nada digitado!");
	}
	// Aguardamos 1000 milésimos de segundo
	delay(1000); 
}
