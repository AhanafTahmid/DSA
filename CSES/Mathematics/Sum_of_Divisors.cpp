#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int md = 1e9 + 7;
void solve(){
    ll n;
    cin>>n;
    ll sum = 0;
    for(ll j=1;j<=n;j++){
        sum +=((n/j)*j);
    }
    cout<<sum<<endl;
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}