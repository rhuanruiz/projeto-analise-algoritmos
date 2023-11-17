#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n1 = 0, n2 = 0, aux = 0;
    scanf("%d %d", &n1, &n2);

    int L1[n1], L2[n2], L3[n1 + n2];

    L1[0] = 0;
    L2[0] = 0;
    L3[0] = 0;

    for(int i = 0; i < n1; i++){
        scanf("%d", &L1[i]);
    }
    for(int i = 0; i < n2; i++){
        scanf("%d", &L2[i]);
    }

    int i = 0,  j = 0;

    while (i < n1 && j < n2){
        if (L1[i] < L2[j]){
            L3[aux] = L1[i];
            aux++;
            i++;
        }else{
            L3[aux] = L2[j];
            aux++;
            j++;
        }
    }
  
    while (i < n1){
        L3[aux] = L1[i];
        aux++;
        i++;
    }
    
    while (j < n2){
        L3[aux] = L2[j];
        aux++;
        j++;
    }

    for(int i = 0; i < (n1 + n2); i++){
        printf("%d\n", L3[i]);
    }

	return 0;
}