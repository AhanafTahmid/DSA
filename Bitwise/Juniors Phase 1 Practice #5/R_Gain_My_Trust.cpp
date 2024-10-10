//Steps: print the lexicographically the smallest kth values after generating all subsets of the string

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    string s;cin>>s;
    int k;cin>>k;
    int n = s.size();
    vector<string> vs;
    for(int i=0;i<(1<<n);i++){
        string tmp = "";
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                tmp+=s[j];
            }
        }
        vs.push_back(tmp);
    }
    sort(vs.begin(),vs.end());
    cout<< vs[k-1] <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}