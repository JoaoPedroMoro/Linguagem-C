// João Pedro Moro Bolognini
// Programa utilizando InsertionSort.

#include <stdio.h>

void insertion(int vetor[], int n);
void troca(int vetor[], int primElem, int segElem);
void selecaoTamanho(int garrafa[], int tamanhos[], int qtdeTamanhos, int qtdeGarrafas);

int main() {
  int qtdeTamanhos, qtdeGarrafas;
  
  scanf("%d", &qtdeTamanhos);
  int vetorTamanhos[qtdeTamanhos];
  for (int i=0; i<qtdeTamanhos ;i++){
    scanf("%d", &vetorTamanhos[i]);
  }
  insertion(vetorTamanhos, qtdeTamanhos);
  scanf("%d", &qtdeGarrafas);
  int vetorGarrafas[qtdeGarrafas];
  for (int i=0; i<qtdeGarrafas ;i++){
    scanf("%d", &vetorGarrafas[i]);
  }
  selecaoTamanho(vetorGarrafas, vetorTamanhos, qtdeTamanhos, qtdeGarrafas);
}

void insertion(int vetor[], int n){
  for (int i=1; i<n ;i++){
    int j=i;
    while (j>0 && vetor[j-1]>vetor[j]){
      troca(vetor, j-1, j);
      j--;
    }
  }
}

void troca(int vetor[], int primElem, int segElem){
  int temp;
  temp=vetor[primElem];
  vetor[primElem]=vetor[segElem];
  vetor[segElem]=temp;
}

void selecaoTamanho(int garrafa[], int tamanhos[], int qtdeTamanhos, int qtdeGarrafas){
  for (int i=0; i<qtdeGarrafas ;i++){  
    for (int j=0; j<qtdeTamanhos ;j++){
      if (garrafa[i]>tamanhos[qtdeTamanhos-1]){
        printf("descartar\n");
        break;
      }
      if (garrafa[i]<=tamanhos[j]){
        printf("%d\n", tamanhos[j]);
        break;
      }
    }
  }  
}