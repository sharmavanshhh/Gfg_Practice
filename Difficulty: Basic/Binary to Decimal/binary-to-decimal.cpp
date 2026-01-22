class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int result = 0;
        for(char ch : b){
            int bit = ch - '0';
            result = result * 2 + bit;
        }
        return result;
    }
};