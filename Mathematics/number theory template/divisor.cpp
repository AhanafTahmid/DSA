

void divisors(int n){
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
			cout << i << " ";
			if(i != n/i) cout << n/i << " ";
		}
    }
}

int main(){
	divisors(36);
    return 0;
}

//####################################################################################
//####################################################################################
//####################################################################################

//#######-------Divisor Count--------########
//tutorial: https://youtu.be/x9KMLQa6G5w

//prime factors * prime factors
// ans *= (ct+1); ->>>>> (a+1)*(b+1)

void div_count(){
    int n;cin>>n;
    int ans = 1;
    for(int i=2;i<=n;i++){
        int ct = 1;
        while(n%i==0){
            ct++;
            n/=i;
        }
        ans = ans * ct;
    }
    cout<< ans  <<endl;
}


//#######-------Divisor Count(Miller rabin)--------########

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// Utility function to do modular exponentiation.
// It returns (x^y) % p
int power(int x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result
	x = x % p; // Update x if it is more than or
				// equal to p
	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that d*2 = n-1
// for some r >= 1
bool miillerTest(int d, int n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	int a = 2 + rand() % (n - 4);

	// Compute a^d % n
	int x = power(a, d, n);

	if (x == 1 || x == n-1)
	return true;

	// Keep squaring x while one of the following doesn't
	// happen
	// (i) d does not reach n-1
	// (ii) (x^2) % n is not 1
	// (iii) (x^2) % n is not n-1
	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	// Return composite
	return false;
}

// It returns false if n is composite and returns true if n
// is probably prime. k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
	// Corner cases
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given number of 'k' times
	for (int i = 0; i < k; i++)
		if (!miillerTest(d, n))
			return false;

	return true;
}



void solve(){
    int n;cin>>n;
    int ans = 1;
    int tmp = n;
    for(int i=2;i*i*i<=n;i++){
        int ct = 1;
        while(n%i==0){
            ct++;
            n/=i;
        }
        //cout<< ct <<' '<<n<<endl;
        //ans = ans * (pow(i, ct)-1)/(i-1);
        ans = ans * ct;
    }
    if(isPrime(n, 4)) ans = ans * 2;
    else if(isPrime(n*n, 4)) ans = ans * 3;
    else if(n!=1) ans = ans * 4;
    cout<< ans  <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


//####################################################################################
//####################################################################################
//####################################################################################

//#######-------Divisor summation--------########

// a^n+1 - 1 / (a-1) formula

void div_sum(){
    int n;cin>>n;
    int ans = 1;
    for(int i=2;i<=n;i++){
        int ct = 1;
        while(n%i==0){
            ct++;
            n/=i;
        }
        ans = ans * (pow(i, ct)-1)/(i-1);
        cout<< ans <<endl;
    }
    cout<< ans <<endl;
}