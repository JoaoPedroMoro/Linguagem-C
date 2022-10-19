// Joao Pedro Moro Bolognini RA: 792185
// Atividade 07 31/05/2021
// Deque deque.h


#ifndef DEQUE_H
#define DEQUE_H


typedef struct Deque Deque;
Deque* inicializaDeque(long tamanho);
void inserirInicio(Deque* d, long numero, long tamanho);
void inserirFinal(Deque* d, long numero, long tamanho);
void removerInicio(Deque* d, long tamanho);
void removerFinal(Deque* d, long tamanho);

#endif 