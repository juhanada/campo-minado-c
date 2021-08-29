#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void imprimeMatriz(char matriz[TAM][TAM], int n){
  int i, j;
  printf("\n");
  
  for (i = 0; i < n + 2; i++){ 
    
    if (i >= n)
    	//imprime espaços em branco na primeira coluna das linhas que não fazem parte do campo (linhas de índice)
      	printf("    ");
    else{
    	//caso faça parte do jogo, imprimir o índice e após o pipe
        if (i < 9)
		  	//justificando, caso o índice só tenha um caractere
          	printf(" %d |", i+1);
        else 
        	//impressão de índices com mais de um caractere
          	printf("%d |", i+1);
    }

    for (j = 0; j < n; j++)
    	if (i == n) // caso seja na primeira linha após o fim da matriz
        	printf("---");
      	else if (i == n + 1) // caso seja a segunda linha após o fim da matriz
        	printf(" %d ", j + 1);
      	else
        	printf(" %c ", matriz[i][j]); // caso seja uma linha dentro da matriz
    printf("\n");
  }
  
  printf("\n");
}

int numeroDeBombas(char matriz[TAM][TAM], int linha, int coluna, int n){
  int qtd = 0;

  //verifica embaixo e cantos inferiores
  if (linha < n-1){
    if (matriz[linha+1][coluna] == '*')
      qtd++;
    if (coluna != 0)
      if (matriz[linha+1][coluna-1] == '*')
        qtd++;
    if (coluna != n-1)
      if (matriz[linha+1][coluna+1] == '*')
        qtd++;
  }

  //verifica em cima e cantos superiores
  if (linha != 0){
    if (matriz[linha-1][coluna] == '*')
      qtd++;
    if (coluna != 0)
      if (matriz[linha-1][coluna-1] == '*')
        qtd++;
    if (coluna != n-1)
      if (matriz[linha-1][coluna+1] == '*')
        qtd++;
  }
  
  //verifica na direita
  if (coluna < n-1)
    if (matriz[linha][coluna+1] == '*')
      qtd++;

  //verifica na esquerda
  if (coluna != 0)
    if (matriz[linha][coluna-1] == '*')
      qtd++;

  //printf("%d\n", qtd);
  return qtd;
}

int main() {
	
  int linha, coluna, ordem, i, j, bombas, qtd = 0, jogadas = 0;
  char solucao[TAM][TAM], jogo[TAM][TAM];

  //inicializando matrizes
  for (i = 0; i < TAM; i++)
    for (j = 0; j < TAM; j++){
      jogo[i][j] =  '?';
      solucao[i][j] = '-';
    }

  printf("\nDigite o tamanho da matriz desejada: ");
  scanf("%d", &ordem);
 
  //preenchendo a matriz com bombas
  bombas = (ordem*ordem)/5;
  //printf("%d\n", bombas);
  srand(time(NULL));
  
  do {
    linha = rand() % ordem;
    coluna = rand() % ordem;

    if(solucao[linha][coluna] != '*'){
      solucao[linha][coluna] = '*';
      qtd++;
    } 
    
  } while (qtd < bombas);

  /*imprimeMatriz(solucao,ordem);
  printf("\n");*/

  //comecando o jogo
  do {
    imprimeMatriz(jogo, ordem);

    printf("Digite a linha e coluna desejada: ");
    scanf("%d %d", &linha, &coluna);

    if ((linha > ordem) || (linha < 1) || (coluna > ordem) || (coluna < 1)){
    	printf ("\nEntrada invalida.\n");
    	continue; 
	}
	
	linha--;
    coluna--;    

    if (solucao[linha][coluna] == '*') {
      jogo[linha][coluna] = '*';
      printf("\nVOCE PERDEU! FIM DO JOGO.\n");

      for (i = 0; i < ordem; i++)
        for (j = 0; j <  ordem; j++)
          if (solucao[i][j] == '*')
            jogo[i][j] = '*';

      imprimeMatriz(jogo, ordem);
      break;
    }
    else {
      if (jogo[linha][coluna] == '?'){
        jogo[linha][coluna] = numeroDeBombas(solucao, linha, coluna, ordem)+'0';
        jogadas++;
      }
    }
    
  } while (jogadas < (ordem * ordem - bombas));

  if (jogadas == ordem*ordem - bombas){
    printf("\nPARABENS! VOCE VENCEU!\n");

    for (i = 0; i < ordem; i++)
        for (j = 0; j <  ordem; j++)
          if (solucao[i][j] == '*')
            jogo[i][j] = '*';

    imprimeMatriz(jogo, ordem);
  }

  return 0;
}
