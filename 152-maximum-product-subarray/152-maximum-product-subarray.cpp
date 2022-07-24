class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],pos=nums[0],neg=nums[0];
        
      
        
        for(int i=1;i<nums.size();i++){
            int temp=pos;
            pos=max({nums[i],neg*nums[i],pos*nums[i]});
            neg=min({nums[i],neg*nums[i],temp*nums[i]});
            
            ans=max(ans,pos);
        }
        return ans;
    }
};