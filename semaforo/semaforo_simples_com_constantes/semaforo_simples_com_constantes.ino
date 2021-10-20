/*
  semaforo simples
*/

int PINO_LED_VERMELHO = 13;
int PINO_LED_AMARELO = 12;
int PINO_LED_VERDE = 11;

int TEMPOATRAVESSANDOCARRO = 4000;
int TEMPOALERTACARRO = 1000;
int TEMPOPARADOCARRO = 3000;

void setup() {
  //Vermelho
  //Define o pino 13 como OUTPUT, a variável de saída
  pinMode(PINO_LED_VERMELHO,OUTPUT); 
    
  //Amarelo
  //Define o pino 12 como OUTPUT, a variável de saída
  pinMode(PINO_LED_AMARELO,OUTPUT); 
    
  //Verde
  //Define o pino 11 como OUTPUT, a variável de saída
  pinMode(PINO_LED_VERDE,OUTPUT);   
}

void loop() {
  //Vermelho
  //Coloca o pino 13 em nível HIGH, em 5 V e acende o vermelho
  digitalWrite(PINO_LED_VERMELHO,HIGH); 
  delay(TEMPOPARADOCARRO); // Tempo de TEMPOPARADOCARRO segundos
  //Coloca o pino 13 em nível LOW, em 0 V e apaga o vermelho
  digitalWrite(PINO_LED_VERMELHO,LOW); 
      
  //Verde    
  //Coloca o pino 11 em nível HIGH, em 5 V e acende o verde
  digitalWrite(PINO_LED_VERDE,HIGH); 
  delay(TEMPOATRAVESSANDOCARRO); // Tempo de TEMPOATRAVESSANDOCARRO segundos
  //Coloca o pino 11 em nível LOW, em 0 V e apaga o verde
  digitalWrite(PINO_LED_VERDE,LOW); 
  
  //Amarelho
  //Coloca o pino 12 em nível HIGH, em 5 V e acende o amarelo
  digitalWrite(PINO_LED_AMARELO,HIGH); 
  delay(TEMPOALERTACARRO); // Tempo de TEMPOALERTACARRO segundo
  //Coloca o pino 12 em nível LOW, em 0 V e apaga o amarelo
  digitalWrite(PINO_LED_AMARELO,LOW); 

}
