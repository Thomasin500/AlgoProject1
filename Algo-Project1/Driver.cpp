#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

#include "Sorting.cpp"
#include "Helper.h"
#include "Helper.cpp"

enum sort_t { SELECTION, INSERTION, MERGE, QUICK };
enum input_t { INCREASING, DECREASING, CONSTANT, RANDOM };

int main(int argc, char** argv)
{
	int n = 100;
	int arrayType = 0;
	int algo = 0;
	sort_t alg = SELECTION;
	input_t intype = RANDOM;
	int* data;
	int* temp;
	clock_t start;
	clock_t timing[3];

	cout << "n (optional):  size of array" << endl;
	cin >> n;

	cout << "algorithm (optional):  one of selectionsort(0), insertionsort(1), mergesort(2), or quicksort(3)" << endl;
	cin >> algo;

	cout << "input type (optional):  one of increasing(0), decreasing(1), constant(2), or random(3)" << endl;
	cin >> arrayType;

	temp = constArray(n);
	
	switch (algo)
		{
		case 0:
			alg = SELECTION;
			break;
		case 1:
			alg = INSERTION;
			break;
		case 2:
			alg = MERGE;
			break;
		case 3:
			alg = QUICK;
			break;
		default:
			cout << "Sorting algorithm not recognized\n";		
	}
	
	switch (arrayType)
		{

		case 0:
			intype = INCREASING;
			break;
		case 1:
			intype = DECREASING;
			break;
		case 2:
			intype = CONSTANT;
			break;
		case 3:
			intype = RANDOM;
			break;
		default:
			cout << "Input array type not recognized\n";
		
	}

	//Run sorting algorithm 3 times
	for (int i = 0; i < 3; i++)
	{
		// Initialize data
		switch (intype)
		{
		case INCREASING:
			data = increasingArray(n);
			break;
		case DECREASING:
			data = decreasingArray(n);
			break;
		case CONSTANT:
			data = constArray(n);
			break;
		case RANDOM:
			data = randomArray(n);
		}

		//Sort data
		//printArray(arr, n);
		start = clock();
		switch (alg)
		{
		case SELECTION:
			selectionSort(data, n);
			break;
		case INSERTION:
			insertionSort(data, n);
			break;
		case MERGE:
			//mergeSort(data, n, temp);
			break;
		case QUICK:
			quickSort(data, 0, n);
			break;
		}
		timing[i] = clock() - start;
		printArray(data, n);

		//Verify data is sorted
		if (isSorted(data, n))
			cout << "Array successfully sorted.\n";
		else
		{
			cout << "Array incorrectly sorted.\n";
			//Time to debug...
			return -1;
		}
	}

	//Output timing results
	for (int i = 0; i < 3; i++)
		cout << "Attempt " << i + 1 << ":  " << setw(8) << (int)(timing[i] * 1000.0 / CLOCKS_PER_SEC) << " ms\n";
	cout << "Median time:     " << setw(8) << (int)(timing[medianof3(timing[0], timing[1], timing[2]) - 1] * 1000.0 / CLOCKS_PER_SEC) << " ms" << endl;

	delete[] data;
	delete[] temp;

	//Windows:  pause so window doesn't vanish
	char c;
	cout << "Type 'q' to quit:  ";
	cin >> c;
	return 0;
}