#include <iostream>
#include <ctime>
#include <windows.h>
#include <algorithm>
using namespace std;

/*
������� print_array ����� �������� ���������, ������������
��� O(n), ��� "n" - ��� ���������� ��������� � �������.

��� ���������� ������, ��� ������� ������ ������
�� ������� �������� ������� � ������� ��� �� �����.
������ �������� ����� ��������� ������� �������� ������
�������� �� �����. ����� �������, ����� ������ �������
����� ��������������� ���������� ��������� � �������.

� ������ ������� ���� for �������� �� ���� ���������
������� � ��������� �������� ������ �� �����.
����� �������, ���� � ��� ���� "n" ��������� � �������,
�� ������� �������� "n" �������� ����� � ��������
������� ��������������� "n" ��� ���������� ������
���� ���������.
*/
void print_array(int data[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i] << ", ";
	}
	cout << "\n\n";
}

/*
������� fill_array ����� ����� �������� ���������,
������������ ��� O(n), ��� "n" - ���������� ���������
� �������.
*/
void fill_array(int data[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		data[i] = rand() % 10000;
	}
}

/*
������� linear_search, ����������� �������� ����� ��������
� �������, ����� ����� �������� ���������,
������������ ��� O(n), ��� "n" - ���������� ���������
� �������.

��� ���������� ��-�� ����, ��� ������� ��������� �����
�������� � �������, ��������������� ������� �����
������ ������� �� ��� ���, ���� �� ������ �������
�������� ��� �� ������� ���� ������. � ������ ������,
����� ������� �������� ����������� � ������� ���
��������� � ��� ��������� ��������, ������� ������
������ ����� ��� "n" ���������.
*/
void linear_search(int data[], const int count, int value_to_search)
{
	int linear_iteration_count = 0;
	int linear_index = -1;

	LARGE_INTEGER frequency, start_time, end_time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	for (int i = 0; i < count; i++)
	{
		linear_iteration_count++;
		if (data[i] == value_to_search)
		{
			linear_index = i;
			break;
		}
	}

	QueryPerformanceCounter(&end_time);

	double work_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart * 1000.0;

	cout << "\nValue was find by index: " << linear_index << "\n";
	cout << "Linear iteration count: " << linear_iteration_count << "\n";
	cout << "Linear search work time: " << work_time << "ms." << "\n";
	cout << "\n////////////////////////////////////////\n";

	system("pause");
}

/*
� ��� ������� binary_search, ����������� �������� (��������)
����� �������� � ��������������� �������, ����� ���
��������������� ���������, ������������ ��� O(log n),
��� "n" - ���������� ��������� � �������.

�������� ����� �������� ���� ������� ������� �������
�� ������ �������� � ��������� �������� ��������
� ��������� � ������� �����. ���� ������� ��������
������ �������� � ������� �����, ����� ������������
������ � ����� �������� �������. ���� ��� ������, ��
����� ������������ ������ � ������ ��������. ����� �������,
� ������ ��������� ������ ���������� ���������������
��������� ����������� � ��� ����.

� ����������, �� ������ �������� ��������� ������
������������� �������� ���������� ���������.
������� ���������� ��������, ����������� ���
���������� ������, ����������� ��������������
� ������ ���������� ��������� � �������.

��-�� ����� �������� ��������� ������, ��� ���������
����������� ��� O(log n), ��� ������ ��� �����
����������� ��� ������ �������� � �������
��������������� ��������.
*/
void binary_search(int data[], const int count, int value_to_search)
{
	int binary_iteration_count = 0;
	int binary_index = -1;

	sort(data, data + count);

	// print_array(data, count);

	LARGE_INTEGER frequency, start_time, end_time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);

	int L = 0, R = count - 1; // left and right border
	int M; // median element index
	while (true)
	{
		binary_iteration_count++;
		M = L + (R - L) / 2; // or (L + R) / 2
		if (data[M] > value_to_search)
			R = M - 1;
		else if (data[M] < value_to_search)
			L = M + 1;
		else
		{
			binary_index = M;
			break;
		}
		if (L > R)
			break; // oops!
	}

	QueryPerformanceCounter(&end_time);

	double work_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart * 1000.0;

	cout << "\nValue was find by index: " << binary_index << "\n";
	cout << "Binary Iteration count: " << binary_iteration_count << "\n";
	cout << "Binary search work time: " << work_time << "ms.\n";

	system("pause");
}

/*
������, ��������� ��������� ������� main ���� ����� ����������.
Ÿ ��������� ������� �� ������� ���������� ���� ��������
������ ��.

������ ��������� ������� main ������� ����� �������
���������� ������ ����������, ������ � ������� ������ �������.
� ������ ������, ������� main �������� ������ fill_array,
print_array, linear_search � binary_search, � ����� ��������
���������� ������� � ���������� ��������� ��������.

����� ��������� ������� main ����� ������������ ����������
����� ����������� �������� ������ ��. ��������,
������� fill_array � print_array ����� �������� ���������.
������� linear_search � binary_search ����� �������� O(n)
� ��������������� O(log n) ��������� ��������������.

����� �������, ����� ��������� ������� main ����� ��������
�� ������� �������, ���������� ��������� "n", � �����
������������ �������� ������������ ���������� ������ ��.
*/
int main()
{
	srand(time(0));
	rand();

	// count of array elements
	const int count = 50; // !!! change to 500, 5000, 50000

	// integer data array
	int data[count];

	fill_array(data, count);

	// print_array(data, count);

	// some value to find in array
	int value_to_search = 777;

	linear_search(data, count, value_to_search);

	binary_search(data, count, value_to_search);
}