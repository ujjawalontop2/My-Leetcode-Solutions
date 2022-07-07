class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long ans=0;
        
        while(s[i]==' ') i++;
        
        int sign=1;
        if(s[i]=='-') {
            sign =-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }

        for(int k=i;k<s.length();k++){
            
            if(s[k]>='0' && s[k]<='9'){
             
                ans=ans*10+(s[k]-'0');
                
                if(ans*sign>=INT_MAX ) return INT_MAX;
                if(ans*sign<=INT_MIN) return INT_MIN;
            }
            else break;
            
            
       }
        
        return ans*sign;
    }
};