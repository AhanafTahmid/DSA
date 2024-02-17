//Playlist: https://www.youtube.com/playlist?list=PLw3E7GGpk4-BeiU9991UdBagSq8UlJPFs



- We can make O(N*N) in O(N) using sliding window
- We have to print (size - k+1) numbers[in fixed size window]
- there could be a possible answer in a window in sliding window
- in variable size window we use map/unorederd map a lot
- array -> subarray thakbe
- string -> substring thakbe

//####################################################################################################
//####################################################################################################




//#######-------3rd - Find maximum (or minimum) sum of a subarray of size k--------########

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


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void sliding_window(int ar[],int n,int k){
    int sum = 0;
    for(int i=0;i<k;i++){
        sum = sum + ar[i];
    }
    int ans = LLONG_MIN;
    for(int i=k;i<n;i++){
        sum = sum + ar[i] - ar[i-k];
        ans = max(ans, sum);
    }
    cout<< ans <<endl;
}

void solve(){
    int n;cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++)cin>>ar[i];
    int k;cin>>k;
    sliding_window(ar, n, k);
}


signed main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}





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

//using queue
void sliding_window(int ar[],int n,int k){
    queue<int>q;
    for(int i=0;i<k;i++){   
        if(ar[i]<0) q.push(i);
    }
    for(int i=k;i<n;i++){
        if(q.empty())cout<<0<<" ";
        else cout<<ar[q.front()]<<" ";

        while(!q.empty() && q.front()<i-k+1 )q.pop();//remove out of this window values

        if(ar[i]<0)q.push(i);
    }

    if(q.empty())cout<<0<<endl;
    else cout<<ar[q.front()]<<endl;//Print the first negative integer of last window
}


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


//Time complexity is O(N) using deque
void sliding_window(int ar[], int n, int k){
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && ar[dq.back()]<ar[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for(int i=k;i<n;i++){
        cout<< ar[dq.front()]<<" ";
        //remove out of all window indices
        while(dq.front()<=i-k)dq.pop_front();
        // Add the current val indices in the dequeue
        while(!dq.empty() && ar[dq.back()]<ar[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<< ar[dq.front()]<<endl;

}





//####################################################################################################
//####################################################################################################

//#######------- 7th Video - Longest sub-array having sum k (variable-size sliding window) --------########

//**********Can you do it using map?????????


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


This approach won’t work for negative numbers

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


//Time complexity is O(N) 
void sliding_window(int ar[], int n, int target){
    //finding the largest window size of target sum
    int sum = 0,ans = 0;
    for(int i=0,j=0;j<n;){
        sum+=ar[j];
        if(sum==target){
            //update answer
            ans = max(ans, j-i+1);
            //then increase j
            j++;
        }
        else if(sum<target)j++;
        else if(sum>target){
            //while chalabo jotokkhn sum<=x hocche na
            while(sum>target){
                sum-=ar[i];
                i++;
            }
            if(sum==target){
                //update answer
                ans = max(ans, j-i+1);
            }
            j++;
        }

    }
    cout<< ans <<endl;

}









//####################################################################################################
//####################################################################################################

//#######------- 10th Video - Find the longest substring with k unique characters in a given string --------########

// - It's a variable size window problem, longest substring = the variable window
// - understanding condition in variable sliding window is very very important


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

Same like Longest sub-array having sum k but here we have to keep on checking the set size<k or not
- Here we will have to maintain the distinct size of the window


(********----- unordered_map() ----*******)
i = start of window , j = end of window

1. Apply two pointers, i,j and an unordered map named um
2. If us.size()==k, j++, update answer (distance from j - distance of i + 1)
3. If us.size()<k , j++ only
4. If us.size()>k , keep on deleting the characters until us[s[i]]==0,if so erase us[s[i]] 
   then update ans = (j-i+1)


*/


//Time complexity is O(N) - using unordered map
void sliding_window(string s, int n, int k){
    unordered_map<char, int> um;
    int i = 0, j = 0, ans = 0;
    while(j<n){
        um[s[j]]++;
        if(um.size()==k){
            ans = max(ans, j-i+1);
            j++;
        }
        else if(um.size()<k)j++;
        else if(um.size()>k){
            while(um.size()>k){
                um[s[i]]--;
                if(um[s[i]]==0){
                    um.erase(s[i]);
                }
                i++;
            }

            if(um.size()==k){
                ans = max(ans, j-i+1);
            }
            j++;
        }
    }
    cout<< ans <<endl;
}







//####################################################################################################
//####################################################################################################

//#######------- 11th Video - Length of the longest substring without repeating characters --------########

// - It's a variable size window problem


/*
Input: “GEEKSFORGEEKS”
Output: 7
Explanation: The longest substrings without repeating characters are “EKSFORG” and “KSFORGE”, with lengths of 7

------

My sample input:
GEEKSFORGEEKS

Output-> 
7


//https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

Step-by-step approach:

visited or not visited approach


1. Visited thakle i pointer non visited prjnto niye asha, else j++, and update answer
    visited na thakle sheta amader potential answer hobe



1. Intialize two pointers left and right with 0, which define the current window being considered.
2. The right pointer moves from left to right, extending the current window.
3. If the character at right pointer is not visited , it’s marked as visited.
4. If the character at right pointer is visited, it means there is a repeating character. 
   The left pointer moves to the right while marking visited characters as false until the repeating character is no longer part of the current window.
5. The length of the current window (right - left + 1) is calculated and answer is updated accordingly.

*/


//Time complexity is O(N)

void sliding_window(string s, int n){
    int i = 0, j = 0, ans = 0;
    bool visited[1000]={};
    while(j<n){

        if(visited[s[j]]){
            //that means there is a repeating character
            //move the left pointer in this case
            while(visited[s[j]]){
                visited[s[i]] = false;
                i++;
            }
        }
        visited[s[j]] = 1;
        ans = max(ans, j-i+1);
        j++;

    }
    cout<< ans <<endl;
}


//another way(little bit) 
void sliding_window(string s, int n){
    int i = 0, j = 0, ans = 0;
    bool visited[1000]={};
    while(j<n){
        if(!visited[j])visited[s[j]] = 1, ans = max(ans, j-i+1), j++;//our potential answer
        if(visited[s[j]]){
            while(visited[s[j]]){
                visited[s[i]] = false;
                i++;
            }
        }
    }
    cout<< ans <<endl;
}

//using unordered map
void sliding_window(string s, int n){
    unordered_map<char, int > um;
    int i=0, j = 0, ans = 0;
    while(j<n){
        um[s[j]]++;
        if(um.size()==j-i+1){
            //this can be potential answer
            ans = max(ans, j-i+1);
            j++;
        }
        else if(um.size()<j-i+1){
            while(um.size()<j-i+1){
                um[s[i]]--;
                if(um[s[i]]==0)um.erase(s[i]);
                i++;
            }
            if(um.size()==j-i+1){
                //this can be potential answer
                ans = max(ans, j-i+1);
            }
            j++;
        }
        //um.size()>j-i+1 = this condition will never hit
    }
    cout<< ans <<endl;

}






//####################################################################################################
//####################################################################################################

//#######------- 12th Video - Pick Toys --------########
//largest substring with unique character k = 2

// - It's a variable size window problem, almost same like the previous one


/*

------

My sample input:
abaccab 2[-> a b c those are different types of toys], John can only take 2 types of toys maximized

Output-> 
4 [4 -> acca ]


//https://www.geeksforgeeks.org/maximise-the-number-of-toys-that-can-be-purchased-with-amount-k/

Step-by-step approach:
1. Keep two pointers and make an unordered map
2. when the um.size()==k, there is our potential ans
3. else um.size()>k, keep removing elements until it become lesser than k size


1. line s uthao --> mtlb substring
2. max k types --> max k unique characters in the substring
type = unique

*/


//using unordered map
void sliding_window(string s, int n, int k){
    unordered_map<char,int> um;
    int i = 0, j = 0, ans = 0;
    while(j<n){
        um[s[j]]++;
        if(um.size()==k){
            ans = max(ans, j-i+1);
            j++;
        }
        else if(um.size()<k){
            j++;
        }
        else if(um.size()>k){
            while(um.size()>k){
                um[s[i]]--;
                if(um[s[i]]==0)um.erase(s[i]);
                i++;
            }
            //our potential answer can be here
            if(um.size()==k){
                ans = max(ans, j-i+1 );
            }
            j++;
        }
    }
    cout<< ans <<endl;

}



//####################################################################################################
//####**** CONFUSEDDDDDDDD  ################################################################################################

//#######------- 13th Video - Minimum Window Substring | Variable Size Sliding Window --------########



/*

Input: string = “this is a test string”, pattern = “tist” 
Output: “t stri” 
Explanation: “t stri” contains all the characters of pattern.

------

My sample input:
this is a test string
tist

Output-> 
t stri

//https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
//https://takeuforward.org/data-structure/minimum-window-substring/

Step-by-step approach:
1. Traverse the pattern and make frequency of that, create sz = pat.size() 
2. Traverse the main pattern
   a. create two pointer i and j
   b. if s[i] is present in pattern map then pt[s[i]]--;
      b.1 if pt[s[i]] == 0 then ct++
      b.2 after some time, if ct == sz, then it is our potential answer. keep the answer; 
      b.2.1 and remove the extra characters from the beginning if there
   c. 

*/

//using unordered map
///CODE TO BE CONTINUED









//####################################################################################################
//####################################################################################################


