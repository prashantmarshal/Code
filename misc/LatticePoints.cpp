#include <bits/stdc++.h>

using namespace std;


int latticePoints(int r){

	int cnt = 0;
	int t = sqrt(r);
	if(t*t < r)
		++t;

	for (int i = 0; i < t ; ++i){

		int ysquare = r - i*i;
		int y = sqrt(ysquare);
		if(y*y == ysquare){
			cnt += 4;
		}
	}

	return cnt;

}


int main(){

	int t, d, n, r, x, y, cnt;

	cin>>t;

	while(t--){
		cin>>d>>n;

		int cnt = latticePoints(d);
		if(cnt <= n)
			cout<<"possible\n";
		else cout<<"impossible\n";
	}

}