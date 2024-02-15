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


Output-> 
3



//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

Step-by-step approach:






*/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void sliding_window(string text, string pat){
    int k = pat.size();
    int n = text.size();
    unordered_map<char, int> um,tmp;
    int ct = 0, ans = 0;
    //create frequency from the pattern
    for(auto c: pat){
        um[c]++;
    }
    //Sliding window approach    
    for(int i=0;i<n;i++){
        tmp[text[i]]++;
        // Remove character that went out of window
        if(i>=k){
            if(tmp[text[i]]==1)tmp.erase(text[i-k]);
            else if(tmp[text[i]]>1) tmp[text[i]]--;
        }
        // Compare frequency maps
        if(i>=k-1 && um==tmp)ct++;
    }

    cout<< ct <<endl;

}

void solve(){
    string text;cin>>text;
    string pat;cin>>pat;
    sliding_window(text,pat);
}


signed main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//####################################################################################################
//####################################################################################################