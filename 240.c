#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int merge(int p[], int esq, int meio, int dir){

    int i = esq, j = meio, k = 0, aux = 0, temp[dir-esq];

    while(i < meio && j < dir){
        if(p[i] <= p[j]){
            temp[k] = p[i];
            k++;
            i++;
        }else{
            temp[k] = p[j];
            k++;
            j++;
            aux += meio - i;
        }
    }
    while(i < meio){
        temp[k] = p[i];
        i++;
        k++;
    } 
    while(j < dir){
        temp[k] = p[j];   
        j++;
        k++;
    } 
    for (i = esq; i < dir; i++){
        p[i] = temp[i-esq];
    }

    return aux;
}

int mergeSort(int p[], int esq, int dir){

    int meio = 0, aux = dir - 1, i = 0, j = 0, k = 0;

    if(esq < aux){
        meio = esq + (dir - esq)/2;
        i = mergeSort(p, esq, meio);
        j = mergeSort(p, meio, dir);
        k = merge(p, esq, meio, dir);
    }

    return i + j + k;
}

int main() {

    while (1){
        int n = 0, cont = 0, aux2 = 0;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        int p[n];
        p[0] = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }
    
        cont = mergeSort(p, 0, n);
    
        if(cont%2 == 0){
            printf("Carlos\n");
        }else{
            printf("Marcelo\n");
        }
    }

    return 0;
}
