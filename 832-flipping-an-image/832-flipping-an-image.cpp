class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        

        for(int k = 0; k < row; k++) {
            int i = 0, j = row - 1;
            while ( i < j ) {
                int tmp = image[k][i];
                image[k][i] = image[k][j] ^ 1;
                image[k][j] = tmp ^ 1;
            
                i++;
                j--;
            

            } 
            if( i == j )
                image[k][i] = image[k][i] ^ 1;
        }

        
        return image;
    }
};