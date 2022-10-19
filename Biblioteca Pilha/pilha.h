// Joao Pedro Moro Bolognini RA : 792185
// Atividade 08 04/06/2021
// pilha pilha.h
#ifndef PILHA_H
#define PILHA_H

typedef char T;
typedef struct pilha pilha;
pilha* inicializarPilha();
void limparPilha(pilha* p);
void inserirPilha(pilha* p, T caractere);
void retirarPilha(pilha* p);
int compararTopo(pilha* p, T caractere);
T topoZerado(pilha* p, T resposta);

#endif 
