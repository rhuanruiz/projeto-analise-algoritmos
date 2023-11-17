#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int tamanhoMaiorPali(char* str){
    int n = strlen(str), aux = 0;
    int din[n][n];
    
    if(n == 0){
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        din[i][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= (n - i); j++){
            aux = j + i - 1;
            if(str[j] == str[aux] && i == 2){
                din[j][aux] = 2;
            }else if(str[j] == str[aux]){
                din[j][aux] = din[j + 1][aux - 1] + 2;
            }else{
                if(din[j][aux - 1] > din[j + 1][aux]){
                    din[j][aux] = din[j][aux - 1];
                }else{
                    din[j][aux] = din[j + 1][aux];
                }
            }
        }
    }

    return din[0][n - 1];

}

int main() {

    int T = 0, maior_tam = 0;

    scanf("%d", &T);
    getchar();

    char palavras[T][1000];

    for(int i = 0; i < T; i++){
        fgets(palavras[i], sizeof(palavras[i]), stdin);
        palavras[i][strcspn(palavras[i], "\n")] = '\0';
    }

    for(int i = 0; i < T; i++){
        maior_tam = tamanhoMaiorPali(palavras[i]);
        printf("%d\n", maior_tam);
    }

	return 0;

}