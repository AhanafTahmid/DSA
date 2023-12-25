#include <bits/stdc++.h>
using namespace std;
void isPrime(long long n, long long k){

    vector<long long> ar;
    for(long long i=2;i<=n;i++){
        
        bool prime[n+1];
        memset(prime,true,sizeof(prime));

        for(long long p=2;p*p<=i;p++){
            if(prime[p]==1){
                for(long long j=p*p;j<=i;j+=p){
                    prime[j] = false;
                }
            }
        }
        //cout<<prime[i]<<" "<<i<<endl;
        if(prime[i]) ar.push_back(i);
    }


    if(k>=ar.size()){
        //print all
        for(auto x: ar){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else{
        for(long long m=k;m<ar.size();m++){
            cout<<ar[m]<<" ";
        }
        cout<<endl;
    }
    





    
    // return prime[n];
}

void solve(){
    long long n,k;
    cin>>n>>k;
    isPrime(n,k);
    // if(isPrime(n))cout<<"Prime"<<endl;
    // else cout<<"Not Prime"<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}