// doing (x^u) and x+u is basically the same
//Steps:
//1. Think all possible cases in bruteforce
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int u,v;cin>>u>>v;
    if(u>v || u%2!=v%2)cout<<-1<<endl;
    else if(u==v && u==0) cout<< 0 <<endl;
    else if(u==v)cout<<"1\n"<<u<<endl;
    else{
        int x = (v-u)/2;
        //𝑎+𝑏=𝑎⊕𝑏+2∗(𝑎&𝑏)
        if((x^u)== x + u){//this basically means there is no intersecting/overlapping 1's values , like no 1's in both x and u
            cout<< "2\n" << x << ' ' << (x^u) <<endl;
        }
        else{
            cout<< "3\n" << u << ' ' << x << ' ' << x <<endl;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}