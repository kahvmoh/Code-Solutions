class Solution {
public:
    string reverseString( string s) {
        string tmpSt;
        int start = 0;
        int end = s.length() - 1;
        
        // Get rid of the blank spaces before and after the string
        while (start < s.length() && s[start] == ' ')
            ++start;
        
        while (end >= 0 && s[end] == ' ')
            --end;
        
        int spaces= 0;
        for( int i = start; i <= end; i++) {
            if( s[i] == ' '  && spaces >= 1 )
                continue;
            else if( s[i] == ' '  && spaces == 0 )
                spaces++;
            else
                spaces = 0;
            
            tmpSt.push_back(s[i]);
        }
        
        reverseWord( tmpSt, 0, tmpSt.length() - 1);
        return tmpSt;
    }

    void reverseWord( string &s, int start, int end) {
        while( start < end && end < s.size() ) {
            swap( s[start], s[end]);
            ++start;
            --end;
        }
    }

        
    string reverseWords(string s) {
        if ( s.size() < 2 )
            return s;
        
        // 1- Remove extra spaces and reverse the whole string
        string myString = reverseString( s );
        
        // 2- find each word in the reversed string and reverse it
        int start = 0, end = 0;
        while (end < myString.size()) {
            start = end;
            // find the next balnk
            while( (end < myString.size()) && (myString[end] != ' '))
               ++end;
            // reverse the found word    
            reverseWord(myString, start, end - 1);
            end++; 
        }
        
        return myString;
        
    }
};