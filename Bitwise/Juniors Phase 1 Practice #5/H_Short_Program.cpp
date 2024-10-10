//Intuition: it does not matter what operation we put but the answer should be same of petya's all operation

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n;cin>>n;
    int v;
    for(int i=1;i<=n;i++){
        char ch;cin>>ch;
        int x;cin>>x;
        if(i==1) {v = x;continue;}

        if(ch=='^')v ^= x;
        if(ch=='&')v &= x;
        if(ch=='|')v |= x;
    }

    if(v==0){
        cout<<0<<endl;
        return;
    }
    cout<< 2 <<endl;
    cout<< "^ " << v <<endl;
    cout<< "| " << 0 <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}