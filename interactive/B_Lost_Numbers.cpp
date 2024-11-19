#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<int>a{4 , 8 , 15 , 16 , 23 , 42};
    vector<int>v(4);
    for(int i=0;i<4;i++){
        cout<< "? " << i + 1 << ' ' << i + 2 << endl;
        int x;cin>>x;
        v[i] = x;
    }

    do{
        vector<int>t(4);
        for(int i=0;i<4;i++){
            t[i] = a[i] * a[i+1];
        }
        if(t==v){
            cout<< "! ";
            for(int x: a) cout<< x << " \n"[x==a.back()];
        }
    }while(next_permutation(a.begin(),a.end()));
}

int32_t main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}