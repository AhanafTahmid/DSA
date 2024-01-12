//https://leetcode.com/problems/super-pow/submissions/1143009946/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1337;//1337 is not prime, we'll have to find 1337's coprime which is 191*7 = 1140
int coprime_val = 1140;
// a^(b%1140)%1337 = ans

//finding b%1140
ll calculate_b(string b){
    int t = 0;
    ll val = 0 ;
    for(int i=0;i<b.size();i++){
        //val =  (b[i] + val * 10  ) % coprime_val;
        //val =(val + (b[i] - '0') * pow(10,t))%coprime_val;// 35 = for 3 = 3x10e2
        //val+=  ((b[i] - '0') * vv ) % coprime_val;//this will overflow, do modulo after sunmation
        val = ( (b[i] - '0') + val*10 ) % coprime_val;//here, val must be always less than the modulo
    }
    
    return val;
}


ll binpow(ll a,ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%md;
        a = (a * a)%md;
        b >>= 1;
    }
    return res;
}

void solve(){
    int a;
    string b;
    cin>>a>>b;
    //cout<<binpow(a,b)<<endl;
    if(calculate_b(b)==0) cout<< binpow(a,1140);
    else cout<< binpow(a,calculate_b(b));  
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}





///Accetped
class Solution {
public:
    #define ll long long
    int md = 1337;
    int coprime_val = 1140;
    // a^(b%1140)%1337 = ans

    //finding b%1140
    ll calculate_b(vector<int>& b){
        ll val = 0 ;
        for(int i=0;i<b.size();i++){
            val =  (b[i] + val * 10  ) % coprime_val;
        }
        return val;
    }


    ll binpow(ll a,ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a)%md;
            a = (a * a)%md;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(calculate_b(b)==0) return binpow(a,1140);
        else return binpow(a,calculate_b(b));
    }
};
