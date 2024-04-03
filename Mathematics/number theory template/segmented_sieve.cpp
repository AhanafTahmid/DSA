//Segmented Sieve

//if there is range in problem, use segmented sieve
//Range will always be in between 10^6 to 10^7, will not be given more than that

/*
Steps
1. Count primes of the sqrt of the total length using normal sieve
2. Total area of the prime vector should be = r-l+1,0
3. We will start our loop from ----- (low/the_prime_number)*the_prime_number   ------ (l/x)*x;
4. we will keep marking the prime multiples as non prime




Main section of code where segmenting is occuring:



void seg_sieve(int l, int r){
    vector<int> isPrime(r-l+1,0);
    
    for(auto x: primes){
        //int start = max(x * x, (l + x - 1) / x * x);
        int start = (l/x)*x;
        if(start<l) start+=x;
        //making the factors non prime
        for(int i=start;i<=r;i+=x){
            //if(i!=x) -> prime k non prime korbo na
            if(i!=x)isPrime[i-l] = 1;
        }
    }

    //appending the primes a vector

    for(int i=0;i<isPrime.size();i++){
        if(!isPrime[i]) cout<< i+l <<" ";//ans++;
    }
    cout<<endl;

}

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<int> primes;

void precalc_sieve(int x){
    vector<int>pr(x+1,0);

    pr[0] = pr[1] = 1;//0 and 1 is not prime
    
    for(int i=2;i*i<=x;i++){
        if(!pr[i]){
            for(int j=i*i;j<=x;j+=i){
                pr[j] = 1;
            }
        }
    }
    for(int k=2;k<=x;k++){
        if(!pr[k]) primes.push_back(k);
    }
}

void seg_sieve(int l, int r){
    if(l==1)l++;
    vector<int> isPrime(r-l+1,0);
    
    for(auto x: primes){
        int start = (l/x)*x;
        if(start<l) start+=x;
        for(int i=start;i<=r;i+=x){
            if(i!=x)isPrime[i-l] = 1;
        }
    }

    for(int i=0;i<isPrime.size();i++){
        if(!isPrime[i]) cout<< i+l <<" ";
    }
    cout<<endl;

}

void solve(){
    int l, r, ans = 0;
    cin>> l >> r;
    int sq = sqrt(r);
    precalc_sieve(sq);
    seg_sieve(l,r);
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}