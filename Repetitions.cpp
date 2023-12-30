#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int l = s.size(); 
    vector<int> c;
    int ct = 1;
    for(int i=0;i<l;i++){
        if(s[i]==s[i+1]){
            ct++;
        }
        else{
            c.push_back(ct);
            ct = 1;
        }
    }

    sort(c.begin(),c.end(),greater<int>());
    cout<<c[0];
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}