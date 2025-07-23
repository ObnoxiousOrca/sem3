/*
Write a C program to read two matrices, A and B and perform the following operations:
(i) Multiply the two matrices (A * B)
(ii) Add the two matrices (A + B)
(iii) Read a square matrix and check whether it is a magic square or not
(Hint: A magic square is a square matrix in which the sum of every row, column, and both diagonals is the same.)
*/

#include <stdio.h>

int main()
{
	int m1, n1, m2, n2;
	printf("Enter the number of rows and columns for matrix A: ");
	scanf("%d %d", &m1, &n1);
	int A[m1][n1];

	printf("Enter elements of matrix A:\n");
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	printf("Enter the number of rows and columns for matrix B: ");
	scanf("%d", &m2, &n2);
	int B[m2][n2];

	printf("Enter elements of matrix B:\n");
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	// Matrix multiplication
	if (n1 != m2)
	{
		printf("Matrix multiplication not possible due to dimension mismatch.\n");
		return 1;
	}

	int C[m1][n2];

	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			C[i][j] = 0; // Initialize to zero
			for (int k = 0; k < n1; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("Result of A * B:\n");
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	// Matrix addition
	if (m1 == m2 && n1 == n2)
	{ // Only add if dimensions match
		int D[m1][n1];
		for (int i = 0; i < m1; i++)
		{
			for (int j = 0; j < n1; j++)
			{
				D[i][j] = A[i][j] + B[i][j];
			}
		}

		printf("Result of A + B:\n");
		for (int i = 0; i < m1; i++)
		{
			for (int j = 0; j < n1; j++)
			{
				printf("%d ", D[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Matrices A and B cannot be added due to dimension mismatch.\n");
	}

	// Check for magic square
	int magicSquare = 1;
	if (m1 == n1) // Only check if A is a square matrix
	{
		int sum = 0;
		for (int j = 0; j < n1; j++)
		{
			sum += A[0][j]; // Sum of the first row
		}
		// Check rows
		for (int i = 0; i < m1; i++)
		{
			int rowSum = 0;
			for (int j = 0; j < n1; j++)
			{
				rowSum += A[i][j];
			}
			if (rowSum != sum)
			{
				magicSquare = 0;
				break;
			}
		}
		// Check columns
		if (magicSquare)
		{
			for (int j = 0; j < n1; j++)
			{
				int colSum = 0;
				for (int i = 0; i < m1; i++)
				{
					colSum += A[i][j];
				}
				if (colSum != sum)
				{
					magicSquare = 0;
					break;
				}
			}
		}
	}
	if (magicSquare)
	{
		printf("Matrix A is a magic square.\n");
	}
	else
	{
		printf("Matrix A is not a magic square.\n");
	}

	return 0;
}