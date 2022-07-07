class Solution {
public:
    string reverseWords(string s) {
        int i=s.length()-1;
        string ans="";
        
          while(ans.empty() && s[i]==' '){
               i--;
           }
        
        while(i>=0){
            
           int end=i;
            
          while(  i>=0 && s[i]!=' ' ){
                i--;
            }
            
           ans+=s.substr(i+1,end-i); 
            
            while(i>=0 && s[i]==' ') i--;
            
            if(i>=0) ans+=' ';
        }
        
        return ans;
    }
};