#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9 + 7;
ll dp[2000000];
ll dearrangement(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;

    if(dp[n]!=-1) return dp[n];
    return  dp[n] = ((n-1) * ( dearrangement(n-1) + dearrangement(n-2) ))%md;
}

void solve(){
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<dearrangement(n)<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}