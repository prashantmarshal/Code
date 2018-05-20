#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 10


/*
https://stackoverflow.com/questions/2346091/c-templated-class-implementation-of-the-multiton-pattern?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
class Multiton
{
    static Multiton* instance[MAX_NUM];

    Multiton(){}

public:
    static Multiton* getInstance(int num);
};

Multiton* Multiton::instance[] = {0};

Multiton* Multiton::getInstance(int num)
{
    if (instance[num] == 0)
        instance[num] = new Multiton();

    return instance[num];
}

int main()
{
    Multiton* s = Multiton::getInstance(2);
    Multiton* r = Multiton::getInstance(2);

    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
}
