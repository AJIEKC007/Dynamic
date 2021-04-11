#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(double arr[], const int n);
template<typename T>void FillRand(T arr[], const int n);
void FillRand(double** arr, const int m, const int n);
template<typename T>void FillRand(T** arr, const int m, const int n);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>void push_back(T*& arr, int& n, T value);
template<typename T>void push_front(T*& arr, int& n, T value);
template<typename T>void insert(T*& arr, int& n, T value, int index);

template<typename T>void pop_back(T*& arr, int& n);
template<typename T>void pop_front(T*& arr, int& n);
template<typename T>void erase(T*& arr, int& n, int index);

template<typename T>void push_row_back(T**& arr, int& m, const int n);
template<typename T>void push_row_front(T**& arr, int& m, const int n);
template<typename T>void insert_row(T**& arr, int& m, const int n, int index);

template<typename T>void pop_row_back(T**& arr, int& m, const int n);
template<typename T>void pop_row_front(T**& arr, int& m, const int n);
template<typename T>void erase_row(T**& arr, int& m, const int n, int index);

void main()
{
	setlocale(LC_ALL, "Russian");

	//----------------���������� ���������� ������������� �������--------------
	int m; //���-�� �����
	int n; // ���-�� ��������� ������
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������: "; cin >> n;
	//1)������� ������ ����������
	double** arr2 = new double* [m];
	//2)�������� ������ ��� ������ ���������� �������:
	for (int i = 0; i < m; i++)
	{
		arr2[i] = new double[n] {};
	}
	//----------------������������� ���������� ������������� �������--------------
	FillRand(arr2, m, n);
	Print(arr2, m, n);

	cout << "���������� ������ � ����� �������: " << endl;
	push_row_back(arr2, m, n);
	Print(arr2, m, n);

	cout << "���������� ������ � ������ �������: " << endl;
	push_row_front(arr2, m, n);
	Print(arr2, m, n);

	int index;
	cout << "������� ������ ����������� ������ ������: "; cin >> index;
	insert_row(arr2, m, n, index);
	Print(arr2, m, n);


	cout << "�������� ��������� ������: " << endl;
	pop_row_back(arr2, m, n);
	Print(arr2, m, n);

	cout << "�������� ������� ������: " << endl;
	pop_row_front(arr2, m, n);
	Print(arr2, m, n);


	cout << "������� ������ ��������� ������: "; cin >> index;
	erase_row(arr2, m, n, index);
	Print(arr2, m, n);


	//----------------�������� ���������� ������������� �������--------------
	//1)������� �����:
	for (int i = 0; i < m; i++)
	{
		delete[] arr2[i];
	}
	//2) �������� ������� ����������:
	delete[] arr2;

}

void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
		arr[i] /= 100;
	}
}


template<typename T>void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = double(rand() % 1000)/100;
		}
	}
}


template<typename T>void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int m, const int n)
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

template<typename T>void push_back(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
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

template<typename T>void pop_back(T*& arr, int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>void pop_front(T*& arr, int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[n - 1]{};
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

template<typename T>void push_row_back(T**& arr, int& m, const int n)
{
	//1)������� �������� ������
	T** buffer = new T* [m + 1]{};
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
	arr[m] = new T[n] {};
	m++;
}
template<typename T>void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m + 1]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n] {};
	m++;
}
template<typename T>void insert_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T* [m + 1]{};
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
	arr[index] = new T[n] {};
	m++;
}

template<typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;

}
template<typename T>void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T>void erase_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T* [--m];

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