class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> myDeq;
        vector<int> results;
        for( int i = 0; i < k; i++) {
            while( !myDeq.empty() && nums[i] > myDeq.back())
                myDeq.pop_back();
            myDeq.push_back(nums[i]); 
        }
        
        results.push_back(myDeq.front());
        
        for(int i = k; i < nums.size(); i++) {
            // Remove nums[i-k] if it is the deque front element
            if( myDeq.front() == nums[i-k] )
                myDeq.pop_front();
            // Remove the elements less than current one.
            while( !myDeq.empty() && nums[i] > myDeq.back())
                myDeq.pop_back();
            // add the new element to the deque
            myDeq.push_back(nums[i]); 
            results.push_back(myDeq.front());
        }
        return results;
    }    
            
};