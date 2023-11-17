#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(int moedas[], int esq, int meio, int dir){

    int n1 = (meio - esq) + 1;
    int n2 = dir - meio;
    int auxL[n1], auxR[n2];

    for(int i = 0; i < n1; i++){
        auxL[i] = moedas[esq + i];
    }
    for(int i = 0; i < n2; i++){
        auxR[i] = moedas[meio + 1 + i];
    }

    int i = 0, j = 0, k = esq;

    while(i < n1 && j < n2){
        if(auxL[i] >= auxR[j]){
            moedas[k] = auxL[i];
            i++;
        }else{
            moedas[k] = auxR[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        moedas[k] = auxL[i];
        i++;
        k++;
    }

    while(j < n2){
        moedas[k] = auxR[j];
        j++;
        k++;
    }

}

void mergeSort(int moedas[], int esq, int dir){

    int meio = 0;

    if(esq < dir){
        meio = esq + (dir - esq)/2;
    
        mergeSort(moedas, esq, meio);
        mergeSort(moedas, meio + 1, dir);
        merge(moedas, esq, meio, dir);
    }
}

int main() {

    int n = 0, gemeoPicareta = 0, gemeoDorminhoco = 0, menor = 0;

    scanf("%d", &n);

    int moedas[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &moedas[i]);
    }

    mergeSort(moedas, 0, n - 1);

    for(int i = 0; i < n; i++){
        gemeoPicareta += moedas[i];    
    }

    for(int i = 0; i < n; i++){
        gemeoDorminhoco += moedas[i];
        gemeoPicareta -= moedas[i];
        menor++;
        if(gemeoDorminhoco > gemeoPicareta){
            break;
        }   
    }

    printf("%d", menor);

	return 0;

}