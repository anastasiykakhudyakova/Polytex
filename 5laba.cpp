#include <iostream> 
#include <string>  // подключаем библиотеку для работы со строками 

// Перечисление для типов оружия 
enum WeaponType { // enum создает перечисление  
    ONEHANDED,  // Одноручное 
    TWOHANDED,  // Двуручное 
    BOW,        // Лук 
    CROSSBOW    // Арбалет 
};


class Weapon {
protected: // Protected — объявляет метод или свойство защищенными. Тоесть такими, которые не могут быть  
    // доступны из объекта, реализующего класс, но вполне может быть использовано в дочерних классах. 

    //если был Private то эти переменные были бы видны только в этом классе. а так они будут вины еще и в  
    // магическом оружии, то есть в дочернем классе 

    std::string name;    // Название оружия 
    int damage;          // Наносимый урон 
    float weight;        // Вес 
    WeaponType tiporushia;     // Тип оружия 
public:
    // Конструктор с параметрами 
    Weapon(const std::string& weaponName, int weaponDamage, float weaponWeight, WeaponType tiporushia)
        : name(weaponName), damage(weaponDamage), weight(weaponWeight), tiporushia(tiporushia) {}

    // Конструктор без параметров 
    Weapon() : Weapon("Неизвестное оружие", 10, 1.0f, BOW) {}

    // GET-методы 
    std::string getName() const {
        return name;
    }

    virtual int getDamage() const {
        return damage; // этот метод вернет урон  
    }

    float getWeight() const {
        return weight;
    }

    WeaponType gettiporushia() const {
        return tiporushia;
    }

    // SET-метод для наносимого урона 
    void setDamage(int newDamage) {
        damage = newDamage; // присваивает новое значение урона 
    }
    // Метод для вывода текстового представления типа оружия 
    void displayWeaponType() const {

        if (tiporushia == 0) {
            std::cout << "Одноручное оружие" << std::endl;
        }
        if (tiporushia == 1) {
            std::cout << "Двуручное оружие" << std::endl;
        }
        if (tiporushia == 2) {
            std::cout << "Лук" << std::endl;
        }
        if (tiporushia == 3) {
            std::cout << "Арбалет" << std::endl;
        }
    }

    // Оператор сравнения - этим мы переопределим оператор "больше" для оружия, то есть мы можем сравнивать не только числа, но и 
    // само оружие 
    bool operator>(const Weapon& other) const {
        return this->getDamage() > other.getDamage();
    }

    // Оператор сравнения < 
    bool operator<(const Weapon& other) const {
        return this->getDamage() < other.getDamage();
    }
};

// Структура игрока 

//Основное отличие структуры (struct) от класса (class) заключается в том, что структура — это тип значений,  
// а класс — это ссылочный тип. члены структуры публичны 
struct Player {
    int id;                // Уникальный идентификатор 
    std::string username;  // Логин 
    std::string password;  // Пароль 

    // Функция для вывода данных игрока 
    void displayInfo() {
        std::cout << "\nID: " << id << "\nЛогин: " << username << "\nПароль: " << password << std::endl;
    }
};



// Дочерний класс для магического оружия 
class MagicWeapon : public Weapon {
private:
    int extraDamage;  // Дополнительный урон 

public:
    // Конструктор с параметрами 
    MagicWeapon(const std::string& weaponName, int weaponDamage, float weaponWeight, WeaponType tiporushia, int extraDmg)
        : Weapon(weaponName, weaponDamage, weaponWeight, tiporushia), extraDamage(extraDmg) {}

    // Конструктор без параметров 
    MagicWeapon() : MagicWeapon("Магическое оружие", 15, 1.5f, ONEHANDED, 5) {}

    // GET-метод для дополнительного урона 
    int getExtraDamage() const {
        return extraDamage;
    }

    //возращает сумму урона и доп урона 
    int getDamage() const override {//то есть если в родительском классе мы забудем добавить метод getDamage, то будет ошибка 

        //Модификатор override gзволяет компилятору следить за тем, чтобы метод,
            //помеченный этим модификатором действительно переопределял метод базового класса.  
            return damage + extraDamage;
    }
};



int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объектов 
    Weapon sword("Меч", 50, 3.5f, ONEHANDED); //создаем Объект с параметрами 
    Weapon unknownWeapon;           // Объект без параметров 

    // Вывод значений полей первого объекта 
    std::cout << "Оружие 1:" << std::endl;
    std::cout << "Название: " << sword.getName() << std::endl;
    std::cout << "Наносимый урон: " << sword.getDamage() << std::endl;
    std::cout << "Вес: " << sword.getWeight() << " кг" << std::endl;
    sword.displayWeaponType(); //выводит тип оружия 



    // Вывод значений полей второго объекта 
    std::cout << "\nОружие 2:" << std::endl;
    std::cout << "Название: " << unknownWeapon.getName() << std::endl;
    std::cout << "Наносимый урон: " << unknownWeapon.getDamage() << std::endl;
    std::cout << "Вес: " << unknownWeapon.getWeight() << " кг" << std::endl;
    unknownWeapon.displayWeaponType();



    // Изменение урона для второго оружия 
    unknownWeapon.setDamage(20);
    std::cout << "\nПосле изменения урона для неизвестного оружия:" << std::endl;
    std::cout << "Наносимый урон: " << unknownWeapon.getDamage() << std::endl;




    // Тестирование структуры Player 
    Player Igrock;
    Igrock.id = 1;
    Igrock.username = "PlayerOne";
    Igrock.password = "SecurePass123";

    Igrock.displayInfo(); //выводит информацию об игроке 


    // Тестирование класса MagicWeapon 
    MagicWeapon magicSword("Магический меч", 25, 2.5f, TWOHANDED, 10);
    magicSword.displayWeaponType();
    std::cout << "\n" << "Название: " << magicSword.getName() << std::endl;
    std::cout << "Вес: " << unknownWeapon.getWeight() << " кг" << std::endl;
    std::cout << "Урон: " << magicSword.getDamage() << std::endl;
    std::cout << "Дополнительный урон: " << magicSword.getExtraDamage() << std::endl;


    // Проверка работы операторов сравнения 
    //так как мы в классе оружия переопределили работу больше и меньше для оружияя, то теперь моем писать так: sword > magicSword 
    if (sword > magicSword) {
        std::cout << "\n" << sword.getName() << " сильнее " << magicSword.getName() << std::endl;
    }
    else if (sword < magicSword) {
        std::cout << magicSword.getName() << " сильнее " << sword.getName() << std::endl;
    }
    else {
        std::cout << sword.getName() << " и " << magicSword.getName() << " равны по силе." << std::endl;
    }


    return 0;
}
