//1. When making prefix sum, start from 1 index, keep 0 index as 0 or the first value

int pg[100000]={},ps[100000]={};
for(int i=1;i<=n;i++){
    pg[i] = pg[i-1]+ (s[i-1]=='G');
    ps[i] = ps[i-1]+ (s[i-1]=='S');
}    


//////////
#include <bits/stdc++.h>
using namespace std;

//Sample code - My way

void solve(){
    long long int n,q;
	cin>>n>>q;
	long long ar[100000],p[10000]={};//long long ar[],p[] here is must, might give WA becaue of this
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		//p[0]=ar[0];
		p[i]=p[i-1]+ar[i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<p[y]-p[x-1]<<endl;
		
	}
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}