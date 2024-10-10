//Type: DP on Grid - Counting 
---------------------------------------------------------------
//Recursive
int md = 1e9+7;

int f(int i, int j, vector<vector<char>>&mat, vector<vector<int>>&dp){
    if(i==mat.size()-1 && j==mat[0].size()-1) return 1;
    if(i==mat.size() || j==mat[0].size()) return 0;
    if(mat[i][j]=='#')return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = (f(i+1, j, mat, dp) + f(i, j+1, mat, dp))%md;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>>mat(n, vector<char>(m));
    vector<vector<int>>dp(n, vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<< f(0,0,mat,dp) <<endl;
}
---------------------------------------------------------------
//Iterative
int md = 1e9+7;

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>>mat(n, vector<char>(m));
    vector<vector<int>>dp(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
            if(mat[i][j]=='#')continue;
            int down = 0, right = 0;
            if(i>0) down = dp[i-1][j];
            if(j>0) right = dp[i][j-1];
            dp[i][j] = (down + right)%md;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<< dp[n-1][m-1] <<endl;
}