#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include "sorting.h"
#include "arrayGeneration.h"

using namespace std;

int main(){
	char value = 0;
	double Itotal = 0;
	int size = 0;
	
	clock_t beginSort, endSort;
	
	cout << "Pick an array size of increasing order" << endl;
	cin >> size;
	int* increasingArray = generateIncreasingArray(size);
	cout << "[";
	for(int i = 0; i < size; i++){
		cout << increasingArray[i] << ", ";
	}
	cout << "]" << endl;
	
	
	
	size = 0;
	
	cout << "Pick an array size of decreasing order" << endl;
	cin >> size;
	int* decreasingArray = generateDecreasingArray(size);
	cout << "[";
	for(int i = 0; i < size; i++){
		cout << decreasingArray[i] << ", ";
	}
	cout << "]" << endl;
	
	size = 0;
	
	cout << "Pick an array size of random order" << endl;
	cin >> size;
	int* randomArray = generateRandomArray(size);
	/*cout << "[";
	for(int i = 0; i < size - 1; i++){
		cout << randomArray[i] << ", ";
	}
	cout << randomArray[size - 1];
	cout << "]" << endl;
	*/
	beginSort = clock();
		insertionsort(randomArray, size);
		//quicksort(randomArray, size);
		//mergesort(randomArray, size);
	endSort = clock();
	Itotal += difftime(endSort, beginSort);
	//delete[] randomArray;
	/*cout << "[";
	for(int i = 0; i < size - 1; i++){
		cout << randomArray[i] << ", ";
	}
	cout << randomArray[size - 1];
	cout << "]" << endl;
*/
	
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	cout << "runtime of sorting algorithm is: " << Itotal << "ms" << endl;
	cout << "Pick an array size of random order, and a const of your choice order" << endl;
	cin >> size >> value; 
	
	
	char* constArray = generateConstArray(value, size);
	cout << "[";
	for(int i = 0; i < size; i++){
		cout << constArray[i] << ", ";
	}
	cout << "]" << endl;
}

/*cout << "[";
	for(int i = 0; i < size - 1; i++){
		cout << randomArray[i] << ", ";
	}
	cout << randomArray[size - 1];
	cout << "]" << endl;
	*/
