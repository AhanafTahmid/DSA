//Playlist: https://www.youtube.com/playlist?list=PLw3E7GGpk4-BeiU9991UdBagSq8UlJPFs


//#######-------3rd Video - Find maximum (or minimum) sum of a subarray of size k--------########

/*
Input  : arr[] = {100, 200, 300, 400},  k = 2
Output : 700
------

My sample input:
4
100 200 300 400
2

Output-> 700



//https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

Step-by-step approach:
An Efficient Solution is based on the fact that sum of a subarray (or window) of size k can be obtained in O(1) time using the sum of the previous subarray (or window) of size k. 
Except for the first subarray of size k, for other subarrays, we compute the sum by removing the first element of the last window and adding the last element of the current window.


1. Compute sum of first window of size k
2. Compute sums of remaining windows by removing first element of previous window and adding last element of current window.

*/


// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// void sliding_window(int ar[],int n,int k){
//     int sum = 0;
//     for(int i=0;i<k;i++){
//         sum = sum + ar[i];
//     }
//     int ans = LLONG_MIN;
//     for(int i=k;i<n;i++){
//         sum = sum + ar[i] - ar[i-k];
//         ans = max(ans, sum);
//     }
//     cout<< ans <<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int ar[n+1];
//     for(int i=0;i<n;i++)cin>>ar[i];
//     int k;cin>>k;
//     sliding_window(ar,n,k);
// }


// signed main(){
//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }


//####################################################################################################
//####################################################################################################

//#######-------4th Video - First negative integer in every window of size k--------########

/*
Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

------

My sample input:
5
-8 2 3 -6 10
2

Output-> 
-8 0 -6 -6



//https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

Step-by-step approach:

Queue Approach(We are Working with indices, not with values):
1. First make the initial/first window with k
2. Process rest of the element from k to n
    a. if q is not empty then the element at the front of the queue is the first negative integer
    of the previous window, else the window does not have a negative integer
    b. Remove the elements which are out of this window
    c. Add current negative element at the rear of q if it is a negative integer
3. Print the first negative integer of last window

*/


// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// //using queue
// void sliding_window(int ar[],int n,int k){
//     queue<int>q;
//     for(int i=0;i<k;i++){   
//         if(ar[i]<0) q.push(i);
//     }
//     for(int i=k;i<n;i++){
//         if(q.empty())cout<<0<<" ";
//         else cout<<ar[q.front()]<<" ";

//         while(!q.empty() && q.front()<i-k+1 )q.pop();//remove out of this window values

//         if(ar[i]<0)q.push(i);
//     }

//     if(q.empty())cout<<0<<endl;
//     else cout<<ar[q.front()]<<endl;//Print the first negative integer of last window
// }

// void solve(){
//     int n;cin>>n;
//     int ar[n+1];
//     for(int i=0;i<n;i++)cin>>ar[i];
//     int k;cin>>k;
//     sliding_window(ar,n,k);
// }


// signed main(){
//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }






//####################################################################################################
//####################################################################################################

//#######------- 5th Video - Count Occurrences of Anagrams --------########
//anagrams -> a word formed by rearranging letters. listen - silent

/*
Input : forxxorfxdofr
        for
Output : 3
Explanation : Anagrams of the word for – for, orf, ofr appear in the text and hence the count is 3.

------

My sample input:
forxxorfxdofr
for

Output-> 
3



//https://www.geeksforgeeks.org/count-occurrences-of-anagrams/

Step-by-step approach:


1. Create frequency from the pattern
2. Sliding window approach
   a. iterate over the text and add the frequency of each element
   b. Remove character that went out of window
   c. Compare frequency of two maps, if same then ans++





1. Create an empty frequency map of characters in the word we are looking for.
2. Populate the frequency map created in step 1 with the frequency of each character in the word we are looking for.
3. Initialize a frequency map for the current window of characters in the text.
4. Initialize a count variable to keep track of the number of anagrams found.
5. Use a sliding window approach to iterate over the text.
6. At each iteration, add the current character to the frequency map for the window and remove the character that went out of the window.
7. Compare the frequency maps of the word and the window to check if they are equal.
8. If the frequency maps are equal, increment the count of anagrams found.
9. Return the count of anagrams found.



*/


// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// void sliding_window(string text, string pat){
//     int k = pat.size();
//     int n = text.size();
//     unordered_map<char, int> um,tmp;
//     int ct = 0, ans = 0;
//     //create frequency from the pattern
//     for(auto c: pat){
//         um[c]++;
//     }
//     //Sliding window approach    
//     for(int i=0;i<n;i++){
//         tmp[text[i]]++;
//         // Remove character that went out of window
//         if(i>=k){
//             if(tmp[text[i]]==1)tmp.erase(text[i-k]);
//             else if(tmp[text[i]]>1) tmp[text[i]]--;
//         }
//         // Compare frequency maps
//         if(i>=k-1 && um==tmp)ct++;
//     }

//     cout<< ct <<endl;

// }

// void solve(){
//     string text;cin>>text;
//     string pat;cin>>pat;
//     sliding_window(text,pat);
// }


// signed main(){
//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }







//####################################################################################################
//####################################################################################################

//#######------- 6th Video - Sliding Window Maximum (Maximum of all subarrays of size K) --------########

/*
Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation:Maximum of 1, 2, 3 is 3
            Maximum of 2, 3, 1 is 3
            Maximum of 3, 1, 4 is 4
            Maximum of 1, 4, 5 is 5
            Maximum of 4, 5, 2 is 5 
            Maximum of 5, 2, 3 is 5
            Maximum of 2, 3, 6 is 6           
------

My sample input:
9
1 2 3 1 4 5 2 3 6
3

Output-> 
3 3 4 5 5 5 6


//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

Step-by-step approach:
- We are working with indices

1. Create a deque to store first K elements. Add the greatest element index in deque(add in decreasing order)
2. Run loop for rest of the window
   a. Print the front element of the deque.(front e always maximum rakhbo)
   b. Remove out of all window indices from deque
   c. Add the current val indices in the dequeue(add in decreasing order)

*/


// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// //Time complexity is O(N) using deque
// void sliding_window(int ar[], int n, int k){
//     deque<int> dq;
//     for(int i=0;i<k;i++){
//         while(!dq.empty() && ar[dq.back()]<ar[i]){
//             dq.pop_back();
//         }
//         dq.push_back(i);
//     }
    
//     for(int i=k;i<n;i++){
//         cout<< ar[dq.front()]<<" ";
//         //remove out of all window indices
//         while(dq.front()<=i-k)dq.pop_front();
//         // Add the current val indices in the dequeue
//         while(!dq.empty() && ar[dq.back()]<ar[i]){
//             dq.pop_back();
//         }
//         dq.push_back(i);
//     }
//     cout<< ar[dq.front()]<<endl;

// }

// void solve(){
//     int n;cin>>n;
//     int ar[n+1];
//     for(int i=0;i<n;i++)cin>>ar[i];
//     int k;cin>>k;
//     sliding_window(ar, n, k);
// }


// signed main(){
//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }





//####################################################################################################
//####################################################################################################

//#######------- 7th Video - Longest sub-array having sum k (variable-size sliding window) --------########
//**********Can you do it using map?????????

//onno problem e window size check kori but ekhane sum check korbo

//finding the largest window size of target sum

/*
Input: arr[] = { 10, 5, 2, 7, 1, 9 }, k = 15
Output: 4
Explanation: The sub-array is {5, 2, 7, 1}.
         
------

My sample input:
6
10 5 2 7 1 9
15
Output-> 
4 (5,2,7,1)


//https://www.geeksforgeeks.org/longest-sub-array-sum-k/

Step-by-step approach:
i = start of window , j = end of window

1. Apply two pointers, i = to delete the sum>target values
2. If sum==target, j++, update answer
3. If sum<target , j++ only
4. ans = (j-i+1)




This approach won’t work for negative numbers,(we might use dequeue )

1. calculation, in this case doing the sum.
2. drawing results out of calculations. in this case, extracting the size of the window if the sum reaches K (target).

3. adjusting the window. in this case, increasing the size of the window if the sum is less than K(target) or decreasing the size if the sum is greater than K(target).



The approach is to use the concept of the variable-size sliding window using 2 pointers
Initialize i, j, and sum = 0. If the sum is less than k just increment j, if the sum is equal to k compute the max 
and if the sum is greater than k subtract the ith element while the sum is greater than k.


i : we will use i to delete the indexes where sum > x
j : our normal index

----------------------------------------------------------------------
Q. Will the discussed approach work with negative numbers in the array?
A. No. 
Because let's say in the given array [4,1,1,1,2,3,5] when we found the sum within the window to be greater than the desired value 5 (i=0, j=2 -> [4,1,1]), we started reducing the size of the window by doing i++. 
Here we assumed that once the sum of elements within the window becomes greater than 5 then increasing the window size will just add to the sum and hence we will not attain the sum 5 again. 
This is true when all the element are positive and hence reducing the window size by doing i++ makes sense. But this might not be true if array also contains negative numbers. Consider the array [4,1,1,-2,1,5], here we would have found the sum to be greater than 5 for i=0, j=2 and if we would have now started reducing the window size by doing i++, we would have missed the potential subarray (i=0, j=4).
In short, the discussed approach will not work with array having negative numbers.


*/


// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long

// //Time complexity is O(N) 
// void sliding_window(int ar[], int n, int target){
//     //finding the largest window size of target sum
//     int sum = 0,ans = 0;
//     for(int i=0,j=0;j<n;){
//         sum+=ar[j];
//         if(sum==target){
//             //update answer
//             ans = max(ans, j-i+1);
//             //then increase j
//             j++;
//         }
//         else if(sum<target)j++;
//         else if(sum>target){
//             //while chalabo jotokkhn sum<=x hocche na
//             while(sum>target){
//                 sum-=ar[i];
//                 i++;
//             }
//             if(sum==target){
//                 //update answer
//                 ans = max(ans, j-i+1);
//             }
//             j++;
//         }

//     }
//     cout<< ans <<endl;

// }

// void solve(){
//     int n;cin>>n;
//     int ar[n+1];
//     for(int i=0;i<n;i++)cin>>ar[i];
//     int target;cin>>target;
//     sliding_window(ar, n, target);
// }


// signed main(){
//     int t=1;
//     //cin >> t;
//     while(t--)solve(); 
//     return 0;
// }


//use map method to handle negative numbers

//....the method(to be continued) ----------------------------------------


//####################################################################################################
//####################################################################################################

//#######------- 10th Video - Find the longest substring with k unique characters in a given string --------########



/*
Input: Str = “aabbcc”, k = 1
Output: 2
Explanation: Max substring can be any one from {“aa” , “bb” , “cc”}.
         

Input: Str = “aabbcc”, k = 2
Output: 4
Explanation: Max substring can be any one from {“aabb” , “bbcc”}.

------

My sample input:
aabbcc
2
Output-> 
4


//https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/

Step-by-step approach:






*/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//Time complexity is O(N) 
void sliding_window(int ar[], int n, int target){
    

}

void solve(){
    int n;cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++)cin>>ar[i];
    int target;cin>>target;
    sliding_window(ar, n, target);
}


signed main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
