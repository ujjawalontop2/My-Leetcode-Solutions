class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    
    int fill(int m, int n, int maxm,int move, int r, int c){
        if(r<0 || c<0 || r>=m ||c>=n) return 1;
        if(maxm==move) return 0;
        if(dp[move][r][c]!=-1) return dp[move][r][c];
        
        int temp=0;
        
        temp=( temp+fill(m,n,maxm,move+1,r+1,c) )%mod;
        temp=( temp+fill(m,n,maxm,move+1,r,c+1) )%mod;
        temp=( temp+fill(m,n,maxm,move+1,r-1,c) )%mod;
        temp=( temp+fill(m,n,maxm,move+1,r,c-1) )%mod;
        
        dp[move][r][c]=temp;
        
        return dp[move][r][c]%mod;
        
    }
    
    int findPaths(int m, int n, int maxm , int r, int c) {
        for(int i=0;i<51;i++){
              for(int j=0;j<51;j++){
              for(int k=0;k<51;k++){
            dp[i][j][k]=-1;
        }
          }
        }
        
        return fill(m,n,maxm,0,r,c);
    }
};