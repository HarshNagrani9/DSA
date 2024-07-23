class Solution {
public:
    int solve(vector<int>& piles, int i, int M, int alice, vector<vector<vector<int>>>&dp){
        if(i == piles.size()) return 0;
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
        if(dp[i][M][alice] != -1) return dp[i][M][alice];

        for(int X=1; X<=M*2; X++){
            if(i+X-1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice){
                ans = max(ans, total + solve(piles, i+X, max(X,M), !alice, dp));
            }
            else{
                ans = min(ans, solve(piles, i+X, max(X, M), !alice, dp));
            }
        }
        return dp[i][M][alice] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(3, -1)));
        return solve(piles, 0, 1, true, dp);
    }
};