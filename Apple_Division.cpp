#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    int w[n+1];
    ll total = 0;
    for(int i=0;i<n;i++){
        cin>>w[i];
        total+=w[i];
    }

    int mini = INT_MAX;
    ll sum = 0; 
    for(int i=0;i<(1<<n)-1;i++){
        sum =  0;
        //check every bit
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                //cout<<w[j]<<" ";
                sum+=w[j];
            }
        }
        ll diff = abs(total - 2*sum);
        if(mini>diff)mini = abs(diff);//karon 2 ta sets =====> [(total-sum)-sum] - ekhan theke 1 ta set er pabo
        //cout<<mini<<endl;
        //cout<<endl;
    }

    cout<<mini<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}