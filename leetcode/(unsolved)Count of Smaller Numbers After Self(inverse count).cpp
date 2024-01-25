//Merge sort

//Brute Force
//O(N*N)

// #include <bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     int a[n+1];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int ct = 0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             if(a[i]>a[j]) ct++;
//         }
//         cout<<ct<<endl;
//         ct  = 0;
//     }

// }


// int main(){

//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }





//Merge sort algorithm
//O(N*logn)


#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
map<int,int> mp;
int ct = 0;
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

        } 
        //right is smaller
        else {
            //              count[arr[i].second]+=r-j+1;

            //mp[ar[i]] = (m-i+1);
            ct+=(m-i+1);
            //mp[ar[i]] = ct++;
            //ct+=(m-i+1);
            //cout<<ct<<" "<<ar[i]<<endl;
            //cout<<ar[i]<<" "<<ar[j]<<endl;
            
            //ct+=(h-j+1);
            //mp[ar[i]]++;
            //ans.push_back(m-i+1);
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
        //cout<<ar[k]<<" ";
    }
    //cout<<endl;

    // for(auto x: ans)cout<<x<<" ";
    // cout<<endl;
    //cout<<ct<<endl;
    
   
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
        //int ar[100]={2,1,23,45,22,3,6};
        int ar[] = {2,1,4,3,10};
        int n = 5;
  
        merge_sort(ar,0,n-1); //high and low
        // for(int i=0;i<n;i++){
        //     cout<<ar[i]<<endl;
        // }
        // cout<<endl;

        // for(auto [x,y]: mp){
        //     cout<<x<<" "<<y<<endl;
        // }
        // cout<<ct<<endl;

        // for(auto x: ans){
        //     cout<<x;
        // }

        cout<<ct<<endl;

    }
    return 0;
}