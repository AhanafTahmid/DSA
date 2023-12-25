#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    long double ans = 0;

    vector<long long> x(n);
    vector<long long> y(n);
    for(long long i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(long long i=0;i<n-1;i++){
        ans+=(x[i]*y[i+1]-x[i+1]*y[i]);
        //cout<<ans<<endl;
    }
    ans+=(x[n-1]*y[0]-x[0]*y[n-1]);// last coordinate with the first coordinate after traversing the whole polygon
    
    //cout<<2*(abs(ans)/2)<<endl;//2a priting korte bolse -> abs(ans)/2 = polygon
    cout<<fixed << setprecision(0) << abs(ans)<<endl;


}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}