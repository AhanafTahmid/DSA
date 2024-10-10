#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int md = 1e9+7;

ll binpow(ll a,ll b, int md) {
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
    int n;
    cin>>n;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        //power er upor power coprime ber kore kore kora for extremely large values
        cout<<binpow(a,(binpow(b,c,md-1)),md)<<endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}