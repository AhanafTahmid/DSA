#include <bits/stdc++.h>
using namespace std;

int n,x,y;

bool ok(int mid){
    if(mid < min(x,y)) return false;
    mid -= min(x,y); 
    return (mid/x + mid/y + 1) >=n; 
}

void solve(){
    
    cin>>n>>x>>y;

    int l = 0, r = n*min(x,y), m;
    //while( !ok(r)) r*=2;

    n-= min(x,y);

    while(l+1<r){
        m = (l+r)>>1;

        if( ok(m) ) r = m;
        else l = m;
    }
    cout<< r <<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}