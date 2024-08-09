#include <stdio.h>
#define TAM_STR 50

int main()
{
    char entrada[TAM_STR];
    char saida[TAM_STR];
    int iCont, jCont, kCont;
    
    fgets(entrada, TAM_STR, stdin);
    
    for(iCont = 0, jCont = 1, kCont = 0; entrada[iCont]; iCont++){
        if(entrada[iCont] == entrada[iCont + 1])
            jCont++;
        else if(!entrada[iCont + 1] )
            break;
        else{
            saida[kCont] = jCont + '0';
            saida[kCont + 1] = entrada[iCont];
            kCont += 2;
            jCont = 1;
        }
    }
    
    puts(saida);
    return 0;
}
