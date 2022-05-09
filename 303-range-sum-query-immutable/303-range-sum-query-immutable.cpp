class NumArray {
public:
    vector<int> myNums;
    
    NumArray(vector<int>& nums) {
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            myNums.push_back(prefixSum);
        } 
    }
    
    int sumRange(int left, int right) {
        if ( left == 0 )
            return myNums[right];
        else
            return myNums[right] - myNums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */