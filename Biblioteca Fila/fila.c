// Joao Pedro Moro Bolognini RA: 792185
// Atividade 09 - 11/06/2021
// Inversao de fila - fila.c

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct node{
  int item;
  struct node *link;
};
struct fila{
  Node *primeiro, *ultimo;
  unsigned qtde;
};
typedef struct node Node;
fila* inicializa(){
  fila* f;
  f = (fila*)malloc(sizeof(struct fila));
  f->primeiro=f->ultimo=NULL;
  f->qtde=0;
  return f;
}
void insere(fila* f, int numero){
  Node *n=(Node*)malloc(sizeof(Node));
  n->item=numero;
  n->link=NULL;
  if (f->ultimo){
    f->ultimo->link=n;
  } else {
    f->primeiro=n;
  }
  f->ultimo=n;
  f->qtde++;
}
// Pega o node no inicio e vai percorrendo a fila printando os elementos.
void printar(fila *f){
  Node *n=f->primeiro;
  printf("%d", n->item);
  n=n->link;
  for (int a=1; a<f->qtde ;a++){
    printf(" %d", n->item);
    n=n->link;
  }
  printf("\n");
}
// Inverte as ordens dos links de cada node, o link do ultimo elemento em vez de ser NULL vai ser o anterior e por ai vai. Retorna o node encontrado.
Node* trocandoOrdem(fila *f, int qtde, Node *n){
  Node *temp= (Node*)malloc(sizeof(struct node));
  temp=f->ultimo;
  if (qtde==f->qtde){
    temp->link=NULL; // Define o link do primeiro elemento como NULL.
    return n;
  }
  if (qtde!=0){
    n=n->link; // Se nao for na primeira chamada recursiva, ele avanca para o node pro proximo.
  } else {
    n=f->primeiro; // Se estiver na primeira chamada atribui o f->primeiro para o node, o inicio.
  }
  if (qtde<f->qtde){
    temp=trocandoOrdem(f, qtde+1, n);
    temp->link=n;
    return n;
  } else {
    return n;
  }
}
// Como os links estao invertidos, basta agora efetuar a troca do primeiro elemento com o ultimo, pois os links estarao corretos em ordem dessa forma.
void invertendoPrimeiroUltimo(fila *f){
  Node* temp=f->primeiro;
  f->primeiro=f->ultimo;
  f->ultimo=temp;
}