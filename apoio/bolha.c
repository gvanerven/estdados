#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bolha (void *, int , int, int (*cmp)(void *, void *));

int compara_int(void*, void*);

void troca(void *, void *, int);

void * acessar(void*, int, int);

int main(){
  int i;
  int vetor[] = {3, 5, 9, 19, 11, 2, 6, 1, 0, -1};

  for(i = 0; i<10; i++){
    printf("%d\t", vetor[i]);
  }
  printf("\n");

  
  bolha(vetor, 10, sizeof(int), compara_int);
  
  for(i = 0; i<10; i++){
    printf("%d\t", vetor[i]);
  }
  printf("\n");
  
}

void bolha (void *vetor, int tam_vetor, int tam_estr, int (*cmp)(void *, void *)){
  int i,j, fez_troca;
  
  for(i = tam_vetor-1; i > 0; --i){
    fez_troca = 0;
    for(j = 0; j < i; ++j){
      void *e1 = acessar(vetor, j, tam_estr);
      void *e2 = acessar(vetor, j+1, tam_estr);
      if(cmp(e1, e2)) {
        troca(e1, e2, tam_estr);
        fez_troca = 1;
      }
    }
    if(fez_troca == 0){
      return;
    }
  }
}

void* acessar(void *vetor, int posicao, int tam_estr){
  char *t = (char *) vetor;
  return (void *)(t + (tam_estr*posicao));
}
void troca(void *a, void *b, int tam_estr){
  void *tmp = malloc(tam_estr);
  memcpy(tmp, a, tam_estr);
  memcpy(a, b, tam_estr);
  memcpy(b, tmp, tam_estr);
  free(tmp);
}

int compara_int(void *a, void *b){
  int *x = (int*) a;
  int *y = (int*) b;
  if((*x) > (*y) ){
    return 1;
  }
  return 0;
}
