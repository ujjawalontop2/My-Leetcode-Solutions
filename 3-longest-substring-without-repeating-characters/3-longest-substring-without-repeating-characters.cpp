class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int j=0,ans=0,i=0,n=s.length();
        
        while(i<n && j<n){
            
          if(!st.count(s[i])){
              st.insert(s[i]);
              i++;
              
              if(ans<st.size()){
               ans=st.size();
           }
              
          }
            else{
                st.erase(s[j]);
                j++;
            }
               
        }
        return ans;
    }
};