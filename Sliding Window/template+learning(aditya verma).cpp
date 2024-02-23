//Playlist: https://www.youtube.com/playlist?list=PLw3E7GGpk4-BeiU9991UdBagSq8UlJPFs


- Sliding window — In any sliding window based problem we have two pointers. The right pointer whose job is to expand the current window and then we have the left pointer whose job is to contract a given window. At any point in time only one of these pointers moves and the other one remains fixed.

- We can make O(N*N) in O(N) using sliding window
- We have to print total (size - k+1) numbers[in fixed size window]
- there could be a possible answer in a window in sliding window
- in variable size window we use map/unorederd map, unordered_set a lot
- for contiguous things we can use sliding window
- array -> subarray thakbe
- string -> substring thakbe

- We use two pointer and prefix sum a lot in sliding window problems, using both two pointer and prefix sum is sliding window

- keep solving the problems,  while we move the pointers
- we can make two pointer from left to right, or left and right pointer both in the same point, keep solving as we move the both pointer


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
///CODE TO BE CONTINUED*****************************



//####################################################################################################
//####################################################################################################

//#######------- 14th Video - 3. Longest Substring Without Repeating Characters --------########



/*

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

------


//https://leetcode.com/problems/longest-substring-without-repeating-characters/



*/


//Time complexity of this is O(2n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        bool visited[100000]={};
        int l = 0, r = 0, ans = 0;
        while(r<n){
                while(visited[s[r]]){
                    visited[s[l]] = 0;
                    l++;
                }
                ans = max(ans, r - l + 1),visited[s[r]]=1,r++;
            }
        return ans;

    }
    
};





//####################################################################################################
//####################################################################################################

//#######------- 15th Video - Max Consecutive Ones III --------########



/*

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

------


//https://leetcode.com/problems/max-consecutive-ones-iii/

*/

//Time complexity of this is O(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0, ct = 0;
        while(i<n){
            if(nums[i]==0){
                ct++;
            }
            //move right pointer
            while(ct>k){
                if(nums[j]==0)ct--;
                j++;
            }

            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};



//####################################################################################################
//####################################################################################################

//#######------- 16th Video - 904. Fruit Into Baskets --------########

//Maximum subarray that consists only two distinct element

/*

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

------


//https://leetcode.com/problems/fruit-into-baskets/


*/

//Time complexity of this is O(2n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int> um;
        while(i<n){
            um[fruits[i]]++;
            while(um.size()>2){
                um[fruits[j]]--;
                if(um[fruits[j]]==0)um.erase(fruits[j]);
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};


//####################################################################################################
//####################################################################################################


//####################################################################################################
//####################################################################################################

//#######------- 17th Video - Longest Repeating Character Replacement --------########

//it's also a variable size window problem, here we will have to find the longest window

/*

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

------


//https://leetcode.com/problems/longest-repeating-character-replacement/description/


*/

//Time complexity of this is O(2n)

//code.....



//####################################################################################################
//####################################################################################################

//#######------- 18th Video - Binary Subarrays With Sum --------########
//Number of subarrays having sum exactly equal to k

/*

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

------


//https://leetcode.com/problems/binary-subarrays-with-sum/



Steps:
1. make two pointer i and j
2. add all the previous answer that is possible by using an unordered map


*/

//Time complexity of this is O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> um;
        um[0] = 1;
        int i = 0, j = 0, ans = 0, sum = 0;
        int n = nums.size();
        while(i<n){
            sum+=nums[i];
            //check if there is answer previously
            if(um.find(sum-goal)!=um.end())ans+=(um[sum-goal]);
            um[sum]++;
            i++;
        }
        return ans;
    }
};




//####################################################################################################
//####################################################################################################

//#######------- 19th Video - Count number of nice subarrays --------########
//Number of subarrays having sum exactly equal to k

/*

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

------


//https://leetcode.com/problems/count-number-of-nice-subarrays/description/



Steps:
1. convert all odds to 1s and even to 0s
2. apply the Number of subarrays having sum exactly equal to k sum steps


*/

//Time complexity of this is O(n)
//Using hashing
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2) nums[i] = 1;
            else nums[i] = 0;
        }
        unordered_map<int,int> um;
        int i=0,j=0,sum=0, ans = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum==k)ans++;
            if(um.find(sum-k)!=um.end()){
                ans+=um[sum-k];
            }
            um[sum]++;
        }
        return ans;
    }
};


//using sliding window
//1.move right pointer until it is == k . after that count the ct's. Then keep on adding the cts
/*
Sliding Window Technique:

The problem can be efficiently solved using the sliding window technique.
We maintain two pointers: left and right to define the window.
We move the right pointer to expand the window while keeping track of the count of odd numbers encountered.
If the count of odd numbers in the window is less than k, we continue expanding the window.
If the count of odd numbers equals k, we count all possible subarrays with exactly k odd numbers starting from the current position of the left pointer until the window no longer satisfies the condition.

Tracking Odd Numbers:

We keep track of the number of odd numbers encountered within the current window.
Whenever we move the right pointer, if the number at that position is odd, we increment the count of odd numbers.
If the count of odd numbers exceeds k, we start moving the left pointer to the right until the count is again less than k.

*/


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0 , ans = 0, odd = 0, ct = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1)odd++,ct=0;
            while(odd==k){
                odd-=nums[j]&1;
                ct++;
                j++;
            }
            ans+=ct;
        }
        return ans;
    }
};





//####################################################################################################
//####################################################################################################

//#######------- 20th Video - Number of Substrings Containing All Three Characters --------########
//

/*

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

------


//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

Steps:
1. Until the size is 2, we keep on removing the frequency 

*/

//Time complexity of this is O(n)


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<int,int> um;
        int i = 0, j = 0, ans = 0;
        while(i<n){
            um[s[i]]++;
            while(um.size()==3){
                ans+=(n-i);
                um[s[j]]--;
                if(um[s[j]]==0)um.erase(s[j]);
                j++; 
            }
            i++;
        }
        return ans;
    }
};




//####################################################################################################
//####################################################################################################

//#######------- 21th Video - Maximum Points You Can Obtain from Cards --------########
//

/*

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

------


//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

Steps:
1. make a prefix sum of the cards
2. move the window from right to left and check the answer

*/

//Time complexity of this is O(n)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int allsum = cardPoints[0];
        int n = cardPoints.size();
        long long pr[100000]={};
        pr[0] = cardPoints[0];
        for(int i=1;i<n;i++){
            pr[i] = pr[i-1] + cardPoints[i];
            allsum+=cardPoints[i];
        }
        if(n==k)return allsum;
        long long ans = 0;
        for(int i=0,j=n-k-1;i<=k;i++,j++){
            if(i==0)ans = allsum - pr[j] ;
            else ans = max(ans, (allsum - (pr[j] - pr[i-1])));
        }
        return ans;
    }
};


//####################################################################################################
//####################################################################################################

//#######------- 22nd Video - Subarrays with K Different Integers--------########
//Subarrays with k distinct elements

/*

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

------


//https://leetcode.com/problems/subarrays-with-k-different-integers/description/


Steps:
1. Atmost k subarray(total subarray with <k elements) - atmost k-1 = exactly count
3 ta diye jotota banaite parbo(ekhane 2ta walao ase) - 2 ta diye jotota banaite parbo(only 2 ta and 1 ta wala) = tahole bakigula 3 ta walai hobe

Intuition:
Example:
Suppose we have calculated the count of subarrays with at most 3 distinct elements (at most k) and found it to be 10.
Suppose we have also calculated the count of subarrays with at most 2 distinct elements (at most k-1) and found it to be 6.
Then, the count of subarrays with exactly 3 distinct elements is at most k minus at most k-1, i.e., 10 - 6 = 4.


*/

//Time complexity of this is O(n)


class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int i=0, j = 0, ans = 0;
        int n = nums.size();
        while(i<n){
            um[nums[i]]++;
            while(um.size()>k){
                um[nums[j]]--;
                if(um[nums[j]]==0) um.erase(nums[j]);
                j++;
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1); 
    }
};



//####################################################################################################
//####################################################################################################

//#######------- 23rd Video - Minimum window substring --------########

/*

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

------


//https://leetcode.com/problems/minimum-window-substring/description/


Steps:
1. make frequency of all the characters that are present in the array
2. if frequency > 0 then ct++
3. while(ct==pn)then move the start pointer until it becomes false, keep the start and end windoww
4. answer would be string from start(j) to end(i-j+1)

decreasing the frequency → I am using the character
increasing the frequency → I am not using the character

*/

//Time complexity of this is O(n)


class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int pn = t.size();
        vector<int> p(256,0);
        for(char ch: t){
           p[ch]++;
        }
        if(n<pn)return "";
        int ans = 0, ct = 0;
        int start = 0, end = 0, mn = INT_MAX;
        int i = 0, j = 0;
        for(i=0,j=0;i<n;i++){
            if(p[s[i]]>0)ct++;
            p[s[i]]--;
            while(ct==pn){
                //ei window te answer ase
                if(mn>(i-j+1) && ct==pn){
                    mn = (i-j+1);
                    start = j;
                }
                p[s[j]]++;
                if(p[s[j]]>0)ct--;
                j++;
            }

        }
        end = mn;
        if(mn==INT_MAX) return "";
        return s.substr(start,end);//delete everything outside this range
    }
};


//####################################################################################################
//####################################################################################################

//#######------- 24th Video - Minimum window substring --------########

/*

str1: geeksforgeeks
str2: eksrg
Output: 
eksforg
Explanation: 
Eksforg satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.

------


//https://leetcode.com/problems/minimum-window-substring/description/


Steps:
Almost similar to the 23rd one, but it must be in order this time

forward backward -> forward backward -> forward backward until reaches end
1. keep on first forward, then if found all, keep on finding backward and each time update the min length size

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    string s1;cin>>s1;
    string s2;cin>>s2;
    int n = s1.size();
    int pn = s2.size();
    int i = 0, j = 0, end = -1, mn = INT_MAX;
    string ans = "";
    while(i<n){
        if(s1[i]==s2[j]){
            j++;
        }
        if(j==pn){
            //move j as you can
            end = i + 1;
            j--;
            while(j>=0){
                if(s1[i]==s2[j])j--;
                i--;
            }
            i++;
            j++;
            if(end-i<mn){
                mn = end-i;
                ans = s1.substr(i, mn);
            }
            //cout<< s1.substr(j,end)<<endl;
            //cout<< i <<" = "<<end<<" = "<<mn <<endl;
            
        }
        i++;
    }
    cout<< ans <<endl;
}


signed main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//####################################################################################################
//####################################################################################################