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
for( int i = end; i >= start; i--) {
if( s[i] = ' '  && spaces >= 1 )
continue;
else if( s[i] = ' '  && spaces == 0 )
spaces++;
else
spaces = 0;
tmpSt.push_back(s[i]);
}
return tmpSt;
​
}
​
void reverseWord( string &s, int start, int end) {
while( start < end && end < s.size() ) {
swap( s[start], s[end]);
++start;
--end;
}
}