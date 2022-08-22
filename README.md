# -----------------------------------------------------------
# UNA Contagem Sistemas de Informação - 2020
#
# IoT - Projeto final da UC Sistemas distribuidos e mobile
# Consiste na medição do percentual de umidade de 03 amostras de solo por sensores
# Aplicação de monitoramento desenvolvida em Flutter
# -----------------------------------------------------------

Dispositivos:

01 ArduinoUNO
01 Módulo ESP8266-01
01 Protoboard
03 Sensor de umidade do solo (Higrômetro)
02 jumper macho x macho
13 jumper macho x femea

Banco de dados:

Sqlite3
Tabela: umidadeSolo
Colunas: id, sensor, umidade, data
local do arquivo: C:Sqlite3/projetoFinal.db

Thingspeak:

Channel Name: ProjetoFinal
Channel: 1220863
User API: 8X9RN5A4M0LTZQWV
Get channel list: GET https://api.thingspeak.com/channels.json?api_key=8X9RN5A4M0LTZQWV
Read a channel feed: GET https://api.thingspeak.com/channels/1220863/feeds.json?api_key=2WDK7GV1EKJRJ2YQ&results=2
Read a channel field: GET https://api.thingspeak.com/channels/1220863/fields/1.json?api_key=2WDK7GV1EKJRJ2YQ&results=2