#ifndef __TOTO_GUARD__
#define __TOTO_GUARD__

class toto_entry
{
    int number;
    int entry[6];
public:
    toto_entry(int _number);
    int win_check(const toto_entry &result);
};

int filling(int *entry, int index);
void sort_array(int *arr, int lengh);

#endif