
#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int start, int mid, int end)
{
	int start2 = mid + 1;

	
	if (arr[mid] <= arr[start2]) {
		return;
	}

	
	while (start <= mid && start2 <= end) {

		if (arr[start] <= arr[start2]) {
			start++;
		}
		else {
			int value = arr[start2];
			int index = start2;

			
			while (index != start) {
				arr[index] = arr[index - 1];
				index--;
			}
			arr[start] = value;

			
			start++;
			mid++;
			start2++;
		}
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		
		int m = l + (r - l) / 2;

		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
	

	mergeSort(arr, 0, n);

	printArray(arr, n);
	return 0;
}

