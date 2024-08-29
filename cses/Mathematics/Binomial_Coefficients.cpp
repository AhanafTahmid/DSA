#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int md = 1e9 + 7;
ll factorial[10001000];//2e7

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


void precalculateFactorials(int n) {
    factorial[0] = 1;
    for (int j = 1; j <= n; j++) {
        factorial[j] = (factorial[j - 1] * j) % md;
    }
}

// nCr = n! / (r!(n-r)!)
ll binomial_coefficient(int n, int r){
    //Numerator = factorial[a]
    ll numerator = factorial[n];
    //Determinator
    //Denominator, first find the factorial(tt = ((n-r)!*r!) ) then binexpo(tt,M-2,M); = a^(M-2)%M
    ll denominator = (factorial[r] * factorial[n-r]) %md;//t
    ll denominator2 = binpow(denominator, md-2, md);//binexpo(tt,M-2,M); = a^(M-2)%M
    ll ans = (numerator * denominator2)%md;

    return ans;
}


void solve(){
    precalculateFactorials(1000100);//1e6 porjntoi kaj korbe inside local function, main function e 1e8 o cholbe

    ll n;
    cin>>n;
    ll a,b;

    for(ll i=0;i<n;i++){
        cin>>a>>b;
        cout<<binomial_coefficient(a,b)<<endl;
    }
}


int main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}