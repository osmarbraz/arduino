/*
  semaforo com botão de pedestre
*/

int PINO_CARRO_LED_VERMELHO = 13;
int PINO_CARRO_LED_AMARELO = 12;
int PINO_CARRO_LED_VERDE = 11;

int PINO_PEDESTRE_LED_VERDE = 2;
int PINO_PEDESTRE_LED_VERMELHO = 3;

//Botão para indicar a passagem de pedestre
int BOTAO = 7;

int TEMPOATRAVESSANDOPEDESTRE = 4000;
int TEMPOATRAVESSANDOCARRO = 4000;
int TEMPOALERTACARRO = 1000;
int TEMPOPARADOCARRO = 3000;
int TEMPOENTREPEDESTRE = 5000;

//Conta o tempo entre os apertos do botão
unsigned long MUDATEMPO;

void setup() {
  // Inicializamos o temporizador aqui
  // Observe que o "contador" foi atrelado
  // a váriavel que setamos acima.
  MUDATEMPO = millis();
  
  //Vermelho
  //Define o pino 13 como OUTPUT, a variável de saída
  pinMode(PINO_CARRO_LED_VERMELHO,OUTPUT); 
    
  //Amarelo
  //Define o pino 12 como OUTPUT, a variável de saída
  pinMode(PINO_CARRO_LED_AMARELO,OUTPUT); 
    
  //Verde
  //Define o pino 11 como OUTPUT, a variável de saída
  pinMode(PINO_CARRO_LED_VERDE,OUTPUT);
    
  //Verde Pedestre
  //Define o pino 2 como OUTPUT, a variável de saída
  pinMode(PINO_PEDESTRE_LED_VERDE,OUTPUT);
  
  //Vermelho Pedestre
  //Define o pino 3 como OUTPUT, a variável de saída
  pinMode(PINO_PEDESTRE_LED_VERMELHO,OUTPUT);
  
  //Inicialização das luzes
  //Começamos deixando acesas as luzes: verde (referente aos veículos) 
  // e vermelha (referente aos pedestres)
  digitalWrite(PINO_CARRO_LED_VERDE, HIGH);
  digitalWrite(PINO_PEDESTRE_LED_VERMELHO, HIGH);
  digitalWrite(PINO_CARRO_LED_VERMELHO, LOW);
  digitalWrite(PINO_CARRO_LED_AMARELO, LOW);
  digitalWrite(PINO_PEDESTRE_LED_VERDE, LOW);
  //Serial.begin(9600);
    
}

void loop() {  
  
  verificaBotao();
  
  //Verde    
  //Coloca o pino 11 em nível HIGH, em 5 V e acende o verde
  digitalWrite(PINO_CARRO_LED_VERDE,HIGH); 
  delay(TEMPOATRAVESSANDOCARRO); // Tempo de 3 segundos
  //Coloca o pino 11 em nível LOW, em 0 V e apaga o verde
  digitalWrite(PINO_CARRO_LED_VERDE,LOW); 
  
  verificaBotao();
  
  //Amarelho
  //Coloca o pino 12 em nível HIGH, em 5 V e acende o amarelo
  digitalWrite(PINO_CARRO_LED_AMARELO,HIGH); 
  delay(TEMPOALERTACARRO); // Tempo de 1 segundo
  //Coloca o pino 12 em nível LOW, em 0 V e apaga o amarelo
  digitalWrite(PINO_CARRO_LED_AMARELO,LOW); 
    
  verificaBotao();  
    
  //Vermelho
  //Coloca o pino 13 em nível HIGH, em 5 V e acende o vermelho
  digitalWrite(PINO_CARRO_LED_VERMELHO,HIGH); 
  delay(TEMPOPARADOCARRO); // Tempo de TEMPOPARADOCARRO segundos
  //Coloca o pino 13 em nível LOW, em 0 V e apaga o vermelho
  digitalWrite(PINO_CARRO_LED_VERMELHO,LOW);  
  
}  
  
void verificaBotao(){ 
  // A variável que vamos setar abaixo servirá para "guardar" o estado do nosso botão (pressionado ou não pressionado)  
  int estado = digitalRead(BOTAO);
  delay(50);
  Serial.println(estado);
  
  // Se o botão está sendo pressionado E se já passou TEMPOENTREPEDESTRE segundos desde a última pressão.
  
  if (estado == HIGH && (millis() - MUDATEMPO) > TEMPOENTREPEDESTRE) {    
    //Então SE SIM, executa a função de mudar o estado das luzes abaixo:
    mudaLuzesPedestre();
  } 
}

// Mudança de luzes para o pedestre
void mudaLuzesPedestre() {
  
  //Luz verde do carro é desligada
  digitalWrite(PINO_CARRO_LED_VERDE, LOW);    // A luz verde é desligada
  //Acende a luz amarela do carro
  digitalWrite(PINO_CARRO_LED_AMARELO, HIGH); // A luz amarela vai ligar por TEMPOENTREPEDESTRE segundos
  delay(TEMPOALERTACARRO); 
  //Apaga a luz amarela
  digitalWrite(PINO_CARRO_LED_AMARELO, LOW); // A luz amarela vai desligar
  //Acende a vermelha
  digitalWrite(PINO_CARRO_LED_VERMELHO, HIGH); // A luz vermelha vai ligar por TEMPOATRAVESSANDOPEDESTRE segundos
 
  //Desliga a luz vermelha do pedestre
  digitalWrite(PINO_PEDESTRE_LED_VERMELHO, LOW);
  //Acende a luz verde do pedestre
  digitalWrite(PINO_PEDESTRE_LED_VERDE, HIGH);
  delay(TEMPOATRAVESSANDOPEDESTRE);
  
  // Pisca a luz verde dos PEDESTRES 10 vezes
  for (int x=0; x<10; x++) {
    digitalWrite(PINO_PEDESTRE_LED_VERDE, LOW);
    delay(160);
    digitalWrite(PINO_PEDESTRE_LED_VERDE, HIGH);
    delay(160);
  }
  
  //Desliga as luzes verde do pedestre
  digitalWrite(PINO_PEDESTRE_LED_VERDE, LOW);
  //Desliga a luz vermelha do carro
  digitalWrite(PINO_CARRO_LED_VERMELHO, LOW);
  //Desliga a luz amarela do carro
  digitalWrite(PINO_CARRO_LED_AMARELO, LOW);
  //Acende a luz vermelha do pestre
  digitalWrite(PINO_PEDESTRE_LED_VERMELHO, HIGH);
  //Acende a luz verde do carro
  digitalWrite(PINO_CARRO_LED_VERDE, HIGH);
 
  MUDATEMPO = millis();
 } 
 
