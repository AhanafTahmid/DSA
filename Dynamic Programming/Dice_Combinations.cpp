#include <bits/stdc++.h>
using namespace std;

const int md = 1e9+7;
long long dp[1001000];
void solve(){
    int n;
    cin>>n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    for(int i=7;i<=n;i++){
        dp[i] += (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6])%md;
    }
    cout<<dp[n];

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}