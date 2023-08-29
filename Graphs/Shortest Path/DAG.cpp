vector<int>getTopoSort(vector<pair<int,int>>adj[], int n ){
    vector<int>indegree(n,0) ; 
    for( int i = 0 ; i < n ; i++ ){
        for( auto edge : adj[i] ){
            indegree[edge.first]++ ; 
        }
    }
    queue<int>q ; 
    for(int i = 0 ; i < n ; i++ ){
        if( indegree[i] == 0 ){
            q.push(i) ; 
        }
    }
    vector<int>ans ; 
    while(!q.empty() ){
        int node = q.front() ; 
        q.pop() ; 
        ans.push_back(node) ; 
        for( auto it : adj[node] ){
            int adjNode = it.first ; 
            indegree[adjNode]-- ; 
            if( indegree[adjNode] == 0 ){
                q.push(adjNode) ; 
            }
        }
    }
    return ans ; 
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int,int>>adj[n]  ;
    for( auto edge : edges ){
        int u = edge[0] ; 
        int v = edge[1] ; 
        int wt = edge[2] ; 
        adj[u].push_back({v,wt}) ; 
    }
    vector<int>toposort = getTopoSort(adj,n) ; 
    vector<int>dist(n,1e9) ;
    int src = 0 ; 
    dist[src] = 0 ; 
    for( int i = 0 ; i < n ; i++ ){
        int node = toposort[i] ; 
        for( auto it : adj[node] ){
            int adjNode = it.first ; 
            int wt = it.second ; 
            if( dist[node] + wt  < dist[adjNode] ){
                dist[adjNode] = dist[node] + wt ;
            }
        }
    }
    for( int i = 0 ; i < n ; i++) {
        if( dist[i] == 1e9 ){
            dist[i] = -1 ; 
        }
    }
    return dist ; 
}
