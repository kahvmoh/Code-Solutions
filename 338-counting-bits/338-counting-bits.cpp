class Solution {
    private:
    int bitCount( unsigned int a)
    {
        int cnt = 0;
        while(a)
        {
            ++cnt;
            a = a & (a - 1);
        }
        
        return cnt;
    }    
    public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        
        // What about negative numbers
        for(int i = 1; i <= n; i++)
        {
            result[i] += bitCount( i );
        }
        
        return result;
    }
};