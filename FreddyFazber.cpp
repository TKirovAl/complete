```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// Структура для представления информации о пиццериях
struct Pizzeria {
    std::string name;
    int numVisits;
    int numMaleVisits;
    int numFemaleVisits;
    std::unordered_map<std::string, int> pizzaPrices;
};

int main() {
    // Создаем список пиццерий
    std::vector<Pizzeria> pizzerias = {
        {"Pizzeria A", 100, 50, 50, {{"Margherita", 8}, {"Pepperoni", 10}, {"Hawaiian", 9}}},
        {"Pizzeria B", 150, 75, 75, {{"Margherita", 7}, {"Pepperoni", 10}, {"Hawaiian", 8}}},
        {"Pizzeria C", 200, 100, 100, {{"Margherita", 8}, {"Pepperoni", 11}, {"Hawaiian", 9}}}
    };

    // 1. Найти пиццерии, которые были посещены больше женщинами или мужчинами
    std::vector<std::string> pizzeriasByGender;
    for (const auto& pizzeria : pizzerias) {
        if (pizzeria.numMaleVisits > pizzeria.numFemaleVisits) {
            pizzeriasByGender.push_back(pizzeria.name);
        }
    }

    // Сортируем и выводим первые 3 пиццерии
    std::sort(pizzeriasByGender.begin(), pizzeriasByGender.end());
    std::cout << "Пиццерии, посещенные больше мужчинами: " << std::endl;
    for (size_t i = 0; i < pizzeriasByGender.size() && i < 3; ++i) {
        std::cout << pizzeriasByGender[i] << std::endl;
    }

    // 2. Найти пиццерии, которые были посещены только женщинами или мужчинами
    std::string singleGenderPizzeria;
    for (const auto& pizzeria : pizzerias) {
        if (pizzeria.numMaleVisits == 0 || pizzeria.numFemaleVisits == 0) {
            singleGenderPizzeria = pizzeria.name;
            break;
        }
    }
    std::cout << "Пиццерия, посещенная только одним полом: " << singleGenderPizzeria << std::endl;

    // 3. Найти пиццерию, которую посетил Андрей, но не сделал заказ
    std::string andrewPizzeria;
    for (const auto& pizzeria : pizzerias) {
        if (pizzeria.name == "Pizzeria A" && pizzeria.numVisits > pizzeria.pizzaPrices.size()) {
            andrewPizzeria = pizzeria.name;
            break;
        }
    }
    std::cout << "Пиццерия, посещенная Андреем, но не сделан заказ: " << andrewPizzeria << std::endl;
