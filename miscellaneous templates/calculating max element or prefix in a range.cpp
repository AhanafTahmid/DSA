//Submission from : https://codeforces.com/contest/276/submission/75819414
//Problem1: https://codeforces.com/contest/276/problem/C
//Problem2: https://toph.co/arena?practice=663589b3cb54116148a3bcbd#!/p/6633ce1dcb54116148a39358 

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n, q;cin>>n>>q;
    vector<int>a(n),prefix(n+1);
    for(int &i: a)cin>>i;
    while(q--){
        int l, r;cin>>l>>r;
        //Also valid, if you wnat first index to be zero
        // prefix[l]++;
        // prefix[r+1]--; 
        prefix[l-1]++;
        prefix[r]--;
    }

    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1] + prefix[i];
    }
    sort(a.rbegin(),a.rend());
    sort(prefix.rbegin(),prefix.rend());

    int ans = 0;

    // for(int i=0;i<=n;i++) cout<< prefix[i] << ' ';
    // cout<<endl;

    for(int i=0;i<n;i++){
        ans += (prefix[i] * a[i]);
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