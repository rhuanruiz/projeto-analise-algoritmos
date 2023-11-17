#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int n;
	int* elements;
} t_vector;

t_vector repetidas(t_vector album, t_vector novas){
t_vector reps;
    int inicio, fim, aux, aux2 = 0, j = 0;

    if(album.n < novas.n){
        reps.n = 0;
        reps.elements = (int*)malloc((album.n+1)*sizeof(int));

        for(int i = 0; i < album.n; i++){
            inicio = 0;
            fim = novas.n - 1;
            aux = 0;

            while(inicio <= fim){
                aux = (inicio + fim)/2;
                if(novas.elements[aux] == album.elements[i]){
                    aux2++;
                    break;
                }
                if(novas.elements[aux] < album.elements[i]){
                    inicio = aux + 1;
                }else{
                    fim = aux - 1;
                }
            }
            
            if(aux2 == 1){
                reps.elements[j] = novas.elements[aux];
                reps.n++;
                j++;
                aux2--;
            }
        }
        return reps;
    }else{
        reps.n = 0;
        reps.elements = (int*)malloc((novas.n+1)*sizeof(int));

        for(int i = 0; i < novas.n; i++){
            inicio = 0;
            fim = album.n - 1;
            aux = 0;

            while(inicio <= fim){
                aux = (inicio + fim)/2;
                if(album.elements[aux] == novas.elements[i]){
                    aux2++;
                    break;
                }
                if(album.elements[aux] < novas.elements[i]){
                    inicio = aux + 1;
                }else{
                    fim = aux - 1;
                }
            }
            
            if(aux2 == 1){
                reps.elements[j] = album.elements[aux];
                reps.n++;
                j++;
                aux2--;
            }
        }
        return reps;
    }
} 

int main() {
	int i, j, k;
	t_vector album, novas, reps;
	scanf("%d", &album.n);
	album.elements = (int*)malloc((album.n+1)*sizeof(int));
	for(i = 0; i < album.n; i++){
		scanf("%d", &(album.elements[i]));
	}
	album.elements[i] = INT_MAX;
	
	scanf("%d", &novas.n);
	novas.elements = (int*)malloc((novas.n+1)*sizeof(int));
	for(i = 0; i < novas.n; i++){
		scanf("%d", &(novas.elements[i]));
	}
	novas.elements[i] = INT_MAX;
	
	reps = repetidas(album, novas);
	
	for(k = 0; k < reps.n-1; k++)
	  printf("%d ", reps.elements[k]);
	printf("%d\n", reps.elements[k]);
	
	free(reps.elements);
	free(album.elements);
	free(novas.elements);
	
	return 0;
}
