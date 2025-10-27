#include <iostream>
#include <ctime>
#include <windows.h>
#include <algorithm>
using namespace std;

/*
функція print_array має лінійну складність, позначену
як o(n), де "n" — це кількість елементів у масиві.

це відбувається тому, що функція повинна пройти
по кожному елементу масиву та вивести його на екран.
кожна ітерація циклу виконує просту операцію виводу
елемента на екран. таким чином, час роботи функції
зростає пропорційно кількості елементів у масиві.

у цій функції цикл for проходить по всіх елементах
масиву та виконує операцію виводу на екран.
таким чином, якщо у вас є "n" елементів у масиві,
то функція виконає "n" ітерацій циклу та затратить
часу пропорційно "n" для виконання виводу
всіх елементів.
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
функція fill_array також має лінійну складність,
позначену як o(n), де "n" — кількість елементів
у масиві.
*/
void fill_array(int data[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		data[i] = rand() % 10000;
	}
}

/*
функція linear_search, що реалізує лінійний пошук значення
у масиві, також має лінійну складність,
позначену як o(n), де "n" — кількість елементів
у масиві.

це відбувається через те, що функція виконує пошук
значення у масиві, послідовно проходячи через
кожен елемент доти, доки не знайде шукане
значення або не пройде весь масив. у найгіршому випадку,
коли шукане значення відсутнє у масиві або
знаходиться в його останньому елементі, функція повинна
пройти через всі "n" елементи.
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

	cout << "\nзначення знайдено за індексом: " << linear_index << "\n";
	cout << "кількість ітерацій лінійного пошуку: " << linear_iteration_count << "\n";
	cout << "час роботи лінійного пошуку: " << work_time << " мс." << "\n";
	cout << "\n////////////////////////////////////////\n";

	system("pause");
}

/*
а от функція binary_search, що реалізує бінарний (двійний)
пошук значення в отсортованому масиві, має вже
логарифмічну складність, позначену як o(log n),
де "n" — кількість елементів у масиві.

бінарний пошук працює шляхом ділення масиву навпіл
на кожній ітерації та порівняння шуканого значення
з елементом у середній точці. якщо шукане значення
менше елемента в середній точці, пошук продовжується
тільки в лівій половині масиву. якщо воно більше, то
пошук продовжується тільки в правій половині. таким чином,
з кожною ітерацією пошуку кількість розглядаваних
елементів зменшується вдвічі.

у результаті, на кожній ітерації бінарного пошуку
відкидається половина залишених елементів.
тому кількість ітерацій, необхідних для
виконання пошуку, зменшується логарифмічно
з ростом кількості елементів у масиві.

через цю властивість бінарного пошуку, його складність
оцінюється як o(log n), що робить його дуже
ефективним для пошуку значень у великих
отсортованих масивах.
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

	int L = 0, R = count - 1; // лівий та правий кордон
	int M; // індекс медіанного елемента
	while (true)
	{
		binary_iteration_count++;
		M = L + (R - L) / 2; // або (L + R) / 2
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
			break; // ой!
	}

	QueryPerformanceCounter(&end_time);

	double work_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart * 1000.0;

	cout << "\nзначення знайдено за індексом: " << binary_index << "\n";
	cout << "кількість ітерацій бінарного пошуку: " << binary_iteration_count << "\n";
	cout << "час роботи бінарного пошуку: " << work_time << " мс.\n";

	system("pause");
}

/*
до речі, складність алгоритму функції main також можна розрахувати.
її складність залежить від часу виконання всіх операцій
всередині неї.

аналіз складності функції main вимагає врахування часу
виконання кожної інструкції, циклів та викликів інших функцій.
у цьому випадку, функція main містить виклики fill_array,
print_array, linear_search та binary_search, а також операції
заповнення масиву та виконання пошукових операцій.

загальна складність функції main буде визначатися складністю
найбільш ресурсоємних операцій усередині неї. наприклад,
функції fill_array та print_array мають лінійну складність.
функції linear_search та binary_search мають лінійну o(n)
та логарифмічну o(log n) складності відповідно.

таким чином, загальна складність функції main буде залежати
від розміру масиву, кількості елементів "n", і буде
визначатися найбільш ресурсоємними операціями всередині неї.
*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	// кількість елементів масиву
	const int count = 50;

	// масив цілих чисел
	int data[count];

	fill_array(data, count);

	// print_array(data, count);

	// певне значення для пошуку в масиві
	int value_to_search = 777;

	linear_search(data, count, value_to_search);

	binary_search(data, count, value_to_search);
}
