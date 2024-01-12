//0 1 knapsack
#include <bits/stdc++.h>
using namespace std;
int dp[1005][100005];//initially everything is set to 0
void solve(){
    int n,x;//number of books, price of the books = x
    cin>>n>>x;   
    int b[n+1],pg[n+1];// b = prices of books, pg = pages of books
    //prices of books
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    //number of pages of the books
    for(int i=1;i<=n;i++){
        cin>>pg[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            // j = price, b[i] == books , pg[i] = pages of books

            //take
            if(j-b[i]>=0)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-b[i]] + pg[i]);
            //not take
            else dp[i][j] = dp[i-1][j];
        }
    }


    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=x;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    cout<<dp[n][x]<<endl;










}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}