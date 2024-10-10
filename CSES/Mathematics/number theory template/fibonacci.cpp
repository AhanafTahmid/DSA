//Sequence followed here: 0,1,1,2,3,5,8,13,21...

//fibonacci using dp -> O(N)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100];
ll fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-2) + fib(n-1);
}

void solve(){
    memset(dp,-1,sizeof(dp));
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



//#######-------Binet formula of fibonacci number--------########
//Works only upto n<71
//0,1,2,3,5,8,13,21,34,55

#define ll long long

ll binet(ll n) 
{ 
	double phi = (1 + sqrt(5)) / 2; 
	return round(pow(phi, n) / sqrt(5)); 
} 

ll binet_2(ll n){
    return (pow((1 + sqrt(5)),n) - pow((1 - sqrt(5)),n))/ (pow(2,n) * sqrt(5));
}




//#######-------Using Matrix Exponentiation--------######## O(logn)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

// Function that returns nth Fibonacci number
ll fib(ll n)
{
	ll F[2][2] = { { 1, 1 }, { 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
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
	ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

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