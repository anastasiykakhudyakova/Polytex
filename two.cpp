 
#include <iostream>
// библиотека

int main()
// главная исполняемая функция
{
    setlocale(LC_ALL, "Russian");
    // делаем так чтобы вывводились русские буквы
    std::cout << "First string\n" << "Первая строка\n" << "Вторая строка\n";
    // ввывод First string, Первая строка, Вторая строка, \n-переход на новую строку
    std::cout << "Спецсимволы\\\n";
    // ввывод спецсимволы и слеша
    int a = 150;
    float b=15.933;
    unsigned char c =250;
    std::cout << "a=" << a << '\n';
    std::cout << "b=" << b << '\n';
    std::cout << "c=" << c << '\n';
    //введем переменные из предыдущего задания в формате «Моя дата рождения : ДЕНЬ МЕСЯЦ ГОД года»
    int d = 27;
    std::string m = "Апрель";
    int g = 2005;
    std::cout << "Моя дата рождения : " << d << " " << m << " " << g << '\n';
    const float x{ 2.3 };
    const std::string y{ "WINDOWS" };

    std::cout << x << " " << y;
}
