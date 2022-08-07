class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        
            if(n==1) return nums[0];            
            if(nums[low]<nums[high]) return nums[low];
        
        while(low<=high){

            int mid=low+(high-low)/2;
            
            if(nums[mid]<nums[0]){
                high=mid-1;
            }
            else low=mid+1;
        }
        return nums[low];
    }
};