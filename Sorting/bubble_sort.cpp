//Array sorting
// Swapping every element
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int ar[]={44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int n = sizeof(ar)/sizeof(ar[0]);//the size of the array
    int noc=0,noi=0,i,j,t,sw;
    for(int i=0;i<n;i++){
        sw=false;
        cout<<endl<<"pass"<<i+1<<endl;
        for(int j=0;j<n-i-1;j++){
            noc++;
            if(ar[j]>ar[j+1]){
                t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
                noi++;
                sw = true;
                cout<<ar[j]<<" "<<ar[j+1]<<endl;
            }
            
        }

        if(sw==false){
            cout<<"Number of Comparison: "<<noc<<endl;
            cout<<"Number of Interchange: "<<noi<<endl;
            break;
        }
    }
    
    
    cout<<"The sorted array is: "<<endl;

    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}