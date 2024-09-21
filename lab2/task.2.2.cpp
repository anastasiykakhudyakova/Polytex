
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x;

    std::cout << "Введите целое положительное число: ";

    std::cin >> x;

    while (x < 0) {

        std::cout << "Ошибка! " << "Введите положительное число: ";

        std::cin >> x;
    }

    int i = 1;

    while (i <= x) {

        std::cout << i << "\n";

        i++;

    }

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Элементы на четных местах: ";
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            sum += arr[i];
        }
    }

    std::cout << "Сумма элементов на нечетных позициях: " << sum << std::endl;

}

//1.    Попросите пользователя ввести целое положительное число. 
// Если число будет введено отрицательное, то повторно запросить ввод (это делается с помощью бесконечного цикла вида while (true) и break из него при правильном вводе пользователем числа).
//2.    Выведите сумму всех чисел от 1 до введённого числа.Например, если пользователь ввёл 4, то в консоль надо вывести результат : 1 + 2 + 3 + 4.
//3.    Создайте массив из 10 чисел на Ваше усмотрение.
//4.    Выведите все 10 чисел из массива в консоль в формате : "ПЕРВОЕ_ЧИСЛО ВТОРОЕ_ЧИСЛО ... ДЕСЯТОЕ_ЧИСЛО".
//5.    Выведите числа, стоящие на чётных позициях массива(0, 2, 4, 6, 8), используя цикл и операцию% .
//6.    Выведите сумму элементов массива, стоящих на нечётных позициях(1, 3, 5, 7, 9), используя цикл и операцию% .