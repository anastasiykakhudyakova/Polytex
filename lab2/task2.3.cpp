
#include <iostream>

int fe(int x = 1) {

    if (x <= 0) {
        return 0;
    }
    int s = 0;
    int i = 1;

    while (i <= x) {
        s += i;
        i++;
    }
    return s;
}

void Function(int a, int b, int& sum, int& pr) {
    sum = a + b;
    pr = a * b;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int an[2][3] = {
        {2, 3, 4},
        {3, 4, 6}
    };


    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += an[i][j];
        }
    }


    std::cout << "Сумма всех элементов: " << sum << std::endl;

    int an1[3];
    
    an1[0] = an[0][0] + an[1][0];
    an1[1] = an[0][1] + an[1][1];
    an1[2] = an[0][2] + an[1][2];


    std::cout << "Одномерный массив: ";
    for (int i = 0; i < 3; i++) {
        std::cout << an1[i] << " ";
    }
    std::cout << std::endl;

    float t = 20.84;
    float& t1 = t;
    float& t2 = t;

    t1 = 30.75;

    std::cout << "t: " << t << std::endl;
    std::cout << "t2: " << t2 << std::endl;

    std::cout << fe(0) << std::endl;
    std::cout << fe(4) << std::endl;
    std::cout << fe() << std::endl;


    int sumResult, prResult;

    Function(5, 10, sumResult, prResult);

    std::cout << "Сумма: " << sumResult << std::endl;
    std::cout << "Произведение: " << prResult << std::endl;

    int x = 77;
    std::cout << x << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        int y = 10;
        std::cout << y << " ";
    }
    std::cout << std::endl;
    //std::cout << y << std::endl;

}
