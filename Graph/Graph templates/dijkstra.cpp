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