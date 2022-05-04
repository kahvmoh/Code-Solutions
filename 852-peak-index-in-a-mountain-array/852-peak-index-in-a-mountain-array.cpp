class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = 0;
        int max_index = 0;
        
        for(int i  = 0; i < A.size(); i++ )
        {
            if(  A[i] > max )
            {    
                max = A[i];
                max_index = i;                
            }       
        }    
        
        std:: cout << "Max = " << max << " The index = " << max_index << endl;
        return max_index;
    }
};