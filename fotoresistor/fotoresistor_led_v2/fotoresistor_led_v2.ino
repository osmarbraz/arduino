/*
 * Acende um led com a redução de luminosidade do ambiente.
 * 
 */

// Luminosidade do fotoresistor
int luminosidade = 0;
 
// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
	//Porta 0 (Analógica) em modo de entrada(leitura) para o fotoresistor.
	pinMode(A0, INPUT);
	//Porta 13 (LED_BUILTIN) em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT);  	
}

void loop() {
	//Leitura do fotoresistor na porta analógica 0
	luminosidade = analogRead(A0);
	//Se luminosidade menor que 760 acende o LED
	if (luminosidade < 750) {
		//Escrevemos HIGH(1) no pino digital 13	
		digitalWrite(LED_BUILTIN, HIGH); //Liga o LED VERMELHO
	} else {
		digitalWrite(LED_BUILTIN, LOW); //Desliga o LED VERMELHO 
	}
	delay(10); //Atraso para não saturar a leitura analógica  
}
