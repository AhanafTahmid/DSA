#include <bits/stdc++.h>
using namespace std;
int dp[1001000];
void solve(){
    int n,k;
    cin>>n>>k;
    int coin[n+1];
    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }


    for (int i = 1; i <= k; i++) { dp[i] = 1e7; }//putting INT_MAX will cause overflow for int dp[]

    dp[0] = 0;
    //iterative dp
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){//checking 1, 5, 7 for 5,7 it will not enter in first iteration
            if(i-coin[j]>=0) dp[i]= min(dp[i],dp[i-coin[j]]+1);
            //cout<<i<<" "<<dp[i]<<endl;
        }
    }

    if(dp[k]==1e7)cout<<-1<<endl;
    else cout<<dp[k]<<endl;




}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}