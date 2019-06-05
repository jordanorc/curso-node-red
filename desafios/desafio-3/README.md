# Desafio #3 - Capturar dados de monitoramento de atividade física

Capturar os dados de monitoramento e atividade física da pulseira Miband3 e acionar os sensores (vibração e batimentos cardíacos)

## Instalar o plugin para comunicação com Miband3 no Node-RED

Baixe o arquivo node-red-miband3.zip e extraia o node-red-miband3.tar.gz que está dentro dele. 

No terminal execute os seguintes comandos:

```bash
cd $HOME/.node-red
npm i /path/to/node-red-miband3.tar.gz
```

## Reinicie o Node-RED

Se o Node-RED estiver rodando, reinicie a instância.

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