bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N] ; 
	    for( int i = 0 ; i < P ; i++) {
	        int v = prerequisites[i].first ; 
	        int u = prerequisites[i].second  ; 
	        adj[u].push_back(v) ; 
	    }
	    queue<int>q ; 
	    vector<int>indegree(N,0) ; 
	    for( int i = 0 ; i < N ; i++){
	        for( auto adjNode : adj[i] )
	            indegree[adjNode]++ ; 
	    }
	    for( int i = 0 ; i < N ; i++) {
	        if( indegree[i] == 0 )
	            q.push(i) ; 
	    }
	    vector<int>toposort ;
	    while(!q.empty() ){
	        int node = q.front() ; 
	        q.pop() ;
	        toposort.push_back(node) ; 
	        for( auto adjNode : adj[node] ){
	            indegree[adjNode]-- ; 
	            if( indegree[adjNode] == 0 )
	                q.push(adjNode) ; 
	        }
	    }
	    return ( toposort.size() == N ) ? 1 : 0 ; 
	}
