//Adjacency List
#include <bits/stdc++.h>
using namespace std;
void adjacency_list(){
    int v,e;//v=vertices, e = edges
    cin>>v>>e;
    vector<int> graph[N];//can be done like this also
    vector<vector<int>> graph(v + 1); // 2d vector array
    for(int i=1;i<=e;i++){
        int v1,v2;//vertex 1, vertex 2
        cin>>v1>>v2;
        //graph[v1][v2]=1;
        //graph[v2][v1]=1;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }



    //Display the graph
    cout << "Adjacency List:" << endl;

    // Displaying the adjacency list
    for (int i = 1; i <= v; i++) {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }



}


int main(){

    int t=1;
    //cin >> t;
    while(t--)adjacency_list(); 
    return 0;
}


//#########################################################################
//#########################################################################

//Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;
void adjacency_matrix(){
    int v,e;//v=vertices, e = edges
    cin>>v>>e;
    int graph[v+1][v+1]={};
    for(int i=1;i<=e;i++){
        int v1,v2;//vertex 1, vertex 2
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;//for undirected graph, it is 2 way
    }



    //Display the graph
    cout << "Adjacency Matrix:" << endl;

    // Displaying the adjacency matrix
    for (int i = 1; i <=v; i++) {
        for (int j = 1; j <=v; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)adjacency_matrix(); 
    return 0;
}

