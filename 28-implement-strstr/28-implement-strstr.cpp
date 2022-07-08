class Solution {
public:
    int strStr(string h, string n) {
        if(n.length()==0) return 0;
        
        for(int i=0;i<h.length();i++){
            if(h[i]==n[0]){
                if(h.substr(i,n.length())==n) return i;
            }
        }
        return -1;
    }
};