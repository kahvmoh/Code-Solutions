class Solution {
public:
    string validIPAddress(string IP) 
    {

        int dots = 0, colons = 0;
        // find the type of delimeters and count it
        for(int  i = 0; i < IP.length(); i++){
            if(IP[i] == '.')
                dots++;
            if(IP[i] == ':')
                colons++;
        }
        
        if(dots == 3 and colons == 0 and IP.length() <= 15){
            // IPV4
            for(int i = 0; i < IP.length(); i++){
                if(isalpha(IP[i]))
                    return "Neither";
            }
            return checkIPv4(IP);
        }
        else if(colons == 7 and dots == 0){
            // IPV6
            for(int i = 0; i < IP.length(); i++){
                if(IP[i] >= 'G' and IP[i] <= 'Z')
                    return "Neither";
                if(IP[i] >= 'g' and IP[i] <= 'z')
                    return "Neither";
            }
            return checkIPv6(IP);
        }
        else
            return "Neither";
    }
    
    string checkIPv4(string IP)
    {
        int i = 0, j = 0, count = 0;
        while(j < IP.length())
        {
            if(IP[j] == '.')
            {
                count++;
                string s = IP.substr(i, j - i);
                if(s.length() == 0)
                    return "Neither";
                if(s[0] == '0' and s.length() != 1)
                    return "Neither";
                if(stoi(s) > 255)
                    return "Neither";
                i = j + 1;
                j = j + 1;
                if(count == 3)
                    break;
            }
            else
                j++;
        }
        
        string s = IP.substr(i, IP.length() - i);
        if(s.length() == 0)
            return "Neither";
        if(s[0] == '0' and s.length()!= 1)
                    return "Neither";
        if(stoi(s) > 255)
                    return "Neither";
        return "IPv4";
    }
    
    string checkIPv6(string IP) 
    {
        int i = 0, j = 0, count = 0;
        while(j < IP.length()){
            if(IP[j] == ':'){
                count++;
                string s = IP.substr(i, j - i);
                if(s.length() < 1 or s.length() > 4)
                    return "Neither";
                i = j + 1;
                j = j + 1;
                if(count==7)
                    break;
            }
            else
                j++;
        }
        string s = IP.substr(i, IP.length() - j);
        
        if(s.length() == 0)
            return "Neither";
        if(s.length() < 1 or s.length() > 4)
                    return "Neither";
        return "IPv6";
    }
};