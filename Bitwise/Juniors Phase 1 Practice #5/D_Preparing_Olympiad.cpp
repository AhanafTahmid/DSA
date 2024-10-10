//steps
//1. run all possible subset because of low constraints
//2. compare with the minimum value with the maximum if <=x, then sum is ok, also check sum>=l && sum<=r

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n,l,r,x;cin>>n>>l>>r>>x;
    vector<int> a(n);
    for(int &i: a)cin>>i;
    int ans = 0;
    for(int i=1;i<(1<<n);i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                v.push_back(a[j]);
            }
        }
        int sum = accumulate(v.begin(),v.end(),0LL);
        auto [mn, mx] = minmax_element(v.begin(),v.end());
        if( (*mx-*mn)>=x && (sum>=l && sum<=r) ) ans++;
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