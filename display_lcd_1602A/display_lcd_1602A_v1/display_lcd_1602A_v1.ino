//Programa: Teste de Display LCD 16 x 2
//https://www.arduino.cc/en/Tutorial/LibraryExamples/LiquidCrystalBlink
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  //Imprime a mensagem no LCD
  lcd.print("Alo Mundo!");
}
 
void loop()
{
  //Desliga o cursor:
  lcd.noBlink();
  delay(3000);
  //Liga o cursor:
  lcd.blink();
  delay(3000);
}
