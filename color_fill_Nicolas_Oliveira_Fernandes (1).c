#include <stdio.h>

#define linhas 10
#define colunas 16

const char cores[][8] = {
    "\033[30m", // 0 - preto
    "\033[31m", // 1 - vermelho
    "\033[32m", // 2 - verde
    "\033[33m", // 3 - amarelo
    "\033[34m", // 4 - azul
    "\033[35m", // 5 - magenta
    "\033[36m", // 6 - ciano
    "\033[37m", // 7 - branco
    "\033[90m", // 8 - cinza
};
// Imprime a matriz no terminal, representando cada célula como um "losango"
// colorido de acordo com o valor armazenado em I[i][j]
void print_matrix(int I[linhas][colunas]) {
    printf("\n");

    for (int i = 0; i < linhas; i++) {
        printf("%d ", i);// imprime o índice da linha à esquerda
        for (int j = 0; j < colunas; j++) {
             // aplica o código de cor correspondente e imprime o caractere 35 ('#')
            printf("%s%c", cores[I[i][j]], 35);
        }
        printf("\033[0m\n");
    }
    printf("\n");
}
// trocando todas as células com "cor_atual" para "nova_cor", usando BFS
void colorir(int i, int j, int nova_cor, int cor_atual, int I[linhas][colunas]) {
     // filas para armazenar as posições (linha, coluna) a serem processadas
    int fila_i[linhas * colunas];
    int fila_j[linhas * colunas];

    // se a nova cor for igual à cor atual, não há nada a fazer
if (nova_cor == cor_atual) return;

    int inicio = 0; // indice de leitura
    int final = 0; // indice da quantidade de elementos

   // adiciona a inicial na fila e já pinta com a nova cor
    fila_i[final] = i;
    fila_j[final] = j;
    final++;

    I[i][j] = nova_cor; 


    // processa a fila até não haver mais células a visitar
    while (inicio < final) {

         i = fila_i[inicio];
         j = fila_j[inicio];
         inicio++;

         // verifica e pinta o vizinho de cima, se tiver a cor_atual
         /* parte de cima*/
         if ( i > 0 && I[i-1][j] == cor_atual) {
            I[i-1][j] = nova_cor;
             fila_i[final] = i-1;
              fila_j[final] = j;
               final++;

         }  // verifica e pinta o vizinho de baixo, se tiver a cor_atual
         /*parte inferior */  
          if (i < linhas-1 && I[i+1][j] == cor_atual) {
            I[i+1][j] = nova_cor;
            fila_i[final] = i+1;
            fila_j[final] = j;
            final++;
         }
          // verifica e pinta o vizinho da esquerda, se tiver a cor_atual
          /* parte da Esquerda */
          if (j > 0 && I[i][j-1] == cor_atual) {
            I[i][j-1] = nova_cor;
            fila_i[final] = i;
            fila_j[final] = j-1;
            final++;
         }

          // verifica e pinta o vizinho da direita, se tiver a cor_atual
     /* parte da Direita*/
          if (j < colunas-1 && I[i][j+1] == cor_atual) {
            I[i][j+1] = nova_cor;
            fila_i[final] = i;
            fila_j[final] = j+1;
            final++;
         }

    }
}

int main(void) {
//  Caso de teste 1:   
/*    int I[linhas][colunas] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    }; */
//  Caso de teste 2:   
    int I[linhas][colunas] = {
        {3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {3,3,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {3,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    //  Caso de teste 5 (testa acesso fora dos limites - ultima linha):
/*    int I[linhas][colunas] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,0}
    }; */

    int i, j;
     int nova_cor;
      int cor_atual;

       // loop principal: exibe a matriz e pede uma operação de preenchimento até o usuário digitar -1
    
       while (1) {
        print_matrix(I);
    printf("Digite a nova cor entre 0 e 8(-1 para encerrar): "); 
    scanf("%d", &nova_cor);

    if (nova_cor == -1) {
        break; //encerra se for -1
        }
        if (nova_cor < 0 || nova_cor > 8) {
            printf("Cor invalida! Digite uma cor entre 0 e 8.\n");
            continue; //volta ao inicio do loop ate pedir uma cor valida
            }

        printf("Digite a linha: ");
        scanf("%d", &i);

        printf("Digite a coluna: ");
        scanf("%d", &j); 
        
        // verifica se não vai cair fora da matriz
        if (i < 0 || i >= linhas || j < 0 || j >= colunas) {
            printf("Posicao invalida! Linha entre 0 e %d, coluna entre 0 e %d.\n", linhas - 1, colunas - 1);
            continue; // volta o loop desde o inicio 
        }

        cor_atual = I[i][j]; // guarda a cor original
        colorir(i, j, nova_cor, cor_atual, I); //preenche a cor
    }
}