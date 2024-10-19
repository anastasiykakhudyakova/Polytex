#pragma once

#include <iostream>
#include <string>

class Orygue
{
private:
    std::string name;
    unsigned int weight, yron;
public:
    void print();
    Orygue(std::string _name, unsigned int _weight, unsigned int _yron);
    Orygue();
    ~Orygue();
    void operator=(const Orygue& other);
    bool maxweight(unsigned int max_weight);
    int sumweight(const Orygue& other);

    int operator + (const Orygue& other);

};
