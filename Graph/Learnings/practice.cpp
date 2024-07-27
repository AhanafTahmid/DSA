#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
	vector<tuple<int, string, string>> t = {{10,"23", "names"}, {11,"2", "names2"}};
	for(int i=0;i<t.size();i++){
		auto [x, y , z] = t[i];
		cout<< x << ' ' << y << ' '  << z <<endl;
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;
	//cin >> t;
	while(t--)solve(); 
	return 0;
}