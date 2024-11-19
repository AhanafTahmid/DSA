#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int l = 1, r = 1000001,m;
    for(int i=0;i<25;i++){
        m = (l+r)/2;
        string s;cin>>s;
        if( s == ">=" ) l = m;
        else r = m;
        
    }
    cout<< "! " << l <<endl;
}

int32_t main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}