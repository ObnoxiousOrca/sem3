// Binary search

#include <stdio.h>

int binarySearch(int arr[], int n, int key);

int main()
{
	int n, key;

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter the elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Enter the key to search: ");
	scanf("%d", &key);

	int idx = binarySearch(arr, n, key);

	if (idx == -1)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element found at index %d\n", idx);
	}

	return 0;
}

int binarySearch(int arr[], int n, int key)
{
	int lo = 0, hi = n - 1;

	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;

		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return -1;
}