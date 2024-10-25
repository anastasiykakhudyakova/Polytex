
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
    //Const в C++ — это ключевое слово, которое указывает, что значение переменной или параметра функции является неизменяемым 

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
    void displayInfo() const {
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
        : Weapon(weaponDamage, weaponWeight, tiporushia), extraDamage(extraDmg) {}

    // Конструктор без параметров 
    MagicWeapon() : MagicWeapon("Магическое оружие", 15, 1.5f, ONEHANDED, 5) {}

    // GET-метод для дополнительного урона 
    int getExtraDamage() const {
        return extraDamage;
    }

    //возращает сумму урона и доп урона 
    int getDamage() const {//то есть если в родительском классе мы забудем добавить метод getDamage, то будет ошибка 
        return damage + extraDamage; //Модификатор override позволяет компилятору следить за тем, чтобы метод,помеченный этим модификатором действительно переопределял метод базового класса.  
     
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


#include <iostream> // Подключаем библиотеку для выполнения ввода-вывода 
#include <string>   // Подключаем библиотеку для работы со строками 
using namespace std; // Используем стандартное пространство имен, чтобы не писать каждый раз std 

//  Создаем абстрактный класс Оружие с чисто виртуальной функцией Attack 

//Абстрактный класс в C++ — это класс, объект которого нельзя создать, 
// но который может использоваться в качестве базового класса для других классов. 

//поэтому мы не стали использовать предыдущее задание,так как в нем класс оружия был не абсрактным (там мы создавали меч) 
class Weapon {
public:
    virtual void Attack() = 0; // Чисто виртуальная функция 

    //Виртуальная функция — это функция, которую предполагается переопределить в производных классах. 
    //то есть ниже мы определяем ее отдельно для магического и одноразового оружия 
};

// Реализуем класс МагическоеОружие, который наследует Weapon 
//с помощью негоо можно вывести сообщение, что мы им аттакуем 
class MagicWeapon : public Weapon {

public:
    // Переопределяем метод Attack для магического оружия 
    void Attack() override {
        cout << "Атакуем магическим оружием" << endl; // Выводим сообщение в консоль 
    }
};


//  Создаем класс ОдноразовоеОружие, который также наследует Weapon 
class DisposableWeapon : public Weapon {
private: //bool - true/false 
    bool used; //  Поле-флаг для отслеживания использования оружия 
    string name; // Имя оружия 
public:
    // Конструктор, который инициализирует флаг used значением false 
    DisposableWeapon(string weaponName) : used(false), name(weaponName) {}// по умолчанию оружие не использовано 

    // Переопределяем метод Attack 
    void Attack() override {
        if (used) { // Проверяем, было ли оружие использовано 
            cout << "Оружие уже было использовано" << endl; // Сообщаем, если использовано 
        }
        else {
            cout << "Атакуем одноразовым оружием " << name << endl; // Атакуем, если не использовано 
            used = true; // Устанавливаем флаг использования в true 
        }
    }
};





//  Создаем шаблонный класс для хранения оружия в левой и правой руке 
//Шаблонный класс в C++ — это класс, который позволяет задать внутри класса объекты, тип которых на этапе написания кода неизвестен 
//это мы делает потому что мы заранее не знаем, какое оружие в какой руке находится 
template <typename LeftWeaponType, typename RightWeaponType>
class WeaponStorage {
private:
    LeftWeaponType leftWeapon; // Оружие в левой руке 
    RightWeaponType rightWeapon; // Оружие в правой руке 

public:
    // Конструктор для инициализации оружия 
    WeaponStorage(LeftWeaponType lw, RightWeaponType rw)
        : leftWeapon(lw), rightWeapon(rw) {}

    // Метод для установки левого оружия 
    void setLeftWeapon(LeftWeaponType lw) {
        leftWeapon = lw;
    }

    // Метод для получения левого оружия 
    LeftWeaponType getLeftWeapon() {
        return leftWeapon;
    }

    // Метод для установки правого оружия 
    void setRightWeapon(RightWeaponType rw) {
        rightWeapon = rw;
    }

    // Метод для получения правого оружия 
    RightWeaponType getRightWeapon() {
        return rightWeapon;
    }
};





int main() {

    setlocale(LC_ALL, "Russian");
    //  Убедимся, что нельзя создать экземпляр абстрактного класса 
    //Weapon Sword; // Это вызовет ошибку компиляции 

    //  Создаем экземпляр магического оружия и вызываем метод Attack 
    MagicWeapon magicWeapon;
    magicWeapon.Attack(); // Ожидаем "Атакуем магическим оружием" 




    // Создаем экземпляр одноразового оружия 
    DisposableWeapon palka("палка");

    // Первый вызов Attack 
    palka.Attack(); // Ожидаем "Атакуем одноразовым оружием" 
    // Второй вызов Attack 
    palka.Attack(); // Ожидаем "Оружие уже было использовано" 


    // Создаем экземпляр одноразового оружия (так как первая палка сломалась) 
    DisposableWeapon palka2("палка2");



    //  Проверяем работу шаблона с типами оружия и целочисленным типом
        WeaponStorage<MagicWeapon, int> storage1(magicWeapon, 101); // Создаем хранилище 

    // Получим и используем системы оружия 
    storage1.getLeftWeapon().Attack(); //  "Атакуем магическим оружием" 
    cout << "ID оружия в правой руке: " << storage1.getRightWeapon() << endl; // Выводим ID 


    WeaponStorage<MagicWeapon, DisposableWeapon> storage3(magicWeapon, palka2); // Создаем хранилище 
    storage3.getLeftWeapon().Attack(); //  "Атакуем магическим оружием" 
    storage3.getRightWeapon().Attack(); //  "Атакуем одноразовым оружием" 




    return 0;
}
