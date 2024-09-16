//sieve of eratosthenes for prime chekcking
#include <bits/stdc++.h>
using namespace std;
int isPrime(int n){
    if(n<=1){
        return false;
    }
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int p=2;p*p<=n;p++){
        if(prime[p]==1){
            for(int i=p*p;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }
    return prime[n];
}

void solve(){
    int n;
    cin>>n;
    if(isPrime(n))cout<<"Prime"<<endl;
    else cout<<"Not Prime"<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


//#######-------Version 2--------########
const int lim = 100000;
vector<bool>primes(lim, 0);//bool is of 1 byte, use this instead of int,which is of 4 bytes
void sieve(){
    primes[0] = primes[1] = 1;//0 and 1 is not prime
    for(int i=2;i*i<=lim;i++){
        if(!primes[i]){
            for(int j=i*i;j<=lim;j+=i){
                primes[j] = 1;
            }
        }
    }
}
