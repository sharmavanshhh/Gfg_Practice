class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int books = allocation(arr, mid);
            
            if(books <= k) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
    
    int allocation(vector<int>& arr, int mid){
        int totalBooks = 1;
        int pages = 0;
        for(int x : arr){
            if(pages + x > mid){
                totalBooks++;
                pages = x;
            }
            else{
                pages += x;
            }
        }
        return totalBooks;
    }
};