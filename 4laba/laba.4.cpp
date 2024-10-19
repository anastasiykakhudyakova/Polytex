
#include <iostream>
#include "Orygue.h"


int main()
{
    Orygue orygue("Orygue", 50, 90);

    

    orygue.print();

    Orygue orygue2;
    orygue2.print();
    Orygue* obj = new Orygue;
    //обращаемся
    obj->print();
    
    std::cout << orygue.maxweight(1000) << ' ' << orygue2.maxweight(100);

    //и не забываем удалять динамические объекты
    delete obj;

}
