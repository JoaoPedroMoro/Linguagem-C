// Joao Pedro Moro Bolognini RA : 792185
// Atividade 08 04/06/2021
// pilha pilha.c
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
  int topo;
  char vetor[100000];
};

pilha* inicializarPilha(){
  pilha* p;
  p = (pilha*) malloc(sizeof(struct pilha)); 
  p->topo=-1; // Ao inicializar a pilha, define o topo como a posicao -1, pois o topo sempre vai ser a posicao exata do ultimo caractere.
  return p;
}
void limparPilha(pilha* p){
  p->topo=-1; // Para limpar a pilha eh so "zerar" o topo de volta ao inicio.
}
void inserirPilha(pilha* p, T caractere){
  p->topo++; // Primeiro incrementa a posicao para depois inserer o caractere.
  p->vetor[p->topo]=caractere;
}
void retirarPilha(pilha* p){
  p->topo--; // Decrementacao do topo e consequentemente da pilha.
}
int compararTopo(pilha* p, T caractere){
  if (p->topo<0){
    return 0; // Se a pilha nao tiver nenhum dos caracteres mais iniciais ("(", "{" e "[") a pilha eh considerada vazia.
  }
  // Comparacao dos pares de combinacao possiveis.
  if (p->vetor[p->topo]=='('){
    if (caractere==')'){
      return 1;
    } else {
      return 0;
    }
  } else {
    if (p->vetor[p->topo]=='{'){
      if (caractere=='}'){
        return 1;
      } else {
        return 0;
      }
    } else {
      if (caractere==']'){
        return 1;
      } else {
        return 0;
      }
    }
  }
}
T topoZerado(pilha* p, T resposta){
    if (p->topo>=0){
      resposta='N'; // Se ao final das entradas o topo nao estiver na posicao inicial, ela nao eh bem definida.
      return resposta;
    } else {
        return resposta;
    }
}