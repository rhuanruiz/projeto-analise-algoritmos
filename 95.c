#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 26

typedef struct{
    char nome[MAX];
    double valor;
} Produto;

void ordenarProdutos(Produto* produtos, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(produtos[i].valor > produtos[j].valor){
                Produto aux = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = aux;
            }
        }
    }
}

int main() {
    
    int n = 0, aux = 0;
    double D = 0.0, gasto = 0.0;

    scanf("%lf", &D);
    scanf("%d", &n);

    Produto produtos[n];

    for(int i = 0; i < n; i++){
        Produto p;
        scanf("%s", p.nome);
        scanf("%lf", &p.valor);
        produtos[i] = p;
    }
    
    while(gasto + produtos[aux].valor <= D && aux < n){
        gasto += produtos[aux].valor;
        aux++;
    }

    ordenarProdutos(produtos, n);
    
    for(int i = 0; i < aux; i++){
        printf("%s %.2lf\n", produtos[i].nome, produtos[i].valor);
    }
    
    printf("%.2lf", (D - gasto));

    return 0;
    
}
