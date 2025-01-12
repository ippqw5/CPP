#include<iostream>
using namespace std;

//void quickSort(int a[], int low, int high) {
//	if (low < high) {
//		int i = low, j = high;
//		int pivot = a[low];
//		while (i < j) {
//			while (i < j && a[j] >= pivot) j--;
//			if (i < j) a[i++] = a[j];
//			while (i < j && a[i] <= pivot) i++;
//			if (i < j) a[j--] = a[i];
//		}
//		a[i] = pivot;
//		quickSort(a, low, i - 1);
//		quickSort(a, i + 1, high);
//	}
//}

template<class T>
void quickSort(T a[], int low, int high) {
	if (low >= high) return;
	int i = low, j = high;
	T pivot = a[low];
	while (i < j) {
		while (i < j && a[j] >= pivot) j--;
		if (i < j) a[i++] = a[j];
		while (i < j && a[i] <= pivot) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = pivot;
	quickSort(a, low, i - 1);
	quickSort(a, i + 1, high);
}

int main() {
	int a[10] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 };
	cout << "初始序列：";
	for (int j = 0; j < 10; j++) {
		cout << a[j] << " ";
	}
	cout << endl;

	quickSort(a, 0, 9);

	cout << "排序结果：";
	for (int j = 0; j < 10; j++) {
		cout << a[j] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}