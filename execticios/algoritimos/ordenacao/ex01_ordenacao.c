#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *vetor, int n){
}

int main(void){
    int vetor[5] = {2, 9, 5, 38, 17};

    insertion_sort(vetor, 5);

    for(int i = 0; i < 5; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");
    
    exit(0);
}
