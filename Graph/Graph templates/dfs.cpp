#include <bits/stdc++.h>

using namespace std;

int visited(100);
vector <int> adj[100];

void dfs(int s) {
        if (visited[s]) return;
        visited[s] = true;
        //cout<<s<<endl;
        cout<<endl<<endl;
        //visiting neighbours, for 1 adj[s]={4,3,2,1}
        for (auto u: adj[s]) {
            //if(!visited[u])cout<<s<<"rrr "<<u<<"ttt "<<endl;
            cout<<s<<"rrr "<<u<<"ttt "<<endl;
            cout<<adj[s].size()<<endl;
            dfs(u);
        }
        
}


//input 
// 6 5 -> 6 nodes, 5 edges, which is bascially a tree
// 0 1
// 1 4
// 1 3
// 0 2
// 2 5

int main()
{
    int n, s, edges, a, b;
    scanf("%d%d", &n, &edges);
    for(int i=0; i<edges; i++) {
        scanf("%d%d", &a, &b);//not directed graph
        adj[a].push_back(b);//creating adjacency list
        adj[b].push_back(a);
    }
    scanf("%d", &s);
    dfs(s);
    return 0;
}


//2d grid dfs
class Solution {
public:
    void dfs(int i, int j, int n, int m,vector<vector<char>>& grid,vector<vector<bool>>&visited){
        //outbound hole backtrack
        if( i<0 || i==n || j==m || j<0 ) return;
        //already visited or '0' grid then don't visit
        if(visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = 1;
        dfs(i+1,j, n, m, grid, visited);
        dfs(i-1,j, n, m, grid, visited);
        dfs(i,j-1, n, m, grid, visited);
        dfs(i,j+1, n, m, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, n, m, grid, visited);
                }
            }
        }
        return ans;
    }
};


//Clean Template

int visited(100);
vector <int> adj[100];
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = 1;
    for (int u: adj[s]) dfs(u);
}

---------------------------