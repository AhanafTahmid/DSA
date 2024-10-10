//steps
// 1. Read the editorial : https://codeforces.com/blog/entry/54590
// //put values after 10^5
  //1. 1000 ^ 10000 ^ 11000 = 0, when x == xor value
  //2. 0 ^ 10000 ^ (10000^x^xorvalue), when x != xor value, boro value tar bit ta on kora xor kore
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n,x;cin>>n>>x;
    if(n==1)cout<< "YES\n" << x <<endl;
    else if(n==2){
        if(x==0)cout<<"NO"<<endl;
        else cout<< "YES\n0 " << x <<endl;
    }
    else{
        cout<<"YES"<<endl;
        int v = 0;
        for(int i=1;i<=n-3;i++){
            cout<< i <<' ';
            v = v^i;
        }
        int p1 = 1<<18, p2 = 1<<19;
        if(v==x)cout<<p1<<' '<<p2<<' '<<p1+p2<<endl;
        else cout<< 0 << ' ' << p1 << ' '<<((p1^x)^v)<<endl;
    }   
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}