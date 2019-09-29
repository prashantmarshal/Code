#include <bits/stdc++.h>
using namespace std;

class Base {
//public:
    int x;
	~Base(){
cout<<"ok\n";
}
};
 
 
int main()
{
char *ptr = "prashant";
ptr[2] = 'k';
cout<<ptr<<endl;
cout<<sizeof(string)<<endl;
static Base *d = new Base;
 return 0;
}

