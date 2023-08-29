vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
   vector<int>adj[n] ; 
   for( auto edge : edges ){
       int u = edge[0] ; 
       int v = edge[1] ; 
       adj[u].push_back(v) ; 
       adj[v].push_back(u) ; 
   }
   vector<int>vis(n,0) ; 
   vector<int>dist(n,-1) ; 
   queue< pair<int,int> > q ; 
   q.push({src, 0}) ; 
   vis[src] = true ; 
   while( !q.empty() ){
       int node = q.front().first ; 
       int lvl = q.front().second ;
       dist[node] = lvl ;  
       q.pop() ; 
       for( auto adjNode : adj[node] ){
           if( !vis[adjNode] ){
               vis[adjNode] = true ; 
               q.push({adjNode, lvl+1}) ; 
           }
       }
   }
   return dist ; 
}
