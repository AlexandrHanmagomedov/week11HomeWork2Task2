/*
* Неделя 11
* Тема: Функции. Передача массивов внутрь функции Домашнее задание 2
Задание 2. Написать функцию, реализующую алгоритм
бинарного поиска заданного ключа в одномерном массиве.
*/
#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

template <class T>
void insertSort(T a[], long size) {
	T x;
	long i, j;
	for (i = 0; i < size; i++) {
		x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
}
//////////////////////////////////////////////////////////////////////////////////////
int binsearch(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (1)
	{
		mid = (left + right) / 2;
		if (key < arr[mid]) {
			right = mid + 1;
		}
		else if (key > arr[mid]) {
			left = mid - 1;
		}
		else {
			return mid;
		}
		if (left > right)
			return -1;
	}
}

int main()
{
	srand(time(0));
	int key = 0;
	int ind = 0;

	const int size = 20;
	int arr[size];
	cout << "\nMassiv do sortirovki \n";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		cout << "  ";
		cout << arr[i] << "\t";
		if (i == 9) {
			cout << endl;
		}
	}

	insertSort(arr, size);
	cout << "\nMassiv posle sortirovki \n";
	for (int i = 0; i < size; i++) {
		cout << "  ";
		cout << arr[i] << "\t";
		if (i == 9) {
			cout << endl;
		}
	}
	cout << "\n\n";

	cout << "\n\nVvedite klu4 poiska:";
	cin >> key;
	ind = binsearch(arr, 0, size, key);
	if (ind != -1) {
		cout << "\nKlu4 " << key << " nahoditsia v ya4eike " << ind << endl;
	}
	else {
		cout << "\nNet takogo ";
	}
	return 0;
}