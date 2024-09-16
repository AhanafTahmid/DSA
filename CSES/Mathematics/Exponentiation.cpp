#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int md = 1e9+7;
//a^b
ll bin_expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%md;
        a = (a * a)%md;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<bin_expo(a,b)<<endl;
    }
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}