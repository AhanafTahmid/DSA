//https://www.interviewbit.com/problems/painters-partition-problem/

#include <bits/stdc++.h>
using namespace std;
int a;
int b;
int c[100001];

bool ok(int mid){
    int ct = 0;
    int sum = 0;
    for(int i=0;i<10;i++){
        sum+=c[i];
        if(sum>mid) ct++,sum=c[i];
        //cout<< mid <<" " << c[i] << " "<<ct<<endl;
    }
    return ct<=a;
}


void solve(){
    cin>>a;
    cin>>b;
    for(int i=0;i<10;i++){
        cin>>c[i];
        c[i] = c[i] * b;
    }
    int l = *max_element(c,c+a), r = accumulate(c,c+a,0), m;
    while(l+1<r){
        m = (l+r)/2;
        //cout<< m <<endl;
        if( ok(m) ) r = m;
        else l = m;
    }
    cout<< l%10000003 << endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}