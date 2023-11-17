#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int percorrerLab(char** lab, int n, int m, int a, int b){
   
    if(a == (n - 1) && b == (m - 1)){
        return 1;
    }
    
    if((unsigned int)a < n && (unsigned int)b < m && lab[a][b] == '.'){

        lab[a][b] = 'O'; 

        if(percorrerLab(lab, n, m, a - 1, b)){
            return 1;
        }
        if(percorrerLab(lab, n, m, a + 1, b)){
            return 1;
        }
        if(percorrerLab(lab, n, m, a, b - 1)){
            return 1;
        }
        if(percorrerLab(lab, n, m, a, b + 1)){
            return 1;
        }

        lab[a][b] = '.'; 

        return 0;
        
    }
    
    return 0;
    
}

int main() {
    
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);
    getchar();
    
    char **labirinto = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++){
        labirinto[i] = (char *)malloc(m * sizeof(char));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &labirinto[i][j]);
        }
    }

    if(percorrerLab(labirinto, n, m, 0, 0)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    for (int i = 0; i < n; i++) {
        free(labirinto[i]);
    }
    free(labirinto);

    return 0;
    
}
