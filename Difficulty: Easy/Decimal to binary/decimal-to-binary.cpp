// User function Template for C++

void toBinary(int n) {
    // your code here
    string ans = "";
    while(n>0){
        int temp = n%2;
        char bit = temp + '0';
        ans += bit;
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}