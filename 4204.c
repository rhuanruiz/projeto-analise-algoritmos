#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {

    while (1){

        int n = 0, cont = 0, aux1 = 0, aux2 = 0;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        int p[n];
        p[0] = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }
        
        aux1 = n - 1;
        while(aux1 > 0){
            for(int i = 0; i < aux1; i++){
                if(p[i] > p[i+1]){
                    aux2 = p[i];
                    p[i] = p[i+1];
                    p[i+1] = aux2;
                    cont++;
                }
            }  
            aux1--;  
        }

        if(cont%2 == 0){
            printf("Carlos\n");
        }else{
            printf("Marcelo\n");
        }
    }

    return 0;

}
