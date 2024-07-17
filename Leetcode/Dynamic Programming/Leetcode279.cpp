class Solution {
public:
    bool isPerfectSquare(long double x)
{
    if (x >= 0) {
 
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
    int reccKaAns(int n, vector<int> &coins){
        if (n == 0){
            return 0;
        }
        if (n < 0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(n - coins[i] >= 0){
                int ans = reccKaAns(n-coins[i], coins);
            if(ans != INT_MAX){
                int ans2 = 1 + ans;
                mini = min(mini, ans2);
            }
        }
    }
        return mini;
    }
    int MemKaAns(int n, vector<int> &coins, vector<int> &dp){
        if (n == 0){
            return 0;
        }
        if (n < 0){
            return INT_MAX;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(n - coins[i] >= 0){
                int ans = MemKaAns(n-coins[i], coins, dp);
            if(ans != INT_MAX){
                int ans2 = 1 + ans;
                mini = min(mini, ans2);
            }
        }
    }
        return dp[n] =  mini;
    }
    int numSquares(int n) {
        vector<int> coins;
        vector<int> dp(n+1, -1);
        for (int i=1; i<=n; i++){
            if(isPerfectSquare(i)){
                coins.push_back(i);
            }
        }
        int Ans = MemKaAns(n, coins, dp);
        return Ans;
    }
};