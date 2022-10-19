// Joao Pedro Moro Bolognini RA: 792185
// Atividade 07 31/05/2021
// Deque deque.c

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include <time.h>

struct Deque{
    long qtde;
    long inicio;
    long fim;
    long maximo;
    long v[550000];
};

Deque* inicializaDeque(long tamanho){
    Deque *d;
    d = (Deque*) malloc(sizeof(struct Deque));
    d->inicio=0; //A posicao inicio do vetor comeca no 0.
    d->fim=0; //A posicao final do vetor comeca no 0.
    d->qtde=0; //O vetor nao possui nenhum numero
    d->maximo=tamanho; //Tamanho maximo do deque
    return d;
}

void inserirInicio(Deque* d, long numero, long tamanho){
    if (d->qtde==tamanho){
        printf("cheia\n");
    } else {
        if (d->qtde==0){
          d->v[d->inicio]=numero;
          d->fim=(d->fim+1)%tamanho; //Como o deque estava vazio o indicador do final que é incrementado.
        } else {
          d->inicio--; //Como um elemento foi inserido no começo, o começo anda uma posicao para tras.
          if (d->inicio<0){
            d->inicio=tamanho-1; //Se a posicao inicial for menor que 0, ela vai ser realocada para o final do vetor.
          }
          d->v[d->inicio]=numero; //Atribuicao do numero na posicao.
        }
        d->qtde++; 
    }    
}
void inserirFinal(Deque* d, long numero, long tamanho){
    if (d->qtde==tamanho){
        printf("cheia\n");
    } else {
        d->v[d->fim]=numero; //Como a posicao final do deque eh uma a mais, atribui-se nela, para depois incrementa-la.
        d->fim=(d->fim+1)%tamanho; //Se ultrapassar o tamanho do deque, vai para a posicao inicial do vetor, por isso o % tamanho.
        d->qtde++;
    }   
}
void removerInicio(Deque* d, long tamanho){
    if (d->qtde==0){
        printf("vazia\n");
    } else {
        printf("%ld\n", d->v[d->inicio]); //Indica qual numero sera removido.
        d->inicio=(d->inicio+1)%tamanho; //Se ultrapassar o tamanho do deque ao incrementar, vai para a posicao inicial do vetor, por isso o % tamanho.
        d->qtde--;
    }
}
void removerFinal(Deque* d, long tamanho){
    if (d->qtde==0){
        printf("vazia\n");
    } else {
      d->fim--; //Decrementa a posicao final do deque.
        if (d->fim<0){
            d->fim=tamanho-1; //Se a posicao final for menor que 0, ela vai para o fim do deque.
        }
        printf("%ld\n", d->v[d->fim]); //Indica qual numero sera removido.
        d->qtde--;
    }
}