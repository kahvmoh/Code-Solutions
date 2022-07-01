class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int length = letters.size() - 1;
        int start = 0, end = length;
        
        while ( start <= end ) {
            int mid = start + ((end - start) / 2);
            if ( letters[mid] <= target )
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return letters[ start % letters.size() ];
    }
};