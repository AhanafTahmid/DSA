#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string> ans;
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));

    cout<<ans.size()<<endl;
    for(auto x: ans)cout<<x<<endl;

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}