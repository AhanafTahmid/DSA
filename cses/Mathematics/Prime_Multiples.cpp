#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> pm; //prime multiples
    for(ll i=0;i<k;i++){
        ll x; cin>>x;
        pm.push_back(x);
    }

    //inclusion_exclusion(n, pm);

    ll all_subset= (1<<pm.size());
    ll ct = 0;
    double prod = 1;
    ll sum = 0;
    for(ll i=1;i<all_subset;i++){
        ct = 0, prod = 1;//count, product
        for(ll j=0;j<pm.size();j++){
            if(i & (1<<j)){
                ct++;
                prod=(prod * pm[j]);
                //cout<<ar[j]<<" ";
            }
        }
        if(ct%2==1) sum+=(n/(ll)prod);
        else sum-=(n/(ll)prod);
    }
    cout<<sum<<endl;


    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}