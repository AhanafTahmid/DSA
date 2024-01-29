//https://www.spoj.com/problems/PIE/

#include <bits/stdc++.h>
using namespace std;
int np, f;
long double p[1000000];
bool ok(double m){
    int ff = 0;
    for(int i=0;i<np;i++){
        ff+=(int)(p[i]/m);
    }
    return ff>=f;
}

void solve(){
    
    cin>> np >> f;
    f++;
    for(int i=0;i<np;i++){
        cin>>p[i];
    }
    sort(p,p+np);

    for(int i=0;i<np;i++){
        p[i] = p[i] * p[i] * 3.14159265358979323846264338327950;
    }
    

    long double l = 0, r =  p[np-1],m;
    for(int i=0;i<100;i++){
        m = (l+r)/2;
        if( ok(m) ) l = m;
        else r = m;
    }
    cout<< l <<endl;
}


int main(){

    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}