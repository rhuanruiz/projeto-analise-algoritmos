#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n = 0;
    scanf("%d", &n); 

    int aux = 0, x[n], y[n];
    float d = 0.0, menor = 0.0;
    
    x[0] = 0;
    y[0] = 0;

    for(int i = 0; i < n; i++){
      scanf("%d %d", &x[i], &y[i]);
      if(i > 0){
        for(int j = 0; j < aux; j++){
          d = sqrt(pow(x[aux] - x[j], 2) + pow(y[aux] - y[j], 2));
          if(aux == 1){
            menor = d;
          }else if(d < menor){
            menor = d;
          }
        }
      }
      aux++;
    }

    printf("%.4f", menor);

    return 0;
}
  