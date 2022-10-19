// Joao Pedro Moro Bolognini RA:792185
// Atividade 11 - 28/06/2021
// Lista Ordenada (TAD) - main.c

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int comparador(Item a, Item b);

int main() {
  Lista *l;
  inicializa(l, comparador); // Inicializa a lista e passa a funcao.
  return 0;
}

int comparador(Item a, Item b){
  if (a>b){
    return 1;
  }
  if (a<b){
    return -1;
  } 
  return 0;
}