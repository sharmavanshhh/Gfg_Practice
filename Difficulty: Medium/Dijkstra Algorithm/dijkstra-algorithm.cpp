class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        // build graph
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove if directed
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto &it : adj[node]){
                int neigh = it.first;
                int wt = it.second;
                
                if(dist[neigh] > d + wt){
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        
        return dist;
    }
};