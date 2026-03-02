class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        int n = s.size();
        int total = 1 << n;     // 2^n subsets

        vector<string> result;

        for(int mask = 0; mask < total; mask++){
            string temp = "";
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    temp += s[i];
                }
            }
            result.push_back(temp);
        }
        sort(result.begin(), result.end());
        return result;
    }
};