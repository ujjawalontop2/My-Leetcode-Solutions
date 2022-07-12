class Solution {
public:
    bool makesquare(vector<int>& m) {
        int tsum=0,n=m.size();
        for(int i=0;i<n;i++){
            tsum+=m[i];
        }
        if(n<4 || tsum%4 != 0) return false;
        
         int target=tsum/4;
        
      vector<int> dp((1<<n),-1);//create dp table of size 2^n size
       dp[0]=0;//start index
    
    for(int mask=0;mask<(1<<n);mask++){
        if(dp[mask]==-1)// Invalid Case
            continue;
        
        for(int j=0;j<n;j++){
            if(!(mask &(1<<j)) && dp[mask]+m[j]<=target)
            {
                dp[mask | (1<<j)]=(dp[mask]+m[j])%target;
            }
        }
    }
    return dp[(1<<n)-1]==0?true:false;
        
    }
};