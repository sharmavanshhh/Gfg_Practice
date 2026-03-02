class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int i = 0;
        int n = arr.size();
        
        while(i < n){
            int index = arr[i] - 1;
            if(arr[i] < n && arr[i] != arr[index]){
                swap(arr[i], arr[index]);
            }
            else{
                i++;
            }
        }
        
        for(int k = 0; k < n; k++){
            if(arr[k] != k + 1){
                return k + 1;
            }
        }
        
        return n+1;
    }
};