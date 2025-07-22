// Insertion sort

#include <stdio.h>

void swap(int *x, int *y);
void insertionSort(int arr[], int n);

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
	insertionSort(arr, n);
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

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}