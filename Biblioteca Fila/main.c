// Joao Pedro Moro Bolognini RA: 792185
// Atividade 09 - 11/06/2021
// Inversao de fila - main.c

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
  int N, numero;
  fila* F=inicializa();
  scanf("%d", &N);
  for (int i=0; i<N ;i++){
    scanf("%d", &numero);
    insere(F, numero);
  }
  Node *n;
  trocandoOrdem(F, 0, n);
  invertendoPrimeiroUltimo(F);
  printar(F);
  return 0;
}