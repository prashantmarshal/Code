#include <iostream>
using namespace std;

class B
{
public:
     void func(){

    }
    void f2(){
        cout<<"base\n";
    }
};


class D
{
public:
    void func(){

    }

    void f2(){
        cout<<"derived\n";
    }
};

struct s
{
    int x: 30;
    long int y: 1;
};

int main(int argc, char const *argv[])
{
    cout<<sizeof(s);
    // D* d = new D;
    // B* b = new B;
    // d = reinterpret_cast<D*>(b);
    return 0;
}