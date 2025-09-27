#include <stdio.h>
#include <stdlib.h>

// Function to check if the relation is Reflexive
int Reflexive(int **M, int r, int c) {
    int flag = 1;

    // Check if the matrix is square (necessary for reflexivity)
    if (r != c) {
        return 0;  // Not reflexive if it's not a square matrix
    }

    // Check reflexivity: M[i][i] should not be 0 for all i
    for (int i = 0; i < r; i++) {
        if (M[i][i] == 0) {
            flag = 0;  // If any diagonal element is 0, it's not reflexive
            break;
        }
    }

    return flag;
}

// Function to check if the relation is Symmetric
int Symmetric(int **M, int r, int c) {
    int flag = 1;

    // Check symmetry: M[i][j] should be equal to M[j][i] for all i, j
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (M[i][j] != M[j][i]) {
                flag = 0;  // If M[i][j] != M[j][i], it's not symmetric
                break;
            }
        }
    }

    return flag;
}

//Function Transitive
int Transitive(int** M,int r,int c){
    int flag=1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(M[i][j]!=0){
                for(int k=0;k<c;k++){
                    if(M[j][k]!=0){
                        if(M[i][k]==0){
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
    
    }
    return flag;
}

// Function to check if the relation is an equivalence relation (placeholder)
int Equiv_relation(int **M, int r, int c) {
    int a = Reflexive(M,r,c);
    int b = Symmetric(M,r,c);
    int z = Transitive(M,r,c);
    printf("%d%d%d",a,b,z);
    return(a&&b&&z);
}

int main() {
    int N=0;
    printf("Enter number of aliens: ");
    scanf("%d",&N);

    int** M = (int **)(malloc(N*sizeof(int*)));
    for(int i=0;i<N;i++){
        M[i] = (int *)malloc(N*sizeof(int));
    }

    printf("Enter values:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&M[i][j]);
        }
    }

    printf("Enter Ambassador's ID: ");
    int k=-1;
    scanf("%d",&k);
    printf("\n\n\n");

    int Res=Equiv_relation(M,N,N);
    printf("\n");
    if(Res){
        for(int i=0;i<N;i++){
            if(M[i][k]!=0){
                printf("%d ",i);
            }
        }
    }

}
