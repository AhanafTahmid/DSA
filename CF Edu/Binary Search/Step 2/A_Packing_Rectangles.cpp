//000000111111
//invariant(the condition throughout the program): r is always true, l is always false

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll w, h, n;

bool ok(ll m){
    return ((m/h) * (m/w)) >= n;
}

void solve(){
    cin>> w >> h >> n; 

    ll l = 0, r=1, m;
    while(!ok(r)) r*=2;

    while(l+1<r){
        m = (l+r)/2;
        //cout<<m<<endl;
        if( ok(m) ) r = m;
        else l = m;
    }
    cout<< r <<endl;



}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}