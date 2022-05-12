class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int numAngry = 0;
        int numSat = 0;
        int globalAngry = 0;
        
        for( int i = 0; i < customers.size(); i++) {
            if( grumpy[i] == 0)
                numSat += customers[i];
        }
        
        for( int i = 0; i < minutes; i++) {
            if ( grumpy[i] == 1)
                numAngry += customers[i];
        }
        
        globalAngry = numAngry;
        
        for( int i = minutes; i < customers.size(); i++) {
            if (grumpy[i] == 1)
                numAngry += customers[i];
            if (grumpy[i - minutes] == 1)
                numAngry -= customers[i - minutes];
            globalAngry = max(globalAngry, numAngry);
        }
        
        return (numSat + globalAngry);
    }
};