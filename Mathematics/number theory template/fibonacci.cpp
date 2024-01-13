//Sequence followed here: 0,1,1,2,3,5,8,13,21...

//fibonacci using dp -> O(N)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100];
ll fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-2) + fib(n-1);
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



