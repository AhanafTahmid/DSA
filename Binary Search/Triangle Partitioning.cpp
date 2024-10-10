//https://lightoj.com/problem/triangle-partitioning
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// void solve(){
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         double a,b,c,r;
//         cin>> a >> b >> c >> r;
//         double ans = a * sqrt(r/(r+1)); 
//         cout<< fixed << setprecision(7);
//         cout<<"Case "<<i<<": "<< ans <<endl;
//     }
// }

double ab,bc,ca,r;
bool ok(double x){
    //area of abc
    double s = (ab + bc + ca )/2;
    double abc = (sqrt(s*(s-ab)*(s-bc)*(s-ca)));
    
    //area of ade
    double ae = (ca*x)/ab;
    double de =  (bc*x)/ab;
    double ss = (x + ae + de)/2;

    double ade_vol = (sqrt(ss*(ss-x)*(ss-ae)*(ss-de)));

    return ade_vol > (r*(abc-ade_vol));
    //return ade_vol > (r*abc/(1+r));
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>> ab >> bc >> ca >> r;
        double l = 0, r = ab, m;
        for(int i=0;i<=100;i++){
            m = (l+r)/2.0;
            if(ok(m)) r = m;
            else l = m;
        }
        cout<< fixed << setprecision(10);
        cout<<"Case "<<i<<": "<< r <<endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}