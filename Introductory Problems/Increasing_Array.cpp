#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    long long ans = 0;
    for(int i=0;i<n-1;i++){
        if(ar[i]>ar[i+1]){
            ans+=(ar[i]-ar[i+1]);
            ar[i+1]+=(ar[i]-ar[i+1]);
        }
        //cout<<ar[i]<<" ";
    }
    cout<<ans<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}