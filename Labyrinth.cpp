#include <bits/stdc++.h>
using namespace std;


char c[1010][1010];
int vis[1010][1010];
vector<int> ans;
int ct = 0;
int n,e;

int distan[110][110];//distance counting


int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};
char dd[]={'R','L','D','U'};

void bfs(int x, int y) {
    queue<pair<int,int>>q;
    q.push({x,y});
    //cout<<q.front().first<<q.front().second<<c[x][y];
    vis[x][y] = 1;//parent node visited kore dicchi
    distan[x][y] = 0;
    while(!q.empty()) {//queue-r vitor child node visit krtesi
        pair<int,int> u = q.front();
        int x1 = u.first;
        int y1 = u.second;
        q.pop();

        if(c[x][y]=='B')

        //charpashe jawa
        for(int i=0;i<4;i++){
            //cout<<x1+fx[i];
            //cout<<y1+fy[i]<<endl;
            int nx = x1+fx[i];//new x coordinate in 2 direction
            int ny = y1+fy[i];//new y coordinate in 2 direction
            //cout<<nx<<" "<<ny<<" "<<dd[i]<<endl;
            //vis[nx][ny]==0
            
            if(c[nx][ny]=='B'){
                //cout<<"Yes"<<endl;
                //cout<<distan[nx][ny]<<endl;
                //return;
            }
            // every coordinate must be within: nx>=0 && nx<n && ny>=0 && ny<e
            if(nx>=0 && nx<n && ny>=0 && ny<e && vis[nx][ny]==0 && c[nx][ny]=='.'){
                //cout<<nx<<nx;
                q.push({nx,ny});
                vis[nx][ny]=1;
                if(nx>=0)
                distan[nx][ny]= distan[x1][y1] + 1;//distance new = distance old + 1
                
                //cout<<distan[nx][ny]<<endl;
            }
            
            //cout<<q.front().first<<q.front().second<<endl;
            
            // if(x1+fx[i]<0 || x1+fx[i]>n || y1+fy[i]<0 || y1+fy[i]>e){

            //     vis[x][y] = 1;
            // }
        }
    }
    printf("\n");
}


void solve(){
    cin>>n>>e;
    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            cin>>c[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            if(c[i][j]=='A'){
                bfs(i,j);
            }
        }
        cout<<endl;
    }

   // if(bfs)

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}