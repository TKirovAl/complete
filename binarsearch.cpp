#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Если элемент не найден, возвращаем -1 или другое значение, которое определяет отсутствие элемента
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6;
    
    int index = binarySearch(arr, target);
    
    if (index != -1) {
        std::cout << "Элемент найден на индексе: " << index << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0;
}
