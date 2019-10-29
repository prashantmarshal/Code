#include <bits/stdc++.h>
using namespace std;

class T
{
public:
	T(){}

	T(const T& obj){
		cout<<"Copy constructor\n";
	}

	T& operator=(const T& obj){
		cout<<"Assignment operator\n";
		return *this;
	}

	T& operator=(const T&& obj){
		cout<<"Move Assignment operator\n";
		return *this;
	}

	~T(){

	}
	
};

void copy_by_reference(T obj){

}

T new_object(){
	return T();
}

int main(int argc, char const *argv[])
{
	T obj1;
	// copy_by_reference(obj1);
	copy_by_reference(new_object());
	return 0;
}