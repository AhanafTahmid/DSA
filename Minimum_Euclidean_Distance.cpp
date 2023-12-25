#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    //
    long long a[30005],b[30005]; //getting runtime error
    long long dis = 0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    //long long m;
    //long double m = 1e19+10;
    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            
            dis = abs(a[i]-a[j+1])* abs(a[i]-a[j+1]) + abs(b[i]-b[j+1])* abs(b[i]-b[j+1]);
            if(m>dis) m = dis;
            //cout<<dis<<endl;
        }
    }
    cout<<m<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}