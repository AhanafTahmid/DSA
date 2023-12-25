#include <bits/stdc++.h>
using namespace std;

int vis[8][8];

bool isValid(int x,int y){
    return (x<0)
}
vector<pair<int,int>> places = {
    {1,1},{1,1},
    {1,1},{1,1},
    {1,1},{1,1},
    {1,1},{1,1},
}

int bfs(string s, string d){
    int sx = s[0] - 'a';//0
    int sy = s[0] - '1';//0 initially
    int dx = s[0] - 'a';
    int dy = s[0] - '1';
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int v1 = v.first;
        int v2 = v.second;
        q.push({v1,v2});

    }


}

void solve(){
    int n;
    cin>>n;
    string s1, s2;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        bfs(s1,s2);
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}