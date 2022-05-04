class Solution {
public:
    bool isValid(string s) {
       
        stack<char> myst;
        
        if(s.size() < 2)
             return false;
        
        for(int i = 0; i < s.size(); i++)
        {
            if( myst.empty())
            {
                myst.push(s[i]);
                continue;
            }
            
            if( s[i] == ')')
            {    
               if(myst.top() != '(')
                   return false;
               else {        
                  myst.pop();
                  continue;
               }    
            }
            
            if( s[i] == ']')
            {    
               if(myst.top() != '[')
                   return false;
               else {        
                  myst.pop();
                  continue;
               }    
            }
            
            if( s[i] == '}')
            {    
               if(myst.top() != '{')
                   return false;
               else {        
                  myst.pop();
                  continue;
               }    
            }
        
            myst.push(s[i]);            
        }
        
        if( myst.empty())
            return true;
        
        return false;
    }
};