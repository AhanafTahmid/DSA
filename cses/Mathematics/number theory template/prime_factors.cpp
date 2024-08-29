//Prime factors, Prime factorization

//O(sqrt(n))
void pf(int n){
    vector<int> prime_factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n = n/i;
        }
    }
    if(n>1)prime_factors.push_back(n);
    // for(auto x: prime_factors)cout<<x<<" ";
    // cout<<endl;
}


