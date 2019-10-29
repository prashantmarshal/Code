#include <iostream>
using namespace std;


int findDuplicate(int* nums) {


	int slow = nums[0];
	int fast = nums[nums[0]];
	while (slow != fast) {
		cout<<slow<<" "<<fast<<endl;
		slow = nums[slow];
		fast = nums[nums[fast]];
		cout<<slow<<" "<<fast<<endl;
	}
	fast = 0;
	cout<<endl;
	while (slow != fast) {
		cout<<slow<<" "<<fast<<endl;
		slow = nums[slow];
		fast = nums[fast];
		cout<<slow<<" "<<fast<<endl;
	}
	std::vector<char> v;
	return fast;
}

int main(int argc, char const *argv[])
{
	int nums[5]={1,3,4,2,2};//,6,7,10,8,9,2};
	cout<<findDuplicate(nums);
	return 0;
}
