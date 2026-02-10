class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();

        vector<pair<int,int>> meet;
        for(int i = 0; i < n; i++){
            meet.push_back({end[i], start[i]});
        }

        sort(meet.begin(), meet.end());

        int count = 0;
        int lastEnd = -1;

        for(auto &m : meet){
            int e = m.first;
            int s = m.second;

            if(s > lastEnd){   // strict >
                count++;
                lastEnd = e;
            }
        }

        return count;
    }
};