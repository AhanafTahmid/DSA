#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;cin>>n;
    int l = 0, r = n,m;
    vector<int>a(n);
    for(int &i: a)cin>>i;
    for(int i=0;i<30;i++){
        m = (l+r)>>1;
        int ln = m - l+1, s = 0;
        cout<< "? " << ln << ' ';
        for(int i=l;i<=m;i++){
            cout<< i+1 << ' ';
            s+= a[i];
        }
        cout<<endl;

        int val;cin>>val;
        if(s==val) l = m;
        else r = m;
    }

    cout<< "! " << r+1 << endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}