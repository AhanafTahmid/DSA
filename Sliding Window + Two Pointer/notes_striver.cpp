//Sliding Window + Two Pointer

- This is not an algorithm, more of an contructive algo thing
- Hashing + two pointer + sliding_window all work simultaneously in most of the time

---------------------------------------------------------------------------------------------------------
Striver Tree Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL
Resource: https://takeuforward.org/blogs/sliding-window
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####-------Sliding Window & Two Pointer Combined Problems--------#####
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L1. Introduction to Sliding Window and 2 Pointers--------########
//Tutorial: 

------------------------Theory----------------------------------

4 types of sliding window problem: 
1. Constant window
2. Longest subarray/substring(most frequent in this type)
3. Number of subarrays where some conditions(can be solved using pattern 2)
4. shortest/minimum window with some conditions



//Template for most of the problem
int sliding_window(vector<int>& arr, int k) {
    int count = 0, sum = 0;
    int n = arr.size();
    int l = 0, r = 0, mxlength = 0;
    while (r < n) {
        sum += arr[r];
        
        while (sum > k) {
            sum -= arr[l++];
        }
        if(sum<=k) mxlength = max(mxlength, r-l+1);
        r++;
    }
    return count;
}


//#######################################################################
//#######-------L2. Maximum Points You Can Obtain from Cards--------########
//Tutorial: https://takeuforward.org/sliding-window/maximum-points-you-can-obtain-from-cards
//Problem: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

- This problem can be solved using prefix sum too
------------
Approach:
1. Make first window 
2. go one step back from left and one step back from right, and keep updating mxanswer 

------------

class Solution {
  public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size(), score = 0, mxscore = 0;
        for(int i=0;i<k;i++){
            score+=card[i];
        }
        mxscore = score;
        for(int i=k-1,j=n-1;i>=0;i--,j--){
            score = score - card[i] + card[j];
            mxscore = max( mxscore, score);
        }
        return mxscore;
    }
};

//#######################################################################
//#######-------L3. Longest Substring Without Repeating Characters--------########
//Tutorial: https://takeuforward.org/sliding-window/longest-substring-without-repeating-characters-sliding-window
//Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

------------
Approach:
1. Keep moving from r to n 
2. If element appears again keep increasing l until previous element is removed
3. update the max length everytime
------------
//Approach 1 - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        bool visited[256]={};//extended ascii can go upto 256 characters
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

//Approach 2 - O(n+log(n)) (using set - extra logn complexity)
int longestSubstrDistinctChars (string s)
{
    int n = s.size(), l = 0, r = 0, mxlength = 0;
    set<char>st;
    while(l<n && r<n){
        while(st.count(s[r])){
            st.erase(s[l++]);
        }
        st.insert(s[r]);
        mxlength = max(mxlength, r - l + 1);
        r++;
        
    }
    return mxlength;
}


//#######################################################################
//#######-------L4. Max Consecutive Ones III--------########
//Tutorial: https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/
//Problem: https://leetcode.com/problems/max-consecutive-ones-iii/description/

longest subarray at most k 0's
------------
Approach:
1. if arr[i] == 0 increase count 
2. while(ct>k) move left pointer
3. at the end calculate answer using left and right pointer
------------

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0, r = 0, mxcons = 0, ct = 0, n = arr.size();
        while(r<n){
            if(arr[r]==0)ct++;
            
            while(ct>k){
                if(arr[l]==0) ct--;
                l++;
            }
            mxcons = max(mxcons, r - l + 1);
            r++;
        }
        return mxcons;
    }
};

//#######################################################################
//#######-------L5. Fruit Into Baskets--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/fruit-into-baskets/description/
https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L6. Longest Substring With At Most K Distinct Characters--------########
//Tutorial: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
//Problem: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L7. Number of Substrings Containing All Three Characters--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
https://www.geeksforgeeks.org/problems/count-substring/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L8. Longest Repeating Character Replacement--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/longest-repeating-character-replacement/description/
https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L9. Binary Subarrays With Sum--------########
//Tutorial: https://www.geeksforgeeks.org/count-of-subarrays-with-sum-equals-k-in-given-binary-array/
//Problem: https://leetcode.com/problems/binary-subarrays-with-sum/description/
https://www.geeksforgeeks.org/problems/binary-subarray-with-sum/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L10. Count number of Nice subarrays--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/count-number-of-nice-subarrays/description/
https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L11. Subarray with k different integers--------########
//Tutorial: https://www.geeksforgeeks.org/count-of-subarrays-having-exactly-k-distinct-elements/
//Problem: https://leetcode.com/problems/subarrays-with-k-different-integers/description/
https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L12. Minimum Window Substring--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-window-substring
//Problem: https://leetcode.com/problems/minimum-window-substring/description/
https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------L13. Minimum Window Subsequence--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

------------
Approach:
1. 
------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################-------Finished--------#########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
-------------------------------------------------------------------------
-------------------------------------------------------------------------