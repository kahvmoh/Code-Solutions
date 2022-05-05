class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red, cur, blue;
        
        red = cur = 0;
        blue = nums.size() - 1;
        
        while( cur <= blue ) {
            if ( nums[cur] == 0 )
                // this is Red
                swap(nums[cur++], nums[red++]);
            else if ( nums[cur] == 1)
                // This is White
                cur++;
            else
                // this is Blue
                swap(nums[cur], nums[blue--]);
                
        }
        
    }
};