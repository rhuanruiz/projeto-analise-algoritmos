#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void backtracking(int songs[], int M, int N, int atual, int pos, int *melhor, int sol[], int sol_atual[]) {
    if (atual > N){
        return ;
    }

    if (atual > *melhor){
        *melhor = atual;
        for (int i = 0; i < M; i++){
            sol[i] = sol_atual[i];
        }
    }

    if (pos >= M){
        return ;
    }

    sol_atual[pos] = 1;
    backtracking(songs, M, N, atual + songs[pos], pos + 1, melhor, sol, sol_atual);

    sol_atual[pos] = 0;
    backtracking(songs, M, N, atual, pos + 1, melhor, sol, sol_atual);
}


int main() {

    int N = 0, M = 0;
    
    while(scanf("%d %d", &N, &M) != EOF){
        
        int songs[M];
       
        for(int i = 0; i < M; i++){
            scanf("%d", &songs[i]);
        }

        for(int i = 0; i < M; i++){
            
        }

        int melhor = 0;
        int sol[M];
        int sol_atual[M];

        backtracking(songs, M, N, 0, 0, &melhor, sol, sol_atual);

        for(int i = 0; i < M; i++){
            if(sol[i]){
                printf("%d ", songs[i]);
            }
        }
        printf("sum:%d\n", melhor);
    }

	return 0;
}