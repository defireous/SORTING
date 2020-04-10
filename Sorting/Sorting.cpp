// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// --------------------MERGE SORT-------------------
int *merge(int arr[], int left, int mid, int right)
{
	int i, j, k = left;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = new int[n1];
	int *R = new int[n2];

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[mid + j + 1];
	}

	// Merge
	i = 0;
	j = 0;
	while (i < n1 && j < n2)
	{
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		arr[k++] = R[j++];
	}

	return arr;
}

int *mergeSort(int arr[], int left, int right)
{
	/*
	1. Find the middle element
	2. Recursive the first-middle of array
	3. Recursive the last-middle of array
	4. Merge both to create array-solution*/

	if (left >= right)
	{
		return nullptr;
	}

	int middle = (left + right) / 2;

	arr = mergeSort(arr, left, middle);
	arr = mergeSort(arr, middle + 1, right);
	arr = merge(arr, left, middle, right);

	return arr;
}

//-----------------QUICK SORT--------------------
void quickSort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int pivot = arr[(left + right) / 2];
	int i = left, j = right;

	do
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
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

#define NUM_OF_TC 3
#define INPUT_LENGTH 10
#define OUTPUT_LENGTH 10

struct Testcase
{
	int input;
	int output;
};

bool isEqual(int output, int expected)
{
	if (output = expected) {
		return true;
	}

	return false;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int factorSum(int n) {
    int sum = 0;
    int temp = n;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            sum += i;
            n /= i;
        }
    }

    if (sum == temp) {
        return sum;
    }
    else {
        factorSum(sum);
    }
}

int func(int n) {
    int sum = 0;
    int temp = n;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            sum += i;
            n /= i;
        }
    }

    if (sum == temp) {
        return sum;
    }
    else {
        factorSum(sum);
    }
}

int main()
{
	// define testcases
	// read testcase from file
	struct Testcase tc[NUM_OF_TC] = {
			{
					input: 24,
					output: func(24),
			},
			{
					input: 35,
					output: func(35),
			},
			{
					input: 156,
					output: func(156),
			},
			};

	// number of passed/failed
	int passed, failed;

	// run your program here
	for (int i = NUM_OF_TC - 1; i >= 0; i--)
	{
		int input = tc[i].input;
		int expected = tc[i].output;

		int realOutput = factorSum(input);

		if (isEqual(realOutput, expected))
		{
			passed += 1;
		}
		else
		{
			failed += 1;
		}
	}

	// print test result
	printf("Passed: %d\n", passed);
	printf("Failed: %d", failed);

	return 0;
}
