//Type: 2D DP
---------------------------------------------------------------
- for day = 0, donot write the condition extra, just write day<0 return 0
//Recursive
int f(int day,int last,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(day<0)return 0;
    if(dp[day][last]!=-1) return dp[day][last];
    int mx = 0;
    for(int j=0;j<3;j++){
        if(j!=last){
            int ans = mat[day][j] + f(day-1, j, mat, dp);
            mx = max(mx, ans);
        }
    }
    return dp[day][last] = mx;
}

void solve(){
    int n;cin>>n;
    vector<vector<int>>mat(n, vector<int>(3)), dp(n+1, vector<int>(4,-1));
    for(int i=0;i<n;i++){
        cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
    }
    cout<< f(n-1, 3, mat, dp) <<endl;
}
---------------------------------------------------------------
//Iterative
void solve(){
    int n;cin>>n;
    vector<vector<int>>mat(n, vector<int>(3)), dp(n+1, vector<int>(4,0));
    for(int i=0;i<n;i++){
        cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
    }
    dp[0][0] = max(mat[0][1],mat[0][2]);
    dp[0][1] = max(mat[0][0],mat[0][2]);
    dp[0][2] = max(mat[0][0],mat[0][1]);
    dp[0][3] = max({mat[0][0],mat[0][1],mat[0][2]});//just for storing answer, nahole 1 bar traverse kora lagbe

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){//the last index is just for storing answer
            int mx = 0;
            for(int j=0;j<3;j++){
                if(j!=last){
                    int ans = mat[day][j] + dp[day-1][j];
                    mx = max(mx, ans);
                }
            }
            dp[day][last] = mx;
        }
    }

    cout<< dp[n-1][3] <<endl;
}