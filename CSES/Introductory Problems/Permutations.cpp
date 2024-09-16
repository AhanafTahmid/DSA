#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n==1) cout<<1<<endl;
    else if(n<=3) cout<<"NO SOLUTION"<<endl;
    else{
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}