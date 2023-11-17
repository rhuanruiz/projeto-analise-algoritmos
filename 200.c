#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void selectionSort(int inicio[], int termino[], int n){
    int aux = 0;
    for(int i = 0; i < (n - 1); i++){
        for(int j = (i + 1); j < n; j++){
            if(inicio[i] > inicio[j]){
                aux = inicio[i];
                inicio[i] = inicio[j];
                inicio[j] = aux;
                aux = termino[i];
                termino[i] = termino[j];
                termino[j] = aux;
            }
        }
    }
}

int main() {

    int n = 0, qtd_max = 1, aux = 0;

    scanf("%d", &n);

    int inicio[n], termino[n];

    for(int i = 0; i < n; i++){
        scanf("%d %d", &inicio[i], &termino[i]);
    }

    selectionSort(inicio, termino, n);

    aux = termino[0];

    for(int i = 1; i < n; i++){
        if(inicio[i] >= aux){
            qtd_max++;
            aux = termino[i];
        }else if(termino[i] < aux){
            aux = termino[i];
        }
    }

    printf("%d", qtd_max);

	return 0;

}