#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calcularMaior(int p[], int w[], int n, int g, int m){

    int din[31] = {0}, r = 0;

    for(int i = 0; i < n; i++){
        for(int j = m; j >= w[i]; j--){
            if(din[j] < din[j - w[i]] + p[i]){
                din[j] = din[j - w[i]] + p[i];
            }
        }
    }

    for(int i = 0; i < g; i++){
        int m = 0;
        scanf("%d", &m);
        r += din[m];
    }

    return r;

}

int main() {
    
    int T = 0;

    scanf("%d", &T);

    int resultados[T];

    for(int i = 0; i < T; i++){

        int n = 0, g = 0;

        scanf("%d", &n);

        int p[n], w[n];

        for(int j = 0; j < n; j++){
            scanf("%d %d", &p[j], &w[j]);
        }

        scanf("%d", &g);

        resultados[i] = calcularMaior(p, w, n, g, 30);

    }

    for(int i = 0; i < T; i++){
        printf("%d\n", resultados[i]);
    }
    printf("\n");

    return 0;
    
}
