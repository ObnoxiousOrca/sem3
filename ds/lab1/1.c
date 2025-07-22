// Linear search

#include <stdio.h>

int linearSearch(int arr[], int n, int key);

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

	int idx = linearSearch(arr, n, key);

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

int linearSearch(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}