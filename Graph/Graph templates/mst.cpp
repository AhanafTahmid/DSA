//PRIMS ALGORITHM
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

---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
//Kruskal's Algorithm

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