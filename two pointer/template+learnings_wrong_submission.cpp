//Playlist: https://www.youtube.com/playlist?list=PL0G2Ga9ALv6n7OD06Q7cjOMxKKCefG2B1


Instead of trying all possible subsets we can try two pointer
We can decrease 1 loop with two pointer, if it is N*N we can make it N
if it is N*N*N we can make it N*N, if N^4 we can make it N^3


- In two pointer, the first thing is sorting, then move from left and right
- In many two pointer problems, we can just use hashing or binary search
- when see leftmost and rightmost, think about two pointer
- Be careful with while(l<r) must be like this, if while(l<=r) then it will fall in the same index thus you will get error

//####################################################################################################
//####################################################################################################
//#######-------Find sum of pairs whose sum is equal to x--------########

/*
Input: 
5
1 3 4 5 2
9
Output:
Yes

*/

// Time complexity: O(nlogn) -> nlogn for sorting the array and O(N) for two_pointer

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

bool two_pointer(int ar[],int x, int n){
    sort(ar,ar+n);//first have to sort the array to use two pointer
    int l = 0, r = n-1;
    //one pair cannot be the same
    while(l<r){
        int sum = ar[l]+ar[r];
        if(sum==x)return true;
        else if(sum>x) r--;
        else if(sum<x) l++;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++)cin>>ar[i];
    int x;cin>>x;
    bool ans = two_pointer(ar,x,n);
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}


signed main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}

//####################################################################################################
//####################################################################################################
//#######-------Find the pair in Array Whose sum is closest to X--------########

/*
Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
Output: 22 and 30


6
10 22 28 29 30 40
54
-------
//https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

Efficient Approach:- An efficient solution can find the pair in O(n) time. The following is a detailed algorithm. 

1) Initialize a variable diff as infinite (Diff is used to store the 
   difference between pair and x).  We need to find the minimum diff.
2) Initialize two index variables l and r in the given sorted array.
       (a) Initialize first to the leftmost index:  l = 0
       (b) Initialize second  the rightmost index:  r = n-1
3) Loop while l < r.
       (a) If  abs(arr[l] + arr[r] - sum) < diff  then 
           update diff and result 
       (b) If(arr[l] + arr[r] <  sum )  then l++
       (c) Else r--   

*/

void two_pointer(int ar[],int x, int n){
    int l1 = 0, l2 = 0;
    sort(ar,ar+n);
    int l = 0, r = n-1, ans = LLONG_MAX;
    while(l<r){
        int sum = ar[l]+ar[r];
        if(abs(sum-x)<ans) ans = min(ans,abs(sum-x)), l1 = l, l2 = r;

        if(sum>x) r--;
        else l++;
    }
    //The closest pair is
    cout<< ar[l1] << " and " << ar[l2] <<endl;
    //The difference is
    cout<< ans <<endl;
    //The sum is
    cout<< ar[l1]+ar[l2] <<endl;
}



//####################################################################################################
//####################################################################################################
//#######-------Find the closest pair from two sorted arrays--------########


/*
Input: arr1[] = {1, 4, 5, 7};
arr2[] = {10, 20, 30, 40};
x = 32
Output: 1 and 30
------

My sample input:
4
1 4 5 7
10 20 30 40
32
Output-> 1 and 30



//https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

Step-by-step approach:

Initialize a variable diff as infinite (Diff is used to store the difference between pair and x). We need to find the minimum diff.
Initialize two index variables l and r in the given sorted array.
(a) Initialize first to the leftmost index in ar1: l = 0
(b) Initialize second the rightmost index in ar2: r = n-1
Loop while l< length.ar1 and r>=0
(a) If abs(ar1[l] + ar2[r] – sum) < diff then update diff and result
(b) If (ar1[l] + ar2[r] < sum ) then l++
(c) Else r–
Print the result.



*/


// Time complexity: O(n) -> without the sorting things, just finding the two closest

void two_pointer(int a[],int b[],int x, int n){
    sort(a,a+n);
    sort(b,b+n);
    int l = 0, r = n-1, sum = 0, ans = LLONG_MAX;
    int l_res,r_res;
    //while till l<lenth of first array
    while(l<n && r>=0){
       sum = a[l]+b[r];
       if(abs(sum-x)<ans){
           ans = abs(sum-x);
           l_res = l;
           r_res = r;
       }

       //move to right or left
       if(sum<x) l++;
       else if(sum>x) r--;

       //cout<< a[l_res] <<" = "<<b[r_res]<<endl;
    }   

    cout<< a[l_res] <<" = "<<b[r_res]<<endl;
}


//####################################################################################################
//####################################################################################################
//#######-------Find all triplets(3 elements) with zero sum--------########

//take the first index, second index, and the last index and keep increasing second index or keep decreasing last index


/*
Input: arr[] = {0, -1, 2, -3, 1}
Output: (0 -1 1), (2 -3 1)
Explanation: The triplets with zero sum are 0 + -1 + 1 = 0 and 2 + -3 + 1 = 0  

--------------

My sample input:
5
0 -1 2 -3 1

Output: 
0 -1 1 
2 - 3 1
or
-3 1 2
-1 0 1



//https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/


Follow the steps below to implement the idea:

Sort the array in ascending order.
Traverse the array from start to end.
For every index i, create two variables l = i + 1 and r = n – 1
Run a loop until l is less than r if the sum of array[i], array[l] and array[r] is equal to zero then print the triplet and break the loop
If the sum is less than zero then increment the value of l, by increasing the value of l the sum will increase as the array is sorted, so array[l+1] > array [l]
If the sum is greater than zero then decrement the value of r, by decreasing the value of r the sum will decrease as the array is sorted, so array[r-1] < array [r].


*/


// Time complexity: O(n*n)




void two_pointer(int ar[],int n){
    sort(ar,ar+n);
    for(int i=0;i<n;i++){
       //do two pointer here
        int l = i+1, r = n-1, x = ar[i], sum = 0;
        while(l<r){
            sum = x + ar[l] + ar[r];
            if(sum>0)r--;//if sum is positive r--
            else if(sum<0)l++;//if sum is negative l++

            else if(sum==0){
                printf("%lld %lld %lld\n",x,ar[l],ar[r]);
                //break;//there would be one triplet in one sequence
                l++;//or we can increase l, and decrease r
                r--;
            }
       }
    }
}



//Using hashing
//using unoredered_set
// Time complexity: O(n*n) [searching in unordered set in O(1)]

void hashing(int ar[],int n){
    //sort(ar,ar+n);
    for(int i=0;i<n-1;i++){//i=n-1 cause we are doing j=i+1
       //do two pointer here
        //int l = i, r = n-1, x = ar[i], sum = 0;
        unordered_set<int> us;//for every iteration it will be a new set

        for(int j=i+1;j<n;j++){
            int sum = ar[i] + ar[j];
            if(us.find(-sum)!=us.end()){//duita mile jeta thakbe tar ultata khujbo
                //ase
                printf("%lld %lld %lld\n",ar[i],ar[j], -sum);
            }
            us.insert(ar[i]);
            us.insert(ar[j]);
        }
    }
}


//####################################################################################################
//####################################################################################################

//#######-------Find a triplet that sum to a given value--------########

//take the first index, second index, and the last index and keep increasing second index or keep decreasing last index


/*
Input: array = {12, 3, 4, 1, 6, 9}, sum = 24; 
Output: 12, 3, 9 
Explanation: There is a triplet (12, 3 and 9) present 
in the array whose sum is 24. 


My sample input:
6
12 3 4 1 6 9
24

Output: 
12 3 9


//https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

Step-by-step approach:

Sort the given array.
Loop over the array and fix the first element of the possible triplet, arr[i].
Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
If the sum is smaller than the required sum, increment the first pointer.
Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.


*/

//Using hashing
//first in unordered_map or unordered_set, we don't have to sort in this method
// if we have to find the indices also using unordered_map is a good idea
// if we don't have to find the indices we can just use unordered_set


*************(Not possible mone hocche)SEE if it possible in O(N) using hashing (find all the pairs and check the pairs) -> obviously possible

void hashing(int ar[], int n, int x){
    for(int i=0;i<n-1;i++){
        unordered_map<int, int> um;
        for(int j=i+1;j<n;j++){
            int sum = ar[i] + ar[j];
            if(um.find(x-sum)!=um.end()){
                printf("%lld %lld %lld",ar[i],ar[j],x-sum);
            }
            um.insert({ar[i], j});
            um.insert({ar[j], j});
        }
    }
}



//do in pure two pointer -> O(N*N)
void two_pointer(int ar[], int n, int x){
    sort(ar,ar+n);
    for(int i=0;i<n-2;i++){
        int l = i+1, r = n - 1, sum = 0;
        while(l<r){
            sum = ar[l] + ar[r] + ar[i];
            if(sum==x){
                printf("%lld %lld %lld",ar[i],ar[l],ar[r]);
                break;//else if disi bole break must dewa lagbe
            }

            if(sum<x)l++;
            else if(sum>x)r--;//else dile break dewa lagto na
        }
    }

}






//####################################################################################################
//####################################################################################################

//#######-------Find four elements that sum to a given value (4Sum) | Set 1 (n^3 solution)--------########

/*
Input: array = {10, 2, 3, 4, 5, 9, 7, 8}, X = 23
Output: 3 5 7 8
Explanation: Sum of output is equal to 23, i.e. 3 + 5 + 7 + 8 = 23.


My sample input:
8
10 2 3 4 5 9 7 8
23

Output:
2 3 8 10
2 4 7 10
2 4 8 9
2 5 7 9
3 4 7 9
3 5 7 8





//https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
//https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/

Step-by-step approach:

Sort the input array. 
Fix the first element as A[i] where i is from 0 to n–3. After fixing the first element of quadruple, fix the second element as A[j] where j varies from i+1 to n-2. Find remaining two elements in O(n) time, using the method 1 of this post 

*/

//(((((((((((A llittle complicated)))))))))))
//Using Hashing -> Time complexity: O(n^2+logn)-> O(n^2) 

void hashing(int ar[], int n, int x){
    unordered_map<int, pair<int,int> > um;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            um[ ar[i] + ar[j] ] = {i,j};
        }
    }

    // for(auto [x,y]:um){
    //     cout<<x<<" "<<y.first<<" "<<y.second<<endl;
    // }
    //traverse all the pairs and search
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum = ar[i] + ar[j];
            //traversing all the pairs
            if(um.find(x-sum)!=um.end()){
                pair<int,int> pp = um[x-sum];//koita x-sum er value ase khujtese + unique
                //if they are distinct they are OK
                if(pp.first!=i && pp.first!=j && pp.second!=i && pp.second!=j){
                    printf("%lld %lld %lld %lld\n",ar[i],ar[j],ar[pp.first],ar[pp.second]);
                    break;
                }
            }
        }
    }
}


//Using Hashing -> Time complexity: O(n^3).
void hashing(int ar[], int n, int x){
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            unordered_set<int> us;//it will an empty set everytime
            for(int k=j+1;k<n;k++){
                int sum = ar[i] + ar[j] + ar[k];
                if(us.find(x-sum)!=us.end()){
                    printf("%lld %lld %lld %lld\n",ar[i],ar[j],ar[k],x-sum);
                }
                //us.insert(ar[i]);
                //us.insert(ar[j]);
                us.insert(ar[k]);//just add the last one, or it will add the duplicates
            }
        }
    }
}


//Using two pointer -> Time complexity: O(n^3 + nlogn) [nlogn for sorting] so tc is O(N^3)
void two_pointer(int ar[], int n, int x){
    sort(ar,ar+n);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            //do two pointer here
            int l = j+1, r = n-1, sum = ar[i]+ar[j];
            while(l<r){
                //printf("%lld %lld %lld %lld\n",ar[i],ar[j],ar[l],ar[r]);
                if(sum+ar[l]+ar[r]==x){
                    printf("%lld %lld %lld %lld\n",ar[i],ar[j],ar[l],ar[r]);
                    l++;
                    r--;
                }
                else if(sum+ar[l]+ar[r]<x)l++;
                else if(sum+ar[l]+ar[r]>x)r--;
            }
        }
    }
}


//####################################################################################################
//####################################################################################################

//#######-------A. Favorite Sequence--------########
//https://codeforces.com/problemset/problem/1462/A

/*

Input:
6
7
3 4 5 2 9 1 1
4
9 2 7 1
11
8 4 3 1 2 7 8 7 9 4 2
1
42
2
11 7
8
1 1 1 1 1 1 1 1


Output:
3 1 4 1 5 9 2 
9 1 2 7 
8 2 4 4 3 9 1 7 2 8 7 
42 
11 7 
1 1 1 1 1 1 1 1 

*/

void two_pointer(int ar[], int n){
    int l = 0, r = n-1;
    while(l<r){
        cout<<ar[l]<<" "<<ar[r]<<" ";
        l++;
        r--;
    }
    if(n%2)cout<<ar[r]<<endl;
    else if(!(n%2))cout<<endl;
}

//####################################################################################################
//####################################################################################################

//#######-------A. Sereja and Dima--------########
//https://codeforces.com/problemset/problem/381/A

/*

Input:
4
4 1 2 10

Output:
12 5


*/

//keep track of who is taking the value now, and just implement the two pointer

void two_pointer(int ar[], int n){
    int l = 0, r = n-1;
    int s1 = 0, s2 = 0;
    int f = 0;
    while(l<r){
       if(ar[l]<ar[r] && f == 0) s1+=ar[r],r--, f = 1;
       else if(ar[l]>ar[r] && f==0) s1+=ar[l],l++, f = 1;

       else if(ar[l]<ar[r] && f == 1) s2+=ar[r],r--, f = 0;
       else if(ar[l]>ar[r] && f == 1 ) s2+=ar[l],l++, f = 0;
    }
    if(!(n%2)) cout<< s1 <<" " << s2+ar[r] <<endl;
    else cout<< s1+ar[l] <<" " << s2 <<endl;
}


//####################################################################################################
//####################################################################################################


//#######-------Find a triplet such that sum of two equals to third element--------########


//take the first index, second last index, and the last index and keep decreasing second last index or keep increasing the first index and keep comparing with the last index


/*
Input : {5, 32, 1, 7, 10, 50, 19, 21, 2}
Output : 21, 2, 19


My sample input:
9
5 32 1 7 10 50 19 21 2

Output: 
21 2 19
2 5 7


//https://www.geeksforgeeks.org/find-triplet-sum-two-equals-third-element/

Step-by-step approach:
Sort the given array first.
Start fixing the greatest element of three from the back and traverse the array to find the other two numbers which sum up to the third element.
Take two pointers j(from front) and k(initially i-1) to find the smallest of the two number and from i-1 to find the largest of the two remaining numbers
If the addition of both the numbers is still less than A[i], then we need to increase the value of the summation of two numbers, thereby increasing the j pointer, so as to increase the value of A[j] + A[k].
If the addition of both the numbers is more than A[i], then we need to decrease the value of the summation of two numbers, thereby decrease the k pointer so as to decrease the overall value of A[j] + A[k].


*/


void two_pointer(int ar[], int n){
    sort(ar,ar+n);
    for(int i=n-1;i>-1;i--){
        //int l = i+1, r = n-1, x = ar[i];
        int l = 0, r = i-1, x = ar[i];
        while(l<r){
            int sum = ar[l] + ar[r];
            if(sum==x){
                printf("%lld %lld %lld\n",x,ar[l],ar[r]);
                l++;
                r--;
            } 
            else if(sum<x) l++;
            else if(sum>x) r--;
       }
    }
}




//####################################################################################################
//####################################################################################################

//#######-------C. Three Parts of the Array--------########
//https://codeforces.com/contest/1006/problem/C

/*

Input:
5
1 3 1 1 4

Output:
5

*/


//Just move through left or through right, keep summing and check if s1==s2, if so keep the answer

void two_pointer(int ar[], int n){
    int l = 0, r = n-1, ans = 0;
    int s1 = ar[l], s2 = ar[r];
    while(l<r){
        if(s1==s2) ans = s1, l++, r--, s1+=ar[l],s2+=ar[r];
        else if(s1<s2)l++,s1+=ar[l];
        else if(s1>s2)r--,s2+=ar[r];
    }
    cout<< ans <<endl;
}

//####################################################################################################
//####################################################################################################

//#######-------A. Broken Keyboard--------########
//https://codeforces.com/contest/1251/problem/A

/*

Input:
4
a
zzaaz
ccff
cbddbb

Output:
a
z

bc

*/


//Approach: almost two pointer method: keep moving till the last same element using j, and in the main loop if (j-i)%2==1 then insert the element


//almost two_pointer
void two_pointer(string s){
    set<char> ans;
    int ln = s.size();
    for(int i=0,j=0;i<ln;i=j){
        while(j<ln && s[i]==s[j]) j++;
        if( (j-i)%2) ans.insert(s[i]);
    }

    for(auto x: ans)cout<< x;
    cout<<endl;
}

//normal method
void solve(){
    string s;cin>>s;
    s+='0';
    set<char> ans;
    int ln = s.size()-1;
    for(int i=0;i<ln;i++){
        if(s[i]==s[i+1])i++;
        else ans.insert(s[i]);
    }
    for(auto x: ans)cout<<x;
    cout<<endl;
}

//####################################################################################################
//####################################################################################################






