class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string ans = "";
        while(n > 0){
            int rem = n % 2;
            // cout << ans << endl;
            ans += (rem + '0');
            n /= 2;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};