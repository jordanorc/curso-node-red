# Minicurso Node-RED

Tutorial para preparação do ambiente para o minicurso de Node-RED e execução dos exemplos.

## Instalação do Node.js

```bash
sudo apt install curl build-essential 
```

```bash
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
```

```bash
sudo apt install nodejs
```

## Instalação do Node-RED

```bash
sudo npm install -g --unsafe-perm node-red
```

## Inicializar o Node-RED

```bash
node-red 
```

Abrir a url no navegador: http://localhost:1880/

## Executando os exemplos

Para executar os exemplos, basta importar os arquivos .json para o Node-RED