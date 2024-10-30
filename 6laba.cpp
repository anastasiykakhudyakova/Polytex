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
#include <string>
#include <stdexcept>
#include <ctime>
#include <locale>

// Определим собственное исключение с перечислением кодов ошибок
class BirthYearException : public std::exception {
public:
    enum ErrorCode {
        YEAR_TOO_OLD,
        YEAR_IN_FUTURE,
        NEGATIVE_YEAR
    };

    BirthYearException(ErrorCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
        case YEAR_TOO_OLD:
            return "Что-то не верится...";
        case YEAR_IN_FUTURE:
            return "Вы ещё не родились";
        case NEGATIVE_YEAR:
            return "Вы ввели отрицательное число!";
        default:
            return "Неизвестная ошибка";
        }
    }

private:
    ErrorCode code;
};

// Функция для преобразования числа в текст
std::string numberToText(int number) {
    switch (number) {
    case 1: return "Один";
    case 2: return "Два";
    case 3: return "Три";
    default: throw std::invalid_argument("Некорректное значение");
    }
}

// Функция для проверки года рождения
void checkBirthYear(int year) {
    int currentYear = std::time(0) / (60 * 60 * 24 * 365.25) + 1970; // получение текущего года

    if (year < 1850) {
        throw BirthYearException(BirthYearException::YEAR_TOO_OLD);
    }
    else if (year > currentYear) {
        throw BirthYearException(BirthYearException::YEAR_IN_FUTURE);
    }
    else if (year < 0) {
        throw BirthYearException(BirthYearException::NEGATIVE_YEAR);
    }
    else {
        std::cout << "Спасибо!" << std::endl;
    }
}

int main() {
    // Устанавливаем локаль для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "Введите число 1, 2 или 3: ";
        int num;
        std::cin >> num;
        std::cout << numberToText(num) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Введите год своего рождения: ";
        int birthYear;
        std::cin >> birthYear;
        checkBirthYear(birthYear);
    }
    catch (const BirthYearException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
