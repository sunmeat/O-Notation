#include <iostream>
#include <ctime>
#include <windows.h>
#include <algorithm>
using namespace std;

/*
Функция print_array имеет линейную сложность, обозначаемую
как O(n), где "n" - это количество элементов в массиве.

Это происходит потому, что функция должна пройти
по каждому элементу массива и вывести его на экран.
Каждая итерация цикла выполняет простую операцию вывода
элемента на экран. Таким образом, время работы функции
растёт пропорционально количеству элементов в массиве.

В данной функции цикл for проходит по всем элементам
массива и выполняет операцию вывода на экран.
Таким образом, если у вас есть "n" элементов в массиве,
то функция выполнит "n" итераций цикла и затратит
времени пропорционально "n" для выполнения вывода
всех элементов.
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
Функция fill_array также имеет линейную сложность,
обозначаемую как O(n), где "n" - количество элементов
в массиве.
*/
void fill_array(int data[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		data[i] = rand() % 10000;
	}
}

/*
Функция linear_search, реализующая линейный поиск значения
в массиве, также имеет линейную сложность,
обозначаемую как O(n), где "n" - количество элементов
в массиве.

Это происходит из-за того, что функция выполняет поиск
значения в массиве, последовательно проходя через
каждый элемент до тех пор, пока не найдет искомое
значение или не пройдет весь массив. В худшем случае,
когда искомое значение отсутствует в массиве или
находится в его последнем элементе, функция должна
пройти через все "n" элементов.
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
А вот функция binary_search, реализующая бинарный (двоичный)
поиск значения в отсортированном массиве, имеет уже
логарифмическую сложность, обозначаемую как O(log n),
где "n" - количество элементов в массиве.

Бинарный поиск работает путём деления массива пополам
на каждой итерации и сравнения искомого значения
с элементом в средней точке. Если искомое значение
меньше элемента в средней точке, поиск продолжается
только в левой половине массива. Если оно больше, то
поиск продолжается только в правой половине. Таким образом,
с каждой итерацией поиска количество рассматриваемых
элементов уменьшается в два раза.

В результате, на каждой итерации бинарного поиска
отбрасывается половина оставшихся элементов.
Поэтому количество итераций, необходимых для
выполнения поиска, уменьшается логарифмически
с ростом количества элементов в массиве.

Из-за этого свойства бинарного поиска, его сложность
оценивается как O(log n), что делает его очень
эффективным для поиска значений в больших
отсортированных массивах.
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
Кстати, сложность алгоритма функции main тоже можно рассчитать.
Её сложность зависит от времени выполнения всех операций
внутри неё.

Анализ сложности функции main требует учёта времени
выполнения каждой инструкции, циклов и вызовов других функций.
В данном случае, функция main содержит вызовы fill_array,
print_array, linear_search и binary_search, а также операции
заполнения массива и выполнения поисковых операций.

Общая сложность функции main будет определяться сложностью
самых ресурсоёмких операций внутри неё. Например,
функции fill_array и print_array имеют линейную сложность.
Функции linear_search и binary_search имеют линейную O(n)
и логарифмическую O(log n) сложности соответственно.

Таким образом, общая сложность функции main будет зависеть
от размера массива, количества элементов "n", и будет
определяться наиболее ресурсоёмкими операциями внутри неё.
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
