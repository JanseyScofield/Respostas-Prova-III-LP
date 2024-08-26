/* Uma faixa de letras é um conjunto de letras minúsculas alfabeticamente consecutivas tomadas de 'a' até 'z'. A menor e maior letras da faixa, separadas por dois pontos 
(o caractere ':'), são  usadas   para   representar   a   faixa   de   letras.   Por   exemplo,   a   faixa   "a:c"   representa   as   letras consecutivas 'a', 'b' e 'c'. 
(as aspas não fazem parte da faixa). A faixa "w:z" representa as letras 'w', 'x', 'y' e 'z'. A faixa "m:m" representa apenas a letra 'm'. Escreva um programa em C, 
que leia uma string composta por letras minúsculas e espaços em branco e imprima as faixas de letras que a compõe, ordenadas alfabeticamente pelo menor valor de cada faixa. 
Faixas de letras a serem impressas devem representar a maior sequência possível de letras de entrada em ordemcrescente. Ignore espaços e letras duplicadas contidas na entrada.
Por exemplo, a string "iron maiden" tem cinco faixas de letras, "a:a" (a letra 'a'), "d:e" (as letras 'd' e 'e'), "i:i" (a letra 'i'), "m:o" (as letras 'm',   'n' e 'o') e 
"r:r" (a letra 'x').   Assim a saída do programa deveria ser: "a:a d:e i:i m:o r:r".*/ 


#include <stdio.h>
#define TAM_STR 100

void main(){
    char string[TAM_STR];
    char stringSemEspaco[TAM_STR];
    char conjuntos[TAM_STR];
    char aux;
    int iCont, jCont, kCont;

    fgets(string, TAM_STR, stdin);

    for(iCont = 0; string[iCont + 1] != '\n'; iCont++)
        for(jCont = iCont + 1; string[jCont] != '\n'; jCont++)
            if(string[iCont] > string[jCont]){
                aux = string[iCont];
                string[iCont] = string[jCont];
                string[jCont] = aux;
            }

    string[iCont + 1] = '\0';

    for(iCont = 0, jCont = 0; string[iCont]; iCont++){
        if((string[iCont] != string[iCont + 1]) && string[iCont] != ' '){
            stringSemEspaco[jCont] = string[iCont];
            jCont++;
        }
    }

    stringSemEspaco[jCont + 1] = '\0';

    for(iCont = 0, kCont = 0, jCont = 0; stringSemEspaco[iCont];iCont++){
        conjuntos[kCont] = stringSemEspaco[iCont];
        conjuntos[kCont + 1] = ':';
        kCont += 2;
        while(stringSemEspaco[jCont]){
            jCont = iCont + 1;
            if(stringSemEspaco[jCont] - stringSemEspaco[iCont] == 1)
                iCont++;
            else
                break;
        }
        conjuntos[kCont] = stringSemEspaco[iCont];
        conjuntos[kCont + 1] = ' ';
        kCont += 2;
    }
    conjuntos[kCont] = '\0';
    printf("%s", conjuntos);
}
