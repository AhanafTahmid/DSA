#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9 + 7;

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}

ll inverse(ll i){
    return binpow(i, md-2, md);//binexpo(tt,M-2,M); = a^(M-2)%M
}

void burnside_lemma(ll N, ll M)
{
 
    ll ans = 0;
 
    // According to Burnside's Lemma
    // calculate distinct ways for each rotation
    for (ll i = 0; i < N; i++) {
 
        // Find M^(GCD(k,n))
        ans = ( ans + binpow(M,__gcd(i,N),md))%md;
        //cout<< N << " " << M << " " << ans <<endl;
        //cout<<K<<" "<<M<<endl;
    }
    
    //for very long N size, we must do inverse modulo
    ll nn = inverse(N);//cause divided by, so -> ans = ans * N^-1
    ans = (ans%md * nn%md)%md;
    cout << ans << endl;
}
 

void solve(){
    ll n,k;
    cin>>n>>k;
    //cout<<burnside_lemma(n,k)<<endl;
    burnside_lemma(n,k);
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}