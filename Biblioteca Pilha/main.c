// Joao Pedro Moro Bolognini RA : 792185
// Atividade 08 04/06/2021
// pilha main.c
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
  int qtde;
  char caractere, respostaCadeia;
  scanf("%d\n", &qtde);
  pilha *p=inicializarPilha();
  for (int i=0; i<qtde ;i++){
    respostaCadeia='S';
    do{
      scanf("%c", &caractere);
      if (caractere!='\n'){
        // Na pilha so vai entrar as partes "iniciais" dos pares possiveis, para depois comparar com as partes finais.
        if (caractere=='{' || caractere=='[' || caractere=='('){
          inserirPilha(p, caractere);
        } else {
          if (compararTopo(p,caractere)==1){
            retirarPilha(p); // Se o par se encaixar, por enquanto ela eh bem definida, decrementa o topo.
          } else {
            respostaCadeia='N'; // Se o par nao encaixar, ela nao eh bem definida.
          }
        }
      } 
    } while (caractere!='\n');
    //Se ainda tiver elementos na pilha, ela não eh bem definida.
    respostaCadeia=topoZerado(p, respostaCadeia);
    limparPilha(p);
    printf("%c\n", respostaCadeia);
  }
  return 0;
}