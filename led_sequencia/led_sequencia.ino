/*
   Acende um sequencia de leds

*/

//Intervalos dos pinos
int pi = 1;
int pf = 7;


// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
  // Colocamos os pinos de pi a pf como OUTPUT (saída)
  for (int i = pi; i <= pf; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // leitura da entrada analogica no pino 0 para ler o tempo
  int tempo = analogRead(A0);
  
  // imprime o valor lido
  //Serial.println(valorSensor );

  // Ativamos o pino de pi a pf (colocando 5v nele)
  for (int i = pi; i <= pf; i++) {
    digitalWrite(i, HIGH);
    // Aguardamos 1 segundo
    delay(tempo);
    digitalWrite(i, LOW);
    // Aguardamos 1 segundo
    delay(100);
  }
  // leitura da entrada analogica no pino 0 para ler o tempo
  tempo = analogRead(A0);  
  
  // Faz a volta
  for (int i = pf - 1; i > pi; i--) {
    digitalWrite(i, HIGH);
    // Aguardamos 1 segundo
    delay(tempo);
    digitalWrite(i, LOW);
    // Aguardamos 1 segundo
    delay(100);
  }  
}
