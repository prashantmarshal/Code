#include<iostream>
using namespace std;

class SmartPtr
{
	int *ptr;
	int *count;
	public:


	explicit SmartPtr(int *p) {
		cout<<"Constructing shared pointer\n";
		ptr = p;
		count = new int(1);
		cout<<"Initialized reference: "<<*count<<endl;
	} 

	SmartPtr(){
		ptr = NULL;
		count = NULL;
	}

	~SmartPtr() {
		(*count)--;
		cout<<"Decremented reference: "<<*count<<endl;
		if(*count == 0) {
			delete(ptr);
			ptr = NULL;
		}
		if(ptr != NULL)
			cout<<"Pointer not deleted yet\n";
		else
			cout<<"Pointer deleted\n";
	}  

	int &operator *() {
		return *ptr;
	}

	// for unique_ptr, set this->ptr to NULL
	SmartPtr& operator= (SmartPtr & obj){

		// 1. in case a pointer is leaving its own reference
		if(this->ptr){
			(*count)--;
			cout<<"Decremented reference: "<<*count<<endl;
			if(this->count == 0){
				delete(ptr);
				ptr = NULL;
			}
			if(ptr != NULL)
				cout<<"Pointer not deleted yet\n";
			else
				cout<<"Pointer deleted\n";
		}
		// 2. when some newly created pointer is being pointed to obj
		ptr = obj.ptr;
		count = obj.count;
		(*count)++;
		cout<<"Incremented reference: "<<*count<<endl;
		return *this;
	}

	SmartPtr (const SmartPtr & obj){
		ptr = obj.ptr;
		count = obj.count;
		(*count)++;
		cout<<"Incremented reference: "<<*count<<endl;
	}

	int getcount(){
		return *count;
	}
};



int main()
{
	SmartPtr ptr(new int());
	*ptr = 20;
	{
		SmartPtr ptr2 = ptr;
		cout<<ptr2.getcount()<<endl;
		SmartPtr ptr3;
		ptr3 = ptr;
		cout<<ptr3.getcount()<<endl;
	}
	cout<<ptr.getcount()<<endl;
	return 0;
}
