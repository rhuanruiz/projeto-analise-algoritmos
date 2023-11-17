#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int validarPos(int a, int b, int n, int m){
    return (a >= 0 && a < n && b >= 0 && b < m);
}

void saida(char** lab, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c", lab[i][j]);
        }
        printf("\n");
    }
}

int percorrerLab(char** lab, int n, int m, int a, int b, char* mov, int* cont){
   
    if(a == (n - 1) && b == (m - 1)){
        lab[a][b] = 'O';
        return 1;
    }
    
    if(validarPos(a, b, n, m) && lab[a][b] == '.'){
        lab[a][b] = '*'; 

        if(percorrerLab(lab, n, m, a - 1, b, mov, cont)){
            lab[a][b] = '^'; 
            mov[(*cont)++] = 'U';
            return 1;
        }
        if(percorrerLab(lab, n, m, a + 1, b, mov, cont)){
            lab[a][b] = 'v'; 
            mov[(*cont)++] = 'D';
            return 1;
        }
        if(percorrerLab(lab, n, m, a, b - 1, mov, cont)){
            lab[a][b] = '<'; 
            mov[(*cont)++] = 'L';
            return 1;
        }
        if(percorrerLab(lab, n, m, a, b + 1, mov, cont)){
            lab[a][b] = '>'; 
            mov[(*cont)++] = 'R';
            return 1;
        }

        lab[a][b] = '.'; 
        return 0;
        
    }
    
    return 0;
    
}

int main() {
    
    int n = 0, m = 0, cont = 0;

    scanf("%d %d", &n, &m);
    getchar();
    
    char mov[n * m];
    char **labirinto = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++){
        labirinto[i] = (char *)malloc(m * sizeof(char));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &labirinto[i][j]);
        }
    }
    
    printf("\n");
    if(labirinto[0][0] == '.'){
        percorrerLab(labirinto, n, m, 0, 0, mov, &cont);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(labirinto[i][j] == '*'){
                labirinto[i][j] = '.';
            }
        }
    }

    saida(labirinto, n, m);
    for (int i = cont-1; i >= 0; i--) {
        printf("%c ", mov[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        free(labirinto[i]);
    }
    free(labirinto);

    return 0;
    
}
