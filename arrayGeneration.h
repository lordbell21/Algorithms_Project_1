#include <cstdlib>
#include <ctime>

template <typename T>
class arrayGeneration {
	public:
		int* generateIncreasingArray(const int&);
		int* generateDecreasingArray(const int&);
		int* generateRandomArray(const int&);
		T* generateConstArray(T, const int&);
		
	private:
};

int* generateIncreasingArray(const int& size){
	int* increasingArray = new int[size];
	for(int i = 0; i < size; i++){
		increasingArray[i] = i;
	}
	return increasingArray;

}

int* generateDecreasingArray(const int& size){
	int* decreasingArray = new int[size];
	for(int i = size - 1, j = 0; i > 0 && j != size; i--, j++){
		decreasingArray[j] = i;
	}
	return decreasingArray;

}

int* generateRandomArray(const int& size){
	int variable = 0, temp = 0;
	int* randomArray = generateIncreasingArray(size);
	long seed;
	seed = long(time(0));
	srand(seed);
	
	for(int i = 0; i < size; i++){
		variable = (rand()%size);
		temp = randomArray[variable];
		randomArray[variable] = randomArray[i];
		randomArray[i] = temp;
	}
	return randomArray;

}

template <typename T>
T* generateConstArray(T value, const int& size){
	T* constArray = new T[size];
	for(int i = 0; i < size; i++){
		constArray[i] = value;
	}
	return constArray;
}
