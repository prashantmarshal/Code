#include <climits>
#include <iostream>
using namespace std;

int maxProfit(int price[], int n, int k)
{
	int profit[k + 1][n + 1];

	for (int i = 0; i <= k; i++)
		profit[i][0] = 0;

	for (int j = 0; j <= n; j++)
		profit[0][j] = 0;

	for (int t = 1; t <= k; t++) {
		for (int i = 1; i <= n; i++) {
			int max_so_far = INT_MIN;

			for (int j = 0; j < i; j++)
				max_so_far = max(max_so_far,
								price[i] - price[j] + profit[t - 1][j]);

			profit[t][i] = max(profit[t][i - 1], max_so_far);
		}
	}

	return profit[k][n];
}

int main()
{
	int k = 2;
	int price[] = {10, 22, 5, 75, 65, 80 ,56};
	int n = sizeof(price) / sizeof(price[0]);

	cout << "Maximum profit is: "
		<< maxProfit(price, n, k);

	return 0;
}
