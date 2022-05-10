class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long total = 0;
        int hmap[2];
        // keep track of even prefixSum
        hmap[0] = 1;
        // keep track of odd prefixSum
        hmap[1] = 0;
        int pSum = 0;
        for( int i = 0; i < arr.size(); i++ ) {
            pSum += arr[i];
            
            if( pSum % 2 == 0 ) 
                total += hmap[1];
            else
                total += hmap[0];
            
            // update the counts
            if( pSum % 2 == 0 ) 
                hmap[0] += 1;
            else
                hmap[1] += 1;
            
            total = total % 1000000007;
        }
        
        return total;    
    }
};