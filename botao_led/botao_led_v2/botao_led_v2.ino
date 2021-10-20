/*
 * Acende o led ao se pressionar o botão
 * 
 */
 
int estadoBotao = 0;
  
// Preparação do Arduino, este código irá rodar uma única vez
void setup() 
{
	//Porta 12 (Botão) em modo de entrada(leitura)
	pinMode(12, INPUT); 
	
	//Porta 13 (LED_BUILTIN) em modo de saída(escrita)
	pinMode(LED_BUILTIN, OUTPUT);	
}

void loop() {
	//Leitura do botão na porta 12
	estadoBotao = digitalRead(12);
	
	//Mostra o conteúdo da variável estadoBotao no monitor serial
	Serial.println(estadoBotao);
	
	//Se estado do botão igual a HIGH acende o LED na porta 13
	if (estadoBotao == HIGH) {
		//Escrevemos HIGH(1) no pino digital 13		
		digitalWrite(LED_BUILTIN, HIGH);
	} else {
		//Escrevemos LOW(0) no pino digital 13
		digitalWrite(LED_BUILTIN, LOW);
	}
	//Atrase um pouco para melhorar o desempenho da simulação
	delay(10); 
}
