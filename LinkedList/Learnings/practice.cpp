#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct Node
{   
    int data;
    Node *next;
    Node *prev;
    Node(int data1,Node *next1, Node*prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

void solve(){
    Node *x = new Node(111,nullptr, nullptr);
    cout<< (*x).data <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}