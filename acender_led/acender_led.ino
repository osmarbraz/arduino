/*
 * Acende um led e o faz piscar
 * 
 */

//Tempo em milisegundos para piscar
int TEMPO = 1000;
 
//Utiliza o pino para acender o led
int inPin13 = 13;

// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
  // Colocamos o pino 13 do Arduino como OUTPUT (saída)
  pinMode(inPin13, OUTPUT);  
}

void loop() {
  // Ativamos o pino 13 (colocando 5v nele)  
  digitalWrite(inPin13, HIGH);
  
  // Aguardamos 1 segundo
  delay(TEMPO);

  // Desligamos o pino 13
  digitalWrite(inPin13, LOW);
  
  // Aguardamos mais um segundo
  delay(TEMPO);
}
