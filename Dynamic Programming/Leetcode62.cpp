class Solution {
public:
    int solve(int m, int n, int currm, int currn){
        if(currm >= m) return 0;
        if(currn >= n) return 0;
        if(currm == m-1 && currn == n-1) return 1;
        int ans = 0;
        ans += solve(m, n, currm+1, currn);
        ans += solve(m, n, currm, currn+1);

        return ans;
        
    }
    int solveMem(int m, int n, int currm, int currn, vector<vector<int>>& dp){
        if(currm >= m) return 0;
        if(currn >= n) return 0;
        if(currm == m-1 && currn == n-1) return 1;
        if(dp[currm][currn] != -1) return dp[currm][currn];
        int ans = 0;
        ans += solveMem(m, n, currm+1, currn, dp);
        ans += solveMem(m, n, currm, currn+1, dp);

        return dp[currm][currn] = ans;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int currm = 0;
        int currn = 0;
        int ans = solveMem(m, n, currm, currn, dp);
        return ans;
    }
};