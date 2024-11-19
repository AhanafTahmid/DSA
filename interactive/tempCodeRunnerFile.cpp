#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;cin>>n>>m;
    cout<< "? " << 1 << ' ' << 1 <<endl;

    int x, a,b;cin>>x;//1

    int p1 = min(n, x + 1), q1 = x + 2 - p1;
    int q2 = min(m, x + 1), p2 = x + 2 - q2;

    cout<< "? " << p1 << ' ' << q1 <<endl;
    cin>>x;//2
    a = x;
    if( x == 0 ){
        cout<< "! " << p1 << ' ' << q1 <<endl;
        return;
    }

    cout<< "? " << p2 << ' ' << q2 <<endl;
    cin>>x;//3
    if( x == 0 ){
        cout<< "! " << p2 << ' ' << q2 <<endl;
        return;
    }

    //diagonal and even position
    b = x;
    cout<< "? " << p2 + b/2 << ' ' << q2 - b/2 <<endl;
    cin>>x;//4
    if(x==0){
        cout<< "! " << p2 + b/2 << ' ' << q2 - b/2 <<endl;
        return;
    }

    cout<< "! " << p1 - a/2 << ' ' << q1 + a/2 <<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}