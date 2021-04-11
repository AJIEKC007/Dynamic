

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