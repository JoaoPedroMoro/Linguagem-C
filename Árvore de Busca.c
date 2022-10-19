// João Pedro Moro Bolognini RA:
// Árvore de busca com operações de palavras: inserir, remover e buscar.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bst {
    struct _bst* l;
    struct _bst* r;
    char* str;
} bst;

bst* get(bst* root, char* str) {
    if (root){
        int cmp = strcmp(root->str, str);
        if (cmp > 0){
            root = get(root->l, str);
        } else if (cmp < 0){
            root  = get(root->r, str);
        }
        return root;
    } else {
        return NULL;
    }        
}

bst* put(bst* root, char* str) {
    if(root) {
        int cmp = strcmp(root->str, str);
        if(cmp > 0)
            root->l = put(root->l,str);
        else if (cmp < 0)
            root->r = put(root->r,str);
        return root;
    } else {
        bst* novo = (bst*)malloc(sizeof(bst));
        novo->str = (char*)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(novo->str,str);
        novo->l = novo->r = NULL;
        return novo;
    }
}

bst* max(bst* root) {
    if (root){
        bst *novo = root;
        while (novo->r != NULL){
            novo = novo->r;
        }
        return novo;
    } else {
        return NULL;
    }
}

bst* min(bst* root) {
    if (root){
        bst *novo = root;
        while (novo->l != NULL){
            novo = novo->l;
        }
        return novo;
    } else {
        return NULL;
    }
}

bst* rem(bst* root, char* str) {
    if (!root){
      return NULL;
    } else {
      int cmp = strcmp(root->str, str);
        if (cmp > 0){
            root->l = rem(root->l, str);
        } else if (cmp < 0){
            root->r = rem(root->r, str);
        } else if (root->l == NULL && root->r == NULL){
            free(root);
            root=NULL;
        } else if (root->l == NULL){
            bst* novo = root;
            root = root->r;
            free(novo);
        } else if (root->r == NULL){
            bst* novo = root;
            root = root->l;
            free(novo);
        } else {
            bst* novo = max(root->l);
            strcpy(root->str, novo->str);
            root->l = rem(root->l, novo->str);
        }
    }
    return root;

}

void del(bst* root) {
    if(root) {
        del(root->l);
        del(root->r);
        free(root->str);
        free(root);
    }
}

int main() {

    char comando[2], palavra[255];

    bst* raiz = NULL;

    while(scanf("%s", comando) != EOF) {
        scanf("%s", palavra);
        if( comando[0] == 'P' ) 
            raiz = put(raiz,palavra);
        else if( comando[0] == 'R' ) 
            raiz = rem(raiz,palavra);
        else if( comando[0] == 'G' ) {
            bst* result = get(raiz,palavra);
            if( result )
                printf("%s encontrada\n", result->str);
            else
                printf("%s nao foi encontrada\n", palavra);
        }
    }

    del(raiz);

    return 0;
}