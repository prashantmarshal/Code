#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


vector<vector<int>> threeSumZeroBetter(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) {
		return result;
	}

	size_t n_size = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n_size; ++i) {
		// all numbers from now on will be greater than 0, no point in continuing
		if (nums[i] > 0) break;

		// we have seen this number & combo before; skip
		if (i > 0 and nums[i] == nums[i-1]) continue;

		int left = i+1, right = n_size - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum < 0) {
				++left;
			} else if (sum > 0) {
				--right;
			} else {
				result.push_back({nums[i], nums[left], nums[right]});
				int last_left = nums[left], last_right = nums[right];
				// we have seen this number & combo before; skip
				while (left < right && nums[left] == last_left) ++left;
				while (left < right && nums[right] == last_right) --right;
			}
		}

	}
	return result;
}



// another solution with unnecessary complexities
vector<int> insertinvector(int i, int j, int k){
    vector<int>A;
    
    A.push_back(i);    
    A.push_back(j);    
    A.push_back(k);    
    sort(A.begin(), A.end());
    
    return A;
}

vector<vector<int>> threeSumZero(vector<int>& A) {
    int n = A.size();
    vector<vector<int>>v;
    sort(A.begin(), A.end());

    unordered_set<int>S;

    unordered_set<int> t;
    for (size_t i = 0; i < n; i++)
    {
        // one of three inserted
        
        int sum =  0-A[i];
        if(t.find(A[i]) != t.end())
            continue;
        t.insert(A[i]);
        int j = i+1, k = n-1;
        while(j < k) {
            if((A[j] + A[k]) == sum){
                v.push_back(insertinvector(A[i], A[j], A[k]));
                j++;
                k--;
            }else if((A[j] + A[k]) >= sum){
                k--;
            } else{
                j++;
            }
        }
    }

    vector<vector<int>> v1;
    n = v.size();
    if (n <= 1)
        return v;

    v1.push_back(v[0]);
    int j = 0;
    for (size_t i = 1; i < n; i++)
    {
        if(v[i][0] == v1[j][0] && v[i][1] == v1[j][1] && v[i][2] == v1[j][2]) {
            continue;
        }
        v1.push_back(v[i]);
        j++;
    }


    return v1;  
}


