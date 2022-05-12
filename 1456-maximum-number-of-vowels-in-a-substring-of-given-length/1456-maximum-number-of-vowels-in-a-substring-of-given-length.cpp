class Solution {
public:
    int maxVowels(string s, int k) {
        int maxV = 0;
        int curV = 0;
        
        for( int i = 0; i < k; i++) {
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                curV++;
        }
        
        maxV = curV;
        for( int i = k; i < s.size(); i++) {
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                curV++;
            if( s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u')
                curV--;
            
            maxV = max(maxV, curV);
        }
        
        return maxV;
    }
};