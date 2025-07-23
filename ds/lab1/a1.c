// Write a C program to compare the number of comparisons and swaps made in bubble sort, selection sort, and insertion sort for the same input array.

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main()
{
	int n, i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	printf("Enter the elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	bubbleSort(arr, n);
	selectionSort(arr, n);
	insertionSort(arr, n);

	printf("Sorted array after all sorts:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
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
	int i, j, tmp;
	int c = 0, s = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			c++;
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				s++;
			}
		}
	}

	printf("Bubble Sort: Comparisons = %d, Swaps = %d\n", c, s);
}

void selectionSort(int arr[], int n)
{
	int i, j, min, tmp;
	int c = 0, s = 0;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			c++;
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&arr[i], &arr[min]);
			s++;
		}
	}
	printf("Selection Sort: Comparisons = %d, Swaps = %d\n", c, s);
}

void insertionSort(int arr[], int n)
{
	int i, j, key, tmp;
	int c = 0, s = 0;

	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			c++;
			arr[j + 1] = arr[j];
			s++;
			j--;
		}
		c++;
		arr[j + 1] = key;
	}
	printf("Insertion Sort: Comparisons = %d, Swaps = %d\n", c, s);
}