#include <iostream>

class Orygue
{
public:
    std::string name;
    unsigned int weight, yron;
    void print()
    {
        std::cout << "Name: " << name << "\tYron: " << yron << "\tWeight: " << weight << std::endl;
    }
    Orygue(std::string _name, unsigned int _weight, unsigned int _yron) {
        name = _name;
        weight = _weight;
        yron = _yron;
    }
    Orygue() {
    
        name = "Lilili";
        yron = 343432;
        weight = 3443;
    
    }

};



int main()
{
    Orygue orygue("Orygue",50,90);
    orygue.print();

    Orygue orygue2;
    orygue2.print();
}
