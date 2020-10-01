//Controla o led 13 do Arduíno via WEB
//Acende o led 13
//http://192.168.0.112/?comando=11
//Apaga o led 13
//http://192.168.0.112/?comando=10

//Páginas de referência
// https://mjrobot.org/2016/01/21/o-esp8266-parte-3-acionando-leds-remotamente/ 
// http://www.arduinoetecnologia.com.br/projetos/esp8266-8211-como-enviar-comandos-para-o-arduino-atraves-do-browser/ 

#include <SoftwareSerial.h>
#include <String.h>

/**************** CONSTANTES **********************/
#define WIFI       "JKFG1"            //nome da rede de WIFI
#define PASSWORD   "jrku23091993!_"   //senha da rede WIFI 
#define DEBUG     true                //modo do debug
#define LEDPIN    13                  //pino do led
#define SPEED8266 9600                //velocidade de comunicacao por porta serial com o PC por USB
#define BAUDRATESPEED8266 9600        //velocidade de comunicacao por porta serial com o ESP8266

//RX pino 2, TX pino 3
SoftwareSerial ESP8266(2, 3);         //RX, TX do ESP8266

void setup(){
  Serial.begin(SPEED8266);                  //velocidade de comunicacao por porta serie com o PC por USB
  ESP8266.begin(BAUDRATESPEED8266);         //velocidade de comunicacao por porta serie com o ESP8266

  connectWiFi();                            //ligacao à rede WIFI
   
  pinMode(LEDPIN, OUTPUT);                  //define o pinLED como saída digital  
  digitalWrite(LEDPIN, HIGH);               //acende o led
  
  digitalWrite(LEDPIN, LOW);                //Apaga o led 
  Serial.println(">>>> Pronto para receber comandos");
}

void loop()
{  
  // Verifica se o ESP8266 esta enviando dados
  if (ESP8266.available())                               
  {
    if (ESP8266.find("+IPD,"))
    {     
      delay(300);
      //Retorna o id da conexão
      unsigned int connectionId = ESP8266.read() - 48;   // subtrai 48 porque a função read() retorna
                                                         // o valor ASCII em decimal e 0 (o primeiro número decimal) inicia em 48
      //Verifica se foi enviado a string "comando="                                                   
      if (ESP8266.find("comando=")) {  // avança o cursor até "comando="
        int comando = (ESP8266.read() - 48) * 10;
        comando += (ESP8266.read() - 48);
        
        //Comando o comando recebido
        Serial.print("recebido: ");
        Serial.println(String(comando));
        
        //Comando igual 11 liga o led 13
        if (comando == 11 ) {        
          digitalWrite(LEDPIN,HIGH);          
        } else {
          if (comando == 10 ) {        
            digitalWrite(LEDPIN,LOW);
          }
        } 
        //Gera a resposta ao comando
        String conteudoHTML = "Comando " + String(comando) + " executado com sucesso.";
        
        sendHTTPResponse(connectionId, conteudoHTML);
        
      } else {
          //Mensagem quando não tiver comando
          
          //Leitura do estado do led
          int led = digitalRead(LEDPIN);
      
          String conteudoHTML = "<h1>Comandos:</h1>";
            conteudoHTML += "<h2>O led 13 est&aacute;:"; //Tabela acentuação HTML http://www.lsi.usp.br/~help/html/iso.html
            conteudoHTML += led;
            conteudoHTML += "</h2>";
            conteudoHTML += "<h2>Como ligar led 13</h2>";
            conteudoHTML += "http://192.168.0.106/?comando=11<br>";
            conteudoHTML += "<h2>Como apagar led 13</h2>";
            conteudoHTML += "http://192.168.0.106/?comando=10<br>";
          
          sendHTTPResponse(connectionId, conteudoHTML);
      }      
    }
  }
}

/*
* Nome: sendHTTPResponse
* Descrição: Função utilizada para responder html ao browser
* Params: connectionId, conteudo
*/
void sendHTTPResponse(unsigned int connectionId, String conteudo)
{
      String webpage = "<html><head><title>Controle Led Wifi</title></head><body>";
      webpage += conteudo;
      webpage += "</body></html>";
      
      String cipSend = "AT+CIPSEND=";
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";
 
      ComandoAT(cipSend, 1000);
      ComandoAT(webpage, 1000);
 
      String comandoFechar = "AT+CIPCLOSE=";
      comandoFechar += connectionId; // concatena o id da conexão
      comandoFechar += "\r\n";
 
      ComandoAT(comandoFechar, 3000);
}

/*
* Nome: conectarWIFI
* Descrição: Função utilizada para ligacao ao WIFI
* Params: -
*/
void  connectWiFi()
{
    //Reset
    ComandoAT("AT+RST\r\n", 2000);
    
    //conecta a rede wireless 
    String  cmd = "AT+CWJAP=\"";
    cmd += WIFI;
    cmd += "\",\"";
    cmd += PASSWORD;
    cmd += "\"\r\n";
    ComandoAT(cmd, 20000);                         

    //Modo de conexão do acesspoint
    // 1 : station mode / 2 : softAP mode / 3 : softAP + station mode        
    ComandoAT("AT+CWMODE=1\r\n", 2000);           
    // Mostra o endereco IP
    ComandoAT("AT+CIFSR\r\n", 20000);    
    //Configura para multiplas conexoes
    ComandoAT("AT+CIPMUX=1\r\n", 1000);               
    //Inicia o web server na porta 80
    ComandoAT("AT+CIPSERVER=1,80\r\n", 1000);   
    Serial.println("Conexão realizada com sucesso.");
}

/*
* Name: ComandoAT
* Description: Função para enviar comandos AT para o ESP8266.
* Params: comando - comando AT para enviar; timeout - tempo de espera de uma resposta do ESP
* Returns: devolve a resposta do ESP
*/
String ComandoAT(String  comando, const int timeout){
  //Envio dos comandos AT para o módulo
  String  resposta = "";                 //variavel para armazenar a resposta do ESP
  ESP8266.println(comando);              //Envia os dados para o ESP para executar o comando
  long int tempo = millis();              //variaval para armazenar os millis atuais
  while ( (tempo + timeout) > millis()) 
  {
    while (ESP8266.available())         //utilizado para armazenar o resultado enviado pelo ESP
    {
      // A placa esp tem dados para mostrar da sua saida para a janela do Monitor serial
      char c = ESP8266.read();          // lê o próximo caracter
      resposta += c;                    //concatena o caracter com a resposta
    }
  }
  if (DEBUG) {                         //se estiver em modo debug imprime para o monitor serial
    Serial.println(resposta);
  }
  return resposta;
}
