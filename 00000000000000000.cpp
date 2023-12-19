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
