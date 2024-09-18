#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int x;

    std::cout << "Введите певрое число ";

    std::cin >> x;

    int y;

    std::cout << "Введите второе число ";

    std::cin >> y;

    int sr;

    sr = (x + y)/2;

    std::cout << "среднее арифм " << sr << std::endl;

    
    std::cout << "Введите знак: ";
    char p;
    std::cin >> p;

    int res;
    /*
    if (p == '+') {
        res = x + y;
    }
    else if (p == '-') {
        res = x - y;
    }
    else if (p == '/') {
        res = x / y;
    }
    else if (p == '*') {
        res = x * y;
    }
    else {
        std::cout << "ошибка\n";
        return 0;
    }
    */

    switch (p)
    {
    case '+':
        res = x + y;
        break;
    case '-':
        res = x - y;
        break;
    case '/':
        res = x / y;
        break;
    case '*':
        res = x * y;
        break;
    default:
        std::cout << "ошибка\n";
        break;
    }

    std::cout << res << std::endl;
}
