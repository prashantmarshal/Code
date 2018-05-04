#include <iostream>

using namespace std;

int main(){
	int n, y;
	for(n = 0; n < 30; ++n){
		y = n;
		long x = 0xFFFFFFF0;
		n = n & x;
		x = 1 << 4;
		n = n + x;
		cout<<"number: "<<y<<" next 16: "<<n<<endl;
		n = y;
	}
}
