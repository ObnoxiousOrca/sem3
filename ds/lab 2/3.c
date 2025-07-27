/*
Implement a C program to read, display, and find the product of two matrices using
functions with appropriate parameters.
    • The matrices must be created using dynamic memory allocation (malloc or calloc).
    • Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j) style).
*/

#include<stdio.h>
#include<stdlib.h>

void matrixIn(int **mat, int row, int col); //separate matrix input function for cleanliness
int **allocate(int rows, int cols);
int **multiply(int **a, int **b, int dim1, int dim2, int dim3); //dim1 -> rows of a; dim2 -> cols of a or rows of b; dim3 -> cols of b
void displayMatrix(int** mat, int rows, int cols);


int main(){
    int p,q,r;
    printf("Enter dimensions for matrix A:\n");
    printf("Rows: ");
    scanf("%d", &p);
    printf("Columns: ");
    scanf("%d", &q);

    printf("\nEnter dimensions for matrix B:\n");
    printf("Number of rows of B must be %d\n", q);
    printf("Columns: ");
    scanf("%d", &r);

    int **A = allocate(p, q);
    int **B = allocate(q, r);

    printf("Enter elements for 1st matrix:\n");
    matrixIn(A, p, q);
    printf("\nEntered matrix:\n");
    displayMatrix(A, p, q);

    printf("Enter elements for 2nd matrix:\n");
    matrixIn(B, q, r);
    printf("\nEntered matrix:\n");
    displayMatrix(B, q, r);

    int **C = multiply(A, B, p, q, r);

    printf("\nResultant Matrix:\n");
    displayMatrix(C, p ,r);

    return 0;
}


void matrixIn(int **mat, int row, int col){ 
    for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
            scanf("%d", *(mat+i)+j);
}


void displayMatrix(int** mat, int rows, int cols){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            printf("%d ", *(*(mat+i)+j));
        }
        printf("\n");
    }
}


int **allocate(int rows, int cols){
    int **mat = (int **)malloc(rows*sizeof(int*));  //using malloc to allocate space for rows
    for(int i = 0; i<rows; i++) *(mat + i) = (int*)calloc(cols, sizeof(int));  //using calloc to allocate space for each element and initialize them to 0
    return mat;
}


int **multiply(int **a, int **b, int dim1, int dim2, int dim3){ 
    int** res = allocate(dim1, dim3);
    for(int i = 0; i<dim1; i++)
        for(int j = 0; j<dim2; j++)
            for(int k = 0; k<dim3; k++)
                *(*(res+i)+k) += (*(*(a + i)+j)) * (*(*(b + j)+k));  //res[i][k] += a[i][j] * b[j][k];

    return res;
}