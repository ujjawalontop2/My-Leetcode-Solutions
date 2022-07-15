class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        while(i<j){
            int l=min(height[i],height[j]);
            ans=max(ans,l*(j-i));
           // cout<<ans;
            
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};