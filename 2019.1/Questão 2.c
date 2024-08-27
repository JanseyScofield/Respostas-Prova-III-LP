#include <stdio.h>
#define TAM_STR 15
#define TAM_TABELA 8

void main(){
    char letras[TAM_TABELA][4] = {
                                    {'A','B','C',' '},
                                    {'D','E','F',' '},
                                    {'G','H','I',' '},
                                    {'J','K','L',' '},
                                    {'M','N','O',' '},
                                    {'P','Q','R','S'},
                                    {'T','U','V',' '},
                                    {'W','X','Y','Z',' '}};

    char numeros[TAM_TABELA] = {'2', '3', '4', '5', '6', '7', '8', '9'};
    int iCont, jCont, kCont;
    int naTabela;
    char entrada[TAM_STR];
    char saida[TAM_STR];

    fgets(entrada, TAM_STR, stdin);

    for(iCont = 0; entrada[iCont]; iCont++){
        naTabela = 0;
        for(jCont = 0; jCont < TAM_TABELA && !naTabela; jCont++)
            for(kCont = 0; kCont < 4 && !naTabela; kCont++)
                if(entrada[iCont] == letras[jCont][kCont])
                    naTabela = 1;
        saida[iCont] = naTabela? numeros[jCont - 1]: entrada[iCont];
    }
    saida[iCont] = '\0';
    printf("%s", saida);
}
