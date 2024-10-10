#include <bits/stdc++.h>
using namespace std;

int dp[1001000];
int md = 1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;
    int ar[n+1];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j-ar[i]>=0) dp[j]= (dp[j]+dp[j-ar[i]])%md;
        }
    }

    cout<<dp[k]<<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}