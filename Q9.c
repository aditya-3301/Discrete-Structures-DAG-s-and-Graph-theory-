#include <stdio.h>
#include <stdlib.h>

int main(){
    int R;
    int C;
    scanf("%d",&R);
    scanf("%d",&C);
    int** M = (int**)malloc(R*sizeof(int*));
    for(int i=0;i<R;i++){
        M[i]=(int*)malloc(C*sizeof(int));
    }

    int size = R * C;
    int** N = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        N[i] = (int*)malloc(size * sizeof(int));
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            N[i][j] = 0;
        }
    }


    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            M[i][j]=(i*C)+j;
        }
    }
    printf("\n");


    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int id = M[i][j];
            // Up
            if (i > 0) {
                int neighbor_id = M[i - 1][j];
                N[id][neighbor_id] = 1;
                N[neighbor_id][id] = 1;
            }
            // Down
            if (i < R - 1) {
                int neighbor_id = M[i + 1][j];
                N[id][neighbor_id] = 1;
                N[neighbor_id][id] = 1;
            }
            // Left
            if (j > 0) {
                int neighbor_id = M[i][j - 1];
                N[id][neighbor_id] = 1;
                N[neighbor_id][id] = 1;
            }
            // Right
            if (j < C - 1) {
                int neighbor_id = M[i][j + 1];
                N[id][neighbor_id] = 1;
                N[neighbor_id][id] = 1;
            }
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",N[i][j]);
        }
        printf("\n");
    }

    return 0;
}
