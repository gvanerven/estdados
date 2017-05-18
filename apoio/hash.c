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

}

int func_hash(Hash* tab, int matricula){

}

void insere_hash(Hash* tab, Aluno* aluno){

}

void redimenciona(Hash* tab){
  
}

Aluno* recupera_hash(Hash* tab, int matricula){

}

void libera_tudo(Hash* tab){

}

int main(){
  Aluno* b;
  Aluno* a = (Aluno*) malloc(sizeof(Aluno));
  a->matricula = 100;
  strcpy(a->nome, "Teste");
  printf("a -> %s\n", a->nome);
  //Hash* tab = cria_hash();
  
  //insere_hash(tab, a);
  //b = recupera_hash(tab, a->matricula);
  //printf("b -> %s\n", b->nome);
  //if(!recupera_hash(tab, 19)){
  //  printf("Sem chave\n");
  //}
  //libera_tudo(tab);
  exit(0);
}
