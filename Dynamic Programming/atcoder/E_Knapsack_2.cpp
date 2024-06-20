//Type: 2D DP - rotation of DP state
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n, wg;cin>>n>>wg;
    vector<int>w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int lm = 1e6, lm2 = 1e4;
    vector<vector<int>>dp(n, vector<int>(lm,0)), dp2(n, vector<int>(lm2,0));
    int ff = min(wg, lm);
    for(int i=0;i<=ff;i++){
        if(w[0]<=i) dp[0][i] = v[0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=ff;j++){
            int take = 0;
            int not_take = dp[i-1][j];
            if(j>=w[i]){
                take = v[i] + dp[i-1][j-w[i]];
            }
            dp[i][j] = max(take, not_take);
        }
    }

    if(ff==wg){
        cout<< dp[n-1][wg] << endl;
        return;
    }

    for(int i=lm-1;i<=wg;)
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=lm2;j++){
            int take = 0;
            int not_take = dp2[i-1][j];
            if(j>=w[i]){
                take = v[i] + dp2[i-1][j-w[i]];
            }
            dp2[i][j] = max(take, not_take);
        }
    }

    
    cout<< dp2[n-1][wg] <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}