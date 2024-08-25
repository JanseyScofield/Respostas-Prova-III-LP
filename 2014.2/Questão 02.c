// O agrupamento de duas ou mais consoantes, sem vogal intermediária, recebe o nome  de encontro consonantal.  Escreva  um  programa  em  C,  que  leia  uma  string  de  
//até  256  caracteres,  conte  e  imprima  o  número de encontros consonantais identificados na string. Por exemplo, na string “O istmo de Stradun não fica no Brasil”. 
//O programa deverá imprimir o  valor 3.

#include <stdio.h>
#define TAM_STR 256

void main(){
    char string[TAM_STR];
    char naoConsoantes[11] = {"aeiouAEIOU "};
    int iCont, jCont;
    int qtdencontrosConsonatais = 0;
    int aux = 0;
    int encontroConsonatal;

    fgets(string, TAM_STR, stdin);

    for(iCont = 0; string[iCont + 1] != '\n'; iCont++){
        encontroConsonatal = 1;
        for(jCont = 0; jCont < 11; jCont++)
            if((string[iCont] == naoConsoantes[jCont] || string[iCont + 1] == naoConsoantes[jCont]))
                encontroConsonatal = 0;
        if(encontroConsonatal && !aux)
            qtdencontrosConsonatais++;
        aux = encontroConsonatal;
    }

    printf("%d", qtdencontrosConsonatais);

}
