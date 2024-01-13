#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9+7;
ll dp[1000000];
ll fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = (fib(n-2)%md + fib(n-1)%md)%md;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


