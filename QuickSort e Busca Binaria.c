// João Pedro Moro Bolognini
// Encaixe das pocoes, descartando os menores, utilizando QuickSort e a Busca Binaria, o programa é ineficiente.
// Código útil para o código pronto do algoritmo QuickSort.

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void quicksort(long vetor[], long imin, long imax);
long partition(long vetor[], long imin, long imax);
void swap(long vetor[], long a, long b);
void selecionarTamanho(long garrafas[], long tamanhos[], long qtdeTamanhos, long qtdeGarrafas);
long buscaBinaria(long vetorTamanhos[], long garrafa, long qtdeTamanhos);

int main() {
  long qtdeTamanhos, qtdeGarrafas;

  scanf("%ld", &qtdeTamanhos);
  long vetorTamanhos[qtdeTamanhos];
  for (long i=0; i<qtdeTamanhos ;i++){
    scanf("%ld", &vetorTamanhos[i]);
  }

  quicksort(vetorTamanhos, 0, qtdeTamanhos-1);

  scanf("%ld", &qtdeGarrafas);
  long vetorGarrafas[qtdeGarrafas];
  for (long i=0; i<qtdeGarrafas ;i++){
    scanf("%ld", &vetorGarrafas[i]);
  }
  selecionarTamanho(vetorGarrafas, vetorTamanhos, qtdeTamanhos, qtdeGarrafas);
  return 0;
}

void quicksort(long vetor[], long imin, long imax){
  if (imax <= imin){
    return;
  }
  long i=partition(vetor, imin, imax);
  quicksort(vetor, imin, i-1);
  quicksort(vetor, i+1, imax);
}

long partition(long vetor[], long imin, long imax){
  long i, j=imax+1;
  srand(time(NULL));
  
  // gerando valor aleatorio na faixa de 0 a imax para ser o pivo.
  i=rand() % (imax);

  while (1){
    while(vetor[++i]<vetor[imin]){
      if (i==imax){
        break;
      }  
    }
    while (vetor[imin]<vetor[--j]){
      if (j==imin){
        break;
      }
    }
    if (i>=j){
      break;
    }
    swap(vetor, i, j);
  }
  swap(vetor, imin, j);
  return j;
}

void swap(long vetor[], long a, long b){
  long temp;
  temp=vetor[a];
  vetor[a]=vetor[b];
  vetor[b]=temp;
}

void selecionarTamanho(long garrafas[], long tamanhos[], long qtdeTamanhos, long qtdeGarrafas){
  for (long i=0; i<qtdeGarrafas ;i++){
    if (garrafas[i]<tamanhos[0]){ 
      printf("descartar\n");  // Como a garrafa tem tamanho menor que o menor tamanho, é descartada.
    } else {
      if (garrafas[i]>tamanhos[qtdeTamanhos-1]){
        printf("%ld\n", tamanhos[qtdeTamanhos-1]); // Como a garrafa tem tamanho maior que o tamanho maximo, usa-se esse tamanho.
      } else {
        long resposta=buscaBinaria(tamanhos, garrafas[i], qtdeTamanhos);
        printf("%ld\n", resposta);
      }
    }
  }
}

long buscaBinaria(long vetorTamanhos[], long garrafa, long qtdeTamanhos){
  long iMax=qtdeTamanhos-1;
  long iMin=0;
  while (iMax>=iMin){
    long iMid=iMin+((iMax-iMin)/2);
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