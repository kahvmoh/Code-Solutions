class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        std::size_t size = s.size();
        set<char> mySet;
        
        int start = 0;
        int end = 0;
        
        while( start < size && end < size )
        {
            if(mySet.find(s[end]) == mySet.end())
            {    
                mySet.insert(s[end]);
                ++end;
                maxLen = max(maxLen, end - start);
            }
            else
            {    
                mySet.erase(s[start]);
                ++start;
            }    
        }
        
        return maxLen;
        
    }    
     
};