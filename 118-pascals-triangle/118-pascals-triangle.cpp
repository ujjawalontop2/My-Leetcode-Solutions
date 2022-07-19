class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==1) return {{1}};
        ans={{1},{1,1}};
        
        int n=2;
        
        while(n<numRows){
            vector<int>temp;
            temp.push_back(1);
            
            for(int i=1;i<n;i++){
                temp.push_back(ans[n-1][i]+ans[n-1][i-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            
            n++;
        }
        return ans;
    }
};