// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        if(arr.size() <= 2){
            return max(arr[0], arr[1]);
        }
        
        int* dp = new int[arr.size()+1];
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        for(int i=2; i<=arr.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        
        return dp[arr.size()-1];
    }
};