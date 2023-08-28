
	void dfs( int node, stack<int>&st, vector<int>adj[], vector<int>&vis ){
	    vis[node] = true ; 
	    for( auto adjNode : adj[node] ){
	        if( !vis[adjNode] )
	            dfs(adjNode, st, adj, vis )  ;
	    }
	    st.push(node) ; 
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int>vis(V, 0 ) ; 
	   stack<int>st ; 
	   for( int i = 0 ; i < V ; i++ ){
	       if( !vis[i] )
	            dfs(i, st, adj, vis ) ; 
	   }
	   vector<int>ans ; 
	   while( !st.empty() ){
	       ans.push_back( st.top() ) ; 
	       st.pop() ; 
	   }
	   return ans ; 
	}
};
