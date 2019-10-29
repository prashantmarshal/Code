#include <iostream>
using namespace std;
 
template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    static T aa;
    void print();
};
 
template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
 
template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}

template <typename X>
class Test
{
public:
    static X var;
};


template<class X> 
X Test<X>::var = 5; 

class Test2
{
public:
    static int var;
};


int main() {
    // int arr[5] = {1, 2, 3, 4, 5};
    // Array<int> a(arr, 5);
    // a.print();
    Test<string> p;
    cout<<p.var<<endl;
    return 0;
}