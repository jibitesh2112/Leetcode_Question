// C program to Find the repeating
// and missing elements

#include <stdio.h>
#include <stdlib.h>

void printTwoElements(int arr[], int size)
{
	int i;
	printf("\nThe repeating element is ");

	for (i = 0; i < size; i++) {
		if (arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		else
			printf(" %d ", abs(arr[i]));
	}

	printf("\nand the missing element is ");
	for (i = 0; i < size; i++) {
		if (arr[i] > 0)
			printf("%d", i + 1);
	}
}

// Driver code
int main()
{
	int arr[] = { 4, 3, 6, 5, 2, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElements(arr, n);
	return 0;
}
