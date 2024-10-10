//Type: DP on Subsequence

axyb
abyxb
ans: axb / ayb
0 0 0 0 0 0 
0 1 1 1 1 1 
0 1 1 1 2 2 
0 1 1 2 2 2 
0 1 2 2 2 3 

---------------------------------------------------------------
//Recursive - length of largest sequence
int f(int i, int j, string &s1, string &s2,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j] = 1 + f(i-1, j-1, s1,s2, dp);
    }
    int one = f(i-1, j, s1,s2, dp);
    int two = f(i, j-1, s1,s2, dp);
    return dp[i][j] = max(one, two); 
}

void solve(){
    string s1, s2;cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    cout<< f(n-1, m-1, s1, s2, dp) <<endl;
}
---------------------------------------------------------------
//Iterative
void solve(){
    string s1, s2;cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                int one = dp[i-1][j];
                int two = dp[i][j-1];
                dp[i][j] = max(one, two); 
            }
        }
    }

    string ans="";
    int i = n, j = m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<< ans <<endl;
}