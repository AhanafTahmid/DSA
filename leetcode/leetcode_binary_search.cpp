//https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many

//- If there is monotonicity then we use binary search
//monotonicity is the fundament of our binary search algorithm
// Think what will be the left and right
// When making invariants think about a big number, wheather it is true or false for that
// Search space does not matter if you think correctly, what matter is thinking about the conditions 
// If possible make your own testcases
// - First see the time complexity, then find a approach




//#######-------1--------########
//https://leetcode.com/problems/sqrtx/

/*
69. Sqrt(x) [Easy]

Input: 4
Output: 2
Input: 8
Output: 2

*/
// #include <bits/stdc++.h>
// using namespace std;
// int n=10;
// bool ok(double mid){
//     return mid*mid<=n;
// }

// void solve(){
    
//     double l = 1, r = n , m;
    
//     for(int i=0;i<60;i++){
//         m = (l+r)/2;
//         //cout<< m << endl;
//         if( ok(m) ) l = m;
//         else r = m;
//     }
//     cout<< floor(r) <<endl;

// }


// int main(){

//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }




//#######-------2--------########
//https://leetcode.com/problems/search-insert-position/description/

///111111000000

/*

Input: [1,3,5,6], 5
Output: 2
Input: [1,3,5,6], 2
Output: 1

*/



//This approach was not accepted

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll ar[1000100];
// int target = 5;
// bool ok(int mid){
//     return ar[mid]<=target;
// }

// void solve(){
//     int n;
//     cin>> n;
//     for(int i=0;i<n;i++){
//         cin>>ar[i];
//     }

//     ll l = 0, r = n, m;
    
//     while(l+1<r){
//         m = (l+r)>>1;
//         //cout<< m <<endl;
//         if( ok(m) ) l = m;
//         else r = m;
//     }
//     //cout<< l << " "<< r <<endl;
//     if(r == n) cout<< n <<endl;
//     else if(l==0) cout<< 1 <<endl;
//     else if(ar[l]==target) cout<< l <<endl;
//     else cout<< r  <<endl;

// }


// int main(){

//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }





//#######-------3--------########
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/


//Ekhane weight er man hobe search space

// class Solution {
// public:
//     int ok(vector<int>&w, int mid, int days){
//         int sum = 0, ct =1;
//         for(int i=0;i<w.size();i++){
//             sum+=w[i];
//             if(sum>mid){
//                 ct++;
//                 sum = w[i];if(sum>mid) return false;
//             }
//         }
//         return ct<=days;
//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//         int r = 0;
//         for(int i=0;i<weights.size();i++){
//             r+=weights[i];
//         }
//         int l = *min_element(weights.begin(),weights.end()), m;
//         while(l+1<r){
//             m = (l+r)/2;
//             if( ok(weights,m,days) ) r = m;
//             else l = m;
//         }
//         return r;
//     }
// };





//#######-------4--------########
//https://leetcode.com/problems/split-array-largest-sum/


// Split the array and check it the ct is equal to k


// class Solution {
// public:
//     bool ok(int mid, vector<int> & a, int k){
//         int s = 0, ct = 1;
//         for(int i=0;i<a.size();i++){
//             s+=a[i];
//             if(s>mid){
//                 ct++;
//                 s = a[i];
//                 if(s>mid) return false;
//             }
//         }
//         return ct<=k;

//     }

//     int splitArray(vector<int>& nums, int k) {
//         int r =0;
//         for(int i=0;i<nums.size();i++){
//             r+=nums[i];
//         }
//         int l = *min_element(nums.begin(),nums.end()), m;

//         while(l+1<r){
//             m = (l+r)/2;
//             if( ok(m,nums, k) ) r = m;
//             else l = m;
//         }
//         return r;
//     }
// };




//#######-------5--------########
//https://leetcode.com/problems/koko-eating-bananas/

//Got stuck for overflow, but enjoyed it

// class Solution {
// public:
//     bool ok(vector<int>&p, int h, int mid){
//         long long ct = 0;
//         for(int i=0;i<p.size();i++){
//             if(mid>p[i]) ct++;
//             else ct+=(ceil(static_cast<long double>(p[i])/static_cast<long double>(mid)));

//             if(ct>h) return false;
//         }
//         return ct<=h;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int l = 0,m;
//         long long r = 1e9;
        
//         if(piles.size()==1 && h>=(l+r)/2) return 1;

//         while(l+1<r){
//             m = l + (r-l)/2;
//             if( ok(piles, h, m) ) r = m;
//             else l = m;
//         }
//         return r;
//     }
// };


//#######-------6--------########
//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

//Invariant: 0000011111


// #include <bits/stdc++.h>
// using namespace std;
// int n,m,k;
// int b[10000];

// bool ok(int mid){
//         int tc = 0, ct = 0;
//         for(int i=0;i<n;i++){
//             if(b[i]<=mid) ct++;
//             else ct = 0;

//             if(ct==k){
//                 tc++;
//                 ct = 0;
//             }
//         }
//         return tc>=m;
// }

// void solve(){
//     cin>> n >> m >> k;
//     for(int i=0;i<n;i++){
//         cin>>b[i];
//     }
//     int l = 0, r = INT_MAX, m;
//     while(l+1<r){
//         m = (l+r)>>1;
//         if( ok(m) ) r = m;
//         else l = m;
//     }
//     cout<< r << endl;
// }


// int main(){

//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }




// Integer overflow hoise
//For that reason: if(k>bloomDay.size()/m) instead of if(k*m>bloomDay.size())



// class Solution {
// public:
//     bool ok(vector<int>&b, int m, int k, int mid){
//         int tc = 0, ct = 0;
//         for(int i=0;i<b.size();i++){
//             if(b[i]<=mid) ct++;
//             else ct = 0;

//             if(ct==k){
//                 tc++;
//                 ct = 0;
//             }
//         }
//         return tc>=m;
//     }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         //long long noans = static_cast<long long>(m)*k;
//         if(k>bloomDay.size()/m) return -1;
//         long long l = 0, r = LONG_MAX , mid;
//         while(l+1<r){
//             mid = l+(r-l)/2;
//             if( ok(bloomDay, m , k, mid) ) r = mid;
//             else l = mid;
//         }
//         return r;
//     }   
// };




//#######-------7--------########
//https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

//Tutorial: https://youtu.be/N-7biZf7a0I



// class Solution {
// public:
//     bool ok(int mid, int m, int n, int k){
//         int ct = 0;
//         for(int i=1;i<=m;i++){
//             ct+= min((mid/i), n);
//         }
//         return ct>=k;
//     }

//     int findKthNumber(int m, int n, int k) {
//         int l = 1, r = m*n, mid;
//         while(l+1<r){
//             mid = l + (r-l)/2;
//             if( ok(mid, m, n, k) ) r = mid;
//             else l = mid;
//         }
//         return r;
//     }

// };

//#######-------8--------########
//https://leetcode.com/problems/find-k-th-smallest-pair-distance/
