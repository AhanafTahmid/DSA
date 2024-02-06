#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[1000100];
bool ok(){

}

void solve(){
    
    ll l = 0, r = , m;
    
    while(l+1<r){
        m = (l+r)>>1;
        if( ok(m) ) l = m;
        else r = m;
    }
    cout<< l <<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}