class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls.front();
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int cows = checkCows(stalls, mid);
            
            if(cows >= k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
    
    int checkCows(vector<int>& stalls, int dist){
        int cows = 1;
        int last = stalls[0];
        
        
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - last >= dist){
                cows++;
                last = stalls[i];
            }
        }
        
        return cows;
    }
};