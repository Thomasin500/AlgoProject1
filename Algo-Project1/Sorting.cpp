#include <iostream>
#include <algorithm> //needed for min

#include "Helper.h"


using namespace std;

template <typename Comparable>
void selectionSort(Comparable a[], int n) {

for (int i = 0; i < n; i++) {

	int min = i;

	for (int j = i; j < n; j++) {

		if (a[j] < a[min]) {

			min = j;
		}
	}

	swap(a[i], a[min]);
}

cout << "Selection Sort Finished:\n";
}
/*-----------------------------------------------------------------------
selectionSort

Precondition:  implements selection sort
Postcondition: the array is now sorted
-----------------------------------------------------------------------*/

template <typename Comparable>
void insertionSort(Comparable a[], int n) {

for (int i = 0; i < n; i++) {

	int j = i;

	while (j > 0 && a[j - 1] > a[j]) {
		swap(a[j], a[j - 1]);
		j--;
	}
}

cout << "Insertion Sort Finished:\n";
}
/*-----------------------------------------------------------------------
insertionSort

Precondition:  implements insertion sort
Postcondition: the array is now sorted
-----------------------------------------------------------------------*/

//template <typename Comparable>
//void mergeSort(Comparable a[], const int n, Comparable temp[]) {
//
//const int size = n;
//
//Comparable finalArray [n];
//
//for (int subArrays = 1; subArrays < n; subArrays *= 2) {
//
//	for (int i = 0; i < n; i = i + 2 * subArrays) {
//
//		mergeSortUtil(a, i, min(i + subArrays, size), min(i + 2 * subArrays, size), finalArray);
//	}
//
//	copyArray(a, finalArray);
//}
//
//cout << "Merge Sort Finished:\n";
//}
///*-----------------------------------------------------------------------
//mergeSort
//
//Precondition:  implements merge sort
//Postcondition: the array is now sorted
//-----------------------------------------------------------------------*/
//
////merges two arrays into one sorted array
//template <typename Comparable>
//void mergeSortUtil(Comparable a[], int left, int right, int end, Comparable b[]) {
//
//int i = left;
//int j = right;
//
//for (int k = left; k < end; k++) {
//
//	if (i < right && (j >= end || a[i] <= a[j])) {
//
//		b[k] = a[i];
//		i++;
//	}
//	else {
//
//		b[k] = a[j];
//		j++;
//	}
//}
//}
///*-----------------------------------------------------------------------
//mergeSort util
//
//Precondition: a util function of merge sort
//Postcondition: the array is now sorted
//-----------------------------------------------------------------------*/

template <typename Comparable>
void quickSort(Comparable a[], int low, int high) {

if (low < high) {

	int pivot = quickSortUtil(a, low, high);

	quickSort(a, low, pivot - 1);
	quickSort(a, pivot + 1, high);
}
}
/*-----------------------------------------------------------------------
quickSort

Precondition:  implements quick sort
Postcondition: the array is now sorted
-----------------------------------------------------------------------*/

template <typename Comparable>
int quickSortUtil(Comparable a[], int low, int high) {

int temp = low;
int pivot = a[low];

for (int i = low + 1; i <= high; i++) {

	if (a[i] <= pivot) {

		temp++;
		swap(a[i], a[temp]);
	}
}

swap(a[temp], a[low]);

return temp;
}
/*-----------------------------------------------------------------------
quickSortUtil

Precondition:  a utility function of quick sort
Postcondition: the array is now sorted
-----------------------------------------------------------------------*/

