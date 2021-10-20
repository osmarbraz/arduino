/*
 *  Controle de vãrios LEDs para indicar a potência..
 * 
 */
 
 int valorLido = 0;

// Preparação do Arduino, este código irá rodar uma única vez
void setup()
{
	// Porta Analógica 0 em modo de entrada(leitura).
	pinMode(A0, INPUT);
	Serial.begin(9600);
	
	// Coloca os pinos dos LEDs em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
}

void loop()
{
	// Leitura da porta analógica A0
	valorLido = analogRead(A0);
	
	Serial.println(valor);
	if (valor > 200) {
		// Escrevemos HIGH(1) no pino digital LED_BUILTIN
		digitalWrite(LED_BUILTIN, HIGH);
	} else {
		// Escrevemos LOW(0) no pino digital LED_BUILTIN
		digitalWrite(LED_BUILTIN, LOW);
	}
	if (valor > 400) {
		// Escrevemos HIGH(1) no pino digital 12
		digitalWrite(12, HIGH);
	} else {
		// Escrevemos LOW(0) no pino digital 12
		digitalWrite(12, LOW);
	}
	if (valor > 600) {
		// Escrevemos HIGH(1) no pino digital 11
		digitalWrite(11, HIGH);
	} else {
		// Escrevemos LOW(0) no pino digital 11
		digitalWrite(11, LOW);
	}
	if (valor > 800) {
		// Escrevemos HIGH(1) no pino digital 10
		digitalWrite(10, HIGH);
	} else {
		// Escrevemos LOW(0) no pino digital 10
		digitalWrite(10, LOW);
	}
	if (valor > 1000) {
		// Escrevemos HIGH(1) no pino digital 9
		digitalWrite(9, HIGH);
	} else {
		// Escrevemos LOW(0) no pino digital 9
		digitalWrite(9, LOW);
	}
	// Atrase por 500 milissegundos.
	delay(500); 	
}