class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],pos=nums[0],neg=nums[0];
         
        for(int i=1;i<nums.size();i++){
          if(nums[i]<0) {
              int temp=pos;
              pos=neg;
              neg=temp;
          }
            
            pos=max(nums[i],pos*nums[i]);
            neg=min(nums[i],neg*nums[i]);
            
            ans=max(ans,pos);
        }
        return ans;
    }
};