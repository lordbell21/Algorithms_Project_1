#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class sorting {
	public:
		void swapvalues(T&, T&);
		void mergesort_function(T*, T*, int, int);
		void quicksort_function(T*, int, int, int);
		T decrementpivot(T*, const int&);
		T incrementpivot(T*, const int&);
		T maxvalue(T, T);
		void insertionsort(T*, const int&);
		void quicksort(T*, const int&);
		void mergesort(T*, const int&);
		//bool isSorted(T*, const int&);
	
	private:
};

template <class T>
void swapvalues(T &a, T &b){
	int temp = a;
	a = b;
	b = temp;
}

template <class T>
T decrementpivot(T* items, const int& size){
	int temp = 0;
	for(int i = 0; i < size; i++){
		int temp = items[0];
		items[i] = items[i+1];
	}
	items[size-1] = temp;
}

template <class T>
T incrementpivot(T* items, const int& size){
	int temp = 0;
	for(int i = 0; i < size; i++){
	    temp = items[size-1];
		items[i] = items[i-1];
	}
	items[0] = temp;
}

template <class T>
T maxvalue(T x, T y){
	if(x > y)
		return x;
	else
		return y;
}

template <class T>
void mergesort_function(T* items, T* temparray, int left, int right){
	if(right == left + 1){ //single element, "sorted"
		return;
	}
	else{
		int length = right - left;
		int midpoint = length/2;
		int ltemp = left,r = left + midpoint;
		
		mergesort_function(items, temparray,left, r);
		mergesort_function(items, temparray, r, right);
		
		for(int i = 0; i < length; i++){
			if(ltemp < left + midpoint /*r*//*r might change*/ 
			&& (r == right || maxvalue(items[ltemp], items[r]) == items[ltemp])){
				temparray[i] = items[ltemp];
				ltemp++;
			}
			else{
				temparray[i] = items[r];
				r++;
			}
		}
		for(int i = left; i < right; i++){ //sorted, but reverse
			items[i] = temparray[i - left];
		}
	}
	
}

template <class T>
void quicksort_function(T* items, int left, int right, int pivot){
	int ltemp = left, rtemp = right;
	if(right != 1){
		while(ltemp <= rtemp){
			while(items[ltemp] < pivot){
				ltemp++;
			}
			while(items[rtemp] > pivot){
				rtemp--;
			}
			if(ltemp <= rtemp){
				swapvalues(items[ltemp], items[rtemp]);
				ltemp++;
				rtemp--;
			}
		}
		if(left < rtemp){
			quicksort_function(items, left, rtemp, pivot);
		}
		if(ltemp < right){
			quicksort_function(items, ltemp, right, pivot);
		}
	}//partitions
	
}


template <class T>
void insertionsort(T* items, const int& size){
	int j = 0;
	for (int i = 1; i < size; i++) {
		j = i;
		while (j > 0 && items[j - 1] > items[j]) {
			swapvalues(items[j], items[j-1]);
			j--;
		}
	}
}


template <class T>
void quicksort(T* items, const int& size){
	bool isRandomPivot = 1;
	bool isSorted = 0;
	int pivot = rand() % size+1;
	
	if(isSorted != 1){
		quicksort_function(items, 0, size, pivot);
	}
}

template <class T>
void mergesort(T* items, const int& size){	
	T* temparray = new T[size];
	if(temparray != NULL){
		mergesort_function(items, temparray, 0, size);
		for(int i = 0; i < (size/2); i++){
			swapvalues(items[i], items[size - i - 1]); //return to increasing sorted
		}
	}
	delete[] temparray;
	return;
	
}

/*template <class T>
bool isSorted(T* items, const int& size){
	bool sorted;
	do{
		for(int i = 0; i < size; i++){
		
		
		}
	} while(isSorted != FALSE);
	
	return sorted;

}*/
