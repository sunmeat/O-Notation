#include <iostream>
using namespace std;

// Функция для проверки простоты числа (неоптимизированная!!!)
bool is_prime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

// Функция для нахождения суммы простых чисел до N
int sum_of_primes(int N)
{
    int sum = 0;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime(i))
        {
            cout << i << " + ";
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int N = 100;
    int result = sum_of_primes(N);
    cout << "\b\b= " << result << "\n";
}