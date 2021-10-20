/*
 *  Controle do pisca-pica com potenciômetro.
 * 
 */
 
 int valorLido = 0;

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
	valorLido = analogRead(A0);
	// Escrevemos HIGH(1) no pino digital LED_BUILTIN
	digitalWrite(LED_BUILTIN, HIGH);
	// Atrase por valorLido milissegundos.
	delay(valorLido); 
	// Escrevemos LOW(0) no pino digital LED_BUILTIN
	digitalWrite(LED_BUILTIN, LOW);
	// Atrase por valorLido milissegundos.
	delay(valorLido); 
}