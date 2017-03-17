#include <stdio.h>
#include <stdlib.h>

int main(void){
  int a;
  int *p;
  int **q;
  
  a = 10;
  p = &a;
  q = &p;
  
  printf("Endereço de a: 0x%08x\n", &a);
  printf("Endereço apontado por p: 0x%08x\n", p);
  printf("Endereço apontado por q: 0x%08x\n", q);
  printf("Endereço de p: 0x%08x\n", &p);
  printf("Endereço de q: 0x%08x\n", &q);
  printf("Valor no endereço apontado por p: %d\n", *p);
  printf("Valor no endereço apontado por q: 0x%08x\n", *q);
  printf("Valor no endereço indiretamente apontado por q: %d\n", **q);
  printf("Valor de a: %d\n", a);

  *p = 5;
  printf("Novo valor no endereço apontado por p: %d\n", *p);
  printf("Novo valor no endereço indiretamente apontado por q: %d\n", **q);
  printf("Novo valor de a: %d\n", a);
  
  
  int *vetor = (int*) malloc(10*sizeof(int));
  
  vetor[0] = 10;
  vetor[5] = 25;
  
  printf("Valor de v[0]: %d\n", vetor[0]);
  printf("Valor de v[5]: %d\n", vetor[5]);
  printf("Valor de v[5] (com *): %d\n", *(vetor+5));
  printf("Acessando memória inválida: %d\n", vetor[11]);
  
  free(vetor);
  
  printf("Acessando memória inválida depois do free %d\n", vetor[0]);

  exit(0);
  
}
