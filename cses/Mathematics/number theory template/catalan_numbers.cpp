
ll catalan[1001000];
void solve(){

    ll n;
    cin>>n;
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }

    for(int i=1;i<=n;i++){
        cout<<catalan[i]<<endl;
    }
 
    
}











//#################################################





#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1e6;


int catalan[MAX];
void init() {
    int n = 10;
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }


    for (int i=1; i<=n; i++) {
        cout<<catalan[i]<<endl;
    }


}

void solve(){
    init();
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}




//################################################//Recursive



#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int md = 1e9 + 7;
ll factorial[10001000];//2e7



ll inverse(ll i){
    if(i==1) return 1;
    return (md - ((md/i)*inverse(md%i))%md+md)%md;
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


void precalculateFactorials(int n) {
    factorial[0] = 1;
    for (int j = 1; j <= n; j++) {
        factorial[j] = (factorial[j - 1] * j) % md;
    }
}



void solve(){
    precalculateFactorials(1000100);

    ll n;
    cin>>n;
    
    ll numerator = factorial[2*n];

    ll denominator1 = (factorial[n] * factorial[(n+1)])%md;

    ll denominator = ((inverse(factorial[n]) * inverse(factorial[n]))%md * inverse(n+1))%md;
    cout<<numerator<<endl;
    cout<<denominator<<endl;
    cout<<(numerator*denominator)%md<<endl;
   


    
}




int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}