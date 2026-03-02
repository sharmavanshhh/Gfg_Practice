class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        long long i = 0;
        long long n = arr.size();
        while(i < n){
            long long index = (long long)arr[i] - 1;
            if(arr[i] > 0 && arr[i] <=n && arr[i] != arr[index]){
                swap(arr[i],arr[index]);
            }
            else{
                i++;
            }
        }
        for(int k=0; k<n; k++){
            if(arr[k] != k+1){
                return k+1;
            }
        }
        return n+1;
    }
};