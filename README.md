# Campo minado em C

## Descrição do Projeto
Este projeto gera um jogo de campo minado em uma matriz NxN, posicionando aleatoriamente uma quantidade de bombas _0,2*(N*N)_ com a função _rand()_ utilizando uma semente aleatória.

### Entradas
* __Entrada inicial__: Um número inteiro 3 <= N <= 9, que será a ordem da matriz
* __Entradas ao longo do jogo__: Dois números inteiros formando um par ordenado com as coordenadas (linha, coluna) no campo minado. 
A entrada se encerra quando o jogo termina, ou seja, quando o jogador completa a matriz ou seleciona um espaço ocupado por cada bomba

## Pré-requisitos
* gcc

## Como rodar essa aplicação
```bash
# Clone este repositório
$ git clone 

# Acesse a pasta do projeto no terminal/cmd
$ cd campo-minado-c

# Compile o código e gere o executável com o comando:
$ gcc campominado.c -o campominado

# Execute
$ ./campominado
```

## Tecnologias utilizadas
* C
