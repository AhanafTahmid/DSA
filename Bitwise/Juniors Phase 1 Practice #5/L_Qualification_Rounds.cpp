#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n,k;cin>>n>>k;
    int v[k+1]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int x;cin>>x;
            v[j%4]+=(x==1);
        }
    }
    int atmost = (n+1)/2;
    for(int i=0;i<k;i++){
        if(v[i]>atmost){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}