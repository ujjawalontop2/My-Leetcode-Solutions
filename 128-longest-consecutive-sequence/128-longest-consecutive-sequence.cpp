class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ans=0;
        
        for(int x :nums){
            if(s.count(x-1))  continue;
            else{
                int temp=x;
                int count=1;
                
                while(s.count(++temp)) count++;
                
                ans=max(ans,count);
            }
        }
        
        return ans;
    }
};