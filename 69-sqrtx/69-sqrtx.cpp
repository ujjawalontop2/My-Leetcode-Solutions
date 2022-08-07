class Solution {
public:
    int mySqrt(int x) {
        
        long long start=0,end=x;
        float ans;
        long long mid;
        
        while(start<=end){
             mid=start+(end-start)/2;
            
            if(mid*mid<=x) {
               start=mid+1; 
            } 
            else end=mid-1;
        }
        
        return end;
    }
};