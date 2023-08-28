 vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>reverseAdj[V] ;
        for( int i = 0 ; i < V ; i++){
            for( auto adjNode : adj[i] ){
                reverseAdj[adjNode].push_back(i) ;        
            }
        }
        adj = reverseAdj; 
        vector<int>indegree(V,0) ; 
        for(int i = 0 ; i < V ; i++){
            for( auto adjNode : adj[i] ){
                indegree[adjNode]++ ; 
            }
        }
        queue<int>q ; 
        for( int i = 0 ; i < V ; i++ ){
            if( indegree[i] == 0 ){
                q.push(i) ; 
            }
        }
        vector<int>ans ; 
        while( !q.empty() ){
            int node = q.front() ; 
            q.pop() ; 
            ans.push_back(node) ; 
            for( auto adjNode : adj[node] ){
                indegree[adjNode]-- ; 
                if( indegree[adjNode] == 0 ){
                    q.push(adjNode) ; 
                }
            }
        }
        sort( ans.begin(), ans.end() ) ; 
        return ans ; 
    }
