class Solution {
  public:
    int solve(int index, int currSum, vector<int>& arr, int target, vector<vector<int>>& dp){
        if(index == arr.size()){
            return (currSum == target) ? 1 : 0;
        }
        
        if(dp[index][currSum] != -1) return dp[index][currSum];
        
        int skip = solve(index + 1, currSum, arr, target, dp);
        int take = 0;
        
        if(currSum + arr[index] <= target){
            take = solve(index + 1, currSum + arr[index], arr, target, dp);
        }
        
        return dp[index][currSum] = skip + take;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return solve(0, 0, arr, target, dp);
    }
};