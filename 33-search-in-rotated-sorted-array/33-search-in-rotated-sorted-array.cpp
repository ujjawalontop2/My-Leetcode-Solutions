class Solution {
public:
    
    int pivot(vector<int>nums){
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            //cout << l << " " << h << endl;
            int mid=(l+h)/2;
            int next=(mid+1)%n,prev=(mid+n-1)%n;
            
           
            if(nums[mid]>=nums[0]) l=mid+1;
            else h=mid-1;
                        

           
        }
        return l;
    }
   
    int search(vector<int>& nums, int target) {
        if (nums.front() < nums.back()) {
            if (binary_search(nums.begin(), nums.end(), target)) {
            return lower_bound(nums.begin(),nums.end(), target)-nums.begin();
        }
        
        return -1;
        }
        int index=pivot(nums);
        cout<<index;
        int l,h,n=nums.size();
        
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        
        if(target < nums[0]){
            l=index;
            h=n-1;
        }
        else{
            l=0;
            h=max(0,index-1);
        }
        
        if (binary_search(nums.begin() + l, nums.begin() + h + 1, target)) {
            return lower_bound(nums.begin()+l,nums.begin()+h+1,target)-nums.begin();
        }
        
        return -1;
    }
};