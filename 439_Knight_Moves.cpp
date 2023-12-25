//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> chals = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};

bool isVal(int x, int y){
    return x>=0 && x<8 && y>=0 && y<8;//true ta return korbo
}
int bfs(string s1, string s2){
    int sx = s1[0] - 'a';//0 initially
    int sy = s1[1] - '1';//0 initially
    int dx = s2[0] - 'a';
    int dy = s2[1] - '1';

    int vis[10][10]={};
    int lev[10][10]={};
    
    queue<pair<int,int>>q;
    q.push({sx,sy});
    vis[sx][sy] = 1;

    while(!q.empty()){
        pair<int,int> u = q.front();
        int x1 = u.first;
        int y1 = u.second;
        q.pop();

        for(auto xx: chals){
            int x2 = x1 + xx.first;
            int y2 = y1 + xx.second;
            if(isVal(x2,y2) && vis[x2][y2]!=1){
                q.push({x2,y2});
                vis[x2][y2] = 1;
                lev[x2][y2] = lev[x1][y1] + 1;
            }
        }
    }
    return lev[dx][dy];

}

void solve(){
    string s1,s2;
    while(cin>>s1>>s2){
        printf("To get from %s to %s takes %d knight moves.\n", s1.c_str(), s2.c_str(), bfs(s1,s2));
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}