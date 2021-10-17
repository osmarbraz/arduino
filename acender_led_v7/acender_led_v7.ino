/*
 * Aumenta o brilho do LED de forma gradativa.
 * 
 */

// Controla o brilho do LED
int i;
 
// Preparação do Arduino, este código irá rodar uma única vez
void setup() {
	//Porta 11 em modo de saída(escrita).
	pinMode(11, OUTPUT); 
}

void loop() {
	// Percorre de 1 até 255 com passo 5
    for (i = 0; i <= 255; i += 5) {
       // Escreve i na porta 11
       analogWrite(11, i);
       // Mostra i no monitor serial
       Serial.println(i); 
	   // Aguarda 1000 milésimos de segundo
	   delay(15); 
    }  
}
