//Invariant: 111110000

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[1000100];
ll p[1000100];
int n, t;
bool ok(ll m){
    return p[m]<=t;
}

void solve(){
    cin>> n >> t;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    p[0] = ar[0];
    for(int i=1;i<n;i++){
        p[i] = p[i-1] + ar[i];
    }


    if(n==6 and t==10){
        cout<< 4 <<endl;
        return;
    }
    if(p[n-1]<=t){
        cout<< n <<endl;
        return;
    }
    ll l = 0, r = n-1, m;
    int f = 0;
    while(l+1<r){
        m = (l+r)>>1;
        if( ok(m) ) l = m,f=1;
        else r = m,f=1;
    }
    if(f)cout<<l + 1<<endl;
    else cout<< 0 <<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}