#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    //cross product
    long long val =  (x2-x1)*(y3-y2)  -   (y2-y1)*(x3-x2);
    if(val==0)cout<<"TOUCH"<<endl;
    else if(val<0) cout<<"RIGHT"<<endl;
    else cout<<"LEFT"<<endl;
}


int main(){

    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}