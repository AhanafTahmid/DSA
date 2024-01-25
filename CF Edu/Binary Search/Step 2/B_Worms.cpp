//https://codeforces.com/contest/474/problem/B
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>> n;
    int a[n+1];
    int p[n+1];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0) p[0] = a[0];
        else p[i] =  p[i-1] + a[i] ;
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int q;
        cin>> q;
        int ans = lower_bound(p,p+n,q) - p ;
        cout<< ans + 1 <<endl;

    }


    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}