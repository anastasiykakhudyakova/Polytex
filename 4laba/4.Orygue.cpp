#include "Orygue.h"

void Orygue::print() 
{
    std::cout << "Name: " << name << "\tYron: " << yron << "\tWeight: " << weight << std::endl;
}


Orygue::Orygue(std::string _name, unsigned int _weight, unsigned int _yron) {
    name = _name;
    weight = _weight;
    yron = _yron;
}

Orygue::Orygue() {

    name = "Lilili";
    yron = 343432;
    weight = 3443;

}

Orygue::~Orygue()
{
    std::cout << "Orygue" << name << " deleted" << std::endl;
}

void Orygue::operator=(const Orygue& other) {
    name = other.name;
    weight = other.weight;
    yron = other.yron;

}


bool Orygue::maxweight(unsigned int max_weight)
{
    if (max_weight > weight) {
        return true;
    }
    else {
        return false;
    }

}


int Orygue::sumweight(const Orygue & other) {
    return other.weight + weight;
}

int Orygue::operator+(const Orygue& other) {
    return sumweight(other);
}

