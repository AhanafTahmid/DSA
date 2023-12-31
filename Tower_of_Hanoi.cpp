#include <bits/stdc++.h>
using namespace std;
//n = number of disks
//s = source
//d = destination
//aux = auxilary, helper

void toh(int n, int s, int d, int aux){
    if(n==0)return;
    //solving for n-1 disks, moving n-1 disk in the aux, from source to destination
    toh(n-1,s,aux,d);
    cout<<s<<" "<<d<<endl;//printing source and destination
    //moving largest disk to the destination, from auxilary to destination using source
    toh(n-1,aux,d,s);

}

void solve(){
    int disks;
    cin>>disks;
    cout<<pow(2,disks)-1<<endl;
    toh(disks,1,3,2);

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}