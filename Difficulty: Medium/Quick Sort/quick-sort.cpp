class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high){
            int p = partition(arr, low, high);
            
            quickSort(arr, low, p - 1);   // left part
            quickSort(arr, p + 1, high);  // right part
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];   // last element as pivot
        int i = low - 1;         // place for smaller elements
        
        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        // put pivot in correct position
        swap(arr[i + 1], arr[high]);
        
        return i + 1;   // pivot index
    }
};
