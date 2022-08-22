#### -----------------------------------------------------------
#### UNA Contagem Sistemas de Informação - 2020
####
#### IoT - Projeto final da UC Sistemas distribuidos e mobile
#### Consiste na medição do percentual de umidade de 03 amostras de solo por sensores
#### Aplicação de monitoramento desenvolvida em Flutter
#### -----------------------------------------------------------

Dispositivos:

* 01 ArduinoUNO&nbsp;
* 01 Módulo ESP8266-01&nbsp;
* 01 Protoboard&nbsp;
* 03 Sensor de umidade do solo (Higrômetro)&nbsp;
* 02 jumper macho x macho&nbsp;
* 13 jumper macho x femea&nbsp;

Banco de dados:

Sqlite3&nbsp;
Tabela: umidadeSolo&nbsp;
Colunas: id, sensor, umidade, data&nbsp;
local do arquivo: C:Sqlite3/projetoFinal.db&nbsp;

Thingspeak:

Channel Name: ProjetoFinal&nbsp;
Channel: 1220863&nbsp;
User API: 8X9RN5A4M0LTZQWV&nbsp;
Get channel list: GET https://api.thingspeak.com/channels.json?api_key=8X9RN5A4M0LTZQWV &nbsp;
Read a channel feed: GET https://api.thingspeak.com/channels/1220863/feeds.json?api_key=2WDK7GV1EKJRJ2YQ&results=2 &nbsp;
Read a channel field: GET https://api.thingspeak.com/channels/1220863/fields/1.json?api_key=2WDK7GV1EKJRJ2YQ&results=2
