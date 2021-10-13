/*
 *  Buzzer Do,Ré, Mi, Fá, Só, Lá e Si
 * 
 */

// Preparação do Arduino, este código irá rodar uma única vez
void setup()
{
	// Porta 12 (LED_BUILTIN) em modo de saída(escrita).
	pinMode(12, OUTPUT);
}

void loop()
{
	tone(12, 294, 1000); // play tone 50 (D4 = 294 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 311, 1000); // play tone 51 (D#4 = 311 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 330, 1000); // play tone 52 (E4 = 330 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 349, 1000); // play tone 53 (F4 = 349 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 370, 1000); // play tone 54 (F#4 = 370 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 392, 1000); // play tone 55 (G4 = 392 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 415, 1000); // play tone 56 (G#4 = 415 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
	tone(12, 440, 1000); // play tone 57 (A4 = 440 Hz)
	delay(1000); // Wait for 1000 millisecond(s)
}