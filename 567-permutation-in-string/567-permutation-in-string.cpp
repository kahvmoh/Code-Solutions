class Solution {
public:
    //bool isEqual()
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hmap_s1;
        unordered_map<char, int> hmap_s2;
        int k = s1.size();
        
        if( s2.size() < s1.size() )
            return false;
        
        for( int i = 0; i < k; i++) {
            if (hmap_s1.find(s1[i]) == hmap_s1.end())
                hmap_s1[s1[i]] = 1;
            else
                hmap_s1[s1[i]] += 1;
        }
        
        for( int i = 0; i < k; i++) {
            if (hmap_s2.find(s2[i]) == hmap_s2.end())
                hmap_s2[s2[i]] = 1;
            else
                hmap_s2[s2[i]] += 1;
        }            
        
        if( hmap_s1 == hmap_s2 )
            return true;
        
        for( int i = k; i < s2.size(); i++) {
            // Delete the outgoing char
            if (hmap_s2[s2[i- k]] > 1)
                hmap_s2[s2[i- k]] -= 1;
            else
                hmap_s2.erase(s2[i-k]);
                
            // Add the new char to the window
            if (hmap_s2.find(s2[i]) == hmap_s2.end())
                hmap_s2[s2[i]] = 1;
            else
                hmap_s2[s2[i]] += 1;
            
            if( hmap_s1 == hmap_s2 )
                return true;
        }
        
        return false; 
    }
};