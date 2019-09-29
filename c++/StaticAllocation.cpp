#include <iostream>
using namespace std;

class p
{
    public:
    int* q;
    p()
    {
        q = new int(100);
        cout<<"p constructor called"<<endl;
    }
    ~p(){
        delete q;
    }
};

static p* p1 = new p();
static p p2;

int main() {
    // your code goes here
    cout<<"main called"<<endl;

    std::cout << *(p1->q);
    std::cout << *(p2.q);

    delete p1;
}