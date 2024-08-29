#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve(){
    int n;
    cin>>n;
    long long num = n*(n+1)/2;//total sum of an inclusive number from 1 to n
    if(num%2!=0) cout<<"NO"<<endl;//28 hole , 14+ 14 kora jabe, else kora jabe na
    else{
        cout<<"YES"<<endl;
        //mod = 0 and mod = 3    (mod = 1,2 te no hobe)
        ll main_mod = n%4;
        if(main_mod==0){
            ll nn = n/2;
            cout<<nn<<endl;
            for(int i=1;i<=n;i++){
                if(i%4==1 || i%4==0)cout<<i<<" ";
            }
            cout<<nn<<endl;
            for(int i=1;i<=n;i++){
                if(i%4==2 || i%4==3)cout<<i<<" ";
            }
            cout<<endl;
        }

        else if(main_mod==3){
            ll nn = n/2;
            cout<<nn+1<<endl;
            cout<<"1 2 ";
            for(int i=4;i<=n;i++){
                if(i%4==3 || i%4==0)cout<<i<<" ";
            }
            cout<<endl;
            cout<<nn<<endl;
            cout<<"3 ";
            for(int i=4;i<=n;i++){
                if(i%4==2 || i%4==1)cout<<i<<" ";
            }

        }
    } 
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


