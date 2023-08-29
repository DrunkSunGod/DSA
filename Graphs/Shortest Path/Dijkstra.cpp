vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,1e9) ; 
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ; 
        pq.push({0,S}) ; 
        dist[S] = 0 ;
        while( !pq.empty() ){
            int node = pq.top().second ; 
            int d = pq.top().first ;
            pq.pop() ; 
            for( auto it : adj[node] ){
                int adjNode = it[0] ; 
                int wt = it[1] ; 
                if( dist[adjNode] > wt + d ){
                    dist[adjNode] = wt + d ; 
                    pq.push({dist[adjNode], adjNode}) ; 
                }
            }
        }
        return dist ; 
    }
