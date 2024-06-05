//Type: 1D DP(Loop)
---------------------------------
//Recursive
int f(int i,int k, vector<int>&a, vector<int>&dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int a1 = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int a2 = abs(a[i-j] - a[i]) + f(i-j,k, a, dp);
            a1 = min(a1, a2);
        }
    }
    return dp[i] = a1;
}
---------------------------------
//Iterative
int n, k;cin>>n>>k;
vector<int>a(n),dp(n,0);
for(int &i: a)cin>>i;
dp[0]=0;
for(int i=1;i<n;i++){
    int a1 = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int a2 = abs(a[i-j] - a[i]) + dp[i-j];
            a1 = min(a1, a2);
        }
    }
    dp[i] = a1;
}
cout<< dp.back() <<endl;