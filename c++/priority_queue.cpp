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
};

class CompareTime {
public:
	iterator operator++(int);
    bool operator()(node& a, node& b) // t2 has highest prio than t1 if t2 is earlier than t1
    {
    	node temp1=a,temp2=b;
    	if(a.age != b.age)
    		return a.age > b.age;
    	else{
    		return temp1.name.append(temp2.name) > temp2.name.append(temp1.name);
    	}
    }
};

bool operator<(const node& a, const node& b) {

	node temp1=a,temp2=b;
	if(a.age != b.age)
		return a.age > b.age;
	else{
		return temp1.name.append(temp2.name) > temp2.name.append(temp1.name);
	}
}

bool operator<(int a, node b){
	return a<b.age;
}

int main(){
	node aaa(22,"prashant");
	if(5 < aaa)
		printf("ok\n");
	return 0;
	priority_queue<node, vector<node>, CompareTime> pq;
	node b(23,"prashantandsoon..");
	node a(22,"prashant");
	node c(22,"prashantonly");
	pq.push(b);
	pq.push(a);
	pq.push(c);
	node aa(5, "lund");
	node bb(5, "choot");
	if(aa < bb)
		printf("ok\n");
	else
		printf("l\n");

    int size = pq.size();
    for (int i = 0; i < size; ++i)
    {
        cout<<pq.top().age<<" "<<pq.top().name<<"\n";
        pq.pop();
    }
}