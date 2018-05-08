#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
using namespace std;


class LRU{
	list<int> q;
	unordered_map<int, list<int>::iterator> hash;
	int size;

public:

	LRU(int size = 10){
		this->size = size;
	}

	void refer(int key){

		// if key is not present
		if(hash.find(key) == hash.end()){
			
			if(q.size() == size){
				int last = q.back();
				q.pop_back();
				hash.erase(last);
			}
		}else{
			q.erase(hash[key]);
		}

		q.push_front(key);
		hash[key] = q.begin();
	}

	void display(){
		list<int>::iterator it;

		for (it = q.begin(); it != q.end(); ++it)
			cout<<*it<<" ";
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	LRU cache(5);
	int n;
	while(cin>>n){
		cache.refer(n);
		cout<<"Current cache: ";
		cache.display();
	}
	return 0;
}