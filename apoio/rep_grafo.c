#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1->2, 1->5, 2->3, 3->4, 4->1, 5->6*/
typedef struct aluno Aluno;
typedef struct aresta Aresta;
typedef struct vertice Vertice;

struct aluno {
  int matricula;
  char nome[60];
};

struct aresta {
  int id_vertice_destino;
  Aresta* proximo;
};

struct vertice {
  int id_vertice;
  Aresta* arestas;
  Aluno* aluno;
};

int main(){
  int i;
  char num[5];
  Vertice** grafo_lista = (Vertice**) malloc(10*sizeof(Vertice*));
  for(i = 0; i < 10; i++){
    char nome[20] = "Aluno-";
    grafo_lista[i] = (Vertice*) malloc(sizeof(Vertice));
    grafo_lista[i]->aluno = (Aluno*) malloc(sizeof(Aluno));
    grafo_lista[i]->aluno->matricula = i;
    sprintf(num,"%d", i);
    strcat(nome, num);
    strcpy(grafo_lista[i]->aluno->nome, nome);
    printf("%s\n", grafo_lista[i]->aluno->nome);
    grafo_lista[i]->arestas = NULL;
  }

  exit(0);
}
