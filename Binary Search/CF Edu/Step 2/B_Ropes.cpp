//Invariant = 11111000000
//while(ok(r)) r*=2;(why giving wrong answer for this don't know)


#include <bits/stdc++.h>
using namespace std;

int n, k;
int ar[100000];


bool ok(double m){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=(ar[i]/m);
    }
    //cout<<ans<<endl;
    return ans >= k;
}

void solve(){

    cin>> n >> k;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    double l = 0, r = 1e8, m;

    for(int i=0;i<100;i++){
        m = (l+r)/2;
        if( ok(m) ) l = m;
        else r = m;
    }
    cout<< fixed << setprecision(10) ;
    cout<< l <<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}