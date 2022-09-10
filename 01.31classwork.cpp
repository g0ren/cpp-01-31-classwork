#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define MIN 0
#define MAX 100

template<typename T>
void swap(T *p1, T *p2) {
	T t { };
	t = *p1;
	*p1 = *p2;
	*p2 = t;
}

template<typename T>
void fillArray(T *ar, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		double m { (double) rand() / RAND_MAX };
		*(ar + i) = (MAX - MIN) * m;
	}
}

template<typename T>
void printArray(T *ar, int size) {
	for (int i = 0; i < size; i++) {
		cout << *(ar + i) << " ";
	}
	cout << endl;
}

/*
 * Необходимо написать функцию, которая поменяет значения четных и нечетных ячеек массива.
 */
template<typename T>
void switchOddAndEven(T *ar, int size) {
	T *ptr = ar;
	for (; ptr < ar + size - 1; ptr += 2) {
		swap(ptr, ptr + 1);
	}
}

template<typename T>
bool isIncreasing(T *ar, int size) {
	for (int i = 1; i < size; i++)
		if (ar[i] < ar[i - 1])
			return false;
	return true;
}

/*
 * Написать программу, которая проверяет, представляют ли элементы введенного с
 * клавиатуры массива возрастающую последовательность. Использовать
 * форматированный ввод-вывод данных.
 */
void increasingArray(int pre = 0) {
	int n { };
	cout << "Enter next element, 0 to exit ";
	cin >> n;
	if (n == 0) {
		cout << "It's an increasing sequence";
		return;
	}
	if (n < pre) {
		cout << "It's not an increasing sequence";
		return;
	}
	increasingArray(n);
}

template<typename T>
void fillArrayFromKeyboard(T *ar, int size) {
	T val { };
	for (int i = 0; i < size; i++) {
		cout << "Enter element #" << i << ": ";
		cin >> val;
		*(ar + i) = val;
	}
}

/*Дан массив целых. Сформировать по нему массив, содержащий длины всех серий (подряд идущих одинаковых элементов).
 * Одиночные элементы счи-тать сериями длины 1.
 *
 */
int *lengthArray(int *ar, int size){
	int *r=new int[size]{};
	int l{1};
	int *ptr=r;
	for(int i=1;i<size;i++){
		if(ar[i]==ar[i-1]){
			l++;
		}else{
			*ptr=l;
			ptr++;
			l=1;
		}
	}
	*ptr=l;
	return r;
}

void makeArrays() {
	int size { };
	do {
		cout << "Enter array size (0 to exit)" << endl;
		cin >> size;
		if (!size)
			return;
		int *array = new int[size];
		fillArray(array, size);
		printArray(array, size);
		switchOddAndEven(array, size);
		printArray(array, size);
		delete array;
	} while (size);
}

int main() {
	int size { };
	cout << "Enter array size (0 to exit)" << endl;
	cin >> size;
	if (!size)
		return 0;
	int *array = new int[size];
	fillArrayFromKeyboard(array, size);
	printArray(array, size);
	int *l{};
	l=lengthArray(array, size);
	printArray(l, size);

	delete array;

	return 0;
}
