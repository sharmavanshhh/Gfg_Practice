class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int m = a.size();
        int n = b.size();
        
        if(m > n){
            return kthElement(b, a, k);
        }
        
        int low = max(0, k-n);
        int high = min(k, m);
        
        while(low <= high){
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1;
            
            int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int r1 = (mid1 == m) ? INT_MAX : a[mid1];
            
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int r2 = (mid2 == n) ? INT_MAX : b[mid2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            }
            else if(l1 > r2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
        return -1;
    }
};