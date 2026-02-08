class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();

        for(int i = 1; i < n; i++){
            int key = arr[i];
            int j = i - 1;

            // shift bigger elements to right
            while(j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }

            // insert at correct place
            arr[j + 1] = key;
        }
    }
};
