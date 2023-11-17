#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(int x[], int y[], int esq, int meio, int dir){

    int i = esq, j = meio, k = 0, aux = 0, temp[dir-esq], temp2[dir-esq];

    while(i < meio && j < dir){
        if(x[i] <= x[j]){
            temp[k] = x[i];
            temp2[k] = y[i];
            k++;
            i++;
        }else{
            temp[k] = x[j];
            temp2[k] = y[j];
            k++;
            j++;
            aux += meio - i;
        }
    }
    while(i < meio){
        temp[k] = x[i];
        temp2[k] = y[i];
        i++;
        k++;
    } 
    while(j < dir){
        temp[k] = x[j];
        temp2[k] = y[j];   
        j++;
        k++;
    } 
    for (i = esq; i < dir; i++){
        x[i] = temp[i-esq];
        y[i] = temp2[i-esq];
    }
}

void mergeSort(int x[], int y[], int esq, int dir){

    int meio = 0, aux = dir - 1;

    if(esq < aux){
        meio = esq + (dir - esq)/2;
        mergeSort(x, y, esq, meio);
        mergeSort(x, y, meio, dir);
        merge(x, y, esq, meio, dir);
    }
}

int main() {

    int caso = 0, n = 0, aux = 0;

    scanf("%d", &caso);

    while(aux < caso){

        scanf("%d", &n);
        int x[n], y[n];

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x[i], &y[i]);
        }

        mergeSort(x, y, 0, n);

        
        double maior = 0.0, dist = 0.0, m = 0.0, c = 0.0;

        for(int i = n - 1; i >= 0; --i){
            if( y[i] > maior ){ 
                m = (double)(y[i+1] - y[i])/(x[i+1] - x[i]);
                c = y[i] - (m*x[i]);
                dist += sqrt(pow(((maior-c)/m) - x[i], 2) + pow(y[i] - maior, 2));
				maior = y[i];
			}
        }

        printf("%.2lf\n", dist);
        aux++;   
    }

	return 0;
}