
#include"FillRand.h"
#include"Print.h"
#include"Arrays1.h"
#include"Arrays2.h"

//��������� ������� ��������� � ������������ �����(*.h)

void main()
{
	setlocale(LC_ALL, "Russian");

	//----------------���������� ���������� ������������� �������--------------
	int m; //���-�� �����
	int n; // ���-�� ��������� ������
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������: "; cin >> n;
	//1)������� ������ ����������
	int** arr = new int* [m];
	//2)�������� ������ ��� ������ ���������� �������:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	//----------------������������� ���������� ������������� �������--------------
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������ � ����� �������: " << endl;
	push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������ � ������ �������: " << endl;
	push_row_front(arr, m, n);
	Print(arr, m, n);

	int index;
	cout << "������� ������ ����������� ������ ������: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);


	cout << "�������� ��������� ������: " << endl;
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "�������� ������� ������: " << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);


	cout << "������� ������ ��������� ������: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);


	//----------------�������� ���������� ������������� �������--------------
	//1)������� �����:
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2) �������� ������� ����������:
	delete[] arr;

}

