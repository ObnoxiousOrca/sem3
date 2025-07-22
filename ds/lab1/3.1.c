// Bubble sort

#include <stdio.h>

void swap(int *x, int *y);
void bubbleSort(int arr[], int n);

int main()
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter the elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Unsorted array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\nSorted array:\n");
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}