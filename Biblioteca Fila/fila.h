// Joao Pedro Moro Bolognini RA: 792185
// Atividade 09 - 11/06/2021
// Inversao de fila - fila.h
#ifndef FILA_H
#define FILA_H

typedef struct node Node;
typedef struct fila fila;
fila* inicializa();
void insere(fila* f, int numero);
void printar(fila* f); 
Node* trocandoOrdem(fila *f, int qtde, Node *n);
void invertendoPrimeiroUltimo(fila *f);

#endif