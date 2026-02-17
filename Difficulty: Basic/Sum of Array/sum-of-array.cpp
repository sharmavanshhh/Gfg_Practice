// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
       return sum(arr, arr.size());
    }
    
    int sum(vector<int>& arr, int n){
        if(n == 0) return 0;
        
        return arr[n-1] + sum(arr, n-1);
    }
};