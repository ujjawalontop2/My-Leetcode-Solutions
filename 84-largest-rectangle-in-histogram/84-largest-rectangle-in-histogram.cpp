class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>>st;
        
        st.push({heights[0],0});
        vector<int >left;left.push_back(-1);
        
        for(int i=1;i<n;i++){
            if(heights[i] > st.top().first){
                left.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>=heights[i]) st.pop();
                if(st.empty()) left.push_back(-1);
                else{
                    left.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
           
        }
        
  while(!st.empty()) st.pop();
        
        vector<int>right;right.push_back(n);
        st.push({heights[n-1],n-1});
        
        for(int i=n-2;i>=0;i--){
            if(heights[i]>st.top().first){
                right.push_back(st.top().second);
            }
            else{
               while(!st.empty() && st.top().first>=heights[i]) st.pop();
                
                if(st.empty()) right.push_back(n);
                else{
                    right.push_back(st.top().second);
                }
            }
            st.push({heights[i],i}); 
        }
        reverse(right.begin(),right.end());
       
        int ans=heights[0];
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,heights[i]*width);
        }
        
        return ans;
    }
};