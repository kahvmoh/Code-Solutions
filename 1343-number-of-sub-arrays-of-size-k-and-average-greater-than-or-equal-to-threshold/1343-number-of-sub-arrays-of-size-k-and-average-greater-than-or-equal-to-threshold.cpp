class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        double sum = 0;
        
        // initial sunset array of size k
        for( int i = 0; i < k;i++ ) 
            sum += arr[i];
        
        if( ( sum / k ) >= threshold )
            count++;
        
        // all other sub-arrays
        for( int i = k; i < arr.size(); i++ ) {
            sum = sum + arr[i] - arr[i - k];
            if( ( sum / k ) >= threshold )
                count++;
        }
        
        return count;
    }
};