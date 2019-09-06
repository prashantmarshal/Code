#include <iostream>
using namespace std;

/*global variable created
global static variable created
local to main created
Program start
static variable created
Local variable created
Function executed
Local variable destroyed
Program end
local to main destroyed
static variable destroyed
global static variable destroyed
global variable destroyed*/

static int a;
class test
{
public:
        test(const char *name)
                : _name(name)
        {
                cout << _name << " created" << endl;
        }

        ~test()
        {
                cout << _name << " destroyed" << endl;
        }

        string _name;
};

test t("global variable");
static test t2("global static variable");
void f()
{
        static test t("static variable");

        test t2("Local variable");

        cout << "Function executed" << endl;
}


int main()
{
        test t("local to main");

        cout << "Program start" << endl;

        f();

        cout << "Program end" << endl;
        return 0;
}
