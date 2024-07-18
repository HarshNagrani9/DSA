class Solution {
public:
    int solve(int plan, vector<int>& days, vector<int>& costs, int n, vector<vector<int>>& dp){
        if(n >= days.size()) return 0;
        if(days[n] <= plan){
            return solve(plan, days, costs, n+1,dp);
        }
        if(dp[plan][n] != -1) return dp[plan][n];

        int one = costs[0] + solve(days[n], days, costs, n+1, dp);
        int seven = costs[1] + solve(days[n]+6, days, costs, n+1, dp);
        int thirty = costs[2] + solve(days[n]+29, days, costs, n+1, dp);

        return dp[plan][n] = min({one, seven, thirty});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(366, vector<int>(days.size()+1, -1));
        int ans = solve(0, days, costs, 0, dp);
        return ans;
    }
};