# Minicurso Node-RED

Tutorial para preparação do ambiente para o minicurso de Node-RED e execução dos exemplos.

[![Apresentação](assets/minicurso.png)](https://docs.google.com/presentation/d/e/2PACX-1vS9fcNr4xYVpWFEedpadD2dFgkcSIrn0xcxUucQ8o1tKFDXuisT2zPU84L4RNqDEHEjGIgqaMT2cITg/pub?start=false)

## Instalação Local

### Instalação do Node.js

```bash
sudo apt install curl build-essential 
```

```bash
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
```

```bash
sudo apt install nodejs
```

### Instalação do Node-RED

```bash
sudo npm install -g --unsafe-perm node-red
```

### Inicializar o Node-RED

```bash
node-red 
```

## Instalação com Docker

### Instalação do Docker

Adicionar chave GPG oficial do Docker:

```bash
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```

Configurar o repositório estável:

```bash
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
```

Instalar o Docker:

```bash
sudo apt-get install docker-ce docker-ce-cli containerd.io
```

### Executar o Node-RED:

```bash
docker run -it -p 1880:1880 --name nodered nodered/node-red-docker
```

## Abrir interface gráfica

Abrir a url no navegador: http://localhost:1880/

## Executando os exemplos

Para executar os exemplos, basta importar os arquivos .json para o Node-RED