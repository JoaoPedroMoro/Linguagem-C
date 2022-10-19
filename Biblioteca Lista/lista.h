// Joao Pedro Moro Bolognini RA:792185
// Atividade 11 - 28/06/2021
// Lista Ordenada (TAD) - lista.h

#ifndef LISTA_H
#define LISTA_H

#define Item char

typedef struct Lista Lista;
typedef struct Iterador Iterador;
void inicializa( Lista* l, int (*menor_igual_maior)( Item i1, Item i2));
void destroi(Lista* l);
int vazia(Lista* l);
void insere(Lista* l, Item i);
void retira(Lista* l, Item i);
Iterador primeiro(Lista* l);
Iterador ultimo(Lista* l);
int elementov(Iterador it, Item* i);
Item elemento(Iterador it);
int proximo(Iterador* it);
int anterior(Iterador* it);
int acabou(Iterador it);
Iterador impressao(Lista *l);

#endif