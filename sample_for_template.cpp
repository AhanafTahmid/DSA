//Tree

- See notion notes / striver notes for details
- 

Confusions:
1. 

Questions: 


---------------------------------------------------------------------------------------------------------
Striver Tree Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
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


------------------------Theory----------------------------------
//

//


//#######################################################################
//#######-------G-8. Number of Islands | Number of Connected Components in Matrix--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-islands/
//Problem: https://leetcode.com/problems/number-of-islands/description/


2d grid bfs
------------
BFS
Time complexity:
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