#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(m);
    int sum = 0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<n)cout<< -1 <<endl;
    else{
        sort(a.begin(),a.end());
        int ans = 0;
        for(int i=0;i<m;i++){
            while(a[i]>n){
                a[i]/=2;
                ans++;
            }
        }
        cout<< ans <<endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}