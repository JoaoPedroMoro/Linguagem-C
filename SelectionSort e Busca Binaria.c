// João Pedro Moro Bolognini
// RA: 792185
// Encaixe das pocoes, descartando os menores, utilizando SelectionSort e Busca Binaria.

#include <stdio.h>

void selectionSort(int vetor[], int n);
void troca(int vetor[], int i, int minimo);
void selecionarTamanho(int garrafas[], int tamanhos[], int qtdeTamanhos, int qtdeGarrafas);
int buscaBinaria(int vetorTamanhos[], int garrafa, int qtdeTamanhos);

int main() {
  int qtdeTamanhos, qtdeGarrafas;
  
  scanf("%d", &qtdeTamanhos);
  int vetorTamanhos[qtdeTamanhos];
  for (int i=0; i<qtdeTamanhos ;i++){
    scanf("%d", &vetorTamanhos[i]);
  }
  selectionSort(vetorTamanhos, qtdeTamanhos);
  scanf("%d", &qtdeGarrafas);
  int vetorGarrafas[qtdeGarrafas];
  for (int i=0; i<qtdeGarrafas ;i++){
    scanf("%d", &vetorGarrafas[i]);
  }
  selecionarTamanho(vetorGarrafas, vetorTamanhos, qtdeTamanhos, qtdeGarrafas);
  return 0;
}

void selectionSort(int vetor[], int n){
  for (int i=0; i<n-1 ; i++){
    int minimo=i;
    for(int j=i+i; j<n ;j++){
      if (vetor[j]<vetor[minimo]){
        minimo=j;
      }
    }
    troca(vetor, i, minimo);
  }
}

void troca(int vetor[], int i, int minimo){
  int temp;
  temp=vetor[i];
  vetor[i]=vetor[minimo];
  vetor[minimo]=temp;
}

void selecionarTamanho(int garrafas[], int tamanhos[], int qtdeTamanhos, int qtdeGarrafas){
  for (int i=0; i<qtdeGarrafas ;i++){
    if (garrafas[i]<tamanhos[0]){ 
      printf("descartar\n");  // Como a garrafa tem tamanho menor que o menor tamanho, é descartada.
    } else {
      if (garrafas[i]>tamanhos[qtdeTamanhos-1]){
        printf("%d\n", tamanhos[qtdeTamanhos-1]); // Como a garrafa tem tamanho maior que o tamanho maximo, usa-se esse tamanho.
      } else {
        int resposta=buscaBinaria(tamanhos, garrafas[i], qtdeTamanhos);
        printf("%d\n", resposta);
      }
    }
  }
}

int buscaBinaria(int vetorTamanhos[], int garrafa, int qtdeTamanhos){
  int iMax=qtdeTamanhos-1;
  int iMin=0;
  while (iMax>=iMin){
    int iMid=iMin+((iMax-iMin)/2);
    if (garrafa>vetorTamanhos[iMid]){
      if (garrafa<vetorTamanhos[iMid+1]){
        return vetorTamanhos[iMid]; // Caso o tamanho da garrafa seja maior que o tamanho do meio e seja menor que o tamanho do meio+1, o tamanho do meio e usado.
      } else {
        iMin=iMid+1;
      }
    } else {
      if (garrafa<vetorTamanhos[iMid]){
        if (garrafa>vetorTamanhos[iMid-1]){
          return vetorTamanhos[iMid-1]; // Caso o tamanho da garrafa seja menor que o tamanho do meio e maior que o tamanho do meio-1, o tamanho do meio-1 e usado.
        } else {
          iMax=iMid-1;
        }  
      } else {
        return vetorTamanhos[iMid];
      }
    }
  }
  return vetorTamanhos[iMin];
}