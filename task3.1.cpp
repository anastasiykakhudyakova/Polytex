 
#include <iostream>


int main()

{
    int a = 10;
    int* pointer;
    pointer = &a;
    std::cout << "pointer = " << pointer << "\n";
    std::cout << "znachenie = " << a << "\n";

    *pointer = 15;
    
    std::cout << "novoe znachenie = " << a << "\n";

    int mArray[3][2] = { {1,2}, {3,4}, {5,6} };

    int rows = sizeof(mArray) / sizeof(mArray[0]);

    int col = sizeof(mArray[0]) / sizeof(mArray[0][0]);

    int* end = mArray[0] + rows * col - 1;

    for (int* p = mArray[0]; p <= end; p++) {

        std::cout << *p << " ""\n";

    }
    int z = 5;

    int* const pz = &z;

    std::cout << pz << " = " << *pz << "\n";

    *pz = 25;

    std::cout << pz << " = " << *pz << "\n";

    std::cout << "z" << " = " << z << "\n";

    //pz = &x;//ошибка
}

