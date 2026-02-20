class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> path;
        
        if(maze[0][0] == 0) return path;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        backtrack(maze, n, path, visited, 0, 0, "");
        
        return path;
    }
    
    void backtrack(vector<vector<int>>& maze, int n, vector<string>& path,
                    vector<vector<bool>>& visited, int row, int col, string curr){
        
        if(row == n - 1 && col == n - 1){
            path.push_back(curr);
            return;
        }          
        
        visited[row][col] = true;
        
        if(row + 1 < n && maze[row + 1][col] == 1 && !visited[row + 1][col]){
            backtrack(maze, n, path, visited, row + 1, col, curr + 'D');
        }
        if(col - 1 >= 0 && maze[row][col - 1] == 1 && !visited[row][col - 1]){
            backtrack(maze, n, path, visited, row, col - 1, curr + 'L');
        }
        if(col + 1 < n && maze[row][col + 1] == 1 && !visited[row][col + 1]){
            backtrack(maze, n, path, visited, row, col + 1, curr + 'R');
        }
        if(row - 1 >= 0 && maze[row - 1][col] == 1 && !visited[row - 1][col]){
            backtrack(maze, n, path, visited, row - 1, col, curr + 'U');
        }
        
        visited[row][col] = false;
    }
};