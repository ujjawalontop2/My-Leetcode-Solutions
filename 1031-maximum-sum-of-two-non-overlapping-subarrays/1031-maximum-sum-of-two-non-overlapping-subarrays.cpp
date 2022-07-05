class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n=nums.size();
        int presum[n+1];
        
        presum[0]=0;
        for(int i=1;i<=n;i++) {
            presum[i]=presum[i-1]+nums[i-1];
        }
        
        int ans=0;
        
        for(int i=0;i<=n-f;i++){
            int fsum=presum[i+f]-presum[i];
            
            for(int j=0;j<i-s;j++){
                int ssum=presum[j+s]-presum[j];
                ans=max(ans,ssum+fsum);
            }
            for(int j=i+f;j<=n-s;j++){
                int ssum=presum[j+s]-presum[j];
                ans=max(ans,ssum+fsum);
            }
        }
      return ans;  
                                                 
    }
};

    // 4  && 3
//   0 1 2  3  4  5  6  7  8  9
//   2 1 5  6  0  9  5  0  3  8
//   0 2 3 8  14 14 23 28 28 31 39                                               