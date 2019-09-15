#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>&arr, int low, int high, int key) {
    while (low <= high) {
        int mid = (low+high)/2;
        if (key == arr[mid])
            return mid;
        
        if (key > arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}


int findPivot(vector<int>&arr) {
    int low = 0, high = arr.size()-1;

    while(low <= high){
        int mid = (low+high)/2;

        // 2 4 7 3 1 pivot 7
        if(mid > low && arr[mid-1]>arr[mid])
            return mid-1;
        
        if(mid < high && arr[mid] > arr[mid+1])
            return mid;

        if(arr[mid] >= arr[high])
            low = mid+1;
        else
            high = mid-1;
    }

    return -1;
}

int search(vector<int>&arr, int key)
{ 
    int n = arr.size();
    int pivot = findPivot(arr); 
  
    if (pivot == -1) 
        return binarySearch(arr, 0, n-1, key); 

    if (arr[pivot] == key) 
        return pivot; 

    if (arr[0] <= key) 
        return binarySearch(arr, 0, pivot-1, key); 

    return binarySearch(arr, pivot+1, n-1, key); 
} 