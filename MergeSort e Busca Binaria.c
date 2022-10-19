// João Pedro Moro Bolognini
// Encaixe das pocoes, descartando os menores, utilizando MergeSort e Busca Binaria.

#include <stdio.h>

void inicVetAux(long vetor[], long qtdeTamanhos);
void merge(long vetor[], long vetorAux[], long imin, long imid, long imax);
void mergeSort(long vetor[], long vetorAux[], long imin, long imax);
void selecionarTamanho(long garrafas[], long tamanhos[], long qtdeTamanhos, long qtdeGarrafas);
long buscaBinaria(long vetorTamanhos[], long garrafa, long qtdeTamanhos);

int main() {
  long qtdeTamanhos, qtdeGarrafas;
  
  scanf("%ld", &qtdeTamanhos);
  long vetorTamanhos[qtdeTamanhos];
  for (long i=0; i<qtdeTamanhos ;i++){
    scanf("%ld", &vetorTamanhos[i]);
  }
  inicVetAux(vetorTamanhos, qtdeTamanhos);
  scanf("%ld", &qtdeGarrafas);
  long vetorGarrafas[qtdeGarrafas];
  for (long i=0; i<qtdeGarrafas ;i++){
    scanf("%ld", &vetorGarrafas[i]);
  }
  selecionarTamanho(vetorGarrafas, vetorTamanhos, qtdeTamanhos, qtdeGarrafas);
  return 0;
}

void inicVetAux(long vetor[], long qtdeTamanhos){
  long vetAux[qtdeTamanhos];
  mergeSort(vetor, vetAux, 0, qtdeTamanhos-1);
}

void merge(long vetor[], long vetorAux[], long imin, long imid, long imax){
  long i=imin, j=imid+1;
  for (long x=imin; x<=imax ;x++){
    vetorAux[x]=vetor[x];
  }
  for (long x=imin; x<=imax ;x++){
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

void mergeSort(long vetor[], long vetorAux[], long imin, long imax){
  if (imax<=imin){
    return;
  }
  long imid=imin+((imax-imin)/2);
  mergeSort(vetor, vetorAux, imin, imid);
  mergeSort(vetor, vetorAux, imid+1, imax);
  merge(vetor, vetorAux, imin, imid, imax);
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