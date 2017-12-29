#include <iostream>
#include <algorithm>

using namespace std;

struct jobs
{
	int stime;
	int etime;
	int value;
};

bool comparator(jobs j1, jobs j2){
	return j1.etime < j2.etime;
}

void optimalJobs(jobs job[], int n){

	// sorting jobs according to finish time
	sort(job, job+n, comparator);

	int d[n];

	d[0] = job[0].value;
	
	cout<<d[0]<<" ";

	for (int i = 1; i < n; ++i){
		int j = i-1;
		while(job[j].etime > job[i].stime)
			j--;
		if(j>=0)
			d[i] = max(d[j]+job[i].value, d[i-1]);
		else
			d[i] = d[i-1];
			cout<<d[i]<<" ";
	}

	cout<<endl;

}

int main(){
	int n;
	cout<<"Enter number of jobs: ";
	cin>>n;
	jobs job[n];
	for (int i = 0; i < n; ++i){
		cin>>job[i].stime>>job[i].etime>>job[i].value;
	}
	cout<<"Optimal value is: ";
	optimalJobs(job, n);
}