class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(v, 0);
        
        return backtrack(0, v, m, color, adj);
    }
    
    bool backtrack(int node, int v, int m, vector<int>& color, vector<vector<int>>& adj){
        if(node == v){
            return true;
        }
        
        for(int c = 1; c <= m; c++){
            if(isSafe(node, c, color, adj)){
                color[node] = c;
                
                if(backtrack(node + 1, v, m, color, adj)){
                    return true;
                }
                
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& adj){
        for(int neighbour : adj[node]){
            if(color[neighbour] == col){
                return false;
            }
        }
        return true;
    }
};