#include <iostream>
#include "library.h"
#include "toto.h"

int main()
{
    // std::cout << "hello world" << std::endl;

    // person jinbo = person("jinbo", 31);

    // jinbo.print_members_addr();

    // int a = 10;
    // std::cout << "main address of int a is: " << std::hex << &a << std::endl;
    // testing(a);
    // reference_testing(a);

    // person yangjie = person("yangjie", 26);

    // std::cout << "before adding :" << std::endl;
    // jinbo.print_attr();
    // yangjie.print_attr();

    // yangjie = jinbo + yangjie;
    // std::cout << "after adding :" << std::endl;
    // yangjie.print_attr();

    
    int i = 0;
    int day = 0;
    int purchased_number = 60;
    int win_count = 0;
    toto_entry result(i);
    while (win_count == 0) {
        for (i = 1; i <= purchased_number; i++) {
            toto_entry ticket(i);
            if (ticket.win_check(result)) {
                win_count++;
            }
        }
        std::cout << "on day " << day << " you purchased " << purchased_number << " tickets, and won: " << win_count << std::endl;
        day++;
    }

    std::cout << "you finally won on day " << day << std::endl;

    return 0;
}
