class Solution {
public:
    void reverse_str( string &s, int start, int end)
    {
        while( start < end ) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }    
        
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2*k)  {
            if(i+k <= s.size() )
                reverse_str(s, i, i + k - 1);
                //reverse(s.begin() + i, s.begin() + i + k);
            else 
                reverse_str(s, i, s.size() - 1 );
                //reverse(s.begin() + i, s.end());
        }
        return s;
    }
};