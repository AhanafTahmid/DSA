//Type: DP on Graph
---------------------------------------------------------------
//Recursive
vector<int> adj[100005];
vector<int>dp(100005,-1);
int visit(int i){
    if(dp[i]!=-1) return dp[i];
    int mx = 0;
    for(auto x: adj[i]){
        mx = max(mx, visit(x)+1);
    }
    return dp[i] = mx;
}

void solve(){
    int n, e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, visit(i));
    }
    cout<< ans <<endl;
}
---------------------------------------------------------------
//Iterative
Do it using topological sorting???