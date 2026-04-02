class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int low = 0;
        int high = arr.size() - 1;
        while(low < high){
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
};