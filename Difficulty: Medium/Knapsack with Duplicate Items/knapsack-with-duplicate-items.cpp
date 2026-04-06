class Solution {
  public:
    int solve(int index, int cap, vector<int>&val, vector<int>& wt, vector<vector<int>>& dp){
        if(index == val.size()) return 0;
        
        if(cap <= 0) return 0;
        
        if(dp[index][cap] != -1) return dp[index][cap];
        
        int skip = solve(index + 1, cap, val, wt, dp);
        int take = 0;
        if(wt[index] <= cap){
            take = val[index] + solve(index, cap - wt[index], val, wt, dp);
        }
        
        return dp[index][cap] = max(skip, take);
        
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        
        return solve(0, capacity, val, wt, dp);
    }
};