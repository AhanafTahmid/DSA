//https://codeforces.com/contest/1336/submission/76827781
void dfs(int u, int p) {
    sz[u] = 1;
    dep[u] = 1 + dep[p];
    for (int v: adj[u]) {
        if (v==p)   continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    score.push_back(dep[u]-sz[u]);
}


//////////////////////////////////////////////////////////
void dfs(int child, int par, vector<int>&a, vector<int>adj[]){
    sz[child] = 1;
    dep[child] = 1 + dep[par];
    for(int neighbours: adj[child]){
        if( neighbours == par ) continue;//both child parent are the same
        dfs(neighbours, child, a, adj);
        sz[child]+= sz[neighbours];
    }
    a.push_back( dep[child] - sz[child] );
}