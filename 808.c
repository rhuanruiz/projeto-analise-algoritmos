#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int backtracking(int i, int P[], int L, int M, int Q, int R, int soma, int qtd){
    
    if(soma > Q || qtd > L){
        return R;
    }

    if(qtd >= M && soma <= Q){
        R++;
    }

    for(int j = i; j < L; j++){
        R = backtracking(j + 1, P, L, M, Q, R, soma + P[j], qtd + 1);
    }
    
    return R;
    
}

int main() {
    
    int K = 0;

    scanf("%d", &K);

    int resultados[K];

    for(int i = 0; i < K; i++){

        int L = 0, M = 0, Q = 0, R = 0;

        scanf(" %d", &L);

        int P[L];

        for(int j = 0; j < L; j++){
            scanf("%d", &P[j]);
        }

        scanf("%d %d", &M, &Q);
        
        R = backtracking(0, P, L, M, Q, R, 0, 0);
        resultados[i] = R;
    }

    for(int i = 0; i < K; i++){
        printf("caso %d: %d\n", i, resultados[i]);
    }

    return 0;
    
}
