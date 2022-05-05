class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        unordered_set<int> mySet(nums.begin(), nums.end());
        
        //unordered_set<int>::iterator it = mySet.begin();
        //while ( it != mySet.end() ) 
        //    cout << *it++ << ", ";
        
        for(int i = 1; i <= size; i++) {
            if(mySet.find(i) == mySet.end()) {
                cout << "Not found: " << i << ", "; 
                result.push_back( i );
            }
            else
                cout << "found: " << i << ", "; 
        }
        return result;
    }
};