//https://atcoder.jp/contests/abc208/tasks/abc208_b?lang=en
//Good Dynamic Programming Question

#include <bits/stdc++.h>
using namespace std;
#define ll long long


//normal approach
// void solve(){
//     ll n,fac=1;
//     cin>>n;
//     vector<ll> fc;
//     for(int i=1;i<=13;i++){
//         fac = 1;
//         for(int j=1;j<=i;j++)fac*=j;
//         fc.push_back(fac);
//     }
//     ll ans = 1,rem = 0, idx = 0, c = 0;;
//     int ct = 0;
//     for(int i=12;i>=0;i--){
//         if(fc[i]<=n){
//             while(1){
//                 for(int idx = i;idx>=0;idx--){
//                     ans = (n/fc[idx]);
//                     rem =  n - (ans*fc[idx]);//119-96=23
//                     n = rem;
//                     c+=ans;
//                 }
//                 if(rem<=0){
//                     cout<<c<<endl;
//                     return;
//                 }
//             }
//         }
//     }
// }


//DP Approach
int dp[10011000];


void solve(){
    ll n,fac=1;
    cin>>n;
    vector<ll> fc;
    for(int i=1;i<=13;i++){
        fac = 1;
        for(int j=1;j<=i;j++)fac*=j;
            fc.push_back(fac);
    }
    for(int i=1;i<=n;i++){
        dp[i] = 1e9;
    }
    dp[0] = 0;//start from the base case

    for(int i=1;i<=n;i++){
        for(int j=0;j<13;j++){//0 base indexing in vector array
            if(i-fc[j]>=0) dp[i] = min(dp[i],dp[i-fc[j]]+1);
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<dp[i]<<endl;
    // }
    cout<<dp[n]<<endl;



}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}