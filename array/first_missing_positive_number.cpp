
int firstMissingPositive(vector<int>& nums) {
    int size = nums.size();
    int i = 0, j = size-1;

    while(i<=j){

        while(i<=j && nums[i]>0) {
            i++;
        }
        //i points to first non-positive element

        while(i<=j && nums[j]<=0) {
            j--;
        }
        //j points to first positive element

        if (i <= j) {
            swap(nums[i], nums[j]);
        }
    }

    if (j < 0)
        return 1;

    i = 0;
    for (;i<=j;++i){
        
        if ((abs(nums[i])-1) <= j){
            if (nums[abs(nums[i])-1] < 0){
                continue;
            } else {
                nums[abs(nums[i])-1] *= -1;
            }
        }
    }

    i=0;

    while(i <= j) {
        if (nums[i] > 0)
            return i+1;
        i++;
    }

    return i+1;
}

