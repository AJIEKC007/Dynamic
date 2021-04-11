
#include"FillRand.h"
#include"Print.h"
#include"Arrays1.h"
#include"Arrays2.h"

//прототипы функций выносятся в заголовочные файлы(*.h)

void main()
{
	setlocale(LC_ALL, "Russian");

	//----------------ОБЪЯВЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА--------------
	int m; //кол-во строк
	int n; // кол-во элеменьов строки
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов: "; cin >> n;
	//1)создаем массив указателей
	int** arr = new int* [m];
	//2)выделяем память под строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	//----------------ИСПОЛЬЗОВАНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА--------------
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "добавление строки в конец массива: " << endl;
	push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "добавление строки в начало массива: " << endl;
	push_row_front(arr, m, n);
	Print(arr, m, n);

	int index;
	cout << "Введите индекс добавляемой пустой строки: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);


	cout << "Удаление последней строки: " << endl;
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление нулевой строки: " << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);


	cout << "Введите индекс удаляемой строки: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);


	//----------------УДАЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА--------------
	//1)Уаление строк:
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2) Удаление массива указателей:
	delete[] arr;

}

