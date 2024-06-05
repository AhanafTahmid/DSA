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

    //dp[x] = number of ways to make sum x using numbers from 1 to 6.
    //Summing over the possibilities gives dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6].
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