class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int minRow = 0;
        int maxCol = matrix[0].size() - 1;
        
        //cout  << "Rows = " << rows << ", Columns = " << cols << endl;
        while ( minRow < matrix.size() && maxCol >= 0 )
        {
            if (target == matrix[minRow][maxCol])
                return true;
            else if (target < matrix[minRow][maxCol])
                maxCol--;
            else 
                minRow++;
                
        }    
        
        return false;
    }
};