class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
           int n = matrix.size(), m= matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j-1];
                
            }
           
        }
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = i; j < m; j++)
            {
                unordered_map<int, int> um;
                um[0]++;
                int sum = 0;
                for(int k = 0; k < n; k++)
                {
                    sum += matrix[k][j];
                    if(i > 0)
                        sum -= matrix[k][i-1];
                    if(um.count(sum-target))
                        ans += um[sum-target];
                    um[sum]++;
                }
            }
        }
        return ans;
    }
};