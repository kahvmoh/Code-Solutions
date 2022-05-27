class Solution {
public:
    int compress(vector<char>& chars) {
       int i = 0;
       int fill_pos = 0;
       int len = chars.size();

       while( i < len ){
           int j = i + 1;
           while( j < len && chars[i] == chars[j]){
               j++;
           }


           chars[fill_pos++] = chars[i];

           int count = j - i;
           if( count > 1){
               // converting count into string to append single digit one by one
               string countStr = to_string(count);
               for(char ch:countStr){
                   chars[fill_pos++] = ch;
               }
           }
		   // moving to new/diff char
           i = j;
       }
        
       return fill_pos;
    }
};
