/*/
1.  Попросите пользователя ввести число 1, 2 или 3 и выведите его в текстовом виде : "Один", "Два" или "Три" соответственно.

2.  Если пользователь ввёл другое число, то выбросите исключение, в обработке которого выведите в консоль : "Некорректное значение".

3.  Попросите пользователя ввести год своего рождения.

4.  Если пользователь ввёл число меньше 1850, то выбросите исключение и в catch выведите в консоли : "Что-то не верится...".

5.  Если пользователь ввёл число больше, чем текущий год, то выбросите исключение и в catch выведите в консоли : "Вы ещё не родились".

6.  Если пользователь ввёл отрицательное число, то выбросите исключение и в catch выведите в консоли : "Вы ввели отрицательное число!".

7.  Если ввод был корректный(и не было, как следствие, исключений), то выведите в консоль : "Спасибо!".

8.  Создайте свой класс исключений с перечислением(для кода ошибок) и переработайте задание с годом рождения так, чтобы выбрасывалось уже Ваше исключение.
/*/

#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    cout << "Введите число 1, 2 или 3" << endl;
    cin >> choice;
    try {
        switch (choice) {
        case 1:
            cout << "Один" << endl;
            break;
        case 2:
            cout << "Два" << endl;
            break;
        case 3:
            cout << "Три" << endl;
            break;
        default:
            throw runtime_error("Некорректное значение");
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    int birthYear;
    cout << "Введите год вашего рождения: ";
    cin >> birthYear;
    try {
        if (birthYear < 0) {
            throw runtime_error("Вы ввели отрицательное число");
        }
        else if (birthYear < 1850) {
            throw runtime_error("Что то не верится");
        }
        else if (birthYear > 2024) {
            throw runtime_error("Вы еще не родились");
        }

        cout << "Вы ввели год рождения: " << birthYear << endl;


    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "Спасибо!" << endl;
    return 0;
}


enum ErrorCode {
    NegativeYear,
    FutureYear,
    YearTooOld
};

class BirthYearException : public runtime_error {
public:
    ErrorCode code;

    BirthYearException(const string& message, ErrorCode errCode)
        : runtime_error(message), code(errCode) {}
};

