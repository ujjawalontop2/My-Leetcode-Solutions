class Solution {
public:
   bool check(char a,char b){
        return a=='(' && b==')' ||a=='{' && b=='}' ||a=='[' && b==']' ;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(check(st.top(),s[i])==false) return false;
                else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};