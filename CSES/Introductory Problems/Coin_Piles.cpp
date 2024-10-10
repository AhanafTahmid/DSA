#include <bits/stdc++.h>
using namespace std;
//recursion way - got tle on test 2
// void rec(int x,int y){
//     //cout<<x<<y<<endl;
//     if(x==0 && y==0){
//         cout<<"YES"<<endl;
//         return;
//     }
//     else if(x==0 && y!=0){
//         cout<<"NO"<<endl;
//         return;
//     }
//     else if(x!=0 && y==0){
//         cout<<"NO"<<endl;
//         return;
//     }
//     if(x>=y)rec(x-2,y-1);
//     else if(x<y)rec(x-1,y-2);

// }


void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        int maxi = max(x,y);
        int mini = min(x,y);
        if((x+y)%3==0 && maxi<=2*mini)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}