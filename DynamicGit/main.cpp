#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);

void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);
void insert_row(int**& arr, int& m, const int n, int index);

void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);
void erase_row(int**& arr, int& m, const int n, int index);

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



void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

void push_back(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[] arr;
	arr = buffer;
	n--;
}

void push_row_back(int**& arr, int& m, const int n)
{
	//1)������� �������� ������
	int** buffer = new int* [m + 1]{};
	/*for (int i = 0; i < m+1; i++)
	{
		buffer[i] = new int[n] {};
	}*/
	//2)�������� ��� �������� ��������� ������� � ��������
	for (int i = 0; i < m; i++)
	{
		/*	for (int j = 0; j < n; j++)
			{
				buffer[i][j] = arr[i][j];
			}*/
		buffer[i] = arr[i]; // � �������� ������ ��������� ����� ��������������� ������
	}
	//3)������� �������� ������:
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//�� ����� ������� ������, ���������� ������� ������ ������ ����������
	delete[] arr;
	//4)�������������� ����� ������
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
}
void insert_row(int**& arr, int& m, const int n, int index)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m + 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[n] {};
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;

}
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
void erase_row(int**& arr, int& m, const int n, int index)
{
	int** buffer = new int* [--m];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete arr[index];
	delete arr;
	arr = buffer;
}