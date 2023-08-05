#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

enum colors {
	RED = 12, GREEN = 10, BLUE = 9,
	GRAY = 7, YELLOW = 14, WHITE = 15,
	DARKYELLOW = 6, DARKGRAY = 8, DARKGREEN = 2
};

void print_array(int data[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i] << ", ";
	}
	cout << "\n\n";
}

void fill_array(int data[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		data[i] = rand() % 10000;
	}
}

/*
Алгоритм сортировки пузырьком (bubble_sort)
имеет квадратичную сложность O(N^2).

В данной реализации сортировка пузырьком состоит из двух
вложенных циклов. Внешний цикл выполняет N-1 проходов по массиву,
а внутренний цикл проходит от последнего элемента до второго
(от k = count - 1 до k = 1). На каждом проходе внутренний цикл
сравнивает текущий элемент с предыдущим и, если текущий элемент
меньше предыдущего, выполняет обмен их местами.

При сортировке пузырьком в худшем случае для каждого элемента
массива производится ещё N-1 сравнений (при k=1). Это приводит к тому,
что общее количество операций будет пропорционально квадрату
размера массива, т.е. O(N^2).

При работе с большими массивами сортировка пузырьком может
быть неэффективной из-за своей квадратичной сложности,
но для небольших массивов и обучающих целей она может быть
неплохим примером сортировочного алгоритма.
*/
void bubble_sort(int data[], const int count)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int pr = 0; pr < count - 1; pr++)
	{
		SetConsoleTextAttribute(h, DARKYELLOW);
		cout << "///////////////////////////\n"; // показ номера проходов
		SetConsoleTextAttribute(h, YELLOW);
		cout << "Номер прохода: " << pr << "\n";
		SetConsoleTextAttribute(h, DARKYELLOW);
		cout << "///////////////////////////\n\n";
		SetConsoleTextAttribute(h, DARKGRAY);
		for (int k = count - 1; k > 0; k--)
		{
			if (data[k - 1] > data[k])
			{ // сравниваем пару элементов, если левый больше правого
				double temp = data[k];
				data[k] = data[k - 1];
				data[k - 1] = temp;

				for (int i = 0; i < count; i++)
				{
					if (i == k)
						SetConsoleTextAttribute(h, RED); // красным и синим отмечена перестановочная пара
					else if (i == k - 1)
						SetConsoleTextAttribute(h, BLUE);
					else
						SetConsoleTextAttribute(h, DARKYELLOW);
					cout << data[i] << "\t";
				}
				cout << "\n";
			}
		}

		SetConsoleTextAttribute(h, GRAY);
		cout << "\nPезультат прохода:\n\n"; // показать что получилось на этом проходе
		SetConsoleTextAttribute(h, WHITE);
		for (int i = 0; i < count; i++)
			cout << data[i] << "\t";
		cout << "\n\n";
	}
}

/*
А вот у функции random_sort сложность алгоритма не явно определена
из-за использования случайных операций, таких как rand().
Сложность такого алгоритма будет зависеть от статистических
свойств случайных операций и длины массива count.

Похоже, что функция random_sort предполагает сортировку
массива путём случайных перестановок элементов до тех пор,
пока массив не будет отсортирован. Алгоритм не гарантирует
сортировку массива за конечное количество операций,
и его эффективность будет зависеть от совпадения случайных
перестановок с требуемой сортировкой.

Такой подход сортировки называется "BogoSort" или "Monkey Sort"
и является алгоритмом сравнительно плохой производительности.
В худшем случае, когда случайные перестановки не приносят результата,
алгоритм может выполняться очень долго и не завершаться.

Сложность алгоритма random_sort непредсказуема и зависит
от случайных факторов, поэтому её трудно формально оценить.
*/
void random_sort(int data[], const int count)
{
	bool in_order = false;

	int total_try = 0;

sorting:
	while (!in_order)
	{

		for (int i = 0; i < 1000; i++)
		{
			int swap_position1 = rand() % count;
			int swap_position2 = rand() % count;
			int temp = data[swap_position1];
			data[swap_position1] = data[swap_position2];
			data[swap_position2] = temp;
		}

		// current state of array
		cout << ++total_try << ": ";
		print_array(data, count);

		for (int i = 0; i < count - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				goto sorting;
			}
		}
		in_order = true;
	}
}

int main()
{
	system("title Sorting");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(0, "");

	srand(time(0));
	rand();

	// count of array elements
	const int count = 5; // !!!

	// integer data array
	int data[count];

	SetConsoleTextAttribute(h, DARKGREEN);
	cout << "Массив до сортировки:\n\n";
	SetConsoleTextAttribute(h, GREEN);
	fill_array(data, count);
	print_array(data, count);
	SetConsoleTextAttribute(h, GRAY);
	cout << endl;

	bubble_sort(data, count);
	// random_sort(data, count);

	SetConsoleTextAttribute(h, DARKGREEN);
	cout << "\n\nМассив после сортировки:\n\n";
	SetConsoleTextAttribute(h, GREEN);

	print_array(data, count);

	Sleep(INFINITE);
}