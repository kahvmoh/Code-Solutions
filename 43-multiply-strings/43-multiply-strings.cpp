class Solution {
public:
    
    string multiply(string num1, string num2) {
       
        int l1 = num1.size(); // n
        int l2 = num2.size(); // m
        
        vector<int> a(l1+l2);
        int temp;
        
        for(int i=0; i<l1; i++){
            for(int j=0; j<l2; j++){
                // multiplying numbers from rigth to left
                temp = (num1[l1-i-1]-'0') * (num2[l2-j-1]-'0');
                a[l1+l2-(i+j)-1] += temp;
                cout<< temp << "\n";
            }
        }
        
        int carry=0;
        for(int i=l1+l2-1; i>=0; i--){
            a[i] += carry;
            carry=a[i]/10;
            a[i]%=10;
        }
        
        // count the number of  non-zero elements
        int len=0;
        while(len<l1 + l2 && a[len]==0){
            len++; 
        }
        
        if(len == l1 + l2){
            return("0");
        }
        
        for(int i=0;i<l1+l2;i++){
            cout<<a[i];
        }
        
        string ans(l1+l2-len, '0');
        
        for(int i=len;i<l1+l2;i++){
            ans[i-len]=a[i]+'0';
        }
        
        return ans;
    }
    
};