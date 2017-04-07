#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int i;
  int *vetor;
  int min = 4;
  int max = 10;
  int *v;
  int *aux;
  
  vetor = (int *) malloc(min*sizeof(int));
  
  for(i = 0; i < min; ++i){
    vetor[i] = i;
    printf("%d\t", vetor[i]);
  }
  printf("\n");
  
  aux = vetor;
  v = (int *) malloc(max*sizeof(int));
  memcpy(v, vetor, min*sizeof(int));
  vetor = v;
  free(aux);
  
  for(i = min; i < max; ++i){
    vetor[i] = i;
    printf("%d\t", vetor[i]);
  }  
  printf("\n");

  for(i = 0; i < max; ++i){
    vetor[i] = i;
    printf("%d\t", vetor[i]);
  }
  printf("\n");

  
}