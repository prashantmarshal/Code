#include <bits/stdc++.h>

using namespace std;

// kadane product
int maxproduct(int arr[], int n){
	int p=0,cp=0,cn=0,temp;

	p = cp = cn = arr[0];

	for (int i = 1; i < n; ++i)
	{
		if(arr[i] > 0){
			cn = cn*arr[i];
			cp = max(cp*arr[i], arr[i]);

		}else if(arr[i]<0){
			temp = cp;
			cp = cn*arr[i];
			cn = min(temp*arr[i], arr[i]);
		}else{
			cp = cn = 0;
		}
		p = max(cp, p);
	
	}

	return p;

}


int maxproductBetter(int A[], int n) {
	int r = A[0];
    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
	int  imax = r, imin = r;

    for (int i = 1; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}

int main(int argc, char const *argv[])
{
	int n; cout<<"Enter array size: "; cin>>n;
	cout<<"Enter array: ";
	int arr[100];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cout<<maxproduct(arr, n)<<endl;
	return 0;
}
