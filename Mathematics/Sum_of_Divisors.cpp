#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int md = 1e9 + 7;
void solve(){
    ll n;
    cin>>n;
    ll sum = 0;
    for(ll j=1;j<=n;j++){
        //divisors
        for(ll i = 1; i*i <= j; i++){
            if(j % i == 0){
                sum = (sum + j)%md;
                if(j != j/i) sum= (sum + (j/i))%md;
            }
        }
    }
    cout<<sum<<endl;
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}