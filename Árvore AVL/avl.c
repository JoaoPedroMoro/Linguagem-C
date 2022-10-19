#include <stdlib.h>
#include "avl.h"

void inicializar( avl* arvore ) {
	arvore->raiz = 0;
}

void destruir_privado( node *p ) {
    if (p->dir == 0 && p->esq == 0){
        free (p);
    } else if (p->dir == 0 && p->esq != 0){
        destruir_privado(p->esq);
        free(p);
    } else if (p->dir != 0 && p->esq == 0){
        destruir_privado(p->dir);
        free(p);
    } else {
        destruir_privado(p->esq);
        destruir_privado(p->dir);
        free(p);
    }
}

void destruir( avl* arvore ) {
    destruir_privado(arvore->raiz);
}

node* rotEE( node* A ) {
    node* B = A->esq;
    A->esq = B->dir; 
    B->dir = A;
    A->bal=0;
    B->bal=0;
    return B;
}

node* rotDD( node* A ) {
	node* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    A->bal = 0;
    B->bal = 0;
    return B;
}

node* rotED( node* A ) {
	node* B= A->esq;
    node* C = B->dir;
    B->dir = C->esq;
    C->esq = B;
    A->esq = C->dir;
    C->dir = A;
    if (C->bal == -1){
        A->bal=1;
        B->bal=0;
        C->bal=0;
    } else if (C->bal==1){
        A->bal=0;
        B->bal=-1;
        C->bal=0;
    } else {
        A->bal=0;
        B->bal=0;
    }
    return C;
}

node* rotDE( node* A ) {
	node* B = A->dir;
    node* C = B->esq;
    B->esq = C->dir;
    C->dir = B;
    A->dir = C->esq;
    C->esq = A;
    if (C->bal == -1){
        A->bal=0;
        B->bal=1;
        C->bal=0;
    } else if (C->bal==1){
        A->bal=-1;
        B->bal=0;
        C->bal=0;
    } else {
        A->bal=0;
        B->bal=0;
    }
    return C;
}

node* inserir_privado( node* p, int data, int *mudouAltura) {
	if(!p) {
		node* novo = (node*)malloc(sizeof(node));
		novo->data = data;
        	novo->bal=0;
		novo->dir = novo->esq = 0;
		*mudouAltura = 1;
		return novo;
	} else if(data < p->data){
        p->esq = inserir_privado(p->esq, data, mudouAltura);
        if (*mudouAltura==1){
            p->bal--;
        }
        if ((p->bal <= -2)&&(p->esq->bal==0)){
            p->bal++;
        } else if (p->dir !=0){
            if ((p->bal <=-1)&&(p->esq->bal==0)&&(p->dir->bal==0)){
                p->bal++;
            }
        }
        if (*mudouAltura == 1){
            if (p->bal == -2 && p->esq->bal == -1){
                p=rotEE(p);
            } else if (p->bal == -2 && p->esq->bal == 1){
                p=rotED(p);
            }           
        }  
    } else if (data > p->data){
        p->dir = inserir_privado(p->dir, data, mudouAltura);
        if (*mudouAltura==1){
            p->bal++;
        }
        if ((p->bal >= 2)&&(p->dir->bal==0)){
            p->bal--;
        } else if(p->esq != 0){
            if ((p->bal >= 1)&&(p->esq->bal == 0)&&(p->dir->bal==0)){
                p->bal--;
            }
        }
        if (*mudouAltura == 1){
            if ((p->bal == 2)&&(p->dir->bal == 1)){
                p=rotDD(p);
            } else if (p->bal == 2 && p->dir->bal == -1){
                p=rotDE(p);
            } 
        }    
    } else {
        p->data = data;
    }
    if (p->bal >= 1 || p->bal <=- 1){
            *mudouAltura = 1;
        } else {
            if (p->bal == 0){
                *mudouAltura = 0;
            }
        }
    return p;
}


void inserir( avl* arvore, int data) {
	
	int mudouAltura = 0;
	
	arvore->raiz = inserir_privado( arvore->raiz, data, &mudouAltura );
	
}
    
node* teto_privado(node* p, int dado) {
   if (dado > p->data){
       if (p->dir ==0){
            if (p->data < dado){
                return NULL;
            }   
            return p;
       } else {
           return teto_privado(p->dir, dado);
       }
   } else if (dado < p->data){
       if (p->esq == 0){
           if (p->data < dado){
               return NULL;
           }
           return p;
       } else {
           /*node* esq = teto_privado(p->esq, dado);
           if (esq == NULL){
               return p;
           }
           if (dado > esq->data){
               return p;
           } else {
               return esq;
           }*/
           if (p->esq->data < dado){
               return p;
           }
           return teto_privado(p->esq, dado);
       }
   } else {
       return p;
   }
}

node* piso_privado(node* p, int dado) {
   if (dado < p->data){
       if (p->esq == 0){
           if (p->data > dado){
               return NULL;
           }
           return p;
       } else {
           return piso_privado(p->esq, dado);
       }
   } else if (dado > p->data){
       if (p->dir == 0){
           if (p->data > dado){
               return NULL;
           }
           return p;
       } else {
           /*node* dir = piso_privado(p->dir, dado);
           if (dir == NULL){
               return p;
           }
           if (dado < dir->data){
               return p;
           }
           else {
               return dir;
           }*/
           if (p->dir->data > dado){
               return p;
           }
           return piso_privado(p->dir, dado);
       }
   } else {
       return p;
   }
}


int teto( avl* arvore, int dado, int *teto_dado ) {
    node* c = teto_privado(arvore->raiz, dado);
    if(c) {
        *teto_dado = c->data; // Busca pela menor chave maior ou igual a uma chave.
        return 1;
    }
    return 0;
}

int piso( avl* arvore, int dado, int *piso_dado ) {
    node* f = piso_privado(arvore->raiz, dado); // Busca pela maior chave menor ou igual a uma chave.
    if(f) {
        *piso_dado = f->data;
        return 1;
    }
    return 0;
}