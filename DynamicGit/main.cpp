
#include"FillRand.h"
#include"FillRandTemplated.cpp"
#include"Print.h"
#include"Array1.h"
#include"Array2.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	//----------------ОБЪЯВЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА--------------
	int m; //кол-во строк
	int n; // кол-во элеменьов строки
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов: "; cin >> n;
	//1)создаем массив указателей
	double** arr2 = new double* [m];
	//2)выделяем память под строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		arr2[i] = new double[n] {};
	}
	//----------------ИСПОЛЬЗОВАНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА--------------
	FillRand(arr2, m, n);
	Print(arr2, m, n);

	cout << "добавление строки в конец массива: " << endl;
	push_row_back(arr2, m, n);
	Print(arr2, m, n);

	cout << "добавление строки в начало массива: " << endl;
	push_row_front(arr2, m, n);
	Print(arr2, m, n);

	int index;
	cout << "Введите индекс добавляемой пустой строки: "; cin >> index;
	insert_row(arr2, m, n, index);
	Print(arr2, m, n);


	cout << "Удаление последней строки: " << endl;
	pop_row_back(arr2, m, n);
	Print(arr2, m, n);

	cout << "Удаление нулевой строки: " << endl;
	pop_row_front(arr2, m, n);
	Print(arr2, m, n);


	cout << "Введите индекс удаляемой строки: "; cin >> index;
	erase_row(arr2, m, n, index);
	Print(arr2, m, n);


	//----------------УДАЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА--------------
	//1)Уаление строк:
	for (int i = 0; i < m; i++)
	{
		delete[] arr2[i];
	}
	//2) Удаление массива указателей:
	delete[] arr2;

}

