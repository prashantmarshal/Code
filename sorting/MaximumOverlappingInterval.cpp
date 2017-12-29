#include <iostream>
#include <algorithm>

using namespace std;

struct interval
{
	int s;
	int e;
};

void findMaximumOverlappingInterval(interval intervals[], int n){
	int stimes[n], etimes[n];

	for (int i = 0; i < n; ++i){
		stimes[i] = intervals[i].s;
		etimes[i] = intervals[i].e;
	}

	sort(stimes, stimes+n);
	sort(etimes, etimes+n);

	int time = stimes[0], maxg = 1, g = 1;
	int i = 1, j = 0;

	while(i < n && j < n){
		if(stimes[i] < etimes[j]){
			g++;
			if(maxg < g){
				maxg = g;
				time = stimes[i];
			}
			i++;
		}else if(etimes[j] < stimes[i]){
			g--;
			j++;
		}else{
			i++;
			j++;
		}
	}
	cout<<"Time and count: "<<time<<" "<<maxg<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter number of intervals: ";
	cin>>n;
	scanf("\n");
	interval intervals[n];
	for (int i = 0; i < n; ++i)
		cin>>intervals[i].s>>intervals[i].e;

	findMaximumOverlappingInterval(intervals, n);

	return 0;
}
