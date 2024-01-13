#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    int ar[100100];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int x;
    for(int i=0;i<q;i++){
        cin>>x;
        int l = -1;//a[l] < x
        int r = n;//a[r] >= x
        while(l+1<r){
            int m = (l+r)/2;
            if(ar[m]<x){
                l = m;
            }
            else{
                r = m;
            }
        }
        cout<<r+1<<endl;
    }

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}