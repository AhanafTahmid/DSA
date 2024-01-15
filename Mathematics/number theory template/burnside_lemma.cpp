#define ll long long
int md = 1e9 + 7;

ll power(ll a, ll b, ll m) {
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
    return power(i, md-2, md);
}

void burnside_lemma(ll N, ll M)
{
 
    ll ans = 0;
 
    for (ll i = 0; i < N; i++) {
 
        // Find M^(GCD(k,n))
        ans = ( ans + power(M,__gcd(i,N),md))%md;
        //cout<< N << " " << M << " " << ans <<endl;
    }
    
    //for very long N size, we must do inverse modulo
    ll nn = inverse(N);//cause divided by, so -> ans = ans * N^-1
    ans = (ans%md * nn%md)%md;// modulo multiplication rule
    cout << ans << endl;
}