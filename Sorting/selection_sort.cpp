//Selection Sort algorithm.

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n = 5;
    int ar[100]={33,12,3,1,4};
    int min = ar[0];
    int minIndex = 0;
    for(int i=0;i<n-1;i++){
        min = ar[i];
        for(int j=i+1;j<n;j++){
            if(min>=ar[j]){
                min = ar[j];
                minIndex = j;
            }
        }

        //now swapping with index, swapping with min does not work
        if(ar[i]>=min){
            int t = ar[i];
            ar[i] = ar[minIndex];
            ar[minIndex] = t;
        }

        // for(int x=0;x<n;x++){
        //     cout<<ar[x]<<" ";
        // }
        // cout<<endl;
    }
    for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}