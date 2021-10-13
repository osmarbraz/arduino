/*
 * Monitora a distância de um objeto com o sensor ultrassônico
 * 
 */

// Distância do sensor
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
	Serial.begin(9600);
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
	
	//Saída da variável distância no monitor serial
	Serial.println(distancia);
	//Atrase um pouco para melhorar o desempenho da simulação
	delay(10); 
}
