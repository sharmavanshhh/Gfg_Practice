class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int parts = canPaint(arr, mid);
            
            if(parts <= k) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
        
        int canPaint(vector<int>& arr, int mid){
        int part = 1;
        int t = 0;
        for(int x : arr){
            if(t + x > mid){
                part++;
                t = x;
            }
            else{
                t += x;
            }
        }
        return part;
    }
};