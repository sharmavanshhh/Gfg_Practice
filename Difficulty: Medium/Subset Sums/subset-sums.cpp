class Solution {
  public:
  
    void sum(vector<int>& arr, vector<int>& res, int index, int currSum){
        if(index == arr.size()){
            res.push_back(currSum);
            return;
        }
        // include.
        sum(arr, res, index+1, currSum + arr[index]);
        
        // exclude.
        sum(arr, res, index+1, currSum);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;      
        
        sum(arr, res, 0, 0);
        
        return res;
    }
};