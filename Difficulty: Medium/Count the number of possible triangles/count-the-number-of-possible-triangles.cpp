class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int count = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i = n - 1; i >= 2; i--){
            int left = 0;
            int right = i - 1;
            
            while(left < right){
                if(arr[left] + arr[right] > arr[i]){
                    count += (right - left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        
        return count;
    }   
};
