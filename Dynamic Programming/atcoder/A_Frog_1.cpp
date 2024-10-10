//Type: 1D DP
---------------------------------------------------------------
//Recursive
vector<int>dp(n,-1);
int f(int i, vector<int>&a, vector<int>&dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int a1 = abs(a[i-1] - a[i]) + f(i-1, a, dp);
    int a2 = INT_MAX;
    if(i>1)a2 = abs(a[i-2] - a[i]) + f(i-2, a, dp);
    return dp[i] = min(a1, a2);
}
---------------------------------------------------------------
//Iterative
dp[0] = 0;
dp[1] = abs(a[1] - a[0]);
for(int i=2;i<n;i++){
    int a1 = abs(a[i-1] - a[i]) + dp[i-1];
    int a2 = abs(a[i-2] - a[i]) + dp[i-2];
    dp[i] = min(a1,a2);
}
cout<< dp[n-1] <<endl;