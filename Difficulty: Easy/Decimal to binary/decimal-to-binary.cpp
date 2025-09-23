class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string ans = "";
        while(n > 0){
            int temp = n % 2;
            char bit = temp + '0';
            ans += bit;
            n /= 2;
        }
        reverse(ans.begin(), ans.end()); // correct way to reverse
        return ans;
    }
};