/*
 * Monitora a distância de um objeto com o sensor ultrassônico e acende LEDs para indicar proximidade
 * 
 */

//Distância do sensor
int distancia = 0;

//Função de leitura do sensor
long readUltrasonicDistance(int triggerPin, int echoPin)
{
	//Porta triggerPin em modo de saída(escrita).
	pinMode(triggerPin, OUTPUT);  // Clear the trigger
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	// Sets the trigger pin to HIGH state for 10 microseconds
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	//Porta echoPin em modo de entrada(leitura).
	pinMode(echoPin, INPUT);
	// Reads the echo pin, and returns the sound wave travel time in microseconds
	return pulseIn(echoPin, HIGH);
}

void setup()
{
	Serial.println("Lendo dados do sensor...");
	Serial.begin(9600);  

	//Porta 12 em modo de saída(escrita).
	pinMode(12, OUTPUT); //VERMELHO

	//Porta 13 em modo de saída(escrita).
	pinMode(LED_BUILTIN, OUTPUT); //VERDE
}
 
void loop()
{
	//Sensor envia pela porta 4 e recebe pela porta 5 e calcula da distância do objeto
	distancia = 0.01723 * readUltrasonicDistance(4, 5);
	//Como sabemos, a velocidade do som no ar = 340m/s e corresponde a cerca de 29,412 microseg/cm
	//Aqui, usaremos esta fórmula para medir a distância percorrida pelo sensor de som ultrassônico
	//Distância = (Tempo * velocidade do som) / 2
	//Este “2” é dividido aqui porque o som está viajando para frente e para trás. Para frente e para trás significa que 
	//primeiro o som é emitido do sensor de som ultrassônico e, em seguida, é recuperado de volta após mirar o objeto.
	//Distância = (100 × 340) / 1000000) / 2 = 0,017  

	//Verifica se distancia é 100 cm
	if (cmMsec < 100) {
		Serial.print("\nPerigo!");
		//Escrevemos HIGH(1) no pino digital 12
		digitalWrite(12, HIGH);
		//Escrevemos LOW(0) no pino digital 13
		digitalWrite(LED_BUILTIN, LOW);
	} else {
		Serial.print("\nLiberado!");
		//Escrevemos LOW(0) no pino digital 12
		digitalWrite(12, LOW);
		//Escrevemos HIGH(1) no pino digital 13
		digitalWrite(LED_BUILTIN, HIGH);
	}
	//Atrase um pouco para melhorar o desempenho da simulação
	delay(10);
}
