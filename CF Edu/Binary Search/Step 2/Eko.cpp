//https://www.spoj.com/problems/EKO/

//Invariant: 111111000000, TTTTFFFF

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ar[3000000];
ll n,k;

bool ok(int mid){
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(ar[i]>=mid)ans += (ar[i]-mid);
        //cout<<ans<<" ";
    }
    //cout<<ans<<endl;
    if(ans>=k) return true;
    else return false;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    ll l = 0, r = 1, m;// 0 theke kata shuru

    while(ok(r)) r*=2;

    while(l+1<r){
        m = (l+r)>>1;
        if( ok(m) ) l = m;
        else r = m;

    }

    cout<< l << endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}