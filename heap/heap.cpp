#include <iostream>
using namespace std;


class heap{
	public:

		int arr[100];
		int count;

		heap(){
			count = 0;
		}

		void insert(int a){

			arr[count] = a;
			int i = count++;
			while(i >= 0 && arr[(i-1)/2] > arr[i]){
				swap(arr[i],arr[(i-1)/2]);
				i = (i-1)/ 2;
			}

			int extractmin(){

				int val = arr[0];
				int i = 0;

				// inserted last index element to top and doing heapify
				arr[0] = arr[--count];

				while(2*i+1 < count){

					int l = 2*i+1;
					int r = 2*i+2;

					// compare only with l if there is no right child
					if(r >= count){
						if(arr[i] > arr[l]){
							swap(arr[i], arr[l]);
						}
						break;
					}

					if(arr[i] < arr[l] && arr[i] < arr[r]){
						break;
					}else if(arr[i] > arr[l] && arr[i] > arr[r]){
						if(arr[l] < arr[r]){
							swap(arr[i], arr[l]);
							i = l;
						}else{
							swap(arr[i], arr[r]);
							i = r;
						}
					}else if(arr[i] > arr[l]){
						swap(arr[i], arr[l]);
						i = l;
					}else {
						swap(arr[i], arr[r]);
						i = r;
					}
				}

				return val;

			}

		};


		int main(){
			heap h;

			int arr[] = {10,34,56,32,45,12,15,22,66,41,28,90,87,89,68};
			for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
			{
				h.insert(arr[i]);
			}

			for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
			{
				cout<<h.extractmin()<<" ";
			}
			cout<<endl;

		}
