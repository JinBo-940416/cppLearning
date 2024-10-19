#include <iostream>
#include "toto.h"
#include <cstring>

toto_entry::toto_entry(int _number)
{
    number = _number;
    memset(entry, 0, 6);
    int i = 0;
    for (i = 0; i < 6; i++) {
        while (1 != filling(entry, i)) {};
    }
    sort_array(entry, 6);
    std::cout << "toto_entry " << number << " : [" << entry[0] << ", " << entry [1] << ", " << entry [2] << ", " << entry [3] << ", " << entry [4] << ", " << entry [5] << " ]"<< std::endl;
}

int toto_entry::win_check(const toto_entry &result)
{
    int i = 0;
    std::cout << "result        : [" << result.entry[0] << ", " << result.entry[1] << ", " << result.entry[2] << ", " << result.entry [3] << ", " << result.entry [4] << ", " << result.entry [5] << " ]"<< std::endl;
    for (i = 0; i < 6; i++) {
        if (this->entry[i] != result.entry[i]) {
            std::cout << "not a winner !" << std::endl;
            return 0;
        }
    }
    std::cout << "You won 10 million fucking dollars !" << std::endl;
    return 1;
}

int filling(int *entry, int index)
{
    int number = rand()%48 + 1;
    int i = 0;
    for (i = 0; i < index; i++) {
        if (entry[i] == number) 
            return 0;
    }
    entry[i] = number;
    return 1;
}

void sort_array(int *entry, int length)
{
    int tmp[length];
    memset(tmp, 0, length * sizeof(int));
    int i = 0;
    int j = 0;
    int minimum = 50;
    int minimum_index = 0;
    for (j = 0; j < length; j++) {
        minimum = 50;
        minimum_index = 0;
        for (i = 0; i < length; i++) {
            if (entry[i] < minimum) {
                minimum = entry[i];
                minimum_index = i;
            }
        }
        tmp[j] = minimum;
        entry[minimum_index] = 50;
    }
    memcpy(entry, tmp, length * sizeof(int));
}

