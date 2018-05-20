#include <iostream>

class Singleton
{
    static Singleton* instance;

		/* Private constructor to prevent instancing. */
		Singleton();

	public:
		/* Static access method. */
		static Singleton* getInstance();
};

/* Lazy instantiation*/
Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
	if (instance == 0)
		instance = new Singleton();

	return instance;
}

Singleton::Singleton()
{
	instance = 0;
}

int main()
{
	//new Singleton(); // Won't work
	Singleton* s = Singleton::getInstance();
	Singleton* r = Singleton::getInstance();

	/* The addresses will be the same. */
	std::cout << s << std::endl;
	std::cout << r << std::endl;
}
