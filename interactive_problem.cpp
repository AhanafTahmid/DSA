//https://codeforces.com/gym/101021/problem/1
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int l = 1, r = 1000001, m;
    while(l+1<r){
        m = (l+r)>>1;
        printf("%d\n",m);
        string s;cin>>s;
        if(s=="<")r = m;
        else l = m;
    }
    cout<< "! " << l <<endl;
    cout<<flush;
}

int32_t main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}