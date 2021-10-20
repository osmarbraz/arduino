/*
 * Mede a luminosidade do ambiente
 * 
 */

// Luminosidade do fotoresistor
int luminosidade = 0;
 
// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
	//Porta 0 (Analógica) em modo de entrada(leitura) para o fotoresistor.
	pinMode(A0, INPUT);
}

void loop() {
	//Leitura do fotoresistor na porta analógica 0
	luminosidade = analogRead(A0);
	//Saída da variável luminosidade no monitor serial
	Serial.println(luminosidade);
	delay(10); //Atraso para não saturar a leitura analógica  
}
