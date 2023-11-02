#include <iostream>
#include <cstring>

// Функция для установки заданного символа в каждый символ строки str
char* strset(char* str, char ch) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = ch;
    }
    return str;
}

// Функция для установки заданного символа в первые n символов строки str
char* strnset(char* str, char ch, int n) {
    int len = strlen(str);
    int numChars = n > len ? len : n; // Обработка случая, когда n больше длины строки
    for (int i = 0; i < numChars; i++) {
        str[i] = ch;
    }
    return str;
}

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";

    std::cout << strset(str1, '*') << std::endl; // Вывод: "************"
    std::cout << strnset(str2, '#', 5) << std::endl; // Вывод: "#####, world!"

    return 0;
}
