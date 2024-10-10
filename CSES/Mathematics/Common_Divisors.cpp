#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> num(n);
    int mxval = 0;
    int fr[1000001]={};
    for(int i=0;i<n;i++){
        cin>>num[i];
        fr[num[i]]++;
    }

    int mx = 1;
    int ans;
    int st = 1e6;
    for(int i=st;i>=1;i--){
        ans = 0;
        for(int j=i;j<=st;j+=i){
            ans+=fr[j];
        }
        if(ans>=2){
            cout<<i<<endl;   
            return;
        }  
    }   

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}




