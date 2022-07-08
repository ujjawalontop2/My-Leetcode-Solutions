class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        else if(n==2) return "11";
        
            string str=countAndSay(n-1);
            int i=0,count=1;
            string res="";
        for(int i=1;i<str.length();i++){
            if(str[i]==str[i-1]) count++;
            else{
                res+=to_string(count)+str[i-1];
                count=1;
            }
        }
        
        res += to_string(count)+str[str.length()-1];
        return res;
    }
};