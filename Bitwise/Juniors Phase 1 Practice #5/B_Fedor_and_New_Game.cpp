//when done xor we can found the total different bits
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(m);
    for(int &i: a)cin>>i;
    int fd;cin>>fd;
    int ans = 0;
    for(int i=0;i<m;i++){
        ans += ( __builtin_popcount(fd^a[i]) <=k);
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