#include <bits/stdc++.h>
using namespace std;
vector<int>dp(1001000,1e9);
void solve(){
    int n;
    cin>>n;
    dp[0] = 0;//for 0 the answer is 0
    //for 1 to 9 numbers the answer is 1
    for(int i=1;i<=9;i++)dp[i] = 1;

    //for 10<=n solving the problem
    for(int i=10;i<=n;i++){
        string s = to_string(i);
        sort(s.begin(),s.end(),greater<int>());
        int mx = s[0] - '0';
        dp[i] = min(dp[i],dp[i-mx]+1);
        //cout<<i<<" "<<dp[i]<<" "<<mx<<endl;
    }

    cout<<dp[n]<<endl;
   
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}