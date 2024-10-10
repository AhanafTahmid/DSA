//Sliding Window + Two Pointer

- This is not an algorithm, more of an contructive algo thing
- Hashing + two pointer + sliding_window all work simultaneously in most of the time
- Subarray and substring, think sliding window or two pointer
- When you are not sure about shrinking and expanding use the below formula 
    Formula: Atmost(k) - atmost (k-1) = exactly k

---------------------------------------------------------------------------------------------------------
Striver Sliding Window + Two Pointer Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL
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
//Tutorial: 
//Problem: https://leetcode.com/problems/max-consecutive-ones-iii/description/

Q: longest subarray at most k 0's
------------
Approach:
1. if arr[i] == 0 increase count 
2. while(ct>k) move left pointer
3. at the end calculate answer using left and right pointer
------------

//Approach 1
//Better
Time complexity : O(2N)
Space complexity: O(1)
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


//Approach 2
//Optimal - Removing the inside while loop
Time complexity : O(N)
Space complexity: O(1)

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0, r = 0, mxcons = 0, ct = 0, n = arr.size();
        while(r<n){
            if(arr[r]==0)ct++;
    
            if(ct>k){
                if(arr[l]==0) ct--;
                l++;
            }
            
            if(ct<=k){
                mxcons = max(mxcons, r - l + 1);
            }
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

Q: max length subarray having at most 2 type of fruits 

------------
Approach:
1. take map, 
1.1 while mp.size() == 3 keep decreasing the leftmost element 
1.2 If leftmost element frequency is 0, then delete it 

2. Keep doing the step 1, and keep updating the answer
------------

//Approach 1
Time complexity: O(2N) - 3 3 3 3 1 2 [ei case e 2N jabe]
Space complexity: O(3)

class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size(), l = 0, r = 0, mxfruits = 0;
        map<int, int>mp;
        while(r<n){
            mp[arr[r]]++;
            while( mp.size() == 3 ){
                mp[arr[l]]--;
                if(mp[arr[l]]==0)mp.erase(arr[l]);
                l++;
            }
            mxfruits = max(mxfruits, r - l + 1);
            r++;
        }
        return mxfruits;
    }
};

//Approach 2
Time complexity: O(N)

class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size(), l = 0, r = 0, mxfruits = 0;
        map<int, int>mp;
        while(r<n){
            mp[arr[r]]++;
            if( mp.size() >= 3 ){
                mp[arr[l]]--;
                if(mp[arr[l]]==0)mp.erase(arr[l]);
                l++;
            }
            if(mp.size()<=2){
                mxfruits = max(mxfruits, r - l + 1);
            }
            r++;
        }
        return mxfruits;
    }
};

//#######################################################################
//#######-------L6. Longest Substring With At Most K Distinct Characters--------########
//Tutorial: 
//Problem: https://www.naukri.com/code360/problems/distinct-characters_2221410

------------
Approach:
1. take map, 
1.1 while mp.size() > 3 keep decreasing the leftmost element 
1.2 If leftmost element frequency is 0, then delete it 

2. Keep doing the step 1, and keep updating the answer when mp.size()<=k [cause it said atmost]
------------


//Approach 1
Time complexity: O(2N) + O(log256)
Space complexity: O(256)

#include<bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    int n = s.size(), l = 0, r = 0, longest_unique = -1;
    map<char, int>mp;
    while(r<n){
        mp[s[r]]++;
        while(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(s[l]);
            l++;
        }
        if(mp.size()<=k) 
        longest_unique = max(longest_unique, r - l + 1);
        r++;
    }
    return longest_unique;
}

//Approach 2
Time complexity: O(N) + O(log256)
Space complexity: O(256)

#include<bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    int n = s.size(), l = 0, r = 0, longest_unique = -1;
    map<char, int>mp;
    while(r<n){
        mp[s[r]]++;
        if(mp.size()>k){//only this thing has been changed
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(s[l]);
            l++;
        }
        if(mp.size()<=k) 
        longest_unique = max(longest_unique, r - l + 1);
        r++;
    }
    return longest_unique;
}

//#######################################################################
//#######-------L7. Number of Substrings Containing All Three Characters--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

------------
Approach:
1. Get the last place of occurance and count the subarray [ min(a,b,c)]

Time Complexity : O(N)
Space Complexity: O(3)
------------
class Solution {
  public:
    int countSubstring(string s) {
        int n = s.size(), l = 0, substrings = 0;
        map<int, int>mp;
        while(l<n){
            mp[s[l]] = l + 1;//convert to 1 base indexing
            if(mp.size() == 3){
                substrings+= 1 + min({mp['a'],mp['b'],mp['c']});
            }
            l++;
        }
        return substrings;
    }
};

//#######################################################################
//#######-------L8. Longest Repeating Character Replacement--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/longest-repeating-character-replacement/description/

------------
Approach:
1. Maintain (length - maxfrequency <= k)
------------

//Approach 1
Time Complexity: O(2N * 26)
Space Complexity: O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0, longest_rep = 0, mxf = 0;
        map<char, int>mp;
        while(r<n){
            mp[s[r]]++;
            int length = r - l + 1;
            mxf = max(mxf, mp[s[r]]);
            while( length - mxf > k ){
                mp[ s[l] ]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                mxf = 0;
                for(auto [x,y]: mp) mxf = max(mxf, y);
                l++;
                length = r - l + 1;
            }
            longest_rep = max(longest_rep, length);
            r++;
        }
        return longest_rep;
    }
};

//Approach 2
Time Complexity: O(N * 26)
Space Complexity: O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0, longest_rep = 0, mxf = 0;
        map<char, int>mp;
        while(r<n){
            mp[s[r]]++;
            int length = r - l + 1;
            mxf = max(mxf, mp[s[r]]);
            if( length - mxf > k ){
                mp[ s[l] ]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                mxf = 0;
                for(auto [x,y]: mp) mxf = max(mxf, y);
                l++;
                length = r - l + 1;
            }

            if(length - mxf <= k)
            longest_rep = max(longest_rep, length);
            r++;
        }
        return longest_rep;
    }
};


//#######################################################################
//#######-------L9. Binary Subarrays With Sum--------########
//Tutorial: https://www.geeksforgeeks.org/count-of-subarrays-with-sum-equals-k-in-given-binary-array/
//Problem: https://leetcode.com/problems/binary-subarrays-with-sum/description/

------------
Approach 1:
1. if mp[sum - target] != 0 then add ans += mp[sum-target]
------------

//Approach 1
Time Complexity: O(N) [Most times cause using unordered map]
Space Complexity: O(N) [For the map]

class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int target) {
        int n = arr.size(), l = 0, sum = 0, total_sub = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        while(l<n){
            sum+=arr[l];
            if(mp[sum - target]) total_sub += mp[sum - target];
            mp[sum]++;
            l++;
        }
        return total_sub;
    }
};

//Approach 2
------------
Approach 2:
1. Find number of subarray with = atmost(k) - atmost(k-1)
------------

Formula: Atmost(k) - atmost (k-1) = exactly k

Time Complexity: O(2N)
Space Complexity: O(1)

class Solution {
public:
    int atmost(vector<int>&arr, int target){
        int n = arr.size(), l = 0, r = 0, sum = 0, length = 0, total_sub = 0;
        while(r<n){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            length = r - l + 1;
            total_sub += length;
            r++;
        }
        return total_sub;
    }
    int numSubarraysWithSum(vector<int>& arr, int target) {
        if(target==0) return atmost(arr, target);
        return atmost(arr, target) - atmost(arr, target-1);
    }
};

//#######################################################################
//#######-------L10. Count number of Nice subarrays--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

- When you are not sure about shrinking and expanding use the below formula 
Formula: Atmost(k) - atmost (k-1) = exactly k

Prerequisite: L9. Binary Subarrays With Sum

------------
Approach:
1. Convert the problem with Number of subarrays having sum exactly equal to k
1. Or Convert the problem with Binary Subarrays With Sum

After that the approach is same
------------
Time Complexity: O(2N)
Space Complexity: O(1)

class Solution {
public:
    int atmost(vector<int>&arr, int target){
        int n = arr.size(), l = 0, r = 0, sum = 0, length = 0, total_sub = 0;
        while(r<n){
            sum+=(arr[r]&1);
            while(sum>target){
                sum-=(arr[l]&1);
                l++;
            }
            length = r - l + 1;
            total_sub += length;
            r++;
        }
        return total_sub;
    }
    int numberOfSubarrays(vector<int>& arr, int target) {
        return atmost(arr, target) - atmost(arr, target-1);
    }
};

//#######################################################################
//#######-------L11. Subarray with k different integers--------########
//Tutorial: https://www.geeksforgeeks.org/count-of-subarrays-having-exactly-k-distinct-elements/
//Problem: https://leetcode.com/problems/subarrays-with-k-different-integers/description/
https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1

Formula: Atmost(k) - atmost (k-1) = exactly k

------------
Approach:
1. Convert the problem with Number of subarrays having sum exactly equal to k
1. Or Convert the problem with Binary Subarrays With Sum

After that the approach is same
------------

Time Complexity: O(2N*1) [ unordered_map == O(1)]
Space Complexity: O(N) [taking all elements in array in the map]

class Solution {
public:
    int atmost(vector<int>&arr, int target){
        int n = arr.size(), l = 0, r = 0, sum = 0, length = 0, total_sub = 0;
        unordered_map<int, int>mp;
        while(r<n){
            mp[arr[r]]++;
            while(mp.size() > target){
                mp[arr[l]]--;
                if( mp[arr[l]] == 0 ) mp.erase(arr[l]);
                l++;
            }
            length = r - l + 1;
            total_sub += length;
            r++;
        }
        return total_sub;
    }

    int subarraysWithKDistinct(vector<int>& nums, int target) {
        return atmost(nums, target) - atmost(nums, target-1); 
    }
};

//#######################################################################
//#######-------L12. Minimum Window Substring--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-window-substring
//Problem: https://leetcode.com/problems/minimum-window-substring/description/
//Problem(gfg): https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

- Using map in this problem will give tle in some sites(like gfg) because of extra logn 

------------
Approach:
1. make frequency of all the characters that are present in the array
2. if frequency > 0 then ct++
3.1 if (ct == pz) then our answer is found
3,2 while(ct==pz)then move the start pointer until it becomes false, keep the start and end windoww
4. answer would be string from start(j) to end(i-j+1)
------------
Time Complexity: O(2N + pz)
Space Complexity: O(256) [extended ascii is of 256 length]

class Solution {
public:
    string minWindow(string s, string p) {
        int sz = s.size(), pz = p.size(), ct = 0, l = 0, r = 0, start = -1, end = -1, length = INT_MAX;
        if(sz<pz) return "";
        vector<int> v(256);
        for(char ch: p)v[ch]++;
        while(r<sz){
            if(v[ s[r] ]>0) ct++;
            v[ s[r] ] --;
            while(ct==pz){
                //ct == pz means string paisi
                int now_length = r - l + 1;
                if( length > now_length && ct==pz){
                    length = now_length;
                    start = l;
                    end = length;
                }
                v[ s[l] ]++;
                //age pre-inserted chilo bole positive hobei
                if(v[ s[l] ]>0) ct--;
                l++;
            }
            r++;
        }
        
        if(length==INT_MAX) return "";
        return s.substr(start, end);
    }
};

//#######################################################################
//#######-------L13. Minimum Window Subsequence--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

------------
Approach:
1. keep on first forward, then if found all, keep on finding backward and each time update the min length size
Keep doing step 1 until i is exhausted
------------
class Solution {
  public:
    string minWindow(string str1, string str2) {
        int n = str1.size();
        int pn = str2.size();
        int i = 0, j = 0, mn = INT_MAX;
        string ans = "";
        while(i<n){
            if(str1[i]==str2[j])j++;
            if(j==pn){
                j--;
                int end = i + 1;
                while(j>=0){
                    if(str1[i]==str2[j]) j--;
                    i--;
                }
                j++;
                i++;
                if(mn>(end-i)){
                    mn = end-i;
                    ans = str1.substr(i,mn);
                }
            }
            i++;
        }
        return ans;
        
    }
};

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