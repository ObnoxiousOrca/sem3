// Write a C program to read two matrices A & B, create and display a third matrix C such that C (i, j) = max (A(i, j) , B(i, j)).

#include <stdio.h>

int main()
{
	int m, n;

	printf("Enter the number of rows and columns: ");
	scanf("%d %d", &m, &n);

	int A[m][n], B[m][n], C[m][n];
	printf("Enter elements of matrix A:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	printf("Enter elements of matrix B:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	printf("Matrix C (max of A and B):\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}