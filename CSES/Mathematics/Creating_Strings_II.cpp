// (n! * inverse(common!))%mod

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9+7;

ll factorial[1002000];
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
    precalculateFactorials(1001000);

    string s;
    cin>>s;
    int n = s.size();
    int fr[26]={};

    
    for(int i=0;i<n;i++){
        fr[s[i]-'a']++;
    }

    vector<int> p;
    for(int i=0;i<=25;i++){
        //cout<<fr[i]<<" "<<char(i+97)<<endl;
        if(fr[i]>=2) p.push_back(fr[i]);
    }

    // (n! * inverse(common!))%mod
    ll numerator = factorial[s.size()];
    ll denominator = 1;
    for(auto x: p){
        denominator = (denominator * factorial[x])%md;
    }
    denominator = binpow(denominator,md-2,md);
    cout<< (numerator * denominator)%md <<endl;
    // cout<<numerator<<endl;
    // cout<<denominator<<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}