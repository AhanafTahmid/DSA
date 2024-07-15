//Graph

- See notion notes 
- Think what is the starting point(in bfs)
- Grid type problems, think graph
- Always use bool type for visited array(2 bytes)
- 

Confusions:
1. G-17. Bipartite Graph | BFS -> little confused on queue stack also
Wrong Answer(in my way )
60 / 81 testcases passed
Input graph =
[[1],[0,3],[3],[1,2]]

2. G-18. Bipartite Graph | DFS - little confused on how dfs in working 

TODO: https://leetcode.com/problems/course-schedule-ii/description/
3. G-19. Detect cycle in a directed graph using DFS
4. G-20. Find Eventual Safe States - DFS (draw the tree )

Good practice: donot temper data, make a copy and solve[for this type of question, just remember]


---------------------------------------------------------------------------------------------------------
Striver Graph Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
Resource: https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions/
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Introduction to Graph--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-1. Introduction to Graph | Types | Different Conventions Used--------########
//Tutorial: https://takeuforward.org/graph/introduction-to-graph/
//Problem: https://www.geeksforgeeks.org/problems/graph-and-vertices/1

Code:(number of undirected graph in node)
In a graph G with n vertices, maixmum number of edges possible = ( n*(n-1) ) / 2
Total number of graphs with n vertices = 2 ^ ( n*(n-1) ) / 2
example:
1LL<<((n*(n-1) )/2);

------------------------Theory----------------------------------
Graph -> having nodes and edges
Undirected Graph-> NO Direction 
Directed Graph-> With Direction (all edges are direceted)
- Nodes/Vertex is the same
- There is no specific order of numbering nodes 
- Edge -> Directed or Undirected(bi direction)
- Cycles in a Graph: Start and end at the same node(enclosed structure)
- every edge has 2 nodes in undirected graph

//Directed graph 
Acyclic Graph: Having no cycles 
DAG: 
Directed cyclic graph(not closed at the same node, no cycle having direction
, have directions but no cycle)
Path -> direction of having the edge
Degree(for undirected graph): Number of edges that are attached to a node
Degree property: total degree = 2 x edges [because every edge attached with 2 direction]
- A node cannot appear twice in a path

//Undirected graph 
- indegree(node)  [number of incoming edges]
- outdegree(node) [number of outgoing edges]


edge weight: edge having value
if weights are not assigned, we will always assume unit weight -> 1



//#######################################################################
//#######-------G-2. Graph Representation in C++ | Two Ways to Represent--------########
//Tutorial: https://takeuforward.org/graph/graph-representation-in-c/
//Problem: https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges){
    vector<vector<int>>adj(V);
    int n = edges.size();
    for(int i=0;i<n;i++){
        int u = edges[i].first, v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

------------------------Theory----------------------------------
Input: n,m -> will always give node and edge, + edge lines
n is constant, m can be anything

Store:
1. Adjacency Matrix - (O(N*N) Space Complexity, have unused space where value is 0, so it is cosly in space)
2. Adjacency list - (O(N+2E) ~ O(N+E), Better Space Complexity)

//Code:
-------------------------------
1. Adjacency Matrix 
int v,e;//v=vertices, e = edges
cin>>v>>e;
int graph[v+1][v+1]={};
cin>>v1>>v2;
//for undirected graph, it is 2 way
graph[v1][v2]=1;
graph[v2][v1]=1;
//for weighted graph
graph[v1][v2]=weight;
-------------------------------
2. Adjacency list
vector<int>adj[10];//empty vector
scanf("%d%d", &a, &b);
adj[a].push_back(b);
adj[b].push_back(a);
//weighed graph {node, weight}
adj[u].push_back({v, wt});
adj[v].push_back({u, wt});




//#######################################################################
//#######-------G-3. Graph Representation in Java | Two Ways to Represent--------########


//#######################################################################
//#######-------G-4. What are Connected Components?--------########
//Tutorial: https://takeuforward.org/graph/connected-components-in-graphs/
//Problem: https://neetcode.io/problems/count-connected-components
class Solution {
public:
    void dfs(int i,vector<int>&vis, vector<int> adj[]){
        if(vis[i]) return;
        vis[i] = 1;
        for(auto x: adj[i]) dfs(x, vis, adj);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans;
    }
};

------------------------Theory----------------------------------
- Single Graph separated by components
- i = Go 1 to N 
- if(!visit) traverse(I)

//#######################################################################
//#######-------G-5. Breadth-First Search (BFS) | Traversal Technique in Graphs--------########
//Tutorial: https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/
//Problem: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
-----------------------------
BFS in adjacency list
-----------------------------
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool>vis(V);
        queue<int>q;
        q.push(0);//source node
        ans.push_back(0);
        vis[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int x: adj[u]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                    ans.push_back(x);
                }
            }
        } 
        return ans;
    }
};

------------------------Theory----------------------------------
2 types of graph: 0 base indexing, 1 base indexing
Breadth First Search / Level Wise
Everything depends on the starting node in bfs

go on a node and asks: who are the neighbours

Time Complexity: O(N+2E) [for undirected graph]
node goes once into the bfs, and runs its neighbours

Code:


//#######################################################################
//#######-------G-6. Depth-First Search (DFS) | Traversal Technique in Graphs--------########
//Tutorial: https://takeuforward.org/data-structure/depth-first-search-dfs/
//Problem: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

-----------------------------
DFS in adjacency list
-----------------------------

class Solution {
  public:
    void dfs(int i,vector<int>adj[], vector<bool>&vis,vector<int>&ans){
        if(vis[i]) return;
        vis[i] = 1;
        ans.push_back(i);
        for(int x: adj[i])dfs(x, adj, vis, ans);
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj, vis, ans);
        }
        return ans;
    }   
};

------------------------Theory----------------------------------
- There will be plenty of dfs depending on the starting node
- Depending on the adjacency_list the traversal will change
- Time Complexity: O(N+2E) [for undirected graph]

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Problems on BFS/DFS--------###########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//BFS:
vector<bool>vis(V);
queue<int>q;
q.push(0);//source node
ans.push_back(0);
vis[0] = 1;
while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int x: adj[u]){
        if(!vis[x]){
            q.push(x);
            vis[x] = 1;
            ans.push_back(x);
        }
    }
} 


//DFS: 
int visited(100);
vector <int> adj[100];
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = 1;
    for (int u: adj[s]) dfs(u);
}



//#######################################################################
//#######-------G-7. Number of Provinces | Connected Components--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-provinces/
//Problem: https://leetcode.com/problems/number-of-provinces

Time Complexity: O(N) + O(V+2E)

class Solution {
public:
    void dfs(int i,vector<bool>&visited,vector<int>adj[]){
        if(visited[i])return;
        visited[i] = 1;
        for(int x: adj[i])dfs(x, visited, adj);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        vector<bool>visited(n);
        //converting the matrix to adjacency list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( isConnected[i][j] == 1 ){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i, visited, adj);
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-8. Number of Islands | Number of Connected Components in Matrix--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-islands/
//Problem: https://leetcode.com/problems/number-of-islands/description/



------------
BFS
Space complexity: O(N*N) + O(N*N)[for queue, all are connected, marked as 1]
------------
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

------------
DFS:
------------
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


//#######################################################################
//#######-------G-9. Flood Fill Algorithm--------########
//Tutorial: https://takeuforward.org/graph/flood-fill-algorithm-graphs/
//Problem: https://leetcode.com/problems/flood-fill/description/
(matrix ei solve korle better, instead of adjacency list)
------------
BFS
------------
class Solution {
public:
    vector<int>dx{ 0,  0,+1, -1};
    vector<int>dy{-1, +1, 0,  0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        int color_prev = image[sr][sc];

        queue<pair<int, int>>q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        while(!q.empty()){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                if( x>=0 && x<n && y<m && y>=0  && image[x][y] == color_prev && !visited[x][y]){
                    visited[x][y] = 1;
                    image[x][y] = color;
                    q.push({x,y});
                }
            }
        }

        return image;
    }
};

------------
DFS
Time complexity: O(N*M)
Space complexity: O(N*M) + O(N*M)[recursion stack space]
------------

class Solution {
public:
    void dfs(int i, int j, int n, int m, int color_prev, int color,vector<vector<int>>&image,vector<vector<bool>>&visited){
        if(i<0 || i==n || j==m || j<0) return;
        if(visited[i][j] || image[i][j]!=color_prev) return;
        visited[i][j] = 1;
        image[i][j] = color;
        dfs(i+1, j, n, m, color_prev, color, image, visited);
        dfs(i-1, j, n, m, color_prev, color, image, visited);
        dfs(i, j+1, n, m, color_prev, color, image, visited);
        dfs(i, j-1, n, m, color_prev, color, image, visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        int color_prev = image[sr][sc];
        dfs(sr, sc, n, m, color_prev, color, image, visited);
        return image;
    }
};

//#######################################################################
//#######-------G-10. Rotten Oranges--------########
//Tutorial: https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/
//Problem: https://leetcode.com/problems/rotting-oranges/description/

------------
BFS
Minimum time: that is why use bfs, going simultaneously to its neigbour
Time complexity and Space Complexity: O(N*M)
------------
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j] == 2 ){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int q_all = q.size();
            bool ok = 0;
            while(q_all--){//all the added elements in queue until become 0
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x = xx + dx[k];
                    int y = yy + dy[k];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        ok = 1;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            if(ok) ans++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};

//Another approach(striver way)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        queue<pair<pair<int, int>, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j] == 2 ){
                    q.push({{i,j},0});
                }
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            int xx = q.front().first.first;
            int yy = q.front().first.second;
            int ct = q.front().second;
            ans = max(ct, ans);
            q.pop();
            for(int k=0;k<4;k++){
                int x = xx + dx[k];
                int y = yy + dy[k];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                    grid[x][y] = 2;
                    q.push({{x,y} ,ct+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};



//#######################################################################
//#######-------G-11. Detect a Cycle in an Undirected Graph using BFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

------------
BFS
Intuition: Starting in different and colliding in the same path
Time complexity:  O(N + 2E) + O(N)
Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
------------

class Solution {
  public:
    bool detect(int i,vector<int> adj[],vector<bool>visited){
        queue<pair<int, int>>q;
        visited[i] = 1;
        //source, destination
        q.push({i, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int x: adj[node]){
                if(!visited[x]){
                    visited[x] = 1;
                    q.push({x, node});
                }
                else if(visited[x] && x!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        for(int i=0;i<V;i++){
            //start from all nodes
            if(detect(i, adj, visited)) return true;
        }
        return false;
    }
};


//#######################################################################
//#######-------G-12. Detect a Cycle in an Undirected Graph using DFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
------------
DFS
Intuition: Starting in different and colliding in the same path
Time complexity:  O(N + 2E) + O(N)
Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.
------------
class Solution {
  public:
    bool detect(int i,int p, vector<int> adj[],vector<bool>visited){
        visited[i] = 1;
        for(int x: adj[i]){
            if(!visited[x]){
                if(detect(x, i, adj, visited)){
                    return true;
                }
            }
            else if(visited[x] && x!=p){//-1 is the source parent
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        for(int i=0;i<V;i++){
            //start from all nodes
            if(!visited[i] && detect(i, -1, adj, visited)) return true;
        }
        return false;
    }
};

//#######################################################################
//#######-------G-13. Distance of nearest cell having 1 | 0/1 Matrix--------########
//Tutorial: https://takeuforward.org/graph/distance-of-nearest-cell-having-1/
//Problem: https://leetcode.com/problems/01-matrix/description/

------------
BFS
Approach: put all 0s(cause nearest 0 bolse) in the queue and build the matrix from this 
Time complexity:  O(NxM + NxMx4) ~ O(N x M)
------------

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(); 
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int>dx = {0,  0, 1, -1};
        vector<int>dy = {-1, 1, 0,  0};
        queue<pair<int, int>>q;
        vector<vector<int>> visited(n, vector<int>(m));  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }     
        }

        int v = 1;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x = xx + dx[k];
                    int y = yy + dy[k];
                    if( x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                        q.push({x,y});
                        visited[x][y] = 1;
                        ans[x][y] = v;
                    }
                }
            }
            v++;
        }
        return ans;
    }
};

//Another way(striver way)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(); 
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int>dx = {0,  0, 1, -1};
        vector<int>dy = {-1, 1, 0,  0};
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>> visited(n, vector<int>(m));  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }     
        }

        while(!q.empty()){
            int xx = q.front().first.first;
            int yy = q.front().first.second;
            int step = q.front().second;
            ans[xx][yy] = step;
            q.pop();
            for(int k=0;k<4;k++){
                int x = xx + dx[k];
                int y = yy + dy[k];
                if( x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                    visited[x][y] = 1;
                    q.push({{x,y},step+1});
                }
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-14. Surrounded Regions | Replace O's with X's--------########
//Tutorial: https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/
//Problem: https://leetcode.com/problems/surrounded-regions/description/


------------
BFS
Approach: 
If not visit from boundary, convert to 'X'
side er charpasher gular connected component visited[i][j] = 1 kora, 
          rest 'X' kra jegulate visited == 0
------------
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<m;i++) if(board[0][i]=='O') q.push({0,i}), visited[0][i] = 1;
        for(int i=1;i<n-1;i++) if(board[i][0]=='O') q.push({i,0}), visited[i][0] = 1;
        for(int i=0;i<m;i++) if(board[n-1][i]=='O') q.push({n-1,i}), visited[n-1][i] = 1;
        for(int i=1;i<n-1;i++) if(board[i][m-1]=='O') q.push({i,m-1}), visited[i][m-1] = 1;
        
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        while(!q.empty()){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && board[x][y]=='O'){
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};


------------
DFS
Time complexity:  O(N) + O(M) + O(NxMx4) ~ O(N x M)
Space Complexity: O(N x M), O(N x M) 
------------
class Solution {
public:
    vector<int>dx = {1, -1, 0, 0};
    vector<int>dy = {0, 0, 1, -1};
    void dfs(int xx, int yy,int n, int m, vector<vector<char>>& board, vector<vector<bool>>&visited){
        visited[xx][yy] = 1;
        for(int i=0;i<4;i++){
            int x = xx + dx[i];
            int y = yy + dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && board[x][y]=='O'){
                dfs(x, y,n, m, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<m;i++) if(board[0][i]=='O') dfs(0,i,n, m, board, visited);
        for(int i=1;i<n-1;i++) if(board[i][0]=='O') dfs(i,0,n, m, board, visited);
        for(int i=0;i<m;i++) if(board[n-1][i]=='O') dfs(n-1,i,n, m, board, visited);
        for(int i=1;i<n-1;i++) if(board[i][m-1]=='O') dfs(i, m-1,n, m, board, visited);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};

//#######################################################################
//#######-------G-15. Number of Enclaves | Multi-source BFS--------########
//Tutorial: https://takeuforward.org/graph/number-of-enclaves/
//Problem: https://leetcode.com/problems/number-of-enclaves/description/



------------
BFS
Approach: Boundary connected component, Same like the above question(G-14)
Time complexity:  O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, 
the BFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. 
Space Complexity: O(N x M), O(N x M) for the visited array, and queue space takes up N x M locations at max. 
------------
class Solution {
public:
    int numEnclaves(vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        queue<pair<int, int>>q;
        for(int i=0;i<m;i++) if(grid[0][i]==1 && !visited[0][i]) q.push({0,i}), visited[0][i] = 1;
        for(int i=1;i<n-1;i++) if(grid[i][0]==1 && !visited[i][0]) q.push({i,0}), visited[i][0] = 1;
        for(int i=0;i<m;i++) if(grid[n-1][i]==1 && !visited[n-1][i]) q.push({n-1,i}), visited[n-1][i] = 1;
        for(int i=1;i<n-1;i++) if(grid[i][m-1]==1 && !visited[i][m-1]) q.push({i,m-1}), visited[i][m-1] = 1;

        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        while(!q.empty()){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};

------------
DFS
------------

class Solution {
public:
    void dfs(int xx, int yy, int n, int m,vector<vector<int>>&grid, vector<vector<bool>>&visited  ){
        visited[xx][yy] = 1;
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        for(int i=0;i<4;i++){
            int x = xx + dx[i];
            int y = yy + dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                dfs(x, y, n, m, grid, visited);
            }
        }
    }

    int numEnclaves(vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<m;i++) if(grid[0][i]==1 && !visited[0][i]) dfs(0,i,n, m, grid, visited);
        for(int i=1;i<n-1;i++) if(grid[i][0]==1 && !visited[i][0]) dfs(i,0,n, m, grid, visited);
        for(int i=0;i<m;i++) if(grid[n-1][i]==1 && !visited[n-1][i]) dfs(n-1,i,n, m, grid, visited);
        for(int i=1;i<n-1;i++) if(grid[i][m-1]==1 && !visited[i][m-1]) dfs(i, m-1,n, m, grid, visited);

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------G-16. Number of Distinct Islands | Constructive Thinking + DFS--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-distinct-islands/
//Problem: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

------------
BFS
Approach: write bfs, and put the list in a set, print set size at the end(same approach for dfs also)
------------

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        set<vector<pair<int, int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int, int>>v;
                    int bx = i;//basex
                    int by = j;//basey
                    v.push_back({bx-bx,by-by});
                    visited[bx][by] = 1;
                    queue<pair<int, int>> q;
                    q.push({bx,by});
                    vector<int>dx = {1,-1,0,0};
                    vector<int>dy = {0,0,1,-1};
                    while(!q.empty()){
                        int xx = q.front().first;
                        int yy = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int x = xx + dx[k];
                            int y = yy + dy[k];
                            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                                v.push_back({x-bx,y-by});
                                visited[x][y] = 1;
                                q.push({x,y});
                            }
                                
                        }
                    }
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
------------
DFS
TC: O(N x M x log(N x M)) + O(NxMx4) ~ O(N x M)
SP: O(N x M), O(N x M) 
------------
class Solution {
        void dfs(int r, int c, int rp, int cp,vector<vector<int>>&grid, vector<vector<bool>>&visited, vector<pair<int, int>>&v){
            int n = grid.size(), m = grid[0].size();
            visited[r][c] = 1;
            v.push_back({r-rp,c-cp});
            vector<int>dx = {1,-1,0,0};
            vector<int>dy = {0,0,1,-1};
            for(int k=0;k<4;k++){
                int x = r + dx[k];
                int y = c + dy[k];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                    dfs(x,y, rp, cp, grid,visited, v);
                }
            }
        }
public:
    int countDistinctIslands(vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        set<vector<pair<int, int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int, int>>v;
                    int bx = i;//basex
                    int by = j;//basey
                    dfs(bx, by, bx, by, grid, visited, v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};

//#######################################################################
//#######-------G-17. Bipartite Graph | BFS--------########
//Tutorial: https://takeuforward.org/graph/bipartite-graph-bfs-implementation/
//Problem: https://leetcode.com/problems/is-graph-bipartite/description/

Bipartite: Coloring with two colors alternatively(no two path has the same color)
------------
BFS
------------

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(auto x: adj[v]){
                        if(color[x]==-1){
                            color[x] = !color[v];
                            q.push(x);
                        }
                        else if(color[x] == color[v]){//parenet cannot be same with child
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};



//#######################################################################
//#######-------G-18. Bipartite Graph | DFS--------########
//Tutorial: https://takeuforward.org/graph/bipartite-graph-dfs-implementation/
//Problem: https://leetcode.com/problems/is-graph-bipartite/description/

------------
DFS
TC: O(V + 2E)
SP: O(3V) ~ O(V)
------------

class Solution {
    bool dfs(int i, int now,vector<int>&color,vector<int>adj[]){
        color[i] = now;
        for(auto x: adj[i]){
            if(color[x] == -1){
                //ekbar false then keep false
                if(!dfs(x, !now, color, adj))return false;
            }
            else if(now == color[x]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                if(!dfs(i, 0, color, adj))return false;
            }
        }
        return true;
    }
};

//Another version
class Solution {
    bool dfs(int i, int now,vector<int>&color,vector<int>adj[], int ans){
        color[i] = now;
        for(auto x: adj[i]){
            if(color[x] == -1){
                ans = ans & dfs(x, !now, color, adj, ans);
            }
            else if(now == color[x]){
                ans = ans & 0;
            }
        }
        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                if(!dfs(i, 0, color, adj, 1))return false;
            }
        }
        return true;
    }
};

//#######################################################################
//#######-------G-19. Detect cycle in a directed graph using DFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Approach: 
On the same path node has to be visited again
visited and  path visited  == true , then there is a cycle
- BFS will not work for directed graph

------------
DFS
TC: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
SP: O(2N) + O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for recursive stack space.
------------


class Solution {
    bool dfs(int node, vector<bool>&pathVis,vector<bool>&visited, vector<int> adj[]){
        visited[node] = 1;
        pathVis[node] = 1;
        for(auto child: adj[node]){
            if(!visited[child]){
                if(dfs(child, pathVis, visited, adj)) return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        vector<bool>pathVis(V);
        for(int i=0;i<V;i++){
            if( dfs(i, pathVis, visited, adj)  == true) return true;
        }
        return false;
    }
};



//Another approach:
3 states in visited array (that is why use int type in visited array)
0 , 1 , 2 state 

class Solution {
    bool dfs(int node,vector<int>&visited, vector<int> adj[]){
        visited[node] = 1;
        for(auto child: adj[node]){
            if(!visited[child]){
                if(dfs(child, visited, adj)) return true;
            }
            else if(visited[child]==1){
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V);
        for(int i=0;i<V;i++){
            if( !visited[i] && dfs(i, visited, adj)  == true) return true;
        }
        return false;
    }
};


//#######################################################################
//#######-------G-20. Find Eventual Safe States - DFS--------########
//Tutorial: https://takeuforward.org/data-structure/find-eventual-safe-states-dfs-g-20/
//Problem: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

- Everynode that is connected to the cycle can never be safe node 
- everynode that is incoming to the cycle is not a safe node

------------
DFS
------------




//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Problems on Topo Sort--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-21. Topological Sort Algorithm | DFS--------########
//Tutorial: https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/
//Problem: https://www.geeksforgeeks.org/problems/topological-sort/1

------------
DFS
------------


//#######################################################################
//#######-------G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS--------########
//Tutorial: https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/
//Problem: https://www.geeksforgeeks.org/problems/topological-sort/1

see the problem? is it correct


//#######################################################################
//#######-------G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


//#######################################################################
//#######-------G-24. Course Schedule I and II | Pre-requisite Tasks | Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/
//Problem1: https://leetcode.com/problems/course-schedule/description/
//Problem2: https://leetcode.com/problems/course-schedule-ii/description/


//#######################################################################
//#######-------G-25. Find Eventual Safe States - BFS - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/
//Problem: https://leetcode.com/problems/find-eventual-safe-states/description/


//#######################################################################
//#######-------G-26. Alien Dictionary - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/
//Problem: 



---=-=-===-===-= SOlve all the question above
???????????????????????????????????????????????????????????????????????????


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Singly LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261












//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Singly LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Singly LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Singly LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Singly LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
-------------------------------------------------------------------------
-------------------------------------------------------------------------