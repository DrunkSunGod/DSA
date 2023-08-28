 vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
       vector<int>adj[n] ; 
       for( int i = 0 ; i < m ; i++){
           int v = prerequisites[i][0] ; 
           int u = prerequisites[i][1] ; 
           adj[u].push_back(v); 
       }
       vector<int>indegree(n,0) ; 
       for( int i = 0 ; i < n ; i++){
           for( auto adjNode : adj[i] ){
               indegree[adjNode]++ ; 
           }
       }
       queue<int>q ; 
       for( int i = 0 ; i < n ; i++ ){
           if( indegree[i] == 0 )
                q.push(i) ; 
       }
       vector<int>toposort ; 
       vector<int>empty ; 
       
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
           if( toposort.size() == n ){
               return toposort ; 
           }
           return empty ; 
       }
