class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int, int>> timings;
        
        for(int i = 0; i < start.size(); i++){
            timings.push_back({start[i], finish[i]});
        }
        
        sort(
            timings.begin(), timings.end(),
            [](auto &a, auto &b){
                return a.second < b.second;
            }
        );
        
        int count = 1;
        int lastEnd = timings[0].second;
        
        for(int i = 1; i < timings.size(); i++){
            if(timings[i].first > lastEnd){
                count++;
                lastEnd = timings[i].second;
            }
        }
        
        return count;
    }
};