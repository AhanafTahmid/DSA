//Graph

- See notion notes / striver notes for details
- Think what is the starting point(in bfs)
- Grid type problems, think graph
- Always use bool type for visited array(2 bytes)
- Result can be different in bfs topological or dfs topological sort

Confusions:
1. G-17. Bipartite Graph | BFS -> little confused on queue stack also
Wrong Answer(in my way )
60 / 81 testcases passed
Input graph =
[[1],[0,3],[3],[1,2]]
2. g-40. not sure about dist[node] vs dis???? - /?????????WA on leetcode
//Problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
3.todo: G-42. Floyd Warshall Algorithm - solve using dijkstra as well
4. todo: G-43. Find the City With the Smallest Number of Neighbours at a Threshold Distance - solve using dijkstra as well
5. todo: G-51. Number of Islands - II - Online Queries - DSU solve using dfs, or bfs
q.pop();//always forgets

2. G-18. Bipartite Graph | DFS - little confused on how dfs in working 
3. G-19. Detect cycle in a directed graph using DFS
4. G-20. Find Eventual Safe States - DFS (draw the tree )
5. not sure why queue is faster than pq in dijkstra, it will visit all the nodes even if we donot use 
pq, it will just not change the values
6. G-52. Making a Large Island - DSU
if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
    ds.unionBySize(u,v);//a little confused
}
7. confused on the solution: https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
8. G-55. Bridges in Graph - Using Tarjans Algorithm of time in and low time confused

Questions: 
1. How to get shortest path having negative cycle
2. How to get get all the shortest path dijkstra


Good practice: donot temper data, make a copy and solve[for this type of question, just remember]
- For undirected graph dijkstra use queue instead of priority queue, cause it does not make it different, level e same distance thakbe[binary maze question]

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


2d grid bfs
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
2d grid dfs

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
- all path has to come at a terminal node -> then it is a safe node

------------
DFS
------------
class Solution {
public:
    bool dfs(int i, vector<int>adj[], vector<bool>&visited, vector<bool>&pathvisited, vector<bool>&choice){
        visited[i] = 1;
        choice[i] = 0;
        pathvisited[i] = 1;
        for(int x: adj[i]){
            if(!visited[x]){
                if(dfs(x, adj, visited, pathvisited, choice)) return true;
            }
            else if(pathvisited[x]==1){
                return true;
            }
        }
        choice[i] = 1;
        pathvisited[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;
        vector<int>adj[V];
        vector<bool>visited(V), pathvisited(V), choice(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, adj, visited, pathvisited, choice);
            }
        }

        for(int i=0;i<V;i++){
            if(choice[i]==1) ans.push_back(i);
        }
        return ans;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################nnn
//##########-------Problems on Topo Sort--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
 
- Something before something, Use topological sort
- Topological sorting only exists/valid in Directed Acyclic Graph (DAG).
- Toplogical sort: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

//#######################################################################
//#######-------G-21. Topological Sort Algorithm | DFS--------########
//Tutorial: https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/
//Problem: https://www.geeksforgeeks.org/problems/topological-sort/1

------------
DFS
TC: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
SC: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.
------------

class Solution
{   
    void dfs(int i,vector<int> adj[],vector<bool>&visited,stack<int>&st){
        visited[i] = 1;
        for(int x: adj[i]){
            if(!visited[x]){
                dfs(x, adj, visited, st);
            }
        }
        st.push(i);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V);
	    stack<int>st;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(!visited[i])dfs(i, adj, visited, st);
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

//#######################################################################
//#######-------G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS--------########
//Tutorial: https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/
//Problem: https://www.geeksforgeeks.org/problems/topological-sort/1


Kahns Algorithm: Calculate indegree and from indegree find topological sorting(see striver notes for more)
- By using kahns we can use topological sort in bfs 

------------
BFS
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
------------

class Solution
{   
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{

	    vector<int>ans;
	    vector<int> indegree(V);
	    for(int i=0;i<V;i++){
	       for(int x: adj[i]) indegree[x]++;
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    
        //someone will always be in queue as it is DAG
	    while(!q.empty()){
	       int v = q.front();
	       q.pop();
	       ans.push_back(v);
	       for(int x: adj[v]){
	           indegree[x]--;
	           if(indegree[x]==0){
	               q.push(x);
	           }
	       }
	    }
	    
	    return ans;
	}
};

//#######################################################################
//#######-------G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

------------
BFS
Approach: If ct == vertices, then it is a dag, hence, toposort is available, hence no cycle,else cycle ase
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
------------

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
	    vector<int> indegree(V);
	    for(int i=0;i<V;i++){
	       for(int x: adj[i]) indegree[x]++;
	    }
	    int ct = 0;
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    while(!q.empty()){
	        int v = q.front();
	        q.pop();
	        ct++;
	        for(int x: adj[v]){
	            indegree[x]--;
	            if(indegree[x] == 0)q.push(x);
	        }
	    }
        
        return (ct==V?false:true);
    }
};

//#######################################################################
//#######-------G-24. Course Schedule I and II | Pre-requisite Tasks | Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

//Problem1: https://leetcode.com/problems/course-schedule/description/
------------
BFS
------------
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int x: adj[i]) indegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        int ct = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ct++;
            for(int x: adj[v]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }

        if(ct==numCourses) return true;//means there is no cycle
        return false;
    }
};

//Problem2: https://leetcode.com/problems/course-schedule-ii/description/
------------
BFS
------------
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            // {0, 1}
            // to finish 0 you must finish 1, 0 is dependent to 1
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int x: adj[i]) indegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(int x: adj[v]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }

        if(ans.size()!=numCourses)ans.clear();
        return ans;
    }
};

//#######################################################################
//#######-------G-25. Find Eventual Safe States - BFS - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/
//Problem: https://leetcode.com/problems/find-eventual-safe-states/description/

------------
BFS
Approach: backtracking the answer
Time Complexity: O(V+E)+O(N*logN), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm. Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.
Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the indegree array, O(N) for the queue data structure used in BFS(where N = no.of nodes), and extra O(N) for the adjacency list to store the graph in a reversed order.
------------

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;
        vector<int>indegree(V);
        vector<int>adj2[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj2[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto x: adj2[v]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//#######################################################################
//#######-------G-26. Alien Dictionary - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/
//Problem: https://www.geeksforgeeks.org/problems/alien-dictionary/1

------------
BFS
Approach: convert the string to directed graph, after that, use topological to find the sequence
Not possible, when: 1. abcd , abc 2. Cyclic dependency
Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.
Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency list used in the algorithm.
------------

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //make directed graph
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int l = 0;
            while(l<s1.size()){
                if(s1[l]!=s2[l]){
                    adj[s1[l] - 'a'].push_back(s2[l]-'a');
                    break;
                }
                l++;
            }
        }
        
        vector<int>indegree(K);
        for(int i=0;i<K;i++){
            for(int x: adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<K;i++){
            if( indegree[i] == 0) q.push(i);
        }
        
        string s = "";
        while(!q.empty()){
            int v = q.front();
            s+= (v+'a'); 
            q.pop();
            for(int x: adj[v]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        
        return s;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Shortest Path Algorithms and Problems--------##########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

Dijkstra's algorithm is necessary for graphs that can contain cycles because they cannot be topologically sorted. In other cases, the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.

//#######################################################################
//#######-------G-27. Shortest Path in Directed Acyclic Graph - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/
//Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

(ei question ta khatai kore bujha important beshi)

------------
BFS
Approach: 1. Do toposort 2. build the distance array from the values
Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M). Where N= number of vertices and M= number of edges.
Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .
------------
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //1. Do toposort 2. build the distance array from the values
        vector<pair<int, int>>  adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //1. Toposort
        vector<int>indegree(N);
        for(int i=0;i<N;i++){
            for(auto x: adj[i]){
                indegree[x.first]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>g;
        while(!q.empty()){
            int v = q.front();
            g.push_back(v);
            q.pop();
            for(auto x: adj[v]){
                indegree[x.first]--;
                if(indegree[x.first]==0)q.push(x.first);
            }
        }
        
        //2. build the distance array from the values
        vector<int>dist(N,1e9);
        dist[0] = 0;
        for(int i=0;i<N;i++){
            int v = g[i];
            for(auto x: adj[v]){
                int p = x.first;//to the node
                int q = x.second;//weight
                //neighbour weight e beshi cost lagle komai fela
                if( dist[v] + q < dist[p] ){
                    dist[p] = dist[v] + q;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        
        return dist;
    }
};

//#######################################################################
//#######-------G-28. Shortest Path in Undirected Graph with Unit Weights--------########
//Tutorial: https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/
//Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

------------
BFS
Approach: 1. Make adjacency list 2. build distance array using formula dist[v]+1<dist[x]
Time Complexity: O(M) { for creating the adjacency list from given list edges} + O(N + 2M) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). Where N= number of vertices and M= number of edges.
Space Complexity:  O(N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M). Where N= number of vertices and M= number of edges.
------------

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
		for(int i=0;i<M;i++){
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int>dist(N, 1e9);
		dist[src] = 0;
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int x: adj[v]){
				if(dist[v]+1<dist[x]){
					dist[x] = dist[v] + 1;
					q.push(x);
				}
			}
		}

		for(int i=0;i<N;i++) if(dist[i]==1e9) dist[i] = -1;
		return dist;
    }
};

//#######################################################################
//#######-------G-29. Word Ladder - I | Shortest Paths--------########
//Tutorial: https://takeuforward.org/graph/word-ladder-i-g-29/
//Problem: https://leetcode.com/problems/word-ladder/description/

------------
BFS
Approach: 1. Put all the words in a set 2. for each startword keep finding the word in wordlist by changing characters. If found push in the queue
Time Complexity: O(N * M * 26). Where N = size of wordList Array and M = word length of words present in the wordList..
Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.
Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }
Where N = size of wordList Array.
------------

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st (wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int j=0;j<word.size();j++){
                for(char i='a';i<='z';i++){
                    string nword = word;
                    nword[j] = i;
                    if( st.find(nword)!=st.end() ){
                        st.erase(nword);
                        q.push({nword, steps+1});
                    }
                }
            }
        }
        return 0;
    }
};


//#######################################################################
//#######-------G-30. Word Ladder - 2 | Shortest Paths--------########
//Tutorial: https://takeuforward.org/graph/g-30-word-ladder-ii/
//Problem: https://leetcode.com/problems/word-ladder-ii/description/

build array along the way

//#######################################################################
//#######-------G-31. Word Ladder - 2 | Optimised Approach for Leetcode--------########
//Tutorial: https://takeuforward.org/graph/word-ladder-ii-optimised-approach-g-31/
//Problem: https://leetcode.com/problems/word-ladder-ii/description/


//#######################################################################
//#######-------G-32. Dijkstra's Algorithm - Using Priority Queue - C++ and Java - Part 1--------########
//Tutorial: https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/
//Problem: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

dijkstra does not work in negative weight and negative cycle, fall in infiinte loop
0 -> 1 (with -2 weight not possible)
------------
BFS
Approach: 1. build distance array using formula dist[v]+1<dist[x] [Must use priority queue]
Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.
Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
		vector<pair<int, int>> adj2[V];
		
		for(int i=0;i<V;i++){
			for(int j=0;j<adj[i].size();j++){
				adj2[i].push_back({adj[i][j][0], adj[i][j][1]});
			}
		}

		// for(int i=0;i<V;i++){
		// 	cout<< i << endl;
		// 	for(auto x: adj2[i]){
		// 		cout<< x.first << ' ' << x.second << endl;
		// 	}
		// 	cout<<endl<<endl;
		// }

		vector<int>dist(V, 1e9);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({S, 0});
		dist[S] = 0;
		while(!pq.empty()){
			int nd = pq.top().first;
			int wg = pq.top().second;//this is just for optimizing time complexity, else it is not needed
			pq.pop();
			for(auto [x,y]: adj2[nd]){
				if(dist[nd] + y < dist[x] ){
					dist[x] = dist[nd] + y;
					pq.push({x, dist[x]});
				}
			}
		}
		for(int i=0;i<V;i++) if(dist[i]==1e9) dist[i] = -1;

        return dist;
	}
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


//////////////////////////////////////////////////////////////////
//another version gfg
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, S});
		dist[S] = 0;
		while(!pq.empty()){
			int nd = pq.top().second;
			int wg = pq.top().first;//this is just for optimizing time complexity, else it is not needed, 
            //or can be used like this, wg + y < dist[x] 
			pq.pop();
			for(auto v: adj[nd]){
			    int x = v[0];
			    int y = v[1];
				if(dist[nd] + y < dist[x] ){
					dist[x] = dist[nd] + y;
					pq.push({dist[x], x});
				}
			}
		}
        return dist;
    }
};

//#######################################################################
//#######-------G-33. Dijkstra's Algorithm - Using Set - Part 2--------########
//Tutorial: https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33/
//Problem: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


------------
BFS
Time Complexity : O( E log(V) ) Where E = Number of edges and V = Number of Nodes.
Space Complexity : O( |E| + |V| ) Where E = Number of edges and V = Number of Nodes.
------------

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
		set<int> st;
		st.insert(S);
		dist[S] = 0;
		while(!st.empty()){
			int nd = (*st.begin());
			st.erase(*st.begin());
			for(auto x: adj[nd]){
			    int adjn = x[0];
			    int w = x[1];
				if(dist[nd] + w < dist[adjn]){
                    //if(dist[adjn]!=1e9)st.erase(adjn);
					dist[adjn] = dist[nd] + w;
					st.insert(adjn);
				}
			}
		}
        return dist;
    }
};


//#######################################################################
//#######-------G-34. Dijkstra's Algorithm - Why PQ and not Q, Intuition, Time Complexity Derivation - Part 3--------########
//Tutorial: https://takeuforward.org/data-structure/g-34-dijkstras-algorithm-intuition-and-time-complexity-derivation/

Theory 

//#######################################################################
//#######-------G-35. Print Shortest Path - Dijkstra's Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm/
//Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

------------
BFS
Approach: build a parent array and backtrack the path from n to 1
Time Complexity: O( E log(V) ) { for Dijkstra’s Algorithm } + O(V) { for backtracking in order to find the parent for each node } Where E = Number of edges and V = Number of Nodes.
Space Complexity: O( |E| + |V| ) { for priority queue and dist array } + O( |V| ) { for storing the final path } Where E = Number of edges and V = Number of Nodes.
------------
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector< pair<int, int> >adj[n+1];
        // node -> {directed node, weight}
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
        pq.push({0, 1});//{weight, node}
        
        vector<int> dist(n+1, 1e9), parent(n+1, -1), path;
        parent[1] = 1;//1 er parent 1 e
        dist[1] = 0; //distance of source node
        while(!pq.empty()){
            int nd = pq.top().second;
            pq.pop();
            for(auto v: adj[nd]){
                int x = v.first;
                int y = v.second;
                if(dist[x] > dist[nd] + y ){
                    dist[x] = dist[nd] + y;
                    pq.push({dist[x], x});
                    parent[x] = nd;//new parent 
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        int i = n;
        while(1){
            path.push_back(i);
            i = parent[i];
            if(i==1){
                path.push_back(i);
                break;
            }
            if(i==-1)return {-1};
        }
        path.push_back(dist[n]);// first element is the weight of the path acc to gfg
        reverse(path.begin(), path.end());
        return path;
    }
};

------------
//CF Problem: https://codeforces.com/problemset/problem/20/C
------------
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
	int n, m;cin>>n>>m;
	vector<vector<int>>edges;
	for(int i=0;i<m;i++){
		int x, y, z;cin>> x >> y >> z;
		edges.push_back({x,y,z});
	}

	vector< pair<int, int> >adj[n+1];
	for(int i=0;i<m;i++){
		adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
		adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
	pq.push({0, 1});
	
	vector<int> dist(n+1, 1e19), parent(n+1, -1), path;
	parent[1] = 1;
	dist[1] = 0;
	while(!pq.empty()){
		int nd = pq.top().second;
		pq.pop();
		for(auto v: adj[nd]){
			int x = v.first;
			int y = v.second;
			if(dist[x] > dist[nd] + y ){
				dist[x] = dist[nd] + y;
				pq.push({dist[x], x});
				parent[x] = nd;
			}
		}
	}
	
	
	int i = n;
	while(1){
		path.push_back(i);
		i = parent[i];
		if(i==1){
			path.push_back(i);
			break;
		}
		if(i==-1){
			cout<< -1 <<endl;
			return;
		}
	}
	reverse(path.begin(), path.end());
	for(auto x: path)cout << x << ' ';
	cout<<endl;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;
	//cin >> t;
	while(t--)solve(); 
	return 0;
}


//#######################################################################
//#######-------G-36. Shortest Distance in a Binary Maze--------########
//Tutorial: https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze/
//Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

2d grid dijkstra
------------
BFS
Approach: apply bfs and use dijkstra algo for undirected graph -> dist[x][y] > dist[xx][yy] + 1
Time Complexity: O( 8*N*M ) { N*M are the total cells, for each of which we also check 8 adjacent nodes for the shortest path length}, Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
Space Complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
------------

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> dirx = {1, -1, 0, 0, 1, -1, -1,  1};
        vector<int> diry = {0, 0, -1, 1, -1, 1,  -1, 1};
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        int sx = 0, sy = 0;
        int dx = n-1, dy = n-1;
        dist[sx][sy] = 1;

        if(grid[sx][sy]==1) return -1;

        queue<pair< int, pair<int, int> > >q;
        q.push({0, {sx, sy}});
        
        while(!q.empty()){
            int xx = q.front().second.first;
            int yy = q.front().second.second;
            //int wg = q.front().first;
            q.pop();
            for(int k=0;k<8;k++){
                int x = xx + dirx[k];
                int y = yy + diry[k];
                if(x>=0 && x<n && y>=0 && y<n &&  grid[x][y] == 0 && dist[x][y] > dist[xx][yy] + 1){
                    dist[x][y] = dist[xx][yy] + 1;
                    q.push({dist[x][y], {x,y}});
                }
            }
        }
        
        if(dist[dx][dy]==1e9) return -1;
        return dist[dx][dy];
    }
};

//#######################################################################
//#######-------G-37. Path With Minimum Effort--------########
//Tutorial: https://takeuforward.org/data-structure/g-37-path-with-minimum-effort/
//Problem: https://leetcode.com/problems/path-with-minimum-effort/description/

------------
BFS
Approach: apply little dijkstra algo and if dist[r][c]>diff keep updating
Time Complexity: O( 4*N*M * log( N*M) ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the minimum effort and additional log(N*M) for insertion-deletion operations in a priority queue }
Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.
Space Complexity: O( N*M ) { Distance matrix containing N*M cells + priority queue in the worst case containing all the nodes ( N*M) }.
------------

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(columns, 1e9));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1,-1, 0,  0};
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> >>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int w = pq.top().first;
            int rr = pq.top().second.first;
            int cc = pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int r = rr + dx[k];
                int c = cc + dy[k];
                if(r>=0 && r<rows && c>=0 && c<columns){
                    int diff = max(abs(heights[r][c] - heights[rr][cc]), w);
                    if(dist[r][c]>diff){
                        dist[r][c] = diff;
                        pq.push({diff,{r,c}});
                    }
                }
            }
        }
        
        return dist[rows-1][columns-1]; 
    }
};

//#######################################################################
//#######-------G-38. Cheapest Flights Within K Stops--------########
//Tutorial: https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/
//Problem: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

First priority should be steps
steps are increasing by +1, that is why queue can be used instead of priority queue
------------
BFS
Approach: apply dijkstra
Time Complexity: O( N ) { Additional log(N) of time eliminated here if we’re using a simple queue rather than a priority queue which is usually used in Dijkstra’s Algorithm }.
Where N = Number of flights / Number of edges.
Space Complexity:  O( |E| + |V| ) { for the adjacency list, priority queue, and the dist array }.
Where E = Number of edges (flights.size()) and V = Number of Airports.
------------

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n, 1e9);
        //steps, cost, node
        priority_queue< tuple<int, int,int> ,vector< tuple<int, int,int> >, greater<tuple<int, int,int>> > pq;
        pq.push({0, 0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto [steps, cost , node] = pq.top();
            pq.pop();
            for(auto x: adj[node]){
                int nd = x.first;
                int wg = x.second;
                if(steps<=k && dist[nd] > cost+wg){
                    dist[nd] = cost+wg;
                    pq.push({steps+1, dist[nd], nd});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

//#######################################################################
//#######-------G-39. Minimum Multiplications to Reach End--------########
//Tutorial: https://takeuforward.org/graph/g-39-minimum-multiplications-to-reach-end/
//Problem: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

First priority should be steps
steps are increasing by +1, that is why queue can be used instead of priority queue
------------
BFS
Approach: 1 to 1e5 prjnto dist array maintain kora
Time Complexity : O(100000 * N) 
Where 100000 are the total possible numbers generated by multiplication (hypothetical) and N = size of the array with numbers of which each node could be multiplied.
Space Complexity :  O(100000 * N) 
Where 100000 are the total possible numbers generated by multiplication (hypothetical) and N = size of the array with numbers of which each node could be multiplied. 100000 * N is the max possible queue size. The space complexity of the dist array is constant.
------------
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        //steps, node
        queue<pair<int, int>> q;
        q.push({0,start});
        vector<int>dist(100000, 1e9);
        dist[start] = 0;
        while(!q.empty()){
            int nd = q.front().second;
            int steps = q.front().first;
            if(nd==end){
                return steps;
            }
            q.pop();
            for(int x: arr){
                int v = (x * nd)%100000;
                if( dist[v] > dist[nd] + 1){//if smaller then enter
                    dist[v] = dist[nd] + 1;
                    q.push({steps+1, v});
                }
            }
            
        }
        
        return dist[end]==1e9?-1:dist[end];
        
    }
};

//#######################################################################
//#######-------G-40. Number of Ways to Arrive at Destination--------########
//Tutorial: https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination/
//Problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

if you know how many ways you have come to a node then you donot need source node 
------------
BFS
Approach: keep pushing {distance, node} in priority queue and remember the total ways[number]
Time Complexity: O( E* log(V)) { As we are using simple Dijkstra's algorithm here, the time complexity will be or the order E*log(V)} Where E = Number of edges and V = No. of vertices.
Space Complexity :  O(N) { for dist array + ways array + approximate complexity for priority queue }Where, N = Number of nodes.
------------
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>>adj[n];
        int md = 1e9+7;
        for(int i=0;i<roads.size();i++){
            adj[ roads[i][0] ].push_back({ roads[i][1],roads[i][2] });
            adj[ roads[i][1] ].push_back({ roads[i][0],roads[i][2] });
        }
        //cost, destination
        priority_queue< pair<int, int> , vector< pair<int, int> > , greater< pair<int, int> > > pq;
        pq.push({0,0});
        vector<long long>dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            for(auto x: adj[node]){
                long long nd = x.first;//destination
                long long d = x.second;//
                if(dist[nd] > dis + d){//not sure about dist[node] vs dis????
                    dist[nd] = dis + d;
                    ways[nd] = ways[node];
                    pq.push({dist[nd], nd});
                }
                else if(dist[nd] == dis + d) ways[nd] = (ways[nd] + ways[node])%md;
            }
        }
        return ways[n-1]%md;
    }
};

//#######################################################################
//#######-------G-41. Bellman Ford Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/
//Problem: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
- dijkstra and bellman ford is single source shortest path algorithm
Bellman Ford Algorithm: Helps to detect negative cycles as well, only application in directed graph 
for directed graph change it to undirected graph in bellman ford
dijkstra + n-1 iternation
- The Bellman-Ford algorithm is a way to find single source shortest paths in a graph with negative edge weights (but no negative cycles).
relax all the edges n-1 times sequentially
complete all the edges n-1 times 
in nth time the distance will be reducing - for negative cycle

------------
BFS
Approach: Run dijkstra N-1 times(edges order does not matter)
Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.
Space Complexity: O(V) for the distance array which stores the minimized distances.
------------

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        int m = edges.size();
        vector<int>dist(V,1e8);
        dist[S] = 0;
        int times = V-1;//all nodes - 1
        while(times--){
            for(int i=0;i<m;i++){
                int n1 = edges[i][0];
                int n2 = edges[i][1];
                int wg = edges[i][2];
                if( dist[n1]!= 1e8 && dist[n1] + wg < dist[n2] ){
                    dist[n2] = dist[n1] + wg;
                }
            }
        }
        
        for(int i=0;i<m;i++){
                int n1 = edges[i][0];
                int n2 = edges[i][1];
                int wg = edges[i][2];
                if( dist[n1]!= 1e8 && dist[n1] + wg < dist[n2] ){
                    return {-1};
                }
            }
        
        return dist;
    }
};


//#######################################################################
//#######-------G-42. Floyd Warshall Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/
//Problem: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
//Yt1: https://youtu.be/YbY8cVwWAvw
//Yt2: https://youtu.be/tFQAoyEu6Bk


- Floyd Warshall is multi source shortest path algorithm
- If there are no negative values, you can use dijkstra for all the values individually - N * Elogv (better than N^3)
- not possible for negative cycle
- if source to source distance is negative, then there is cycle exits

------------
Brute Force(Floyd Warshall)
Approach: 
1. Make all diagonal 0, put all the values 
2. keep finding values for each nodes via other node
Formula: matrix[i][j] = min(matrix[i][j], matrix[i][node] + matrix[node][j]); {via a matrix way, or the matrix way}
Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.
Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
------------

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1)matrix[i][j] = 1e9;
            }
        }
	    
	    for(int node=0;node<n;node++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][node] + matrix[node][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1e9)matrix[i][j] = -1;
            }
        }
	    
	}
};

//#######################################################################
//#######-------G-43. Find the City With the Smallest Number of Neighbours at a Threshold Distance--------########
//Tutorial: https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/
//Problem: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


------------
Brute Force(Floyd Warshall)
Approach: 1. Apply floyd warshall 2. Find the max node with least cities connected in the distanceThreshold
Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.
Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
------------

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n, vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++) mat[i][i] = 0;

        //build the matrix array 
        for(int node=0;node<n;node++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = min(mat[i][j], mat[i][node] + mat[node][j]);
                }
            }
        }

        int mn = 1e9;
        int node_ans = -1;
        for(int i=0;i<n;i++){
            int ct = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold) ct++;
            }
            if(ct<=mn){
                mn = ct;
                node_ans = i;
            }
        }
        return node_ans;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------MinimumSpanningTree/Disjoint Set--------##############
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-44. Minimum Spanning Tree - Theory--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-spanning-tree-theory-g-44/

Minimum Spanning Tree - MST 
MST: A tree which have n nodes and n-1 edges, and all nodes are reachable from each other
everything is in a single component
a graph can have a lot of spanning tree
- The tree which has the minimum edges(in summation, minimum sum), is the mst

MST finding algorithm:
1. Prims algorithm 
2. Kruskal algorithm(must know disjoint set)

//#######################################################################
//#######-------G-45. Prim's Algorithm - Minimum Spanning Tree--------########
//Tutorial: https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/
//Problem: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
//Yt:  https://youtu.be/mJcZjjKzeqk
//Yt2: https://youtu.be/KwYMYX0a73k

Intuition: Going Greedy is the intuition

Steps to find mst using prims algo(in khatai): 
From graph
1. Loop delete 
2. Parallel edge delete 
3. There should be no cycle in new mst

- Helps finding sum as well as the tree 

------------
Steps (in code)
1. Mark the visited array as 0 for all the nodes
2. Start with 0th node and push
(0,0,-1)//weight, node, parent
explanation:  -1 means 0 is the genesis node
Mark 0 as visited
3. Push all the neighbours of 0 in pq Do not mark them visited  (footnote 1)
Since its a min heap the edge with minimum weight will be at the top
4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq
5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends

footnote:
1. why to not mark it visited?
in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up later for sure (algorithm ends only when the queue is empty )
but in msts case even if we push the edge into pq , theres no surety that the edge will be picked up . when prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq


------------
BFS
Approach: 
If not visited keep taking the weight of the destination value, keep doing it until all are visited
Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.
------------

////////////////////////
------------------------
--Total sum of MST--
------------------------
////////////////////////
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        
        priority_queue< pair<int, int> , 
        vector< pair<int, int> > , greater < pair<int, int> > >pq;
        pq.push({0, 0});
        vector<int>visited(V,0);
        int sum = 0;
        while(!pq.empty()){
            int wg = pq.top().first;
            int nd = pq.top().second;
            pq.pop();
            if(!visited[nd]){
                visited[nd] = 1;
                sum+=wg;
                for(auto x: adj[nd]){
                   if(!visited[x[0]])pq.push({x[1], x[0]});
                }
            }
        }
        return sum;
    }
};

////////////////////////
------------------------
--Total sum + the tree(parents) of MST--
------------------------
////////////////////////

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, -1}});
        vector<int>visited(V,0), parent(V, -1);
        parent[0] = 0;
        int sum = 0;
        while(!pq.empty()){
            int wg = pq.top().first;
            int nd = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            if(!visited[nd]){
                visited[nd] = 1;
                sum+=wg;
                for(auto x: adj[nd]){
                   if(!visited[x[0]])pq.push({x[1],{x[0], nd}}),parent[x[0]] = nd;
                }
            }
        }
        
        for(auto x: parent)cout<< x << ' ';
        cout<<endl;
        
        return sum;
    }
};


//#######################################################################
//#######################################################################
------------------------------DSU----------------------------------------
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------G-46. Disjoint Set | Union by Rank | Union by Size | Path Compression--------########
//Tutorial: https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

- When dynamically changing graphs use DSU 

----------------------------------
//Problem: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
int find(int A[],int X)
{
    if(A[X]==X) return X;
    return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	int u = find(A, X);
	int v = find(A, Z);
	if(u==v) return;
	A[u] = v;
}

----------------------------------
- We are making a datastructure here
Disjoing Set working:(TC: O(4alpha))
- Finding Parents
- Finding Union(1. rank, 2. size)

Disjoint set: 
- Helps to find out if nodes in the same component in constant time(kon node kon component er)
- Union (in broad terms this method basically adds an edge between two nodes)
ultimate parent is the boss
path compression -> find parent in change it with ultimate parent

dynamic graphs: Graph that keeps changing


------------
Making Datastructure DSU
Approach: see striver notes
------------

//Disjoint Set Union - By Rank and By Size 
#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    //initialize the values
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    //this will keep finding the ultimate parent of each node
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    //Method1
    //keep updating the tree as nodes are gets added
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    //Method2
    //keep updating the tree as nodes are gets added
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}


//#######################################################################
//#######-------G-47. Kruskal's Algorithm - Minimum Spanning Tree--------########
//Tutorial: https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/
//Problem: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

------------
Approach: 
1. Sort the edges by weight
2. If u,v do not belong to the ultimate same parent, then add in the tree 
If ultimate parent is same donot add
------------

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        vector<pair<int, pair<int, int>> > edges;
        for(int i=0;i<V;i++){
            for(auto x: adj[i]) edges.push_back({x[1], {x[0], i}});
        }
        sort(edges.begin(),edges.end());
        int n = edges.size(), sum = 0;
        DisjointSet ds(V);
        for(int i=0;i<n;i++){
            int n1 = edges[i].second.first;
            int n2 = edges[i].second.second;
            if(ds.findUPar(n1) != ds.findUPar(n2)){
                sum+= edges[i].first;
                ds.unionBySize(n1, n2);
            }
        }
        return sum;
    }
};

//#######################################################################
//#######-------G-48. Number of Provinces - Disjoint Set--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-provinces-disjoint-set-g-48/
//Problem: https://www.geeksforgeeks.org/problems/number-of-provinces/1

------------
DSU
Approach: 
The number of ultimate parents they themselves is the answer
Time Complexity: O(N2)+O(N* 4α) ~ O(N2)+O(N) where N = no. of nodes. 
O(N2) for visiting the adjacency matrix and O(N) for the counting of ultimate parents. 4α is so small that this term can be ignored.
Space Complexity: O(2N), where N = no. of nodes. O(2N) for the two arrays parent and size(or rank) of size N.
------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if( adj[i][j] == 1 ){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){//total parents is they themselves
                ans++;
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-49. Number of Operations to Make Network Connected - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/
//Problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

------------
DSU
Approach: 
if ( Total connected components - 1 <= extra edges) return Total connected components -1
else -1
extra edges: if both the parents are same then it is an extra edge

Time Complexity: O(E*4α)+O(N*4α) where E = no. of edges and N = no. of nodes. The first term is to calculate the number of extra edges and the second term is to count the number of components. 4α is for the disjoint set operation we have used and this term is so small that it can be considered constant.
Space Complexity: O(2N) where N = no. of nodes. 2N for the two arrays(parent and size) of size N we have used inside the disjoint set.
------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        int extra = 0, con = 0;
        DisjointSet ds(n);
        for(int i=0;i<edges.size();i++){
            if( ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1]) ) extra++;
            else ds.unionBySize(edges[i][0], edges[i][1]);
        }
        for(int i=0;i<n;i++){
            if( ds.parent[i] == i ) con++;
        }
        if(extra>=con-1) return con-1;
        else return -1;
    }
};

//#######################################################################
//#######-------G-50. Accounts Merge - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/
//Problem: https://leetcode.com/problems/accounts-merge/description/

------------
DSU
Approach: 
add all edges to corresponding numbers
1. Connect the nodes(strings) 
2. Merge the nodes/mails if same name is found(with the same parent)
3. Print the answer

Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. The first term is for visiting all the emails. The second term is for merging the accounts. And the third term is for sorting the emails and storing them in the answer array.
Space Complexity: O(N)+ O(N) +O(2N) ~ O(N) where N = no. of nodes/indices. The first and second space is for the ‘mergedMail’ and the ‘ans’ array. The last term is for the parent and size array used inside the Disjoint set data structure.

------------



//#######################################################################
//#######-------G-51. Number of Islands - II - Online Queries - DSU--------########
//Tutorial: https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/
//Problem: https://www.geeksforgeeks.org/problems/number-of-islands/1
//https://www.naukri.com/code360/problems/number-of-islands-ii_1266048

------------
DSU
Approach: 
Look if the grid has been used previosuly(use visited array), if so and u,v has different parent then ct--;
vis[n][m] = kon ghortate kaj hoise oita track rakhar jnno visited array, age kaj hoile ar kaj na kora, ager answer print kora

Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries. The term 4α is so small that it can be considered constant.
Space Complexity: O(Q) + O(N*M) + O(N*M), where Q = no. of queries, N = total no. of rows, M = total no. of columns. The last two terms are for the parent and the size array used inside the Disjoint set data structure. The first term is to store the answer.

------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<int>ans;
        vector<vector<int>>vis(n, vector<int>(m));
        int ct = 0;
        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,1,-1};
        for(int i=0;i<operators.size();i++){
            int px = operators[i][0], py = operators[i][1];
            int u = m * px + py;
            if(vis[px][py]==1){
                ans.push_back(ct);
                continue;
            }
            ct++;
            vis[px][py] = 1;
            for(int k=0;k<4;k++){
                int x = px + dx[k];
                int y = py + dy[k];
                int v = m*x + y;
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==1 && ds.findUPar(u) != ds.findUPar(v)){
                    ds.unionBySize(u,v);
                    ct--;
                }
            }
            ans.push_back(ct);
        }
        return ans;
    }
};

//#######################################################################
//#######-------G-52. Making a Large Island - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/
//Problem: https://leetcode.com/problems/making-a-large-island/description/

------------
DSU
Approach: 
1. Using DSU get the size of every component
2. Convert 0 to 1, keep taking the distinct ultimate parents
3. Finally, Keep taking the max answer

Time Complexity: O(N2)+O(N2) ~ O(N2) where N = total number of rows of the grid. Inside those nested loops, all the operations are taking apparently constant time. So, O(N2) for the nested loop only, is the time complexity.
Space Complexity: O(2*N2) where N = the total number of rows of the grid. This is for the two arrays i.e. parent array and size array of size N2 inside the Disjoint set.

------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>&grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {-1,1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int u = i*n + j;
                    for(int k=0;k<4;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int v = x*n + y;
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                            ds.unionBySize(u,v);//a little confused
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>st;
                    for(int k=0;k<4;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int v = x*n + y;
                        if(x>=0 && x<n && y >=0 && y<n && grid[x][y]==1){
                            st.insert(ds.findUPar(v));
                        }
                    }
                    int ct = 1;
                    for(int v: st) ct+= ds.size[v];
                    ans = max(ans, ct);
                } 
            }
        }
        
        ans = max(ans, ds.size[ds.findUPar(0)]);//all are 1
        
        return ans;
    }
};

//#######################################################################
//#######-------G-53. Most Stones Removed with Same Row or Column - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/
//Problem: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

- In connection we use DSU, not traversal techniques

//#######################################################################
//#######-------Swim in rising water--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/swim-in-rising-water/description/



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//####################-------Other Algorithms--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-54. Strongly Connected Components - Kosaraju's Algorithm--------########
//Tutorial: https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/
//Problem: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

SCC -> Strongly Connected Components(kosaraju algo)
Questions: Figure out the number of scc, number of scc
- Only valid for directed graph
pair that is reachable each other == scc

reverse the edges
starting time finishing time
thought: stopping one guy to go to other


------------
Kosarajus Algorithm
Approach/Steps: 
1. Sort all the edges according to the finishing line(by running dfs, putting in stack)
2. Reverse the graph 
3. Do a dfs of connected component

Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.
Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.

------------

class Solution
{   
    void dfs1(int i,vector<bool>&visited,vector<int>adj1[],stack<int>&st){
        visited[i] = 1;
        for(int x: adj1[i]){
            if(!visited[x]) dfs1(x, visited,adj1,st);
        }
        st.push(i);
    }
    void dfs2(int i,vector<bool>&visited,vector<int>adj2[]){
        visited[i] = 1;
        for(int x: adj2[i]){
            if(!visited[x]) dfs2(x, visited,adj2);
        }
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>adj1[V],adj2[V];
        vector<bool>visited(V), visited2(V);
        for(int i=0;i<V;i++){
            for(int x: adj[i]) adj1[i].push_back(x);
        }
        //Sort all the edges according to the finishing line
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs1(i, visited,adj1,st);
        }
        
        //Reverse the graph 
        for(int i=0;i<V;i++){
            for(int x: adj[i]) adj2[x].push_back(i);
        }

        int scc = 0;
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(!visited2[i]) dfs2(i, visited2,adj2), scc++;
        }
        return scc;
    }
};

//#######################################################################
//#######-------G-55. Bridges in Graph - Using Tarjan's Algorithm of time in and low time--------########
//Tutorial: https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/
//Problem: https://leetcode.com/problems/critical-connections-in-a-network/description/

find the edges jegula remove korle component 2 ta hoe jabe

Bridge: the critical part of the graph, if we cut the edges it becomes more than 1 component
The whole graph is a 1 component, After cutting down an edge it should not disconnect

Time of insertion(When going through dfs)
Lowest time of insertion(take the lowest child, and also not the parent itself)

------------
DFS
Approach/Steps: 
1. If cannot reach then that is a bridge 

1. Maintain (Time of insertion + Lowest Time of insertion array) and run a dfs 
For knowing the algo: think(if not able to do see striver note and video)

Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
Space Complexity: O(V+2E) + O(3V), where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(3V) for the three arrays i.e. tin, low, and vis, each of size V.
------------
class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<int>adj[], vector<int>&visited, vector<int>&toi,
        vector<int>&ltoi,vector<vector<int>>&bridges){
        visited[node] = 1;
        toi[node] = ltoi[node] = timer;
        timer++;
        for(auto x: adj[node]){
            if(x==parent) continue;//confused{other than parent->node if there is other paths of reaching parent}
            if(!visited[x]){
                dfs(x, node, adj, visited, toi, ltoi, bridges);
                ltoi[node] = min(ltoi[x], ltoi[node]);
                if(ltoi[x]>toi[node]){//if this is the case, then it cannot traverse back with the paths
                    bridges.push_back({x, node});
                }
            }
            else{
                ltoi[node] = min(ltoi[x], ltoi[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>>bridges;
        vector<int>visited(n,0), toi(n,0), ltoi(n,0);
        dfs(0, -1, adj, visited, toi, ltoi, bridges);
        return bridges;
    }
};

//#######################################################################
//#######-------G-56. Articulation Point in Graph--------########
//Tutorial: https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/
//Problem: https://www.geeksforgeeks.org/problems/articulation-point-1/1

bridges: edges , Articulation Points = Nodes 

Articulation Points of a graph are the nodes on whose removal, the graph breaks into multiple components. 

------------
DFS
Approach/Steps: 
1. 

Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
Space Complexity: O(3V), where V = no. of vertices. O(3V) is for the three arrays i.e. tin, low, and vis, each of size V.
------------



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################-------Finished--------#########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
-------------------------------------------------------------------------
-------------------------------------------------------------------------