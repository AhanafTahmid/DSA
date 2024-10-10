#include <bits/stdc++.h>
using namespace std;

void divisors(int n,int ct){
    for(int i = 1; i*i <= n; i++)
		if(n % i == 0){
			//cout << i << " ";
            ct++;
			if(i != n/i) ct++;;
		}
    cout<<ct<<endl;
}

void solve(){
    int n;
    cin>>n;
    int ct = 0;
    for(int i=0;i<n;i++){
        ct = 0;
        int a;
        cin>>a;
        divisors(a, ct);
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}