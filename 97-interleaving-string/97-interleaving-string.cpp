class Solution {
public:
    int dp[102][102];
    
    bool help(string s1,string s2,string s3,int l1,int l2,int l3){
        if(l1<0 && l2<0 && l3<0) return true;
        
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1){
            return dp[l1][l2];
        }
        
        if(l1>=0 && s3[l3]==s1[l1]  && l2>=0 && s3[l3]==s2[l2]){
         return dp[l1][l2]=(help(s1,s2,s3,l1-1,l2,l3-1) || help(s1,s2,s3,l1,l2-1,l3-1));
        }
        else if(l1>=0 && s3[l3]==s1[l1]){
            return help(s1,s2,s3,l1-1,l2,l3-1);
        }
         else if(l2>=0 && s3[l3]==s2[l2]){
            return help(s1,s2,s3,l1,l2-1,l3-1);
        }
        else{
            return false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        
        memset(dp,-1,sizeof(dp));
        return help(s1,s2,s3,s1.length()-1,s2.length()-1,s3.length()-1);
       
    }
};