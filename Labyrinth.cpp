#include <bits/stdc++.h>
using namespace std;


char c[1010][1010];
int vis[1010][1010];
vector<int> ans;
int ct = 0;
int n,e;
void dfs(int i,int j){
    if(i<0 || j<0 || j>=e || i>=n || c[i][j]=='#' ||  vis[i][j]) return;
    if(c[i][j]=='B'){
        cout<<ct<<endl;
        return;
    }
    vis[i][j] = true;
    //cout<<c[i][j]<<" "<<i<<j<<endl;
    ct++;
    dfs(i+1,j);//up
    //cout<<"U";
    dfs(i-1,j);//down
    dfs(i,j+1);//right
    dfs(i,j-1);//left
    //cout<<ct<<endl;
}

void solve(){
    cin>>n>>e;
    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            cin>>c[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            if(c[i][j]=='A'){
                dfs(i,j);
            }
        }
        cout<<endl;
    }

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}