class Solution {
  public:
    int binary_to_decimal(int B) {
        int decimal = 0;
        int power = 0;
        
        while(B > 0) {
            int lastDigit = B % 10;      // get last binary digit
            decimal += lastDigit * (1 << power); // 2^power
            B /= 10;                     // remove last digit
            power++;
        }
        
        return decimal;
    }
};