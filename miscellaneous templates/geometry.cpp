#include <bits/stdc++.h>
using namespace std;
void solve(){
    
    complex<long double> a = {4,2};
    complex<long double> b = {1,2};
    complex<long double> p;
    p = (conj(a)*b).imag();// 6
    cout<<p<<endl;
   

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}