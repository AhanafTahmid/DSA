#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    ll b,ss,c;
    cin>> b >> ss >> c;
    ll pb,ps,pc;
    cin>> pb >> ps >> pc;
    ll tp;
    cin>>tp;
    ll cb = 0, cs = 0 , cc = 0;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='B') cb++;
        else if(s[i]=='S') cs++;
        else if(s[i]=='C') cc++;
    }

    ll to_make_price = (cb * pb + cs * ps + cc * pc);
    ll total_price_ase = ( ((cb>=1)? b * pb : 0) + ((cs>=1)? ss * ps : 0) + ((cc>=1)? c * pc : 0)) + tp; 

    // cout<< to_make_price <<endl;
    // cout<< total_price_ase <<endl;
    
    cout<< total_price_ase / to_make_price <<endl;
}


int main(){

    ll t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}