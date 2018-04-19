#include <iostream>
#include <map>
using namespace std;


int longestkunique(string s, int k){
	int length = s.length();
	int start = 0, total = 0, distinct = 1;
	int i = 1;

	map<char, int> hash;
	hash[s[0]] = 1;

	while(i < length){
		if(hash[s[i]] > 0){
			hash[s[i]]++;
			if(distinct == k){
				total = max(total, i-start+1);
			}
		}else if(hash[s[i]] == 0){
			distinct++;
			hash[s[i]] = 1;
			if(distinct == k){
				total = max(total, i-start+1);
			}else if(distinct > k){
				while(distinct != k){
					if(--hash[s[start]] == 0){
						distinct--;
					}
					++start;
				}
				total = max(total, i-start+1);
			}
		}
		++i;
	}

	return total;
}

int main(int argc, char const *argv[])
{
	string s;
	int k = 10;
	cout<<"Enter string\n";
	cin>>s;
	cout<<longestkunique(s, k)<<endl;
	return 0;
}