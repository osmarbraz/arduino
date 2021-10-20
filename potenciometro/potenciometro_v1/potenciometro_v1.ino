/*
 *  Leitura de um potenciômetro.
 * 
 */

// Preparação do Arduino, este código irá rodar uma única vez
void setup()
{
	// Porta Analógica 0 em modo de entrada(leitura).
	pinMode(A0, INPUT);
	Serial.begin(9600);
}

void loop()
{
	// Leitura da porta analógica A0
	Serial.println(analogRead(A0));
	// Atrase por 250 milissegundos.
	delay(250); 
}