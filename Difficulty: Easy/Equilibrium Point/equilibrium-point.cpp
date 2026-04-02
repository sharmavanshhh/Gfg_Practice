class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int sum = 0;
        for(int x : arr){
            sum += x;
        }
        int lsum = 0;
        for(int i=0; i<arr.size(); i++){
            int rsum = sum - lsum - arr[i];
            if(lsum == rsum){
                return i;
            }
            lsum += arr[i];
        }
        return -1;
    }
};