// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        
        dist[0][0] = 0;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < N && ny < M && A[nx][ny] == 1){
                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return dist[X][Y] == INT_MAX ? -1 : dist[X][Y];
    }
};