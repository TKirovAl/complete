#include <iostream>
#include <string>

class Pizzeria {
public:
    int id;
    double rating;
    std::string name;

    Pizzeria(int id, double rating, const std::string& name) {
        this->rating = rating;
        this->id = id;
        this->name = name;
    }
};

class Menu {
public:
    int id;
    int pizzeria_id;
    std::string pizza_name;
    double price;

    Menu(int id, int pizzeria_id, const std::string& pizza_name, double price) {
        this->id = id;
        this->pizzeria_id = pizzeria_id;
        this->pizza_name = pizza_name;
        this->price = price;
    }
};

class Person {
public:
    int id;
    std::string name;
    int age;
    bool gender;
    std::string address;

    Person(int id, const std::string& name, int age, bool gender, const std::string& address) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->address = address;
    }
};

class PersonVisit {
public:
    int id;
    int person_id;
    int pizza_id;
    bool date_visit;

    PersonVisit(int id, int person_id, int pizza_id, bool date_visit) {
        this->id = id;
        this->person_id = person_id;
        this->pizza_id = pizza_id;
        this->date_visit = date_visit;
    }
};

class PersonOrder {
public:
    int id;
    int person_id;
    int menu_id;
    int order_id;

    PersonOrder(int id, int person_id, int menu_id, int order_id) {
        this->id = id;
        this->person_id = person_id;
        this->menu_id = menu_id;
        this->order_id = order_id;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    int chosenPizzeria;

    Pizzeria* pizzerias[3];
    pizzerias[0] = new Pizzeria(1, 3, "Dodo");
    pizzerias[1] = new Pizzeria(2, 4, "Mimo");
    pizzerias[2] = new Pizzeria(4, 6, "York");

    Menu* menus[3];
    menus[0] = new Menu(54, 1, "margarita", 20);
    menus[1] = new Menu(23, 2, "peperoni", 30);
    menus[2] = new Menu(65, 4, "sorok sirov", 40);

    Person* persons[3];
    persons[0] = new Person(12, "Gena", 30, true, "Address1");
    persons[1] = new Person(19, "Viktor", 25, true, "Address2");
    persons[2] = new Person(87, "Yuriy", 40, true, "Address3");

    PersonVisit* visits[3];
    visits[0] = new PersonVisit(99, 12, 2, true);
    visits[1] = new PersonVisit(68, 19, 6, true);
    visits[2] = new PersonVisit(85, 51, 1, true);

    PersonOrder* orders[3];
    orders[0] = new PersonOrder(94, 12, 54, true);
    orders[1] = new PersonOrder(24, 19, 23, true);
    orders[2] = new PersonOrder(621, 51, 76, true);

   std:: cout << "Выберите пиццерию (0-2): ";
    std::cin >> chosenPizzeria;

   std:: cout << "Информация о заказах для пиццерии " << pizzerias[chosenPizzeria]->name << ":" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (visits[i]->pizza_id == chosenPizzeria + 1) {
            int personId = visits[i]->person_id - 1;
            int menuId = visits[i]->pizza_id - 1;

            std::cout << "Заказ №" << orders[i]->id << std::endl;
            std::cout << "Покупатель: " << persons[i]->name << std::endl;
            std::cout << "Пицца: " << menus[menuId]->pizza_name << std::endl;
            std::cout << "Цена: " << menus[menuId]->price << " рублей" << std::endl;
            std::cout << "Дата заказа: " << (visits[i]->date_visit ) << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }

    return 0;
}
