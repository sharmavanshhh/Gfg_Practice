
class Solution {
  public:
    long long countBits(long long N) {
        // code here
        if(N == 0) return 0;
        
        // Highest power of 2 less than or equal to N
        long long x = log2(N);
        long long power = 1 << x;       // 2^x
        
        // Total set bits from 1 to 2^(x - 1)
        long long setBits = x * (power >> 1);
        
        // MSB contribution from 2^x to N
        long long msb = N - power + 1;
        
        // Remaining Part
        long long remaining = N - power;
        
        return setBits + msb + countBits(remaining);
    }
};
