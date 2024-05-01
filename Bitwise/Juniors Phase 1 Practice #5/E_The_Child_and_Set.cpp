/*

Steps:
1. Use (__builtin_ctz(i)) to count trailing zeros and solve the problem
2. run lim to 1 loop

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int sum,limit;cin>>sum>>limit;
    vector<int>a;
    int v = 0;
    bool ok = false;
    for(int i=limit;i>=1;i--){
        v = 1 << (__builtin_ctz(i));
        if(v<=sum){
            sum-=v;
            a.push_back(i);
        }
        if(sum==0){
            ok = true;
            break;
        }
    }
    if(!ok)cout<< -1 <<endl;
    else{
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++)cout<< a[i] << " \n"[i==a.size()-1];
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}