// Aqui, definimos os pinos que serão utilizados no programa
int pinoLED = 2;
int BotaoA = 3;
int BotaoB = 4;
 
 
void setup() {
pinMode(pinoLED, OUTPUT); // Define o pino do LED como saída
pinMode(BotaoA, INPUT); // Define os botões como entrada
pinMode(BotaoB, INPUT);
}
 
 
void loop() {
    // Passa o valor dos botões para as variáveis
    boolean A = digitalRead(BotaoA); // Foi escolhido boolean que só assume o valor 0 ou 1
    boolean B = digitalRead(BotaoB); // Também poderia ser um 'int' ou um 'char' 
     
    if(A||B) // LED acende se A OU B
      {
        digitalWrite(pinoLED, HIGH);
      }
      else // Se a condição não for satisfeita, apaga o LED
      {
        digitalWrite(pinoLED, LOW); 
      }
 
    delay(200);
     
}
