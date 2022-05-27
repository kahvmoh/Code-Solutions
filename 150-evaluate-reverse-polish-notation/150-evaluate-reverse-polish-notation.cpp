class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numSt;
        int result = 0;
        
        for(int i = 0; i < tokens.size(); i++) {

            if ( (tokens[i] == "+") || (tokens[i] == "-") || (tokens[i] == "*")  || (tokens[i] == "/") ) {
                // pop out the last two numbers for the operation
                int op2 = numSt.top();
                numSt.pop();
                int op1 = numSt.top();
                numSt.pop();
                if( tokens[i] == "+") {
                   numSt.push(op1 + op2); 
                }
                else if( tokens[i] == "-") {
                   numSt.push(op1 - op2); 
                }
                if( tokens[i] == "*") {
                   numSt.push(op1 * op2); 
                }
                else if( tokens[i] == "/") {
                   numSt.push(op1 / op2); 
                }   
            }
            else {
               numSt.push(stoi(tokens[i])); 
            }
                
        }
 
        result = numSt.top();
        numSt.pop();
        return result;
        
    }
};