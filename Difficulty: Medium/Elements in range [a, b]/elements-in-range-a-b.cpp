class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(), arr.end());
        
        vector<int> ans;
        
        for(auto &q : queries){
            int L = q[0];
            int R = q[1];
            
            int left = lowerBound(arr, L);
            int right = upperBound(arr, R);
            
            ans.push_back(right - left);
        }
        
        return ans;
    }
    
    int lowerBound(vector<int>& arr, int L){
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= L){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int upperBound(vector<int>& arr, int R){
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] > R){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};