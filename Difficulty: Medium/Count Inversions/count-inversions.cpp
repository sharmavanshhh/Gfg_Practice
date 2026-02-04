class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr, 0, arr.size() - 1);
    }
    
    int mergeSort(vector<int> &arr, int l, int r){
        if(l >= r){
            return 0;
        }
        
        int m = l + (r - l) / 2;
        
        int inv = 0;
        
        inv += mergeSort(arr, l, m);
        inv += mergeSort(arr, m+1, r);
        inv += mergeAndCount(arr, l, m, r);
        
        return inv;
    }
    
    int mergeAndCount(vector<int> &arr, int l, int m, int r){
        vector<int> temp;
        int i = l, j = m+1;
        int invCount = 0;
        
        while(i <= m && j <= r){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
                invCount += (m - i + 1);
            }
        }
        
        while(i <= m) temp.push_back(arr[i++]);
        while(j <= r) temp.push_back(arr[j++]);
        
        for(int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }

        return invCount;
    }
};