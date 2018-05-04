#include <bits/stdc++.h>
using namespace std;


class T
{
public:
	static const int a;

	T(int t = 5){
	
	}
	void f() const{
		
	}
};

const int T::a = 10;

int main(){
	const T t(5);
	cout<<&t.a<<endl;	
	t.f();
}