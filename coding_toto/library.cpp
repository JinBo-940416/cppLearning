#include "library.h"
#include <iomanip>

person::person()
{
    std::cout << "default constructor for person invoked !" << std::endl;
}

person::person(std::string _name, int _age)
{
    std::cout << "non default constructor is invoked, name: " << _name << " age: " << _age << ", end!" << std::endl;
    if (_age < 0 || _age > 100) {
        std::cout << "invalid age has been entered: " << _age << std::endl;
    }
    name = _name;
    age = _age;
}

void person::print_attr()
{
    std::cout << "person name is : " << this->name << " age is : " << this->age << std::endl;
}

void person::print_members_addr()
{
    std::cout << "addr of person obj: " << std::hex << this << std::endl;
    std::cout << "addr of name: " << std::hex << &(this->name) << std::endl;
    std::cout << "addr of age : " << std::hex << &(this->age) << std::endl;
}

void person::set_age(const int &_age)
{
    this->age = _age;
}

person person::operator+(const person &_person)
{
    person sum = person(this->name, this->age);
    sum.set_age(sum.age + _person.age);

    return sum;
}

void testing(const int a)
{
    std::cout << "testing address of int passed in is: " << std::hex << &a << std::endl;
}
void reference_testing(const int &a)
{
    std::cout << "reference_testing address of int passed in is: " << std::hex << &a << std::endl;
}
