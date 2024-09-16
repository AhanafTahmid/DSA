#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        //total ghor jekhane knight boshbe
        ll total = (i*i*(i*i-1))/2;  //   [ i^2 * (i^2 -1) /2 ]
        //total attack
        ll attack = 2*2*(i-1)*(i-2);//(vertical+horizontal sajano box ta) * 2x3 te 2 ta knight attack * total ghor jekhane 2x3 grid boshbe vertically + horizontally
        //total ghor - total attack = total do not attack
        cout<<total - attack<<endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}