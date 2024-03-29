//https://www.geeksforgeeks.org/bitwise-sieve/
//https://www.shafaetsplanet.com/?p=855
// Bitwise Sieve of Eratosthene
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
