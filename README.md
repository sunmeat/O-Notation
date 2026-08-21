# O-Notation & Algorithm Complexity in C++

Цей репозиторій присвячений аналізу алгоритмічної складності (Big O Notation) та практичним прикладам оцінки ефективності алгоритмів мовою C++.

---

## 📚 Основні Теми

Репозиторій охоплює теоретичні та практичні аспекти оцінки складності:

1. **Часова складність (Time Complexity):**
   - $O(1)$ — Константна складність (прямий доступ до елементів масиву, базові арифметичні операції).
   - $O(\log n)$ — Логарифмічна складність (бінарний пошук).
   - $O(n)$ — Лінійна складність (лінійний пошук, одноразовий прохід по масиву).
   - $O(n \log n)$ — Лінійно-логарифмічна складність (швидке сортування `QuickSort`, сортування злиттям `MergeSort`).
   - $O(n^2)$ — Квадратична складність (сортування бульбашкою `BubbleSort`, вставками `InsertionSort`, вибором `SelectionSort`).
   - $O(2^n)$ та $O(n!)$ — Експоненціальна та факторіальна складність (рекурсивне обчислення чисел Фібоначчі, задача про комівояжера).

2. **Просторова складність (Space Complexity):**
   - Оцінка використання додаткової пам'яті (In-place алгоритми проти алгоритмів з виділенням допоміжних масивів чи стеку рекурсії).

3. **Бенчмаркінг та Порівняння:**
   - Вимірювання часу виконання реальних алгоритмів за допомогою бібліотеки `<chrono>`.

---

## 🛠 Вимоги та Збирання

Для компіляції та запуску бенчмарків потрібен компілятор C++ із підтримкою стандарту **C++17** або новішого.

### Компіляція через GCC (MinGW / Linux)

```bash
# Клонування репозиторію
git clone https://github.com/sunmeat/O-Notation.git
cd O-Notation

# Компіляція
g++ -std=c++17 -O2 -Wall main.cpp -o o_notation_demo

# Запуск
./o_notation_demo
```

---

## 🚀 Приклад Вимірювання Часу Виконання

```cpp
#include <iostream>
#include <vector>
#include <chrono>

// O(n) - Лінійний пошук
bool linearSearch(const std::vector<int>& arr, int target) {
    for (int val : arr) {
        if (val == target) return true;
    }
    return false;
}

int main() {
    std::vector<int> data(1000000, 42);

    auto start = std::chrono::high_resolution_clock::now();
    bool found = linearSearch(data, 42);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Час виконання: " << duration.count() << " ms" << std::endl;

    return 0;
}
```

---

## 👤 Автор

* **GitHub:** [@sunmeat](https://github.com/sunmeat)
* **Підтримка:** [Monobank](https://send.monobank.ua/2YRyvEGWAn)
