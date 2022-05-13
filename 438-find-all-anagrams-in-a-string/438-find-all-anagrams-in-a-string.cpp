class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hmap_p, hmap_s;
        vector<int> result;
        int k = p.size();
        
        if( s.size() < k )
            return {};
        
        for( int i = 0; i < k; i++) {
            if(hmap_p.find(p[i]) == hmap_p.end())
                hmap_p[p[i]] = 1;
            else
                hmap_p[p[i]] += 1;
        }
        
        for( int i = 0; i < k; i++) {
            if(hmap_s.find(s[i]) == hmap_s.end())
                hmap_s[s[i]] = 1;
            else
                hmap_s[s[i]] += 1;
        }
        
        if( hmap_s == hmap_p )
            result.push_back(0);
        
        for(int i = k; i < s.size(); i++) {
            hmap_s[s[i-k]] -= 1;
            if(hmap_s[s[i-k]] == 0)
                hmap_s.erase(s[i-k]);
            
            if(hmap_s.find(s[i]) == hmap_s.end())
                hmap_s[s[i]] = 1;
            else
                hmap_s[s[i]] += 1;
            
            if(hmap_s == hmap_p)
                result.push_back( i - k + 1);
        }
        
        return result;
        
    }
};