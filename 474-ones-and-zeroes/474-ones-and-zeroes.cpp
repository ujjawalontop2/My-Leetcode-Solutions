class Solution {
public:
    int dp[601][101][101];
    int solve(int i, vector<pair<int,int>> &a, int m, int n) {
        if(i == a.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        
        
        int take = -1;
        int c_zero = a[i].first, c_one = a[i].second;
        
        if(c_zero <= m and c_one <= n) {
            take = 1 + solve(i+1,a,m-c_zero,n-c_one);
        }
        int notake = solve(i+1,a,m,n);

        return dp[i][m][n] = max(take, notake);
    }
    
    int findMaxForm(vector<string>& s, int m, int n) {
        int size_s = s.size();
        int k = 0;
        vector<pair<int,int>> a(size_s);
        memset(dp,-1,sizeof(dp));
        for(auto &i : s) {
            int c = 0;
            for(auto &j : i) {
                if(j == '0') c++;
            }
            a[k++] = {c,abs((int)i.size()-c)};
        }
        return solve(0,a,m,n);
    }
};