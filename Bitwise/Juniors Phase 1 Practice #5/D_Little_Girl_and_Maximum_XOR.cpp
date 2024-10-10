//Be careful with : 1LL<<pw and 1<<pw
//steps
//1.find where l and r differ using xor, get the position using __builtin_clzll
//2. make l = 01111 r = 10000, it will be maximum
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int l, r;cin>>l>>r;
    int pw =  63 - __builtin_clzll((l^r));
    int ans = (1LL<<pw) ^ ((1LL<<pw)-1);
    cout<< ((l==r)?0:ans) <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}