#include <bits/stdc++.h>
using namespace std;    

class node{
public:
	int age;
	string name;
	node(int a, string b){
		age = a;
		name = b;
	}

	/*virtual bool operator<(const node& b) {

		cout<<"Comparator with one argument\n";
		if(age != b.age)
			return age < b.age;
		return true;
		
	}*/

	/*// Overloading of Assignment Operator
    void operator=(const Marks &M ) { 
        m1 = M.m1;
        m2 = M.m2;
    }*/
};


/*this will be overloaded for only the priority_queue having this comparator*/
class CompareTime {
public:
	bool operator()(node& a, node& b)
	{
		node temp1=a,temp2=b;
		if(a.age != b.age)
			return a.age > b.age;
		else{
			return temp1.name.append(temp2.name) > temp2.name.append(temp1.name);
		}
	}
};

/*this will be overloaded for all the comparison operations and node arguments*/
bool operator<(const node& a, const node& b) {

	node temp1=a,temp2=b;
	if(a.age != b.age)
		return a.age < b.age;
	else{
		return temp1.name.append(temp2.name) > temp2.name.append(temp1.name);
	}
}

int main(){
	
	priority_queue <node, vector<node>, CompareTime> pq;
	node b(23,"prashantandsoon..");
	node a(22,"prashant");
	node c(24,"prashantonly");
	pq.push(b);
	pq.push(a);
	pq.push(c);

	int size = pq.size();
	for (int i = 0; i < size; ++i)
	{
		cout<<pq.top().age<<" "<<pq.top().name<<"\n";
		pq.pop();
	}

	node b1(23,"prashantandsoon..");
	node a1(22,"prashant");

	if(a1 < b1)
		cout<<"Age sorting\n";
	else
		cout<<"Age no sorting\n";

}