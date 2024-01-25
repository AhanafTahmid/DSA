//https://www.interviewbit.com/problems/allocate-books/
/*
Input: 
4
12 34 67 90
2

Output: 113
*/


//Invariant: 00000011111

#include <bits/stdc++.h>
using namespace std;

int n;
int b;
int l , r, m;
long long ans = 0;
bool ok(int x, int aa[]){
    long long ct = 1, sum = 0;
    for(int i=0;i<n;i++){
        sum+=aa[i];
        if(sum>x){
            sum = aa[i];
            ct++;
        }
        
    }
    return ct<=b;
}

void solve(){
    cin>>n;
    long long r = 0;
    int ar[100000];
    for(int i=0;i<n;i++){
        cin>>ar[i];
        r+=ar[i];
    }
    
    cin>>b;
    if(b>n){
        cout<<-1<<endl;
        return;
    }
    l = *max_element(ar,ar+n), m;

    //1 bar pathanor pore true paile answer 1
    if(ok(l,ar)){
        cout<< l <<endl;
        return;
    }
    while(l+1<r){
        m = (l+r)>>1;
        if( ok(m,ar) ) r = m;
        else l = m;
    }
    cout<< r <<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}