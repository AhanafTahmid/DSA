#include <bits/stdc++.h>
using namespace std;
#define ll long long

int md = 1e9+7;

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

// Function that returns nth Fibonacci number
ll fib(ll n)
{
	ll F[2][2] = { { 1, 1 }, { 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);

	return (F[0][0])%md;
}

// Optimized version of power() in method 4
void power(ll F[2][2], ll n)
{
	if (n == 0 || n == 1)
		return;
	ll M[2][2] = { { 1, 1 }, { 1, 0 } };

	power(F, n / 2);
	multiply(F, F);//F matrix * F matrix, if power is even

	if (n % 2 != 0)
		multiply(F, M);//F matrix * M matrix, if power is odd
}

void multiply(ll F[2][2], ll M[2][2])
{
	ll x = (F[0][0] * M[0][0])%md + (F[0][1] * M[1][0])%md;
	ll y = (F[0][0] * M[0][1])%md + (F[0][1] * M[1][1])%md;
	ll z = (F[1][0] * M[0][0])%md + (F[1][1] * M[1][0])%md;
	ll w = (F[1][0] * M[0][1])%md + (F[1][1] * M[1][1])%md;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void solve(){
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}