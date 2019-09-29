#include <iostream>
using namespace std;

// const int a1 = 40; // global const - runtime error Bus error if value changed

int main(void)
{
        const int a1 = 40; // local const
        const int* b1 = &a1;

        int* c1 = (int *)(b1);
        *c1 = 100;
        cout<<a1<<endl;
        
        return 0;
}
