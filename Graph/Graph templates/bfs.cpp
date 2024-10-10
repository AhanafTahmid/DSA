#include <bits/stdc++.h>
using namespace std;

/**

Input:

6 5
1 2
1 3
2 4
2 5
3 6
1

Output:
1 2 3 4 5 6

**/

int visited[100];
vector <int> adj[100];
void bfs(int n, int s) {
    // for(int i=0; i<n; i++)
    //     visited[i] = 0;
    queue<int>q;
    q.push(s);
    visited[s] = 1;//parent node visited kore dicchi
    while(!q.empty()) {//queue-r vitor child node visit krtesi
        int u = q.front();
        q.pop();
        //printf("%d ", u);
        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            //cout<<u<< " " <<v<<endl;
            if(visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    printf("\n");
}


int main()
{
    int n, s, edges, a, b;
    scanf("%d%d", &n, &edges);
    // n = no. of vertices and edges =no. of edges
    for(int i=0; i<edges; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &s); //s = source node
    bfs(n, 2);
    return 0;
}


-----------------------------------------------------------------
//2d grid bfs
class Solution {
public:
    vector<int>dx{ 0,  0, 1,-1};
    vector<int>dy{-1, +1, 0, 0};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()){
                        int xx = q.front().first;
                        int yy = q.front().second;
                        q.pop();
                        //go in 4 direction
                        for(int k=0;k<4;k++){
                            int x = xx + dx[k];
                            int y = yy + dy[k];
                            if( x>=0 && x<n && y<m && y>=0  && grid[x][y] != '0' && !visited[x][y]){
                                visited[x][y] = 1;
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

-----------------------------------------------------------------
//Practice
#include <bits/stdc++.h>
using namespace std; 

vector<int>g[100];
int visited[100];

void bfs(int s){
    queue<int> q;
    q.push(s);
	visited[s] = 1;

    while(q.empty()==0){
        int u = q.front();//etar sathe linked node gulate jawa
        q.pop();
        //cout<<u;
        for(int i=0;i<g[u].size();i++){
            //cout<<g[u][i];// g[1 0] -> 2, g[1 1] -> 3
            
            if(visited[g[u][i]]==0){
                q.push(g[u][i]);
                visited[g[u][i]] = 1;
                //cout<<q.front();

            }
            // if(){
            //     //q.push(x);
            //    // cout<<x;
                
            // }
            
        }
        //cout<<q.front();
        
    }

}
int main() 
{ 
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		int v1,v2;
		cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
	}

    int s; //source
    cin>>s;
    cin>>s;
    bfs(s);
	return 0; 
} 



//Clean Template
vector<int>g[100];
int visited(100);
void bfs(int s){
    queue<int> q;
    q.push(s);
	visited[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x: g[u]){            
            if(visited[x]==0){
                visited[gx] = 1;
                q.push(x);
            }
        }        
    }
}