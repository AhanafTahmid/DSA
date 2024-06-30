//Insertion Sort algorithm

#include <bits/stdc++.h>
using namespace std;

//My way
void insertion_sort(){
    int n= 5,k=1;
    int ar[100]={2,10,3,1,4};

    //using while loop
    for(int i=0;i<n;i++){
        int j = i;
        while(j>0 && ar[j-1]>ar[j]){//for comaparing index 4, it will go ---> ar[3]>ar[4] hole swap till ar[0]>ar[1], j>=0 avoid for j[-1]>j[0]
            swap(ar[j],ar[j-1]);
            j--;
        }
    }


    
    //using for loop
        for(int i=0;i<n;i++){
            for(int j=i;j>0;j--){
                if(ar[j-1]>ar[j]) swap(ar[j],ar[j-1]);
            }
        }


    

    //sorted array
    for(int i=0;i<n;i++){
        cout<<ar[i]<<endl;
    }


    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)insertion_sort(); 
    return 0;
}