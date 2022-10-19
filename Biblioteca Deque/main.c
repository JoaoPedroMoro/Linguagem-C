// Joao Pedro Moro Bolognini RA: 792185
// Atividade 07 31/05/2021
// Deque main.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "deque.h"


int main(){
    long N, M, numero;
    char opcao[7];
    scanf("%ld %ld", &N, &M);
    Deque* d=inicializaDeque(M);
    for (long i=0; i<N ; i++){
        scanf("%s", opcao);
        if (opcao[0]=='i'&& opcao[1]=='n'){
          scanf("%ld", &numero);
        }
        if (opcao[0]=='i'){
          if (opcao[6]=='I'){
            inserirInicio(d, numero, M);
          } else {
            inserirFinal(d, numero, M);
          }
        } else {
          if (opcao[6]=='I'){
            removerInicio(d, M);
          } else {
            removerFinal(d, M);
          }
        }
      }      
    return 0; 
}