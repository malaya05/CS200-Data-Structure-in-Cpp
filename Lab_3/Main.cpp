/*
Alaya, Jason
Mendoza, Moises

CS A200
September 17, 2017

Lab 3
*/

#include <iostream>

using namespace std;

const int CAP = 10;

// Number of digits in each element
int numOfDigits(int arr[], int numOfElem)
{
	int digits = 0;
	int element = arr[0];
	while (element)
	{
		++digits;
		element /= 10;
	}
	return digits;
}

// Print the array
void printArray(int arr[], int numOfElem)
{
	for (int i = 0; i < numOfElem; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	/*  Testing Cases
	int a[CAP] = { 130357, 284681, 132579,
	946580, 356343,204773, 132635, 566258, 974034, 210520 };
	int a[CAP] = { 4, 6, 8, 1, 9, 2, 3, 8, 7, 6 };
	int a[CAP] = { 453, 675, 841 };
	int a[CAP] = { 92, 75, 64, 38, 32, 95, 19, 71, 24 };
	int a[CAP] = { 1357, 2468, 3579, 4680, 5634,
	2473, 1235, 5628, 9734, 2050 };
	int a[CAP] = { 13570, 24681, 13579, 94680,
	56343, 20473, 13235, 56628, 97034, 20520 };
	int a[CAP] = { 133570, 284681, 132579, 946580,
	356343, 204773, 132635, 566258, 974034, 210520 };
	*/
	int a[CAP] = { 914, 214, 854,783, 762, 614, 273 };
	int numOfElem = 7;

	int *sorted = new int[CAP];
	int looper = 0,
		j = 0,
		currentDigit = 0,
		multip = 1,
		numDigits = numOfDigits(a, numOfElem);
		// O(K) number of digits 

	cout << "Original array: ";
	printArray(a, numOfElem);
	while (currentDigit < numDigits) // O(K) number of digits 
	{
		int index = 0;
		while (index < numOfElem && j <= 9
			&& looper < numOfElem) // O(n * 9) for the worst case.				
		{
			if ((a[index] / multip) % 10 == j)
				sorted[looper++] = a[index];

			if (++index == numOfElem)
			{
				index = 0;
				++j;
			}
		}
		cout << "Iteration " << ++currentDigit << ": ";
		printArray(sorted, numOfElem);
		multip *= 10;
		j = looper = 0;

		for (int i = 0; i < numOfElem; ++i) // O(n) number of elements 
			a[i] = sorted[i];
	}	// Total O((K+ k)*9n) + n) = O(2K*9n + n) 
		// = O(K*n + n) = O(K*n)
	delete[] sorted;

	cout << endl;
	system("pause");
	return 0;
}