#include <SoftwareSerial.h>
SoftwareSerial esp8266(2,3); // RX, TX

const byte CH_PD=5;
const byte RST=6;
#define rede "JKFG1"
#define senha "jrku23091993!_"

void setup() {
  Serial.begin(38400);
  Serial.println("--------------");
  pinMode(CH_PD,OUTPUT);
  digitalWrite(CH_PD,HIGH);
  pinMode(RST,OUTPUT);
  digitalWrite(RST,LOW);
  delay(100);
  digitalWrite(RST,HIGH);
  delay(1000);
  Serial.begin(9600);
  Serial.setTimeout(5000);

  Serial.println("ESP8266 Demo - aguardando 1 segundo");
  delay(1000);
  Serial.println("Enviando RST");
  esp8266.println("AT+RST");  
  recebeResposta();
  recebeResposta(); // o reset tem 2 respostas - OK (antes) e ready (depois) 
  Serial.println("Selecionando modo de operacao misto (AP e estacao)");
  esp8266.println("AT+CWMODE=3");  
  recebeResposta();
  Serial.println("Listando redes visiveis");
  esp8266.println("AT+CWLAP");  
  recebeResposta();
  Serial.println("Conectando-se a uma rede");
  String comando="AT+CWJAP=\"";
  comando+=rede;
  comando+="\",\"";
  comando+=senha;  
  comando+="\"";
  esp8266.println(comando);  
  recebeResposta();
  Serial.println("Listando endereco IP (pode dar ping no segundo deles)");
  esp8266.println("AT+CIFSR");  
  recebeResposta();
}

void loop() {
}

void recebeResposta() {
  int limite=7000;
  unsigned long chegada=millis();
  boolean continuar=true; 
  String S="";
  unsigned long ultimochar=0;
  while (continuar) { 
    if (esp8266.available()) {
      char c = esp8266.read();
      ultimochar=millis();
      S=S+c;
      esp8266.print(c);
      if (c==10) {  // LF, fim da linha recebida
        byte p=S.indexOf(13);
        String S1=S.substring(0,p);
        if (S1=="OK") continuar=false;
        if (S1=="ready") continuar=false;
        if (S1=="no change") continuar=false;
        if (S1=="ERROR") continuar=false;
        S="";
      }  
    }  
    if (millis()-chegada > limite) continuar=false;
  }
} 
