class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0, p1, p2;
        
    p0 = p1 = 0;
    // for all idx > p2 : nums[idx > p2] = 2
    p2 = nums.size() - 1;

    while (p1 <= p2) {
        if (nums[p1] == 0) {
            swap(nums[p1++], nums[p0++]);
        }
        else if (nums[p1] == 2) {
            swap(nums[p1], nums[p2--]);
        }
        else p1++;
    }
        
    }
};