// User function Template for C++

class Solution {
  public:
    int solve(int index, int length, vector<int>& price, vector<vector<int>>& dp){
        if(index == price.size()) return 0;
        if(length == 0) return 0; 
        
        if(dp[index][length] != -1) return dp[index][length]; 
        
        int skip = solve(index + 1, length, price, dp);
        
        int take = INT_MIN;
        
        int rodLength = index + 1;
        
        if(rodLength <= length){
            take = price[index] + solve(index, length - rodLength, price, dp);
        }
        
        return dp[index][length] = max(skip, take);
    }
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, n, price, dp);
    }
};