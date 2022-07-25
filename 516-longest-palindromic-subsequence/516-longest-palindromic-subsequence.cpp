class Solution {
public:
    int dp[1001][1001];
    
    int solve(string &s1,string &s2,int i,int j){
        if(i==0||j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=1+solve(s1,s2,i-1,j-1);
        }
        else{
            return dp[i][j]=max(solve(s1,s2,i-1,j),solve(s1,s2,i,j-1));
        }
        
        
    }
    
    int longestPalindromeSubseq(string s) {
        
        memset(dp,-1,sizeof(dp));
        
        string s2=s;
        reverse(s.begin(),s.end());
        
        return solve(s,s2,s.size(),s.size());
        
    }
};