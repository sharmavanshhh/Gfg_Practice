class Solution {
  public:
    int solve(int index, int w, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(index == val.size()) return 0;
        
        if(w <= 0) return 0;
        
        if(dp[index][w] != -1) return dp[index][w];
        
        int skip = 0 + solve(index + 1, w, val, wt, dp);
        int take = INT_MIN;
        if(wt[index] <= w){
            take = val[index] + solve(index + 1, w - wt[index], val, wt, dp);
        }
        
        return dp[index][w] = max(skip, take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(0, W, val, wt, dp);
    }
};