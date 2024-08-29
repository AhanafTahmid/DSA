//https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;



bool isValid(int x,int y){
    return (x>=0 && x<8 && y>=0 && y<8);
}
vector<pair<int,int>> places = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};

int bfs(string s, string d){
    int sx = s[0] - 'a';//0
    int sy = s[1] - '1';//0 initially, 0 to 7
    int dx = d[0] - 'a';//
    int dy = d[1] - '1';
    int vis[8][8]={};
    int lev[8][8]={};
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    while(!q.empty()){
        pair<int,int> v = q.front();
        q.pop();
        int v1 = v.first;
        int v2 = v.second;
        for(auto xx: places){
            int new_x = v1 + xx.first;
            int new_y = v2 + xx.second;
            if(isValid(new_x,new_y) && vis[new_x][new_y] != 1){
                q.push({new_x,new_y});
                vis[new_x][new_y] = 1;
                lev[new_x][new_y] = lev[v1][v2] + 1;//not sure about this though
                //cout<<lev[v1][v2]<<" ";
            }
        }
    }
    return lev[dx][dy];

}

void solve(){
    int n;
    cin>>n;
    string s1, s2;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        //cout<<endl<<endl<<endl;
        cout<<bfs(s1,s2)<<endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}