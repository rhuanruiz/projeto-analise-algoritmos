#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int dinheiroRoubado(int joias[], int n){

    int din1 = 0, din2 = 0, max = 0;

    if(n <= 0){
        return 0;
    }

    int* dp = (int*)malloc((n + 1) * sizeof(int));

    dp[0] = 0;
    dp[1] = joias[0];

    for(int i = 2; i <= n; i++){
        din1 = joias[i - 1] + dp[i - 3];
        din2 = dp[i - 1];
        dp[i] = (din1 > din2) ? din1 : din2;
    }

    max = dp[n];
    free(dp);
    return max;

}

int main() {
    
    int n;
    
    scanf("%d", &n);
    
    int joias[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &joias[i]);
    }
    
    printf("%d", dinheiroRoubado(joias, n));

    return 0;
    
}