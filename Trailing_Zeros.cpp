#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans = 2;
    int i = 1;
    int ct = 0;

    //First method
    while(1){

        if(ans == 0){
            cout<<ct<<endl;
            break;
        }
        ans = n/pow(5,i);
        ct+=ans;
        i++;


    }


    //Another method
    int j = 5;
    while(1){

        if(ans == 0){
            cout<<ct<<endl;
            break;
        }
        ans = n/j;
        ct+=ans;
        j*=5;
    }


}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}