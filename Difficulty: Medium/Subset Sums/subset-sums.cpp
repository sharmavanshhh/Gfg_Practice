class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        
        backtrack(arr, res, 0, 0);
        
        return res;
    }
    
    void backtrack(vector<int>& arr, vector<int>& res, int index, int currSum){
        if(index == arr.size()){
            res.push_back(currSum);
            return;
        }
        
        // include
        backtrack(arr, res, index+1, currSum+arr[index]);
        
        // exclude
        backtrack(arr, res, index+1, currSum);
    }
};