#include <iostream>
int main() 
//стандартное начало программ на языке C.
{ //начало функции
    setlocale(LC_ALL, "Russian"); //позволяет делать так чтобы выводились русские буквы
    std::cout << "First string\n"; // \n переводит на следующую строку
    std::cout << "Первая строка\nВторая строка\n";
    std::cout << "Спецсимволы \"\\\"";
} //конец функции
