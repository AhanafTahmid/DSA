#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll modd = 1e9+7;
    ll ans = 1;
    for(ll i=1;i<=n;i++){
        ans= (ans*2)%modd;
    }
    cout<<ans<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}