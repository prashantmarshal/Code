#include<bits/stdc++.h>
using namespace std;


// 1 3 5 7
// 2 4 6 8

// Count number of elements to be shifted from A to B
// eg:- count = 2, then 5 7 move to B and 2 4 to A

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int inv = 0;

    int x = nums1.size();
    int xr = x-1;
    int y = nums2.size();
    int yf = 0;

    int i = 0, j = 0;

    while(i < x && j < y){
        if(nums1[i] > nums2[j]) {
            swap(nums1[xr--], nums2[yf++]);
            inv++;
            j++;
        }else
        {
            i++;
        }
    }
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

int main(int argc, char const *argv[])
{
    vector<int>v1, v2;
    for (int i = 0; i < 100; i++)
    {
        v1.push_back(1+2*i);
        v2.push_back(2+2*i);
    }

    // sort(v1.begin(), v1.end());
    // sort(v2.begin(), v2.end());

    merge(v1, 100, v2, 100);

    vector<int>v3;
    for (int i = 0; i < 100; i++)
    {
        v3.push_back(v1[i]);
    }
    for (int i = 0; i < 100; i++)
    {
        v3.push_back(v2[i]);
    }

    int curr_max = INT_MIN;
    for (int i = 0; i < 200; i++)
    {
        if(v3[i] < curr_max)
            printf("Fail");
        curr_max = v3[i];
    }
    
    return 0;
}
