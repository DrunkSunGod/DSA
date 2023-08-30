vector<vector<int>> sol(function<int(int, int)> f, int z) {
  vector<vector<int>> ans;
  int Y = 2000 ; 
  for( int X = 1 ; X <= 2000 ; X++ ){
	  while( f(X,Y) > z ){
		  Y-- ; 
	  }
	  if( Y >= 1 && f(X,Y) == z ){
		  ans.push_back({X,Y}) ; 
	  }
  }
  return ans ; 
}
