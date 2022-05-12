class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int total = 0;
        int points = 0;
        
        for(int i = 0; i < k; i++)
            total += calories[i];
        if( total < lower )
            points--;
        else if ( total > upper )
            points++;
        
        for( int i = k; i < calories.size(); i++ ) {
            total += calories[i] - calories[i-k];
        
        if( total < lower )
            points--;
        else if ( total > upper )
            points++;
        }
        
        return points;
    }
};