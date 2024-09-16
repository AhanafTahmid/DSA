//Array

- *** Space complexity in different scenario: using in order to return the answer vs using in order to solve the problem
- Donot write brute force, write from better apprach in interview
- Typecasting int to long long ::::::=> 
int s1 = arr[i], s2 = arr[j], s3 = arr[l], s4 = arr[r];
long long total = 1LL - 1LL + s1+s2+s3+s4;
- Think of hashing or two pointer in subarray type problems

---------------------------------------------------------------------------------------------------------
Striver Array Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB
Resource: https://takeuforward.org/array/top-array-interview-questions-structured-path-with-video-solutions
Resource2: https://takeuforward.org/blogs/array
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//########@##-------Lec 1: Easy Problems--------#########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------1. Largest Element in an Array--------########

------------------------Theory----------------------------------

- Array Stores in contiguous manner
- Data structure contains one datatype of elemennt, strings, integer etc 
- All elements filled with 0's in array if defined globally
- Limit: 10^6 inside locally, 10^7 inside globally

//Tutorial: https://takeuforward.org/data-structure/find-the-largest-element-in-an-array/
//Problem: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0
------------
Approach:
1. Traverse the array and find the maximum
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int largest(vector<int> &arr) {
        int mx = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            if( mx < arr[i] ) mx = arr[i];
        }
        return mx;
    }
};

//#######################################################################

//#######-------2.1 Second Largest Element in an Array without sorting--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/second-largest3735/1

------------
Approach:
1. Initially First largest is arr[0]
2. if new largest found, then second == previous largest
3. else if curent element != maximum and current element>second largest, update second largest 
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int sec = -1;
        int mx = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            if( arr[i] > mx ){
                sec = mx;
                mx = arr[i];
            }
            else if ( arr[i]!= mx && arr[i]>sec ){
                sec = arr[i];
            }
        }
        return sec;
    }
};

//#######-------2.2 Second Largest Element in an Array without sorting--------########
//Tutorial: https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array/
//Problem: https://www.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1

Prerequisite: 2.1 Second Largest Element in an Array without sorting
------------
Approach:
1. Use the same approach as 2.1 Second Largest Element in an Array without sorting
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution{
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        int sec = 1e9;
        int mn = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            if( arr[i] < mn ){
                sec = mn;
                mn = arr[i];
            }
            else if ( arr[i]!= mn && arr[i]<sec ){
                sec = arr[i];
            }
        }
        if(sec==1e9) return {-1};
        return {mn, sec};
    }
};

//#######################################################################
//#######-------3. Check if the array is sorted--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-an-array-is-sorted/
//Problem: https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

------------
Approach:
1.1 if arr[i-1]>arr[i] then false
1.2 else last e true return kor
------------
Time Complexity: O(N)
Space Complexity: O()

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]) return false;
        }
        return true;
    }
};

//#######################################################################
//#######-------4. Remove duplicates from Sorted array--------########
//Tutorial: https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/
//Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

------------
Approach:
1. initially count == 1
2. if ar[i-1] != arr[i], then new unique element found
   in that case, update arr[count] = arr[i]
   also incrase count++ to prepare for the next index
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int cnt = 1;
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i-1]!=arr[i]){
                arr[cnt++] = arr[i];
            }
        }
        return cnt;
    }
};

//Another Approach
------------
Approach:
1. Use unique of stl and solve it 
------------

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        auto it = unique(arr.begin(),arr.end());
        int k = distance(arr.begin(), it);
        return k;
    }
};

//#######################################################################
//#######-------5. Left Rotate an array by one place--------########
//Tutorial: https://takeuforward.org/data-structure/left-rotate-the-array-by-one/
//Problem: https://leetcode.com/problems/rotate-array/description/

------------
Approach:
1. take the last element in temporary variable 
2. then change arr[i+1] th element with arr[i]
------------
Time Complexity: O(N)
Space Complexity: O(1) [extra space is O(N), total space is O(N), which is given]

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        int f = arr[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i+1] = arr[i];
        }
        arr[0] = f;
    }
};

//#######################################################################
//#######-------6.1 Left rotate an array by K places--------########
//Tutorial: https://takeuforward.org/data-structure/rotate-array-by-k-elements/
//Problem:https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

Think of reversing when solving this problem

- Left rotate is clockwise

------------
Approach:
Do 3 reversal
1. reverse from 0 to k
2. reverse from k+1 to n
3. reverse from 0 to n
------------
Time Complexity: O(2N)
Space Complexity: O(1)

class Solution{
    public:
    void rotateArr(int arr[], int k, int n){
        k%=n;
        reverse(arr, arr+k);
        reverse(arr+k, arr+n);
        reverse(arr, arr+n);
    }
};
//#######-------6.2 Right rotate an array by K places--------########
//Problem: https://leetcode.com/problems/rotate-array/description/

- Right rotate is clockwise

------------
Approach:
Do 3 reversal
1. reverse from 0 to n-k
2. reverse from n-k to n
3. reverse from 0 to n

We have our rotated array
------------
Time Complexity: O(2N)
Space Complexity: O(1) [Not using from my side, arr is the given array]

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k%=n;
        reverse(arr.begin(), arr.begin()+(n-k) );
        reverse(arr.begin() + (n-k) , arr.end() );
        reverse(arr.begin(), arr.end());
    }
};

//Another Approach
Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        vector<int>ans;
        int n = arr.size();
        k = k%n;
        for(int i=n-k;i<n;i++){
            ans.push_back(arr[i]);
        }
        for(int i=0;i<n-k;i++){
            ans.push_back(arr[i]);
        }
        arr = ans;
    }
};

//#######################################################################
//#######-------7. Move Zeros to end--------########
//Tutorial: https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/
//Problem: https://leetcode.com/problems/move-zeroes/description/

------------
Approach:
Use swapping approach - not exact but similar to 4. Remove duplicates from Sorted array
1. Use two pointer, one for 0 and one for other number 
2. If arr[i]!=0 swap(arr[l],arr[i]); and move left pointer 
------------
Time Complexity: O(N) [ekbar e cholbe]
Space Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        // l for zero pointer
        int n = arr.size();
        int l = n;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                l = i;
                break;
            }
        }

        for(int i=l+1;i<n;i++){
            if(arr[i]!=0){
                swap(arr[l],arr[i]);
                l++;
            }
        }
    }
};

//#######################################################################
//#######-------8. Linear Search--------########
//Tutorial: https://takeuforward.org/data-structure/linear-search-in-c/
//Problem: https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

------------
Approach:
1. Just traverse the array and find the element, if not found return -1
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int searchInSorted(int arr[], int n, int k) {
        for(int i=0;i<n;i++){
            if(arr[i]==k) return 1;
        }
        return -1;
    }
};

//#######################################################################
//#######-------9.1 Find the Union(Only Unique)--------########
//Tutorial: https://takeuforward.org/data-structure/union-of-two-sorted-arrays/
//Problem: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

Q: Take unique elements from both the array
------------
Approach:
1. if arr1[i] <= arr2[j] move left pointer 
2. else move right pointer  
3. In every adding, also check for ans.empty() or new_arr.back()!=arr[i]
------------
Time Complexity: O(N+M)
Space Complexity : O(N+M) [If Space of Union ArrayList is considered]
                   O(1)   [If Space of union ArrayList is not considered]

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {   
        int i = 0, j = 0;
        vector<int> ans;
        while(i<n && j<m){
            if( arr1[i] <= arr2[j] ){
                if(ans.empty() || ans.back()!=arr1[i])ans.push_back(arr1[i]);
                i++;
            }
            else{
                if(ans.empty() || ans.back()!=arr2[j])ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<n){
            if(ans.back()!=arr1[i])ans.push_back(arr1[i]);
            i++;
        }
        
        while(j<m){
            if(ans.back()!=arr2[j])ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
};

//#######-------9.2 Find the Union(All elements)--------########
//Problem: https://leetcode.com/problems/merge-sorted-array/description/

Q: Take all elements
------------
Approach:
1. if arr1[i] <= arr2[j], take arr1[i] and move left pointer
2. else move right pointer, take arr2[j] and move right pointer
------------
Time Complexity: O(N+M)
Space Complexity : O(N+M) [If Space of Union ArrayList is considered]
                   O(1)

class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int i = 0, j = 0;
        vector<int> ans;
        while(i<n && j<m){
            if( arr1[i] <= arr2[j] ){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<n){
            ans.push_back(arr1[i]);
            i++;
        }
        
        while(j<m){
            ans.push_back(arr2[j]);
            j++;
        }
        
        arr1 = ans;
    }
};

//#######################################################################
//#######-------10. Find missing number in an array--------########
//Tutorial: https://takeuforward.org/arrays/find-the-missing-number-in-an-array/
//Problem: https://leetcode.com/problems/missing-number/description/

------------
Approach:
1. total 1 to n sum - total array sum 
------------
Time Complexity: O(N)
Space Complexity: O(1)

//Optimal
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int total = (n*(n+1))/2;
        int sum = 0;
        for(int i=0;i<n;i++)sum+=arr[i];
        return total - sum;
    }
};


//More Optimal Approach
xor of all numbers will not be that big number , so this more optimal
------------
Approach:
1. xor 1 to n ^ xor of full array
ekta number e duibar occur hobe na, so it will remain in the answer
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xor1 = 0, xor2 = 0;
        for(int i=0;i<n;i++){
            xor1 = xor1 ^ arr[i];
            xor2 = xor2 ^ i;
        }
        xor2 = xor2 ^ n;
        return xor1 ^ xor2;
    }
};

//#######################################################################
//#######-------11. Maximum Consecutive Ones--------########
//Tutorial: https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/
//Problem: https://leetcode.com/problems/max-consecutive-ones/description/

------------
Approach:
1. if 1 occurs ct++, else ct = 0
2. Also, keep updating the - mx = max(mx, ct) everytime
------------
Time Complexity: O(N)
Space Complexity: O(2) [as good as O(1)]

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int ct = 0, mx = 0;
        for(int x: arr){
            if(x==1)ct++;
            else ct = 0;
            mx = max(mx, ct);
        }
        return mx;
    }
};

//#######################################################################
//#######-------12. Find the number that appears once, and other numbers twice.--------########
//Tutorial: https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice/
//Problem: https://leetcode.com/problems/single-number/description/

------------
Approach:
1. Use xor to find the single numbers, other numbers will omit in the xor because of duplicate
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = 0;
        for(int x: arr) ans^=x;
        return ans;
    }
};

//#######################################################################
//#######-------13. Longest subarray with given sum K(positives)--------########
//Tutorial: https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
//Problem: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

Subarray: contiguous portion 

- For only positive numbers Use Two pointer 

//Approach1
------------
Approach:
1. Use two pointer approach to solve this 
------------
Time Complexity: O(2N)
Space Complexity: O(1)

int longestSubarrayWithSumK(vector<int> arr, long long k) {
    long long l = 0, r = 0, n = arr.size(), ans = 0, sum = 0;
    while(l<n && r<n){
        sum+=arr[r];
        while(sum>k){
            sum-=arr[l];
            l++;
        }
        if(sum==k) ans = max(ans, r-l+1);
        r++;
    }
    return ans;
}

//#######################################################################
//#######-------14. Longest subarray with sum K (Positives + Negatives)--------########
//Tutorial: https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/
//Problem: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
//Problem: https://leetcode.com/problems/subarray-sum-equals-k/

- For positive and negative numbers Use Hashing
- Only hashing method works when it has negative values

------------
Approach:
1. Move ahead, keep track of sum
2. Keep finding the hashing of hash[sum-k] and update the length
------------
Time Complexity: O(N)
Space Complexity: O(N) [To store hashing]

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    {   
        int ans = 0, sum = 0;
        map<int, int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) ans = max(ans, i+1);
            
            int rem = sum - k;
            if( mp.find(rem) != mp.end() ){
                ans = max(ans, i - mp[rem]);
            }
            
            if( mp.find(sum) == mp.end() ) mp[sum] = i;//look for as left as you can, so don't always update
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
//##################-------Lec 2: Medium Problems--------################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------15. 2 Sum Problem--------########
//Tutorial: https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
//Problem: https://leetcode.com/problems/two-sum/description/

//Two Pointer Approach
------------
Approach:
1. take the elements in a new array with {element, index}
2. sort the new array 
3. run a two pointer in the new array and solve the problem
------------
Time Complexity: O(N) + O(NlogN) + O(N)
Space Complexity: O(N) [for taking in the new array]

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({arr[i], i});
        }
        sort(vp.begin(),vp.end());
        int l = 0, r = n-1, sum = 0;
        while(l<r){
            sum = vp[l].first + vp[r].first;
            if(sum<target) l++;
            else if(sum>target) r--;

            if(sum==target){
                return {vp[l].second, vp[r].second};
            }
        }
        return {0,0};
    }
};


------------------------------------------------
//Another Approach - Hashing
------------
Use hashing to solve the problem

Approach:
1. if up[ target - element ] is found return the answer
2. else keep updating up[ element ] = index;
------------
Time Complexity: O(N) + O(NlogN) + O(N)
Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> up;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(up.find(target - arr[i] ) !=up.end() ){
                return {up[target-arr[i]], i};
            }
            up[arr[i]] = i;
        }
        return {0,0};
    }
};

//#######################################################################
//#######-------16. Sort an array of 0's 1's and 2's--------########
//Tutorial: https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
//Problem: https://leetcode.com/problems/sort-colors/description/

Dutch National flag algorithm: 

- The algorithm uses swapping approach
- See the intution part of the video for better understanding

------------
Approach:
1. There are 4 parts of the array and 3 pointers
- 0 to low-1    [sorted, 00000]
- low to mid-1  [sorted, 11111]
- mid to high   [unsorted part, make this part sorted to solve the problem]
- high+1 to n-1 [sorted, 22222]

------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size(), low = 0, mid = 0, high = n-1;
        while(mid<=high){
            if(arr[mid]==0) swap(arr[low],arr[mid]), low++,mid++;
            else if(arr[mid]==1) mid++;
            else if(arr[mid]==2) swap(arr[mid], arr[high]), high--;
        }
    }
};

//#######################################################################
//#######-------17. Majority Element (>n/2 times)--------########
//Tutorial: https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
//Problem: https://leetcode.com/problems/majority-element/description/

//Algorithm Tutorial: https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
Moore's Voting Algorithm:

------------
Approach:
1. Apply Moore's Voting Algorithm
2. Verify majority element[will not be required if mojority element always appears]

If someone appears more than n/2 times, it will not get cancelled
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& arr){
        int ct = 0, element;
        for(int x: arr){
            if(ct==0) element = x, ct++;
            else if(x == element) ct++;
            else ct--;
        }
        return element;
    }
};

//#######################################################################
//#######-------18. Kadane's Algorithm, maximum subarray sum--------########
//Tutorial: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
//Problem: https://leetcode.com/problems/maximum-subarray/description/

Kadanes Algorithm
------------
Approach:
1. sum+=element;
2. Keep updating mxsum = max(sum, mxsum);
3. if sum if negative set sum = 0
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size(), sum = 0, mxsum = -1e9;
        for(int x: arr){
            sum+=x;
            mxsum = max(sum, mxsum);
            if(sum<0) sum = 0;
        }
        return mxsum;
    }
};

//#######################################################################
//#######-------19. Print subarray with maximum subarray sum (extended version of above problem)--------########
//Tutorial: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
//Problem: https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0

------------
Approach:
1. Find maximum sum between two pairs
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size(), mxSum = 0;
        for(int i=1;i<n;i++){
            mxSum = max(mxSum, arr[i-1] + arr[i]);
        }
        return mxSum;
    }
};

//#######################################################################
//#######-------20. Stock Buy and Sell--------########
//Tutorial: https://takeuforward.org/data-structure/stock-buy-and-sell/
//Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

------------
Approach:
1. Keep track of the minimum while traversing the loop 
2. If minimum is not found, keep updating with ans = max(ans, mx-mn);
3. ans would be what we need to output
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mn = INT_MAX, mx = INT_MIN, ans = 0;
        for(int x: prices){
            if(mn>x){
                mn = x;
                mx = x;
            }
            else{
                if(mx<x) mx = x, ans = max(ans, mx-mn);
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------21.1 Rearrange the array in alternating positive and negative items--------########
//Tutorial: https://takeuforward.org/arrays/rearrange-array-elements-by-sign/
//Problem: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

Variety 1: Make alternating sequence where Total count of positve == negative 

------------
Approach:
1. Take positive from main array and keep increasing index by 2
2. Take negative from main array and keep increasing index by 2
------------
Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size(), pi = 0, ng = 1;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[pi] = arr[i];
                pi+=2;
            }
            else{
                ans[ng] = arr[i];
                ng+=2;
            }
        }
        return ans;
    }
};

//#######-------21.2 Rearrange the array in alternating positive and negative items--------########
//Problem: https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

Variety 2: Make alternating sequence where Total count of positve != negative 

------------
Approach:
1. Push positive in positive array, negative in negative array 
2. Push both positive and negative in the answer array
3. If elements gets leftover push those element in the answer array as well
4. At the end, arr = ans
------------
Time Complexity: O(2N)
Space Complexity: O(N)

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int>pos, neg,ans(n);

        //O(N)
        for(int x: arr){
            if(x>=0)pos.push_back(x);
            else neg.push_back(x);
        }
        int pz = pos.size(), nz = neg.size();

        int i = 0, j = 0, ind = 0;

        //O(N)
        while (i < pz && j < nz) {
            ans[ind++] = pos[i++];
            ans[ind++] = neg[j++];
        }

        while (i < pz) {
            ans[ind++] = pos[i++];
        }

        while (j < nz) {
            ans[ind++] = neg[j++];
        }

        arr = ans;
    }
};

//#######################################################################
//#######-------22 Next Permutation--------########
//Tutorial: https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
//Problem: https://leetcode.com/problems/next-permutation/description/

//Approach
------------
Approach:
1.1 Find the break point [number that is smaller than previous number]
1.2 If break point does not exist, just reverse the array 
2. Find the next greater element and swap it with - swap( arr[break_point_ind], arr[next_greater_element])
3. Reverse the right half, from break point + 1 index to last index

------------
Time Complexity: O(3N)
Space Complexity: O(1) [without the given array]

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int bpoint = -1;

        for(int i=n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                bpoint = i;
                break;
            }
        }

        if(bpoint == -1){
            reverse(arr.begin(),arr.end());
            return;
        }

        for(int i=n-1;i>bpoint;i--){
            if(arr[bpoint] < arr[i]){
                swap(arr[bpoint], arr[i]);
                break;
            }
        }

        reverse(arr.begin()+bpoint+1, arr.end());
    }
};


//Another Approach(STL)
------------
Approach:
1. Use next permutation in stl
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        next_permutation(arr.begin(),arr.end());
    }
};


//#######################################################################
//#######-------23. Leaders in an Array problem--------########
//Tutorial: https://takeuforward.org/data-structure/leaders-in-an-array/
//Problem: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

------------
Approach:
1. Take the last element in the answer 
2. if(arr[i] >= ans.back() ) keep adding arr[i] in the answer array 
3. At the end, reverse the array 
------------
Time Complexity: O(2N)
Space Complexity: O(N)

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int>ans{arr[n-1]};
        for(int i=n-2;i>=0;i--){
            if(arr[i] >= ans.back() ) ans.push_back( arr[i] );
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//#######################################################################
//#######-------24. Longest Consecutive Sequence in an Array--------########
//Tutorial: https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
//Problem: https://leetcode.com/problems/longest-consecutive-sequence/description/

------------
Approach:
1. Put elements in unordered set 
2.1 If the previous element is also available donot search, move forward 
2.2 If the previous element is not available search from that element and keep counting answer

------------
Time Complexity: O(3N)
Space Complexity: O(N) [When all elements are unique]

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        //O(N)
        unordered_set<int>us(arr.begin(),arr.end());
        int ct = 1, ans = 0;
        //O(2N)
        for(auto x: us){
            if( us.find(x-1)==us.end() ){
                ct = 1;
                int element = x;
                while(us.find(element+1)!=us.end()){
                    element++;
                    ct++;
                }
                ans = max(ans, ct);
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------25. Set Matrix Zeros--------########
//Tutorial: https://takeuforward.org/data-structure/set-matrix-zero/
//Problem: https://leetcode.com/problems/set-matrix-zeroes/description/
https://www.geeksforgeeks.org/problems/make-zeroes4042/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()

//#######################################################################
//#######-------26. Rotate Matrix by 90 degrees--------########
//Tutorial: https://takeuforward.org/data-structure/rotate-image-by-90-degree/
//Problem: https://leetcode.com/problems/rotate-image/description/

//1st Approach
------------
Approach:
1. Take another matrix and keep pushing in their order
------------
Time Complexity: O(N*N) 
Space Complexity: O(N*N)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>ans(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][n-1-j] = matrix[j][i];
            }
        }
        matrix = ans;
    }
};

//2nd Approach
------------------------------------------------
------------
Approach:
1. Transpose and reverse
For transposing, use swapping in diagonal wise

Note: For anticlockwise, do reverse then transposing
------------
Time Complexity: O(N*N)
Space Complexity: O(1) [without any extra space by myself]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//#######################################################################
//#######-------27. Print the matrix in spiral manner--------########
//Tutorial: https://takeuforward.org/data-structure/spiral-traversal-of-matrix/
//Problem: https://leetcode.com/problems/spiral-matrix/description/
https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
https://www.geeksforgeeks.org/problems/spiral-matrix--141631/1

------------
Right -> Bottom -> Top -> Left
Approach:
1. 
------------
Time Complexity: O(N*M)
Space Complexity: O(N*M)


//#######################################################################
//#######-------28. Count subarrays with given sum--------########
//Tutorial: https://takeuforward.org/arrays/count-subarray-sum-equals-k/
//Problem: https://leetcode.com/problems/subarray-sum-equals-k/description/

------------
Approach:
1. Move ahead, keep track of sum
2. Keep finding the hashing of hash[sum-k] and update ct+=hash[sum-k];
------------
Time Complexity: O(N x logN)
Space Complexity: O(N) [To store hashing]

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        map<int, int>mp;
        mp[0] = 1;
        int ct = 0, sum = 0;
        for(int x: arr){
            sum+=x;
            if(mp.find(sum-k)!=mp.end()) ct+= mp[sum-k];
            mp[sum]++;
        }
        return ct;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//################-------Lec 3: Hard Problems--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------29. Pascal's Triangle--------########
//Tutorial: https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
//Problem: https://leetcode.com/problems/pascals-triangle/description/
https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()

//#######################################################################
//#######-------30. Majority Element (n/3 times)--------########
//Tutorial: https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
//Problem: https://leetcode.com/problems/majority-element-ii/description/

//Hashing Approach
------------
Approach:
1. if (element count == need) add element in answer 
------------
Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int need = (n/3) + 1;
        vector<int>ans;
        map<int, int>mp;
        for(int x: arr){
            mp[x]++;
            if(mp[x]==need){//ekbar e hobe eta
                ans.push_back(x);
            }
            if(ans.size()==2)break;
        }
        return ans;
    }
};

------------------------------------------------------------
// Moore's Voting Algorithm Approach
Moore's Voting Algorithm:

------------
Observations:
1. atmax the answer can have 2 integers (0, 1, 2 elements can be answer)

Approach:
1. Apply Moore's Voting Algorithm extended version
2. Verify majority element[if appear more than n/3+1 times]
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int need = (n/3) + 1, ct1 = 0, ct2 = 0, el1 = -1, el2 = -1;
        vector<int>ans;
        //Apply Moore's Voting Algorithm
        for(int i=0;i<n;i++){
            if(ct1==0 && el2!=arr[i]) ct1++, el1 = arr[i];
            else if(ct2==0 && el1!=arr[i]) ct2++, el2 = arr[i];
            else if(el1==arr[i]) ct1++;
            else if(el2==arr[i]) ct2++;
            else ct1--, ct2--;
        }
        //Verify Need
        ct1 = 0, ct2 = 0;
        for(int x: arr){
            if(el1==x) ct1++;
            else if(el2==x) ct2++;
        }
        if(need<=ct1) ans.push_back(el1);
        if(need<=ct2) ans.push_back(el2);
        return ans;
    }
};

//#######################################################################
//#######-------31. 3 Sum Problem--------########
//Tutorial: https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
//Problem: https://leetcode.com/problems/3sum/description/

//Better Solution - [Using Hashing]
------------
Approach:
Donot have to sort in this approach 

1. Use hashing to find the missing element

Here, 
s1 + s2 + s3 = 0
Hence, Missing element, s3 = -(s1+s2);

------------
Time Complexity: O(N^2 * logM)
Space Complexity: O(N) + O(number of tripet) [for storing hash + number of tripet]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>>st;
        int target = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int s1 = arr[i];
            set<int>us;
            for(int j=i+1;j<n;j++){
                int s2 = arr[j], s3 = -(s1+s2);
                if(us.find(s3)!=us.end()){
                    vector<int>tmp{s1,s2,s3};
                    sort(tmp.begin(),tmp.end());
                    st.insert(tmp);
                }
                us.insert(arr[j]);
            }
        }

        vector<vector<int>> ans {st.begin(),st.end()};
        return ans;
    }
};

//Optimal [Using Two Pointer + Set]
------------
Approach:
1. Use two pointer apprach 
2. Find target == 0, using two pointer
------------
Time Complexity: O(NlogN) + O( N^2 * log(number of tripets) ) 
Space Complexity: O(number of tripet)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>>st;
        sort(arr.begin(), arr.end());
        int target = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int s1 = arr[i];
            int l = i+1, r = n-1;
            while(l<r){
                int s2 = arr[l], s3 = arr[r];
                int total = s1+s2+s3;
                if( total == target){
                    vector<int>tmp{s1,s2,s3};
                    st.insert(tmp);
                    l++, r--;
                }
                else if(total < target) l++; 
                else if(total > target) r--;
            } 
        }
        
        vector<vector<int>> ans {st.begin(),st.end()};
        return ans;
    }
};

//Best Optimal [Without Using set]
------------
Approach:
To avoid using set just write 3 simple condition

1.1 if(i && arr[i]==arr[i-1]) continue;
1.2 while(l<r && arr[l]==arr[l-1]) l++;
1.3 while(l<r && arr[r]==arr[r+1]) r--;
------------
Time Complexity: O(NlogN) + O(N^2)
Space Complexity: O(number of tripet)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        int target = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(i && arr[i]==arr[i-1]) continue;
            int s1 = arr[i];
            int l = i+1, r = n-1;
            while(l<r){
                int s2 = arr[l], s3 = arr[r];
                int total = s1+s2+s3;
                if( total == target ){
                    vector<int>tmp{s1,s2,s3};
                    ans.push_back(tmp);
                    l++, r--;
                    while(l<r && arr[l]==arr[l-1]) l++;
                    while(l<r && arr[r]==arr[r+1]) r--;
                }
                else if(total < target) l++; 
                else if(total > target) r--;
            } 
        }
        return ans;
    }
};

//#######################################################################
//#######-------32. 4 Sum Problem--------########
//Tutorial: https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
//Problem: https://leetcode.com/problems/4sum/description/

//Better Solution
------------
Approach:
1. Use Hashing Approach to solve the problem(same as 3SUM Problem)

------------
Time Complexity: O(N^3 * logM)
Space Complexity: O(N) + O(number of quadruplet)x2 [for putting in set + for returning ans]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        set<vector<int>>st;
        int n = arr.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                unordered_set<long long> us;
                for(int k=j+1;k<n;k++){
                    int s1 = arr[i], s2 = arr[j], s3 = arr[k];
                    long long total = s1+s2;
                    total+=s3;
                    long long s4 = target - total;
                    if(us.find(s4)!=us.end()){
                        vector<int>tmp{s1,s2,s3,(int)s4};
                        sort(tmp.begin(),tmp.end());
                        st.insert(tmp);
                    }
                    us.insert(arr[k]);//just add the last one, or it will add the duplicates
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

//Optimal Solution [Without Using Hashing and set]
------------
Approach:
First two elements are constant only 
1. Use two pointer Approach to solve the problem(same as 3SUM Problem)

------------
Time Complexity: O(N^3)
Space Complexity: O(number of quadruplet)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(i && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j-1!=i && arr[j]==arr[j-1]) continue;
                int l = j+1, r = n-1;
                while(l<r){
                    int s1 = arr[i], s2 = arr[j], s3 = arr[l], s4 = arr[r];
                    //long long total = 1LL - 1LL + s1+s2+s3+s4;
                    long long total = s1+s2;
                    total+=s3+s4;
                    if( total == target ){
                        vector<int>tmp{s1,s2,s3,s4};
                        ans.push_back(tmp);
                        l++, r--;
                        while(l<r && arr[l]==arr[l-1]) l++;
                        while(l<r && arr[r]==arr[r+1]) r--;
                    }
                    else if(total < target) l++; 
                    else if(total > target) r--;
                }
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------33. Largest Subarray with 0 Sum--------########
//Tutorial: https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
//Problem: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//Problem2[same problem, just a variation]: https://leetcode.com/problems/contiguous-array/description/

------------
Approach:
1. Keep increasing sum with arr[i]
2. Keep mp[0] = -1;
3. if mp[sum] is found, update answer with max(ans, i - mp[sum])
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int mxLength = 0, sum = 0;
        map<int, int>mp;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()){
                mxLength = max(mxLength, i - mp[sum]);
            }
            else mp[sum] = i;
        }
        return mxLength;
    }
};

//#######################################################################
//#######-------34. Count number of subarrays with given xor K--------########
//Tutorial: https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
//Problem: https://www.interviewbit.com/problems/subarray-with-given-xor/

Formula: x = total xor ^ k
Same as other hashing problems 

------------
Approach:
1. Move ahead, keep track of xorSum
2. Keep finding the hashing of hash[xorSum^k] and update ans+=mp[xorSum^k];
------------
Time Complexity: O(N*logN)
Space Complexity: O(N)

int Solution::solve(vector<int> &arr, int k) {
    int allXor = 0, ans = 0;
    map<int, int>mp;
    mp[0] = 1;
    for(int x: arr){
        allXor^=x;
        int target = allXor^k;
        ans+=mp[target];
        mp[allXor]++;
    }
    return ans;
}

//#######################################################################
//#######-------35. Merge Overlapping Subintervals--------########
//Tutorial: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
//Problem: https://leetcode.com/problems/merge-intervals/description/

//My Approach
------------
Khatai aro kora, aro bujhte chaile 

Approach:
1. Set start and end interval from intervals[0] 
2. if end>=intervals[0][0] update end with the maximum end interval 
3. else push_back answer and update new start and end interval 
4. push_back the last interval
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int st = intervals[0][0], end = intervals[0][1];
        for(int i=1;i<n;i++){
            if( end >= intervals[i][0] ){
                if(end<intervals[i][1]) end = intervals[i][1];
            }
            else{
                ans.push_back({st,end});
                st = intervals[i][0], end = intervals[i][1];
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};

//Another Way(Striver Approach)
------------------------------------------------
------------
Approach:
1. if ans.empty() or intervals[i][0] > ans.back()[1] keep adding answer 
2. else keep updating ans.back()[1] with max of (ans.back()[1], intervals[i][1])
2. if end>=intervals[0][0] update end with the maximum end interval 
3. else push_back answer and update new start and end interval 
4. push_back the last interval
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        for(int i=0;i<n;i++){
            if( ans.empty() || intervals[i][0] > ans.back()[1] ){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                ans.back()[1] = max( ans.back()[1], intervals[i][1] );
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------36. Merge two sorted arrays without extra space--------########
//Tutorial: https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
//Problem: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

//1st Optimal Solution
------------
Approach:
1. Keep swapping until arr1[right] > arr1[left], else break 
2. After that, sort arr1 and arr2
------------
Time Complexity: O(N) + O(NlogN) + O(NlogN)
Space Complexity: O(1)

class Solution{
    public:
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int right = n-1, left = 0;
            while(right>=0 && left<m){
                if( arr1[right] > arr2[left] ){
                    swap(arr1[right], arr2[left]);
                    right--, left++;
                }
                else{
                    break;
                }
            }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};

------------------------------------------------
//2nd Optimal Solution

Shell sort algorithm
//Tutorial: https://www.geeksforgeeks.org/shell-sort/

------------
Gap method: Comes from shell sort 
Approach:
1. Use Shell sort algorithm and sort the both array 
2. There would be 3 cases while swapping 
a. Both pointer is in the arr1
b. Both pointer is in the arr2
c. One pointer is in the arr1 and the other is in the arr2 
------------
Time Complexity: O(log2(n+m)) x O(n+m)
Space Complexity: O(1)

class Solution{
    public:
        void swapp(long long arr1[], long long arr2[], int ind1, int ind2) {
            if (arr1[ind1] > arr2[ind2]) {
                swap(arr1[ind1], arr2[ind2]);
            }
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        {   
            int len = n + m;
            int gap = len + len%2;
            while(1){
                int l = 0, r = gap;
                while(r<len){
                    //both in arr1
                    if(l<n && r<n){
                        swapp(arr1, arr1,l,r);
                    }
                    //both in arr2
                    else if(l>=n){
                        swapp(arr2, arr2,l-n,r-n);
                    }
                    //one in arr1, one in arr2
                    else{
                        swapp(arr1, arr2,l,r-n);
                    }
                    l++,r++;
                }
                if(gap==1)break;
                gap = gap/2 + gap%2;
            }
        } 
};

//#######################################################################
//#######-------37. Find the repeating and missing number--------########
//Tutorial: https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
//Problem: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

//1st Approach - Using Math
------------
Approach:
1. Find first natural sum and first square natural sum 
2. derive the missing and repeating using math formula[watch the video for the formula]
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    vector<int> findTwoElement(vector<int> arr) {
        long long n = arr.size();
        
        long long sum = 0,    arr_sum = 0;
        long long sq_sum = 0, sq_arr_sum = 0;
        sq_sum = (n*(n+1)*(2*n+1))/6;
        sum = (n*(n+1))/2;
        
        for(int x: arr){
            arr_sum+= x;
            sq_arr_sum+= 1LL*x*x;
        }
        
        //x - y
        long long v1 = sum - arr_sum;
        //x^2 - y^2
        long long v2 = sq_sum - sq_arr_sum;
        
        //(x+y)(x-y) = x^2 - y^2 = v2
        // (x+y) = (x^2 - y^2) / (x-y)
        
        //x + y
        v2 = v2/v1;
        
        long long x = (v1+v2)/2;
        long long y = x - v1;
        
        return {(int)y,(int)x};
    }
};

//2nd Approach - Using xor
??confused
------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()



//#######################################################################
//#######-------38. Count Inversions--------########
//Tutorial: https://takeuforward.org/data-structure/count-inversions-in-an-array/
//Problem: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/0

------------
Approach:
1. Use merge sort to count the inversion
------------
Time Complexity: O(Nlogn)
Space Complexity: O(N)

class Solution {
  public:
    long long merge(long long ar[],long long l,long long m, long long h){
        vector<long long> temp;
        long long cnt = 0;

        long long i = l;     
        long long j = m + 1; 
    
        while (i <= m && j <= h) {
            if (ar[i] <= ar[j]) {
                temp.push_back(ar[i]);
                i++;
            } else {
                temp.push_back(ar[j]);
                cnt+= (m + 1 - i);
                j++;
            }
        }
    
        while (i <= m) {
            temp.push_back(ar[i]);
            i++;
        }
    
        while (j <= h) {
            temp.push_back(ar[j]);
            j++;
        }
    
        for (long long k = l; k <= h; k++) {
            ar[k] = temp[k-l];//
        }
        return cnt;
    }
    
    long long merge_sort(long long ar[], long long l,long long h){
        long long cnt = 0;
        if(l>=h){
            return cnt;
        }
        long long m = l + (h-l)/2;
        cnt+=merge_sort(ar,l,m);
        cnt+=merge_sort(ar,m+1,h);
    
        cnt+=merge(ar,l,m,h);
        return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
        return merge_sort(arr, 0LL, n-1);
    }
};

//#######################################################################
//#######-------39. Reverse Pairs--------########
//Tutorial: https://takeuforward.org/data-structure/count-reverse-pairs/
//Problem: https://leetcode.com/problems/reverse-pairs/description/

------------
Approach:
1. Use Merge Sort 
2. Before merging count the number of reverse pair [watch the video for better understanding]
------------
Time Complexity: O(2N*logN)
Space Complexity: O(N)

class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;  
        int right = mid + 1;

        int cnt = 0;
        int l = left, r = right;
        for(int i=left;i<=mid;i++){
            while(r<=high && arr[i] > 2LL * arr[r]) r++;
            cnt+= (r - (mid+1));
        }

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = low + (high-low) / 2 ;
        cnt += mergeSort(arr, low, mid);  
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high); 
        return cnt;
    }
    int reversePairs(vector<int>& arr) {
        int ans = mergeSort(arr, 0, arr.size()-1);
        return ans;
    }
};

//#######################################################################
//#######-------40. Maximum Product Subarray--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/
//Problem: https://leetcode.com/problems/maximum-product-subarray/description/

------------
Constraint Numbers are very small, that is a big hint of using prefix/suffix multiplication

Approach:
4 Observations:
1. All numbers are positive 
2. Count of negative numbers are even
3. Count of negative numbers are odd[in that case remove only 1 number]
4. There are number 0 [in that case, change prefix or suffix to 1]

Steps:
Think of prefix,suffix multiplication
1. In one loop, keep calculating prefix and suffix 
and keep updating answer with the maximum multiplication

------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MIN;
        int pre = 1, suff = 1;
        for(int i=0;i<n;i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre = pre * arr[i];
            suff = suff * arr[n-i-1];
            ans = max({ans, pre, suff});
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