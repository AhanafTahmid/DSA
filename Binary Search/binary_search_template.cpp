//####################################################
//#######-------Built In Templates--------############
//####################################################
int x=lower_bound(v.begin(),v.end(),right)-v.begin();
int x=upper_bound(v.begin(),v.end(),right)-v.begin();

//it's returning an address
//lower bound position
int *lpos = lower_bound(ar,ar+n,lx);
int po = lpos - ar;
cout<<po<<endl;    
cout<<lpos<<endl;    
cout<<ar<<endl;
//or....
int lpos = (lower_bound(ar,ar+n,lx))-ar;
cout<<lpos<<endl;


//####################################################
//#######-------Range in Binary Search--------########
//####################################################
while(l+1<r)
//####################################################
//#######-------Lower Bound--------###################
//####################################################

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> ar(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0;i<q;i++){
        cin>>x;
        int l = -1;
        int r = n;
        while(l+1<r){
            int mid = (l+r)/2;
            if(ar[mid]<=x){
                l = mid;
            }
            else{
                r = mid;
            }

        }
        cout<<l+1<<endl;

    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


//####################################################
//#######-------Upper Bound--------###################
//####################################################

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    int ar[100100];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int x;
    for(int i=0;i<q;i++){
        cin>>x;
        int l = -1;//a[l] < x
        int r = n;//a[r] >= x
        while(l+1<r){
            int m = (l+r)/2;
            if(ar[m]<x){
                l = m;
            }
            else{
                r = m;
            }
        }
        cout<<r+1<<endl;
    }

}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//####################################################
//###----to find all the numbers between 2 numbers, we can use lowerbound and upperbound---####
//####################################################

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ar[100000];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);

    int q;
    cin>>q;
    int lx,ux;
    for(int i=0;i<q;i++){
        cin>>lx>>ux;
        //lower bound position
        int lpos = (lower_bound(ar,ar+n,lx))-ar;
        //lower bound position
        int upos = (upper_bound(ar,ar+n,ux))-ar;
        cout<<upos-lpos<<" ";
    }

    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}