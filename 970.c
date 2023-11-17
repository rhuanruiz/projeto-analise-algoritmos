#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 300

int buscarSeq(char* A, int tam_A, int i_A, char* B, int tam_B, int i_B, int* ok, int indice){
    
    if(i_B == tam_B){
        for(int i = 0; i < indice; i++){
            printf("%d", ok[i]);
            if(i < indice - 1){
                printf(" ");
            }
        }
        printf("\n");
        return 1;
    }
    
    int aux = 0;
    for(int i = i_A; i < tam_A; i++){
        if(A[i] == B[i_B]){
            ok[indice] = i + 1;
            aux |= buscarSeq(A, tam_A, i + 1, B, tam_B, i_B + 1, ok, indice + 1);
        }
    }
    
    return aux;
    
}

int main() {
    
    char A[MAX], B[MAX];
    int ok[MAX] = {0};

    fgets(A, sizeof(A), stdin);
    A[strcspn(A, "\n")] = '\0';

    fgets(B, sizeof(B), stdin);
    B[strcspn(B, "\n")] = '\0';

    int tam_A = strlen(A);
    int tam_B = strlen(B);
    
    int aux = buscarSeq(A, tam_A, 0, B, tam_B, 0, ok, 0);
    
    if(!aux){
        printf("-1\n"); 
    }

    return 0;
    
}
