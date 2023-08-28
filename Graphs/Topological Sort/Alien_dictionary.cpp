 void dfs( int node, vector<int>adj[], vector<int>&vis, stack<int>&st ){
        vis[node] = true ; 
        for( auto adjNode : adj[node] ){
            if( !vis[adjNode] )
                dfs(adjNode, adj, vis, st ) ; 
        }
        st.push(node) ; 
    }
    string findOrder(string dict[], int N, int K) {
       vector<int>adj[K] ; 
       for(int i = 0 ; i < N - 1 ; i++ ){
           string word1 = dict[i] ;
           string word2 = dict[i+1] ; 
           int j = 0 ; 
           while( j < word1.size() && j < word2.size() ){
               if( word1[j] != word2[j] ){
                   int u = word1[j] - 'a' ; 
                   int v = word2[j] - 'a' ;
                   adj[u].push_back(v) ;
                   break ; 
               }
               else{
                   j++ ; 
               }
           }
       }
       vector<int>vis(K,0) ; 
       stack<int>st ; 
       for( int i = 0 ; i < K ; i++ ){
           if( !vis[i] ){
               dfs(i, adj, vis, st ) ; 
           }
       }
       string ans ; 
       while( !st.empty()){
           int d = st.top() ; 
           st.pop() ; 
           ans.push_back( 'a' + d ) ; 
       }
       return ans ; 
       
    }
