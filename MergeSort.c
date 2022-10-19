// João Pedro Moro Bolognini
// Programa utilizando MergeSort.

#include <stdio.h>

void selecaoTamanho(int garrafa[], int tamanhos[], int qtdeTamanhos, int qtdeGarrafas);
void merge(int vetor[], int vetorAux[], int imin, int imid,int imax);
void mergeSort(int vetor[], int vetorAux[], int imin, int imax);

int main() {
  int qtdeTamanhos, qtdeGarrafas;
  
  scanf("%d", &qtdeTamanhos);
  int vetorTamanhos[qtdeTamanhos], vetorTamanhosAux[qtdeTamanhos];
  for (int i=0; i<qtdeTamanhos ;i++){
    scanf("%d", &vetorTamanhos[i]);
  }
  mergeSort(vetorTamanhos, vetorTamanhosAux, 0, qtdeTamanhos-1);
  scanf("%d", &qtdeGarrafas);
  int vetorGarrafas[qtdeGarrafas];
  for (int i=0; i<qtdeGarrafas ;i++){
    scanf("%d", &vetorGarrafas[i]);
  }
  selecaoTamanho(vetorGarrafas, vetorTamanhos, qtdeTamanhos, qtdeGarrafas);
}

void merge(int vetor[], int vetorAux[], int imin, int imid,int imax){
  int i=imin, j=imid+1;
  for (int x=imin; x<=imax ;x++){
    vetorAux[x]=vetor[x];
  }
  for (int x=imin; x<=imax ;x++){
    if (i>imid){
      vetor[x]=vetorAux[j++];
    } else {
      if (j>imax){
        vetor[x]=vetorAux[i++];
      } else {
        if (vetorAux[j]<vetorAux[i]){
          vetor[x]=vetorAux[j++];
        } else {
          vetor[x]=vetorAux[i++];
        }
      }
    }
  }
}

void mergeSort(int vetor[], int vetorAux[], int imin, int imax){
  if (imax<=imin){
    return;
  }
  int imid=imin+((imax-imin)/2);
  mergeSort(vetor, vetorAux, imin, imid);
  mergeSort(vetor, vetorAux, imid+1, imax);
  merge(vetor, vetorAux, imin, imid, imax);
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