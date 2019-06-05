# Desafio #2 - Criar um Dashboard para exibir informações de sensores 

Neste desafio você terá que criar um Dashboard para exibir informações de sensores (temperatura, umidade e luminosidade) do SensorTag

## Instalar o plugin para comunicação com SensorTag no Node-RED

Vá ao menu Manage Palette -> Pallet -> Install e localize o plugin node-red-contrib-sensortag (versão 0.1.4).

Clique no botão "Install" para instalar o plugin.

## Importar os fluxos do desafio para Node-RED

Importe o arquivo flows.json para o Node-RED.

## Rodar o fluxo do simulador

Habilite a aba do simulador e execute o fluxo.

## Abrir o Dashboard e veja se os dados são atualizados

Vá até http://localhost:1880/ui/ e observe se os dados estão sendo recebidos. 

## Rodar o fluxo do SensorTag

Desabilite o fluxo de simulação e habilite o fluxo do SensorTag. Faça deploy novamente e verifique se os dados estão sendo atualizados no Dashboard. Teste se o botão de ação também funciona.

## Desafio - Incluir novas informações no Dashboard.

Adicione ao Dashboard novos widgets para exibir informações de pressão atmosférica e do magnetômetro, giroscópio e acelerômetro.