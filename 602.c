#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int din(int *p, int **memo, int inicio, int fim, int ano){

    int esq, dir;

    if(memo[inicio][fim] != -1){
        return memo[inicio][fim];
    }else if(inicio == fim){
        memo[inicio][fim] = p[inicio] * ano;
    }else{
        esq = p[inicio] * ano + din(p, memo, inicio + 1, fim, ano + 1);
        dir = p[fim] * ano + din(p, memo, inicio, fim - 1, ano + 1);
        if(esq > dir){
            memo[inicio][fim] = esq;
        }else{
            memo[inicio][fim] = dir;
        }
    }
    return memo[inicio][fim];
}

int main() {

    int n = 0;

    while(scanf("%d", &n) == 1){

        int p[n], valor = 0;
        int **memo = malloc(n * sizeof(int *));

        for(int i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }

        for(int i = 0; i < n; i++){
            memo[i] = malloc(n * sizeof(int));
            for(int j = 0; j < n; j++){
                memo[i][j] = -1;
            }
        }

        valor = din(p, memo, 0, n-1, 1);
        printf("%d\n", valor);

        for (int i = 0; i < n; i++) {
            free(memo[i]);
        }
        free(memo);
    }  
	return 0;
}