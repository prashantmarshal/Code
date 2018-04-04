#include <iostream>
using namespace std;


int maxProfit(int *a, int length) {
	int profit = 0;
	int maxPrice = -1;int fee=0;
	for(int i = length-1; i>=0; i--) {
		if(a[i] > maxPrice) maxPrice = a[i];
		else {
			int tmpProfit = maxPrice - a[i] - fee;
			if(tmpProfit > 0)
				profit +=tmpProfit;
		}	
	}
	return profit;
}

int main(int argc, char const *argv[])
{
	int prices[] = {40,60,50,100};
	cout<<maxProfit(prices, 4)<<endl;	
	return 0;
}