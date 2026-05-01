// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, vector<string>> mp;
        for(string a : arr){
            string key = a;
            sort(key.begin(), key.end());
            mp[key].push_back(a);
        }
        
        vector<vector<string>> ans;
        for(auto& p : mp){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};