//fibonacci using dp
#include <bits/stdc++.h>
using namespace std;

int dp[100];
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-2) + fib(n-1);
}

void solve(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


