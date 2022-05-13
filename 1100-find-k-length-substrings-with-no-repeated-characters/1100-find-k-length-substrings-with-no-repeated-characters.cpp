class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if ( s.size() < k )
            return 0;
        
        unordered_map<char, int> hmap;
        int gCount = 0;
        
        // Initiating the first substring of leght k
        for (int i = 0; i < k; i++) {
            if (hmap.find(s[i]) == hmap.end())
                hmap[s[i]] = 1;
            else
                hmap[s[i]] += 1;
        }
        
        if (hmap.size() == k)
            gCount = 1;
        
        for (int i = k; i < s.size(); i++) {
            if (hmap.find(s[i]) == hmap.end())
                hmap[s[i]] = 1;
            else
                hmap[s[i]] += 1;
            
            // decrement/erase the otugoing char
            hmap[s[i-k]] -= 1;
            if (hmap[s[i - k]] == 0)
                hmap.erase(s[i-k]);
            
            if (hmap.size() == k)
                gCount += 1;
        } 
        
        return gCount;
    }
};