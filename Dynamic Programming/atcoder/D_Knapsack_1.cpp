//Type: 2D DP - Take or Not Take Pattern(Knapsack)
---------------------------------------------------------------
//Recursive
int f(int i, int wg,vector<int>&w,vector<int>&v,vector<vector<int>>&dp){
    if(i==w.size()) return 0;
    if(dp[i][wg]!=-1) return dp[i][wg];
    int take = 0;
    int not_take = 0 + f(i+1,wg, w, v, dp);
    if(wg>=w[i]){
        take = v[i] + f(i+1,wg-w[i], w, v, dp);
    }
    return dp[i][wg] = max(take, not_take);
}

void solve(){
    int n, wg;cin>>n>>wg;
    vector<int>w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<int>>dp(n, vector<int>(wg+1,-1));
    cout<< f(0, wg, w, v, dp) <<endl;
}
---------------------------------------------------------------
//Iterative
void solve(){
    int n, wg;cin>>n>>wg;
    vector<int>w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<int>>dp(n, vector<int>(wg+1,0));
    for(int i=0;i<=wg;i++){
        if(w[0]<=i) dp[0][i] = v[0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=wg;j++){
            int take = 0;
            int not_take = dp[i-1][j];
            if(j>=w[i]){
                take = v[i] + dp[i-1][j-w[i]];
            }
            dp[i][j] = max(take, not_take);
        }
    }
    cout<< dp[n-1][wg] <<endl;
}