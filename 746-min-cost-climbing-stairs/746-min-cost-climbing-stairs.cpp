class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()+1];
        
        dp[0]=0;
        dp[1]=0;        
        for(int i=2;i<=cost.size();i++){
            int one=cost[i-1]+dp[i-1];
            int two=cost[i-2]+dp[i-2];
            
            dp[i]=min(one,two);
        }
        
        return dp[cost.size()];
        
    }
};