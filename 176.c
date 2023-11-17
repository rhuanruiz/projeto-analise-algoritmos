#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50

void bubbleSort(int habilidades[], char alunos[][MAX], int N){
    
    int aux = 0;
    char aux2[MAX];
    
    for(int i = 0; i < (N - 1); i++){
        for(int j = 0; j < (N - i - 1); j++){
            strcpy(aux2, "");
            if(((int*)habilidades[j + 1] - (int*)habilidades[j]) > 0){
                aux = habilidades[j];
                habilidades[j] = habilidades[j + 1];
                habilidades[j + 1] = aux;
                
                strcpy(aux2, alunos[j]);
                strcpy(alunos[j], alunos[j + 1]);
                strcpy(alunos[j + 1], aux2);
            }
        }
    }
    
}

void distribuirJogadores(int T, int N, char times[][N/T + 1][MAX], int cont[], char alunos[][MAX]){
    
    int aux = 0;
    
    for(int i = 0; i < T; i++){
        cont[i] = 0;
    }
    
    for(int i = 0; i < N; i++){
        strcpy(times[i % T][cont[i % T]], alunos[aux]);
        cont[i % T]++;
        aux++;
    }
       
}

void ordenarAlunos(char times[][MAX], int n) {
    
    char aux[MAX];
    
    for(int i = 0; i < (n - 1); i++){
        for(int j = 0; j < (n - i - 1); j++){
            if(strcmp(times[j], times[j + 1]) > 0) {
                strcpy(aux, times[j]);
                strcpy(times[j], times[j + 1]);
                strcpy(times[j + 1], aux);
            }
        }
    }
    
}

int main() {

    int T = 0, N = 0;
    
    scanf("%d %d", &N, &T);

    int habilidades[N], cont[T];
    char alunos[N][MAX], times[T][N/T + 1][MAX];

    for(int i = 0; i < N; i++){
        scanf("%s %d", alunos[i], &habilidades[i]);
    }

    bubbleSort(habilidades, alunos, N);
    distribuirJogadores(T, N, times, cont, alunos);

    for(int i = 0; i < T; i++){
        printf("Time %d\n", i + 1);
        ordenarAlunos(times[i], cont[i]);
        for(int j = 0; j < cont[i]; j++){
            printf("%s\n", times[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}
