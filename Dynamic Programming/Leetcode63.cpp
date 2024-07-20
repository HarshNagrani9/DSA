class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int row, int col, int targetRow, int targetCol, vector<vector<int>>& dp){
        if(row > targetRow || col > targetCol) return 0;
        if(obstacleGrid[row][col] == 1) return 0;
        if(row == targetRow && col == targetCol) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int rowAns = 0;
        int colAns = 0;
        rowAns = rowAns + solve(obstacleGrid, row+1, col, targetRow, targetCol, dp);
        colAns = colAns + solve(obstacleGrid, row, col+1, targetRow, targetCol, dp); 
        return dp[row][col] = rowAns+colAns;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int targetRow = obstacleGrid.size()-1;
        int targetCol = obstacleGrid[0].size()-1;

        int row = 0;
        int col = 0;

        vector<vector<int>> dp(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1, -1));

        int ans = solve(obstacleGrid, row, col, targetRow, targetCol, dp);
        return ans;
    }
};