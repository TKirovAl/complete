#include <iostream>
#include <cstring>

// Функция для проверки, является ли символ уникальным
bool isUnique(char* str, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (str[i] == str[index])
        {
            return false;
        }
    }
    return true;
}

// Функция для генерации правильного названия файла
void generateFileName(char* folderName, int folderLen, char* fileName, int fileLen, char* buffer, int index, int& count)
{
    if (index == folderLen + fileLen)
    {
        buffer[index] = '\0';
        std::cout << "В папке " << folderName << " создан файл " << buffer + folderLen << std::endl;
        count++;
        return;
    }

    if (index < folderLen)
    {
        buffer[index] = folderName[index];
        generateFileName(folderName, folderLen, fileName, fileLen, buffer, index + 1, count);
    }
    else if (index == folderLen)
    {
        buffer[index] = '.';
        generateFileName(folderName, folderLen, fileName, fileLen, buffer, index + 1, count);
    }
    else
    {
        for (int i = 0; i < fileLen; i++)
        {
            if (isUnique(fileName, i))
            {
                buffer[index] = fileName[i];
                generateFileName(folderName, folderLen, fileName, fileLen, buffer, index + 1, count);
            }
        }
    }
}

int main()
{
    // Ввод данных от пользователя
    char folderName[256];
    int folderCount;
    char fileName[256];
    int fileCount;
    setlocale(LC_ALL, "Russian")

    std::cout << "Введите строку с уникальными символами для названия папок: ";
    std::cin >> folderName;

    std::cout << "Введите количество папок: ";
    std::cin >> folderCount;

    std::cout << "Введите строку с уникальными символами для названия файлов: ";
    std::cin >> fileName;

    std::cout << "Введите количество файлов: ";
    std::cin >> fileCount;

    // Создание и заполнение буфера
    char buffer[256];
    int count = 0;

    for (int i = 0; i < folderCount; i++)
    {
        std::cout << "Создана папка " << folderName << std::endl;

        generateFileName(folderName, std::strlen(folderName), fileName, std::strlen(fileName), buffer, 0, count);
    }

    std::cout << "Всего создано " << count << " файлов." << std::endl;

    return 0;
}
