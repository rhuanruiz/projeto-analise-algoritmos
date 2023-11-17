#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n = 0, m = 0, aux, aux2 = 0;
    scanf("%d", &n);
    
    int cpf[n], nota[n], inicio, fim;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &cpf[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &nota[i]);
    }
    
    scanf("%d", &m);
    int caso[m];
    
    for(int i = 0; i < m; i++){
        scanf("%d", &caso[i]);
    }
    
    for(int i = 0; i < m; i++){

        inicio = 0;
        fim = n - 1;
        aux = 0;

        while(inicio <= fim){

            aux = (inicio + fim)/2;

            if(cpf[aux] == caso[i]){
                aux2++;
                break;
            }
            if(cpf[aux] < caso[i]){
                inicio = aux + 1;
            }else{
                fim = aux - 1;
            }
        }

        if(aux2 == 1){
            printf("%d\n",nota[aux]);
            aux2--;
        }else{
            printf("NAO SE APRESENTOU\n");
        }

    }

	return 0;

}