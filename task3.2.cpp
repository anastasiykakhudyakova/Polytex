//1.       Создайте функцию, которая принимает 2 указателя(на начало и конец массива) и которая возвращает сумму всех элементов массива.
//2.       Проверьте правильность работы функции, вызвав её и передав массив из нескольких чисел.
//3.       Создайте 2 функции, принимающих 2 параметра и возвращающих их сумму и их разность соответственно.
//4.       Создайте функцию, принимающую 1 параметр типа char.
//5.       Созданная функция должна возвращать указатель на одну из двух функций(суммы или разности) в зависимости от значения переданного char.Если он равен '+', то возвращается указатель на функцию суммы, а если он равен '-', то возвращается указатель на функцию разности.
//6.       Проверьте работу созданных функций, вызвав сначала ту, что возвращает указатель, а потом вызвав и эту функцию по указателю, получив правильное значение, которое затем выведите в консоль.
//7.       Создайте динамический указатель типа float.
//8.       Выведите его в консоль, а после удалите его из памяти с помощью delete.

#include <iostream> 
int sumArray(int* begin, int* end) {
    int sum = 0;
    while (begin != end) {
        sum += *begin;
        begin++;
    }
    return sum;
}
int sum(int a, int b) {
    return a + b;
}

int raznost(int a, int b) {
    return a - b;
}
typedef int (*FuncPtr)(int, int);

FuncPtr getOperation(char fyn) {
    if (fyn == '+') {
        return &sum;
    }
    else if (fyn == '-') {
        return &raznost;
    }
    else {
        return nullptr;
    }
}


int main() {

    setlocale(LC_ALL, "Russian");

    int myArray[] = { 1, 2, 3, 4, 5 };
    int* begin = myArray;
    int* end = myArray + 5;
    int result = sumArray(begin, end);
    std::cout << "Сумма элементов массива равна: " << result << std::endl;

    FuncPtr myFunc = getOperation('+');
    int res = myFunc(5, 3);
    std::cout << "Сумма: " << res << std::endl;

    myFunc = getOperation('-');
    res = myFunc(5, 3);
    std::cout << "Разность: " << res << std::endl;

    std::cout << "Сумма2: " << sum(5, 3) << std::endl;

    std::cout << "Разность2: " << raznost(5, 3) << std::endl;


    float* myFloat = new float;
    *myFloat = 3.14;
    std::cout << "myFloat: " << *myFloat << std::endl;
    delete myFloat;
}
