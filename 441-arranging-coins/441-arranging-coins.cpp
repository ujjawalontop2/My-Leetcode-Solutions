class Solution {
public:
    int arrangeCoins(int n) {
        //x*x+1=2n
        int start=1,end=n;
        while(start<=end){
            long long mid=start+(end-start)/2;
            
            if((mid*(mid+1))/2 ==n) return mid;
            
            else if((mid*(mid+1))/2 <n){
                start=mid+1;
            }
            else end=mid-1;
        }
        
         return end;
    }
};