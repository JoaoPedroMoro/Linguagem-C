// Joao Pedro Moro Bolognini RA:792185
// Atividade 11 - 28/06/2021
// Lista Ordenada (TAD) - lista.c

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct node{
  char data;
  struct node *next, *prev;
};
struct Lista{
  struct node *sentinela;
  int qtde;
  int (*menor_igual_maior)(Item i1, Item i2); // ponteiro para a funcao de comparacao.
};
struct Iterador{
  struct node *posicao;
  Lista *estrutura;
};

void inicializa( Lista* l, int (*menor_igual_maior)( Item i1, Item i2)){
  // Inicializacao da lista.
  struct node *n=(struct node*)malloc(sizeof(struct node));
  l = (Lista*)malloc(sizeof(Lista));
  n->next=n->prev=l->sentinela=n;
  l->sentinela->prev=l->sentinela->next=l->sentinela;
  l->qtde=0;
  l->menor_igual_maior=menor_igual_maior;
  // Vai ler as entradas e ja ordenar as instrucoes baseado nas entradas.
  char string[7], caractere;
  int contadorImpressoes=0;
  scanf("%s", string);
  do {
    if (string[1]=='n'){ // insere
      scanf("%c", &caractere);
      if (caractere==' '){
        scanf("%c", &caractere);
      }
      insere(l, caractere);
    }
    if (string[1]=='m'){ // imprime
      impressao(l);
      contadorImpressoes++;
    }
    if (string[0]=='r'){ // remove
      scanf("%c", &caractere);
      if (caractere==' '){
        scanf("%c", &caractere);
      }
      retira(l, caractere);
    }
  } while (scanf("%s", string)!=EOF);
  if (contadorImpressoes==0){
    printf("\n"); // Se nao tiver tido 1 imprimir na funcao, ele da um \n padrao.
  }
}
void destroi(Lista* l){
  while (!vazia(l)){
    retira(l, l->sentinela->data);
  }
  free(l->sentinela);
}
int vazia(Lista* l){
  return l->sentinela->next==l->sentinela;
}
void insere(Lista* l, Item i){
  struct node *n=(struct node*)malloc(sizeof(struct node));
  if (l->qtde==0){
    n=l->sentinela; // Se a lista tiver vazia ele insere na posicao da sentinela.
    n->data=i;
    l->qtde++;
  } else {
    // Se nao tiver vazia ele vai buscando aonde inserir, antes ou depois do elemento analisado.
    struct node *temp;
    temp=l->sentinela;
    if (l->qtde>0){   
      if (l->menor_igual_maior(temp->data, i)==-1){ 
        while (l->menor_igual_maior(temp->data, i)== -1){  
          if (temp->next==l->sentinela){
            break; // Se for a ultima posicao da lista.
          }
          temp=temp->next; // Enquanto o elemento i for maior n->data, o n->data vai sendo deslocado.
          }
          if (l->menor_igual_maior(temp->data, i)==1){  // Se ocorrer do n->data ficar maior que o i, vai ser inserido antes.
            n->data=i;
            temp->prev->next=n;
            n->next=temp;
            n->prev=temp->prev;
            temp->prev=n;
            temp=temp->prev;
            l->qtde++;
            return;
          }
          // Vai ser inserido depois.
          n->data=i;
          temp->next->prev=n;
          n->next=temp->next; 
          temp->next=n;
          n->prev=temp;
          l->qtde++;
      } else {
        if (l->menor_igual_maior(temp->data, i)==1){
          while (l->menor_igual_maior(temp->data, i)==1){
            if (temp==l->sentinela){
              l->sentinela=n; // Se o temp foi igual ao sentinela, o sentinela tem sua posicaoe atribuida a n.
            }
            // Vai ser inserido antes.
            n->data=i;
            temp->prev->next=n;
            n->next=temp;
            n->prev=temp->prev;
            temp->prev=n;
            temp=temp->prev;
          }
          l->qtde++;
        } else {
          if (l->menor_igual_maior(temp->data, i)==0){
            while (l->menor_igual_maior(temp->data, i)==0) {
              if (temp->next==l->sentinela){
                break; // Se for a ultima posicao da lista.
              }
              temp=temp->next;
            }
            // Como o elemento eh igual ao ultimo analisado, ele vai ser inserido logo depois dele.
            n->data=i;
            temp->prev->next=n;
            n->next=temp;
            n->prev=temp->prev;
            temp->prev=n;
            temp=temp->prev;
            l->qtde++;
          }
        } 
      }   
    }
  }
}
void retira(Lista* l, Item i){
  int qtde=l->qtde;
  struct node *n=l->sentinela;
  // Enquanto o elemento i for igual ao n->data, o n->data vai ser removido da lista.
  for (int a=0; a<qtde ;a++){
    if (n->data==i){
      if (l->sentinela==n){
        l->sentinela=n->next; // Se acontecer do sentinela ser o elemento que vai ser removido, ele eh deslocado para o proximo elemento.
      }
      n->next->prev=n->prev;
      n->prev->next=n->next;
      l->qtde--;
    }
    n=n->next;
    if(l->menor_igual_maior(n->data, i)==1){
      break; // Quando o elemento do n->data for maior que o elemento i, ele para o for.
    }
  }
  if (n->data==i && l->qtde==1){
    l->qtde=0; // Se acontecer de sobrar so um elemento, sendo igual ao i, e a quantidade for 1, ele zera e deixa a lista como vazia.
  }
}
Iterador primeiro(Lista* l){
  Iterador it;
  it.posicao=l->sentinela->next;
  it.estrutura=l;
  return it;
}
Iterador ultimo(Lista* l){
  Iterador it;
  it.posicao=l->sentinela->prev;
  it.estrutura=l;
  return it;
}
int elementov(Iterador it, Item* i){
  if (!acabou(it)){
    *i=it.posicao->data;
    return 1;
  }
  return 0;
}
Item elemento(Iterador it){
  return it.posicao->data;
}
int proximo(Iterador* it){
  if (!acabou(*it)){
    it->posicao=it->posicao->next;
  }return 1;
}
int anterior(Iterador* it){
  if (!acabou(*it)){
    it->posicao=it->posicao->prev;
  }return 1;
}
int acabou(Iterador it){
  return it.posicao==it.estrutura->sentinela;
}
Iterador impressao(Lista *l){
  Iterador it;
  if (l->qtde==0){
    printf("vazia\n");
    return it;
  }
  it.posicao=l->sentinela;
  printf("%c", it.posicao->data);
  for (it.posicao=it.posicao->next; it.posicao!=l->sentinela ;it.posicao=it.posicao->next){
    printf(" %c", it.posicao->data);
  }
  printf("\n");
  return it;
}