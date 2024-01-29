//Invariant: 11110000

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[1000100];
ll n, cow;

bool ok(ll mid){
    int ct = 1;
    int lastpos = ar[0];
    for(int i=0;i<n;i++){
        if(ar[i]-lastpos>=mid) ct++,lastpos = ar[i];
    }
    return ct >=cow;
}

void solve(){
    cin>> n >> cow;
    for(int i=0;i<n;i++)cin>>ar[i];
    sort(ar, ar+n);
    
    ll l = 0, r = ar[n-1], m;

    while(l+1<r){ 
        m = (l+r)>>1;
        if( ok(m) ) l = m;
        else r = m;
    }
    cout<< l <<endl;

}


int main(){

    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}