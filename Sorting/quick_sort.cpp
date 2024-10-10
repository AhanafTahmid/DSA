#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=arr[high];//pivot is the last element
    int i=(low-1);//start the loop from the low
    
    for(int j=low;j<=high-1;j++){
        //If current element is smaller than the pivot
        if(arr[j]<pivot){
        //Increment index of smaller element
        i++;
        swap(arr[i],arr[j]);}
    }
    swap(arr[i+1],arr[high]);//swap pivot with the lowest+1 index
    return (i+1);
}
           
void quickSort(int arr[],int low,int high){
    // when low is less than high
    if(low>=high) return;
        
    int pi=partition(arr,low,high);
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
             
 
int main() {
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}