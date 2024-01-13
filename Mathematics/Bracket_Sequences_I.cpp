#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int md = 1e9 + 7;
ll factorial[10001000];//2e7



ll inverse(ll i){
    if(i==1) return 1;
    return (md - ((md/i)*inverse(md%i))%md+md)%md;
}


void precalculateFactorials(int n) {
    factorial[0] = 1;
    for (int j = 1; j <= n; j++) {
        factorial[j] = (factorial[j - 1] * j) % md;
    }
}


ll catalan[1001000];
void solve(){
    precalculateFactorials(1000100);

    ll n;
    cin>>n;
    
    catalan[0] = catalan[1] = 1;
 
    
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }

    for(int i=1;i<=n;i++){
        cout<<catalan[i]<<endl;
    }
 
   


    
}




int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}