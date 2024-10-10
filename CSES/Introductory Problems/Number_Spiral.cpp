#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll q;
    cin>>q;
    ll x,y;
    ll c = 0;
    ll start = 0;
    for(ll i=0;i<q;i++){
        c = 1;
        cin>>x>>y;
        ll maxi = max(x,y);
        ll mini = min(x,y);
        if((x == maxi && x%2==0) || (y == maxi && y%2==1)){
            start = maxi*maxi;//if 4, start from 16, 4*4, start decreasingly
            while(1){
                if(c==mini){
                    cout<<start<<endl;
                    break;
                }
                start--;
                c++;
            }
        }
        

        else if((y == maxi && y%2==0) || (x== maxi && x%2==1)){
            start = (maxi-1)*(maxi-1) + 1;//if 4, start from 3*3+1= 10, start increasingly
            while(1){
                if(c==mini){
                    cout<<start<<endl;
                    break;
                }
                start++;
                c++;
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