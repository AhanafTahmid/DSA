//Binary Exponentiation

#include <bits/stdc++.h>
using namespace std;
#define ll long long


//#######-------Version 1--------########
//Without using val, calling recursion function again and again

//a^b
//For Even: 3^8 = 3^4 * 3^4
//For Odd : 3^9 = 3^4 * 3^4 * 3
int bin_expo(int a,int b){
    if(b==0) return 1;
    //ll val = bin_expo(n/2);
    else if(b%2==0) return bin_expo(a,b/2) * bin_expo(a,b/2);
    else if(b%2==1) return bin_expo(a,b/2) * bin_expo(a,b/2)  * a;//3^9 = 3^4 * 3^4 * 3
}

void solve(){
    cout<<bin_expo(2,5);
}

//#######-------Version 2--------########


int bin_expo(int a,int b){
    if(b==0) return 1;
    int val = bin_expo(a,b/2);
    if(b%2==0) return val * val;
    else if(b%2==1) return val * val * a;
}

void solve(){
    cout<<bin_expo(3,5);
}


//#######-------Version 3 - Using while loop--------########

ll bin_expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            //cout<<res<<endl;
            res = res * a;
        cout<<a<<endl;
        a = a * a;
        b >>= 1;
    }
    return res;
}

res = 1 * 2;//2
a = 2 * 2;//4
b = 7/2;//3(aro 2 bar hobe)

a = 4 * 4;//16
b = 3/2;//1(aro 1 bar hobe)

res = 2*16
a = 16*16//256
b = 1/2//0 get out of the loop



//Mainnnnnnnnnn*************//#######-------Version 4 --------########



//Exponentiation Codes

//Binary Exponential using recursion
ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


//non recursive
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}




