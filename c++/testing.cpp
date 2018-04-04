#include <iostream>
using namespace std;

class T
{
public:
    int a;
    T(){
        printf("constructor\n");
    }

    T(const T &b){
        printf("copy constructor\n");
    }
    T & operator = (const T &t);

};


T & T::operator = (const T &t)
{
 printf("operator\n");
 return *this;
}

T foo(){
    return T();
}

T* _foo(T * temp){
    T a;
    *temp = a;
    return temp;
}

int main(){

    T b1 = foo();

    T b_hidden;

    T b2 = *(_foo(&b_hidden));

}