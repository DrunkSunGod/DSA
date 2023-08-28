	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans ; 
	    vector<int>indegree(V,0) ; 
	    for( int node = 0 ; node < V ; node++ ){
	        for( auto adjNode : adj[node] )
	            indegree[adjNode]++ ; 
	    }
	    queue<int>q ; 
	    for( int i = 0 ; i < V ; i++ ){
	        if(indegree[i] == 0 ){
	            q.push(i) ; 
	        }
	    }
	    while( !q.empty() ){
	        int node = q.front() ; 
	        q.pop() ; 
	        ans.push_back(node) ; 
	        for( auto adjNode : adj[node] ){
	            indegree[adjNode]-- ; 
	            if( indegree[adjNode] == 0 )
	                q.push(adjNode) ; 
	               
	        }
	    }
	    return ans ; 
	    
	}
