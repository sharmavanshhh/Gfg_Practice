class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        for(int i=0; i<arr.size(); i++){
            int min_index = i;
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j]<arr[min_index]){
                    min_index = j;
                }
            }
            if(min_index!=i){
                swap(arr[min_index],arr[i]);
            }
        }
    }
};