#include <stdio.h>
#define LINHAS_COLUNAS 10

void main(){
    int matriz[LINHAS_COLUNAS][LINHAS_COLUNAS];
    int iCont, jCont;
    int qtdUm;
    int matrizPermutacao = 1;

    for(iCont = 0; iCont < LINHAS_COLUNAS; iCont++)
        for(jCont = 0; jCont <  LINHAS_COLUNAS; jCont++)
            scanf("%d", &matriz[iCont][jCont]);
    
    for(iCont = 0; iCont < LINHAS_COLUNAS && matrizPermutacao; iCont++){
        qtdUm = 0;
        for(jCont = 0; jCont < LINHAS_COLUNAS; jCont++){
            if(matriz[iCont][jCont] == 1)
                qtdUm++;
            else if(matriz[iCont][jCont] != 0){
               matrizPermutacao = 0;
               break; 
            }
        }
        if(qtdUm > 1 )
            matrizPermutacao = 0;
    }

    for(iCont = 0; iCont < LINHAS_COLUNAS && matrizPermutacao; iCont++){
        qtdUm = 0;
        for(jCont = 0; jCont < LINHAS_COLUNAS; jCont++){
            if(matriz[jCont][iCont] == 1)
                qtdUm++;
            else if(matriz[jCont][iCont] != 0){
               matrizPermutacao = 0;
               break; 
            }
        }
        if(qtdUm > 1 )
            matrizPermutacao = 0;
    }

    printf("%d", matrizPermutacao);
}
