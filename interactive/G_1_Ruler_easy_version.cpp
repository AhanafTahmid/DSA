#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int l = 1, r = 1001, m;
    for(int i=0;i<10;i++){
        m = (l+r)>>1;
        cout<< "? " << m << ' ' << m << endl;
        int x;cin>>x;
        if( m*m == x) l = m + 1;
        else r = m;

        if(l==r){
            cout<< "! " << l <<endl;
            return;
        }
    }
    cout<< -1 <<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}