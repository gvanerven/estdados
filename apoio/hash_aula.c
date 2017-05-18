#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_INICIAL 7;

typedef struct aluno {
  int matricula;
  char nome[60];
} Aluno;

typedef struct hash {
  int n; //num elementos
  int dim; //tamanho da tabela
  Aluno** v; //ponteiro para a tabela
} Hash;

Hash* cria_hash(){
  int i;
  Hash* tab = (Hash*) malloc(sizeof(Hash));
  tab->v = (Aluno**) malloc(sizeof(Aluno*));
  tab->n = 0;
  tab->dim = TAM_INICIAL;
  for(i = 0; i < tab->dim; i++) {
    tab->v[i] = NULL;
  }
  return tab;
}

int func_hash(Hash* tab, int matricula){
  return matricula % tab->dim;
}

void insere_hash(Hash* tab, Aluno* aluno){
  int h;
  h = func_hash(tab, aluno->matricula);
  while(tab->v[h] != NULL) {
    h = (h+1) % tab->dim;
  }
  tab->v[h] = aluno;
  tab->n++;

}

void redimenciona(Hash* tab){
  
}

Aluno* recupera_hash(Hash* tab, int matricula){
  int h;
  h = func_hash(tab, matricula);
  Aluno* aluno = tab->v[h];
    
       while(aluno != NULL && aluno->matricula != matricula) {
          h = (h+1) % tab->dim;
  
         aluno = tab->v[h];

    }
    return aluno;
}

void libera_tudo(Hash* tab){
  for(int i = 0; i < tab->dim; i++) {
    free(tab->v[i]);
  }
    //free(tab->v);
    free(tab);
}

int main(){
  Aluno* b;
  Aluno* a = (Aluno*) malloc(sizeof(Aluno));
  a->matricula = 100;
  strcpy(a->nome, "Teste");
  printf("a -> %s\n", a->nome);
  Hash* tab = cria_hash();
  printf("tab %d\n", tab->dim);
  insere_hash(tab, a);
  printf("tab %d\n", tab->n);
  b = recupera_hash(tab, a->matricula);
  printf("b -> %s\n", b->nome);
  if(!recupera_hash(tab, 19)){
    printf("Sem chave\n");
  }
  libera_tudo(tab);
  exit(0);
}
