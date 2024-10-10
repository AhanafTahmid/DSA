//DFS
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

//BFS - Kahns Algorithm
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
