#include <WiFiEsp.h>
#include <SoftwareSerial.h>

int sensorAnalogico = 0;
float umidade;
int id = 0;
int numSensores = 3;

SoftwareSerial Serial1(6, 7); //PINOS QUE EMULAM A SERIAL, ONDE O PINO 6 É O RX E O PINO 7 É O TX


char ssid[] = "###########"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO
char pass[] = "###########";//VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO


int status = WL_IDLE_STATUS;
WiFiEspServer server(80);
RingBuffer buf(8);

void setup(){
  Serial.begin(9600); 
  Serial1.begin(9600);
  WiFi.init(&Serial1);
  IPAddress localIP(192,168,15,100);
  WiFi.config(localIP);

  //INÍCIO - VERIFICA SE O ESP8266 ESTÁ CONECTADO AO ARDUINO, CONECTA A REDE SEM FIO E INICIA O WEBSERVER
  if(WiFi.status() == WL_NO_SHIELD){
    while (true);
  }
  while(status != WL_CONNECTED){
    status = WiFi.begin(ssid, pass);
  }
  server.begin();
}

void loop(){
  WiFiEspClient client = server.available();
  if (client) {
    Serial.println("novo cliente");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("<!DOCTYPE HTML>");
        client.println();
        
        //LÊ OS VALORES DE CADA SENSOR ANALÓGICO E FAZ A CONVERSÃO EM PERCENTUAL DE UMIDADE
        for (sensorAnalogico = 0; sensorAnalogico < numSensores; sensorAnalogico++) {
        umidade = ((analogRead(sensorAnalogico)/10.25)-100)*(-1);
          
          //RESPONDE O CLIENTE COM A NUMERAÇÃO DO SENSOR E UMIDADE RESPECTIVAS EM FORMATO DE TEXTO
          client.print(sensorAnalogico);
          client.print(",");
          client.print(umidade);
          if(sensorAnalogico < (numSensores-1)){
          client.print(",");
          }
        }
          break;     
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    //TEMPO PARA RECEBER OS DADOS
    delay(1);
    //FECHA A CONEXÃO
    client.stop();
    Serial.println("cliente desconectado.");
  }
}