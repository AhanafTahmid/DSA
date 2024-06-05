#include <bits/stdc++.h>
using namespace std;
int dp[1100000];
const int md = 1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;
    int ar[n+1];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }

    dp[0] = 1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i-ar[j]>=0) dp[i] = (dp[i] + dp[i-ar[j]]) %md;//i-ar[j] for checking index out of bound
            //if(i-ar[j]>=0) dp[i]+= (dp[i-ar[j]])%md;//(dp[i-ar[j]])%md will give wrong answer, apply the modulo operation after each addition to prevent overflow and maintain the result within the range of the modulo. 
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