//for 1111 , there is 4 ones so 3 exact ones is possible
//1. remove 2^x - 1 to get the only 0's 
//use 1LL to avoid overflow in 2^x

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int a,b;cin>>a>>b;
    int ans = 0, v;
    for(int i=2;i<64;i++){
        for(int j=0;j<i-1;j++){
            v = (1LL<<i) - 1 - (1LL<<j);
            ans += (v>=a && v<=b);
        }
    }
    cout<< ans <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}