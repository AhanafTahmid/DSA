//Merge sort algorithm

#include <bits/stdc++.h>
using namespace std;


void merge(int ar[],int l,int m, int h){
    vector<int> temp;

    //low...mid
    //mid+1...high
    int i = l;      // Initial index of left subarray
    int j = m + 1;  // Initial index of right subarray

    // Merging the two arrays
    while (i <= m && j <= h) {
        if (ar[i] <= ar[j]) {
            temp.push_back(ar[i]);
            i++;//oi position er kaj shesh, tai ++
        } else {
            temp.push_back(ar[j]);
            j++;
        }
    }

    //if there are elements on the left still remains
    while (i <= m) {
        temp.push_back(ar[i]);
        i++;
    }

    //if there are elements on the right still remains
    while (j <= h) {
        temp.push_back(ar[j]);
        j++;
    }

    // moving all elements to an array / Copy elements from temp back to ar[]
    for (int k = l; k <= h; k++) {
        ar[k] = temp[k-l];//
    }


}


void merge_sort(int ar[], int l,int h){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    merge_sort(ar,l,m);//left half
    merge_sort(ar,m+1,h);//right half
    
    //function to merge and sort the array
    merge(ar,l,m,h);
   
}


int main(){

    int t=1;
    //cin >> t;
    while(t--){
        int ar[100]={2,1,23,45,22,3,6};
        int n = 7;
        int l = 0;
        int h = 6;
        int mid = (l+h)/2;

        merge_sort(ar,0,n-1); //high and low
        for(int i=0;i<n;i++){
            cout<<ar[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}