class Solution {
public:
    int dp[501][501];
    int help(string &s1,string &s2,int l1,int l2){
        
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        
        if(l1==0 || l2==0)return 0;
        
        if(s1[l1-1]==s2[l2-1]){
            return dp[l1][l2]=1+help(s1,s2,l1-1,l2-1);
        }
        else{
            return dp[l1][l2]=max(help(s1,s2,l1,l2-1),help(s1,s2,l1-1,l2));
        }
        
        return dp[l1][l2];
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        
        string t=s;
        reverse(t.begin(),t.end());
        
        int count=help(s,t,s.length(),t.length());
        return s.length()-count;
    }
};