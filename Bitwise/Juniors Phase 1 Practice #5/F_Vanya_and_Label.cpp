//In biwise always use () brackets, cause bitwise has low precedance, (v&i)
//Steps:
//1. first make the string, then do the following
//2. if bit is equal to 0, then we can have 3 different optinos of this bit in our pair of words: 0&1, 1&0, 0&0, else we can have only one option: 1&1.
//every bit e jotota shunno, totota pair * 3
//example: 0&1, 1&0, 0&0 -> 3 vabe sajaite parbo ekta number
//editorial: https://codeforces.com/blog/entry/45181

// 1 2 3 4
// 0 0 0 1
// total combination could be 1,2 - 2,3 - 1,3

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve(){
    int st[200]={};
    for(int i=0;i<=9;i++){
        st['0'+i] = i;
    }
    for(int i=10;i<=35;i++){
        st['A'+(i-10)] = i;
    }
    for(int i=36;i<=61;i++){
        st['a'+(i-36)] = i;
    }
    st['-'] = 62;
    st['_'] = 63;

    int ans = 1;
    string s;cin>>s;
    int n = s.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            if(!(st[s[i]] & (1<<j))) ans = (ans * 3)%mod;
        }
    }
    cout<< ans <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}