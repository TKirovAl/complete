#include <iostream>
#include <vector>

// Функция для поиска числа N в массиве
bool searchNInArray(std::vector<int> arr, int N)
{
    for (int num : arr) {
        if (num == N) {
            return true;
        }
    }
    return false;
}

// Функция для поиска числа N^2 в массиве
bool searchNSquaredInArray(std::vector<int> arr, int N)
{
    for (int num : arr) {
        if (num == N * N) {
            return true;
        }
    }
    return false;
}

// Функция для поиска числа N+N в массиве
bool searchNPlusNInArray(std::vector<int> arr, int N)
{
    for (int num : arr) {
        if (num == N + N) {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Поиск числа N в массиве
    bool found = searchNInArray(arr, N);
    std::cout << "Число " << N << " " << (found ? "найдено" : "не найдено") << std::endl;

    // Поиск числа N^2 в массиве
    found = searchNSquaredInArray(arr, N);
    std::cout << "Число " << N * N << " " << (found ? "найдено" : "не найдено") << std::endl;

    // Поиск числа N+N в массиве
    found = searchNPlusNInArray(arr, N);
    std::cout << "Число " << N + N << " " << (found ? "найдено" : "не найдено") << std::endl;

    return 0;
}
