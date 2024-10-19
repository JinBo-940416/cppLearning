#ifndef __LIB_GUARD__
#define __LIB_GUARD__
#include <iostream>
#include <string>

class person
{
    std::string name;
    int age;
public:
    person();
    person(std::string _name, int _age); //constructor cannot use this pointer
    void print_attr();
    void print_members_addr();
    void set_age(const int &_age);
    person operator+(const person &_person);
};

int *generate_6_number();
void testing(const int a);
void reference_testing(const int &a);

#endif