#include <bits/stdc++.h>

using namespace std;


bool comparator(const string s1, const string s2){

	return (s1+s2) > (s2+s1);

}

void findLargestNumber(std::vector<string> v){

	sort(v.begin(), v.end(), comparator);

	int size = v.size();

	for (int i = 0; i < size; ++i)
	{
		cout<<v[i];
	}

	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		std::vector<string> v;
		for (int i = 0; i < n; ++i){
			cin>>s;
			v.push_back(s);

		}

		findLargestNumber(v);
	}

	return 0;
}