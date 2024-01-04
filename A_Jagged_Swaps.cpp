#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int &val : a) {
        cin >> val;
    }
    cout << (a[0] == 1 ? "YES\n" : "NO\n");
}


int main(){

    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}