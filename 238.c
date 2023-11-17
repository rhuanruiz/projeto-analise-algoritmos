#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int validarPos(int x, int y, int n){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void backtracking(int** tab, int n, int x, int y, int custo, int* percurso, int* custo_min, int* per_min){

    int dx[] = {1, 1, 1};
    int dy[] = {-1, 0, 1};
    int x_prox = 0, y_prox = 0;
    
    if(x == n -1){
        if(custo < *custo_min){
            *custo_min = custo;
            memcpy(per_min, percurso, n * sizeof(int));
        }
        return ;
    }

    for(int i = 0; i < 3; i++){
        x_prox = x + dx[i];
        y_prox = y + dy[i];

        if(validarPos(x_prox, y_prox, n)){
            percurso[x_prox] = y_prox;
            backtracking(tab, n, x_prox, y_prox, custo + tab[x_prox][y_prox], percurso, custo_min, per_min);
        }
    }

}


int main() {
    
    int n = 0, custo_min = INT_MAX;

    scanf("%d", &n);

    int *percurso = malloc (n* sizeof(int));
    int *per_min = malloc(n* sizeof(int));

    int **tabuleiro = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        tabuleiro[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &tabuleiro[i][j]);
        }
    }

    for(int j = 0; j < n; j++){
        memset(percurso, -1, n * sizeof(int));
        percurso[0] = j;
        backtracking(tabuleiro, n, 0, j, tabuleiro[0][j], percurso, &custo_min, per_min);
    }
    
    printf("%d\n", custo_min);
    for(int i = n-1; i >= 0; i--){
        if(i == 0){
            printf("[%d,%d]", i, per_min[i]);
        }else{
            printf("[%d,%d] <- ", i, per_min[i]);
        }
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    free(percurso);
    free(per_min);

    return 0;
    
}
