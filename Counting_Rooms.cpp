#include <bits/stdc++.h>
using namespace std;

int visited[2000][2000];
char ar[2000][2000]={};
int n, m;

void dfs(int k, int l){
    if(k<0 || l<0 || k>=n || l>=m || ar[k][l]=='#') return;
    if(visited[k][l]) return;
    visited[k][l]= 1;
    dfs(k+1,l);
    dfs(k-1,l);
    dfs(k,l+1);
    dfs(k,l-1);
}
void solve(){
    cin>>n>>m;
    
    char x, y;
    int ct = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<ar[i][j];
            if(ar[i][j]=='.' && visited[i][j]==0){
                dfs(i,j);
                ct++;
            }
                
        }
    }
    cout<<ct<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}