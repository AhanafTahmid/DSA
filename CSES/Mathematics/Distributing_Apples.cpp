// (n+k-1)! / (n-1)!*k!

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9+7;

ll factorial[10020000];
void precalculateFactorials(int n) {
    factorial[0] = 1;
    for (int j = 1; j <= n; j++) {
        factorial[j] = (factorial[j - 1] * j) % md;
    }
}

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


void solve(){
    precalculateFactorials(10010000);

    ll nn,k;
    cin>>nn>>k;

    ll n = nn + k - 1;
    ll numerator = factorial[n];
    ll denominator = binpow((factorial[nn-1] * factorial[k])%md, md-2, md);
    cout<< (numerator * denominator)%md <<endl;


}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}