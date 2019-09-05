# Desafio #1 - Criar uma rede de sensores sem fio e exibir os dados no Dashboard

Criar uma rede de sensores sem fio utilizando o ESP8266 e simular o envio de dados de temperatura, umidade e luminosidade, exibindo-os em um Dashboard.

Serão utilizados 3 nós ESP8266. 

## Baixar o Arduino IDE - https://www.arduino.cc/en/Main/Software

Baixe e inicie o Arduino IDE

## Configurar o repositório do ESP8266 nas URL's de placas adicionais

Digite https://arduino.esp8266.com/stable/package_esp8266com_index.json no campo "Additional Board Manager URLs". 

## Instalar as configurações para a placa ESP8266

Vá até Tools -> "Board Manager", pesquise por ESP8266 e instale a versão 2.5.2

## Configurar a placa ESP8266 

No Arduino IDE, selecione a placa "NodeMCU 1.0 (ESP-12E Module)" em "Tools" -> "Board"

## Instalar as bibliotecas necessárias

No Arduino IDE, localize e instale as bibliotecas "Painless Mesh" e "ArduinoJson" pelo menu "Tools" -> "Manage Library"

## Instalar o "Server" no nó Sink

Abra o arquivo server.ino no Arduino IDE, altere as configurações do Wifi (STATION_SSID e STATION_PASSWORD) e também o endereço IP do broker MQTT (mqttBroker). Depois que finalizar a configuração, compile e faça upload no nó Sink (#Sink)

## Instalar o "Client" nos nos que farão parte da rede de sensores

Abra o arquivo arduino/client/client.ino no Arduino IDE. Conecte o nó cliente. Caso o nó Sink esteja conectado à máquina, selecione a porta correta em "Tools" -> "Port".

Compile e faça upload nos nós clientes.

## Importar os fluxos do desafio para Node-RED

Importe o arquivo flows.json para o Node-RED.

## Rodar o fluxo do simulador

Habilite a aba do simulador e execute o fluxo.

## Abrir o Dashboard e veja se os dados são atualizados

Vá até http://localhost:1880/ui/ e observe se os dados estão sendo recebidos.

## Rodar o fluxo ESP8266

Desabilite o fluxo de simulação e habilite o fluxo ESP8266. Faça deploy novamente e verifique se os dados estão sendo atualizados no Dashboard.

## Desafio - Controlar o led dos nós da rede

Adicionar um botão na interface e fazer o led de todos os sensores da rede piscarem ao clicar no botão.






