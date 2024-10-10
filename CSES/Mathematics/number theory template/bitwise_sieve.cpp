//https://www.geeksforgeeks.org/bitwise-sieve/
//https://www.shafaetsplanet.com/?p=855
// Bitwise Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

bool ifnotPrime(int prime[], int x){
	return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

bool makeComposite(int prime[], int x){
	prime[x/64] |= (1 << ((x >> 1) & 31));
}

void bitWiseSieve(int n)
{
	int prime[n/64];
	memset(prime, 0, sizeof(prime));

	for (int i = 3; i * i <= n; i += 2) {
		if (!ifnotPrime(prime, i))
			for (int j = i * i, k = i << 1; j < n; j += k)
				makeComposite(prime, j);
	}

	printf("2\n");

	for (int i = 3; i <= n; i += 2){
        if (!ifnotPrime(prime, i)){
            printf("%d\n", i);
        }
    }
		
        
			
            
}

// Driver code
int main()
{
	int n = 10000000;
	bitWiseSieve(n);
	return 0;
}


//#######-------Another version--------########
//https://www.shafaetsplanet.com/?p=855

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int lim = 1e8;

int N =lim,prime[lim]; 
int status[3200000];

bool check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

void bitwise_sieve(){
    int i, j; 
    for( i = 3; i * i <= N; i += 2 ) 
    {
        if(check(status[j>>5],i & 31)==0){
            for( j = i*i; j <= N; j += (i<<1)){
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
    printf("%lld\n",2);
    for(i=3;i<=N;i+=2){
        if(check(status[j>>5],i & 31)==0)printf("%d\n",i);
    }
}

void solve(){
    bitwise_sieve();
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}