#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
const int md = 1e9+7;
void solve(){
    int n;
    cin>>n;

    char ch[1005][1005];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ch[i][j];
        }
    }

    dp[1][1] = ch[1][1]!='*';//if the first element is not * then 1, else 0

    //solving for the rest of the path, sum up from top and left only, ei dui jaiga thekei ashte parbe only
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ch[i][j]=='.' && i-1>=0){
                dp[i][j]+=(dp[i-1][j]);
                dp[i][j]%=md;
            }
            if(ch[i][j]=='.' && j-1>=0){
                dp[i][j]+=(dp[i][j-1]);
                dp[i][j]%=md;
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][n]<<endl;

    

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}