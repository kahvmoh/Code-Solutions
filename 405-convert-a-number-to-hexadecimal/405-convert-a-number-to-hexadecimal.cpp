class Solution {
public:
    string toHex(int num) {
        
        if (num == 0)
            return "0";
        
        string result;
        
        for(int i = 0; i < 8; i++) {
            int cur = num & 0x0F;
            char c = (cur < 10) ? cur + '0' : (cur - 10) + 'a';
            result.push_back(c);
            num = num >> 4;
            if (num == 0)
                break;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};