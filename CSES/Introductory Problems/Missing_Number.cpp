#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ar[910000];
    int fr[900000]={0};
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        fr[ar[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(fr[i]==0){
            cout<<i<<endl;
        }
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}