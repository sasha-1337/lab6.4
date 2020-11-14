#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>

using namespace std;

void FIND_LOW_C(int* a, const int size, int C) {
	int t = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] < C) {
			t++;
		}
	}
	cout << " 1.1 Кількість чисел менших за С: " << t << endl;
}

int SUM(int* a, const int size) {
	int last = 0;
	int s = 0;

	for (int i = size - 1; i >= 0; i--) { 
		if (*(a + i) < 0)
		{
			last = *(a + i); 
			break;
		}
	}
	cout << "Останній від'ємний елемент: " << last << endl;

	for (int i = size-1; i >= last; i--) 
	{
		if (a[i] != last) 
		{		
			s += a[i]; 
		}
		else
			break;
	}
	return s;
}


void Sort(int* a, const int size, int p) {
	int m, swap;
	for (int i = 0; i < size; i++) 
	{
		p = a[i];
		m = i;
		for (int j = 0; j < size - i; j++) 
		{
			if (a[j] > p)
			{
				m = j;
				p = a[j];
			}
		}
		swap = a[i];
		a[i] = a[m];
		a[m] = swap;
	}
}

void Create(int* &a, const int size, const int Low, const int High, int i)
{
	a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);

}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -10;
	int High = 10;

	int n = 0;
	int C = 0;
	int* a = new int[n];
	
	cout << " Введіть кількість елементів массиву: "; cin >> n;
	cout << " Елемент /С/ на який будуть рівнятись: "; cin >> C; 

	Create(a, n, Low, High, 0); // створюємо масив випадковими числами
	Print(a, n); // виводимо створений масив на екран

	FIND_LOW_C(a, n, C); // шукаємо кількість чисел менших за "С"

	SUM(a, n); // шукаємо суму елементів розташованих після останнього відємного елемента
	cout << " 1.2 Сума елементів розташованих після останнього від'ємного елементу: " << SUM(a, n) << endl;
	cout << "2. Сортування: " << endl;

	// шукаємо максимальне число
	int max = 0;
	float p = 0;
	for (int i = 1; i < n; i++)
		if (a[i] > a[max])
			max = i;
	p = a[max] * 0.2; // виконуємо умову про 20%

	Sort(a, n, p);
	Print(a, n);
	
	return 0;
}