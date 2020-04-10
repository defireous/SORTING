// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// --------------------MERGE SORT-------------------
void merge(int arr[], int left, int mid, int right) {
	int i, j, k = left;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + j + 1];
	}

	// Merge
	i = 0; j = 0;
	while (i < n1 && j < n2) {
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}
}

void mergeSort(int arr[], int left, int right) {
	/*
	1. Find the middle element
	2. Recursive the first-middle of array
	3. Recursive the last-middle of array
	4. Merge both to create array-solution*/
	
	if (left >= right) {
		return;
	}

	int middle = (left + right) / 2;
	
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	merge(arr, left, middle, right);
}

//-----------------QUICK SORT--------------------
void quickSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot = arr[(left + right) / 2];
	int i = left, j = right;

	do {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i < j);

	quickSort(arr, left, j);
	quickSort(arr, i, right); // save into stack(LIFO)
}


void output(int arr[], int n) {
	for (int i = 0; i < n;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 2,4,3,6,12,1,235,324,34,23,2356 };
	int length = sizeof(arr) / sizeof(int);
	
	mergeSort(arr, 0, length - 1);
	output(arr, length);

	return 0;
}

