//steps
//1. Think about odd sum, and even sum and also make the xor as large as possible
//it will overflow when 1<<60, use 1<<59

//Another approach, output: 2 \n xor ' ' xor + allsum

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n;cin>>n;
    int xorr = 0, sum = 0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        xorr ^= x; 
        sum+=x;
    }
    
    if(2*xorr == sum) cout<< 0 << endl<<endl;
    else{
        int v;
        if(sum%2)v = (1LL << 59) | 1;
        else v = (1LL << 59);
        xorr = xorr ^ v;
        int other = ((xorr*2) - (sum+v))/2;
        cout<< 3 <<endl;
        cout<< v << ' ' << other << ' ' <<other<<endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}