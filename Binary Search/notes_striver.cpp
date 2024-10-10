//Binary Search

- Binary search always applicable in sorted area
- In searching kind of things, think of using binary search
- minimum and maximum integer do binary search
- search and sorting, use binary search


---------------------------------------------------------------------------------------------------------
Striver Binary Search Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF
Resource: https://takeuforward.org/blogs/binary-search
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------BS on 1D Arrays--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------BS-1. Binary Search Introduction | Real Life Example | Iterative | Recursive | Overflow Cases--------########
//Tutorial: https://takeuforward.org/data-structure/binary-search-explained/
//Problem: https://leetcode.com/problems/binary-search/description/


------------------------Theory----------------------------------
- Time complexity of binary search: O(log2n)
- For overflow use: m = l + (r-l)/2;


------------
Approach:
1. Find in left half or right half
2. if not found change the right half or left half
------------

//Iterative Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while(l<=r){
            m = (l+r)>>1;
            if(nums[m]==target) return m;
            else if(nums[m]>target) r = m-1;
            else l = m+1;
        }
        return -1;
    }
};

//recursive binary search
- Used in merge sort (etodin por e bujhlam 25 august, 2024)

class Solution {
public:
    int f(vector<int>& nums,int low, int high, int target){
        if(low>high) return -1;//if returns -1 anytime it is -1 everytime
        int mid = (low+high)>>1;
        if(nums[mid]==target) return mid;
        else if(nums[mid] > target) return f(nums, low, mid-1, target);
        else return f(nums, mid+1, high, target);
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        return f(nums, l, r, target);
    }
};

//#######################################################################
//#######-------BS-2. Implement Lower Bound and Upper Bound | Search Insert Position | Floor and Ceil--------########

lowerbound: greater than or equal to x
upperbound: greater than x

//#######-------BS-2.1 Implement Lower Bound--------########
//Tutorial: https://takeuforward.org/arrays/implement-lower-bound-bs-2/
//Problem: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

------------
Approach:
1. just apply lowerbound
------------

class Solution {
  public:
    int findFloor(vector<long long> &v, long long n, long long x) {
        long long lw = lower_bound(v.begin(), v.end(), x) - v.begin();
        return v[lw]==x?lw:lw-1;
    }
};

//#######-------BS-2.2 Floor/Ceil in Sorted Array--------########
//Tutorial: https://takeuforward.org/arrays/implement-upper-bound/
//Problem: https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

------------
Approach:
1. use lowerbound and upperbound and find the answer
------------

int low(vector<int> &v, int x){
	int ans = -1;
	int l = 0, r = v.size()-1,m;
	while(l<=r){
		m = (l+r)/2;
		if(v[m]<=x){
			ans = v[m];
			l = m + 1;
		}
		else r = m - 1;
	}
	return ans;
}

int up(vector<int> &v, int x){
	int ans = -1;
	int l = 0, r = v.size()-1,m;
	while(l<=r){
		m = (l+r)/2;
		if(x<=v[m]){
			ans = v[m];
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &v) {
        sort(v.begin(),v.end());
        int lw = low(v, x);
    	int u  = up(v, x);
    	return {lw,u};
    }
};

//#######-------BS-2.3 Search Insert Position--------########
//Tutorial: https://takeuforward.org/arrays/search-insert-position/
//Problem: https://leetcode.com/problems/search-insert-position/description/

------------
Approach:
1. use lowerbound
------------

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(),m;
        while(l+1<r){
            m = (l+r)>>1;
            if(nums[m]<=target){
                l = m;
            }
            else r = m-1;
        }
        return l;
    }
};

//#######################################################################
//#######-------BS-3. First and Last Occurrences in Array --------########
//Tutorial: https://takeuforward.org/data-structure/last-occurrence-in-a-sorted-array/
//Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

------------
Approach:
1. use lowerbound and upperbound
Time Complexity: O(2 * log n)
------------

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lw = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lw==nums.size()) return {-1, -1};
        if(nums[lw]!=target) return {-1, -1};
        return {lw, up-1};
    }
};

//#######################################################################
//#######-------BS-3.2 Count occurrences in Array--------########
//Tutorial: https://takeuforward.org/data-structure/count-occurrences-in-sorted-array/
//Problem: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

------------
Approach:
1. use lowerbound and upperbound
2. answer: (up - lw)+1;
------------

class Solution{
public:	
	int count(int arr[], int n, int x) {
	    int lw = lower_bound(arr, arr+n, x) - arr;
	    int up = upper_bound(arr, arr+n, x) - arr - 1;
	    if(lw==n) return 0;
	    if( arr[lw]!=x) return 0;
	    return (up - lw)+1;
	    
	}
};

//#######################################################################
//#######-------BS-4. Search Element in Rotated Sorted Array - I--------########
//Tutorial: https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/
//Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

------------
Approach:
Either one part is always sorted(right half)
left and right pashapashi ante chaile while(l<=r) use kora

There are 4 cases 
1. arr[m]<=arr[r] sorted and key is in the range (l=m+1)
2. arr[m]<=arr[r] sorted and key is not in the range (r=m-1)
3. arr[l]<=arr[m] sorted and key is in the range (r=m-1)
4. arr[l]<=arr[m] sorted and key is not in the range (l=m+1)

Time Complexity: O(logN)
------------

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int l = 0, r = n-1, m;
        while(l<=r){//left and right pashapashi ante chaile
            m = (l+r)>>1;
            if(arr[m]==key) return m;
            if(arr[m]<=arr[r]){//this part is sorted
                if( arr[m]<=key && arr[r]>=key){//check if key lies in this part if so elimiate left half
                    l = m+1;
                }
                else r = m-1;//else eliminate right half
            }
            else{//from arr[l] to arr[m] is sorted here
                if( arr[l]<=key && arr[m]>=key) r = m-1;
                else l = m+1;
            }
        }
        return -1;
    }
};

//#######################################################################
//#######-------BS-5. Search Element in Rotated Sorted Array II--------########
//Tutorial: https://takeuforward.org/arrays/search-element-in-rotated-sorted-array-ii/
//Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

jehetu duplicate ase we cannot say explicitly one part is sorted(so l++, r--)
------------
Approach:
1. Prequisite: BS-4. Search Element in Rotated Sorted Array - I
2. and just add this new line if(arr[l]==arr[m] && arr[m]==arr[r]) l++, r--;

Time Complexity: O(logN) for the best and average case. O(N/2) for the worst case. Here, N = size of the given array.
------------
class Solution {
public:
    bool search(vector<int>& arr, int key) {
        int n = arr.size();
        int l = 0, r = n - 1, m;
        while(l<=r){
            m = (l+r)>>1;
            if(arr[m] == key) return true;
            if(arr[l]==arr[m] && arr[m]==arr[r]) l++, r--;
            
            else if(arr[m]<=arr[r]){
                if( arr[m]<=key  && key<=arr[r]) l = m + 1;
                else r = m - 1;
            }
            else{
                if( arr[l]<=key  && key<=arr[m]) r = m - 1;
                else l = m + 1;
            }
        }
        return false;
    }
};

//#######################################################################
//#######-------BS-6. Minimum in Rotated Sorted Array--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/
//Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

identify the sorted half
------------
Approach:
There are 2 cases 
1. arr[l]<=arr[m] sorted minimum is arr[l] and update l = m+1
2. arr[m]<=arr[r] sorted minimum is arr[m] and update r = m-1
------------
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1, m, ans = INT_MAX;
        while(l<=r){
            m = (l+r)>>1;
            if( arr[l]<= arr[m]) {
                ans = min(ans, arr[l]);//update the minimum and move forward
                l = m + 1;
            }
            else if( arr[m] <= arr[r]){
                ans = min(ans, arr[m]);
                r = m - 1;
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------BS-7. Find out how many times array has been rotated--------########
//Tutorial: https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated/
//Problem: https://www.geeksforgeeks.org/problems/rotation4723/1

Prequisite: BS-6. Minimum in Rotated Sorted Array
------------
Approach:
1. Find the index of the minimum element, that is our answer
------------
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = n - 1, m, mini = INT_MAX, index = 0;
        while(l<=r){
            m = (l+r)>>1;
            if(arr[l]<=arr[m]){
                if(mini>=arr[l]) 
                    index = l, mini = arr[l];
                l = m + 1;
            }
            else{
                if(mini>=arr[m])
                    index = m, mini = arr[m];
                r = m - 1;
            }
        }
        return index;
    }
};

//#######################################################################
//#######-------BS-8. Single Element in Sorted Array--------########
//Tutorial: https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
//Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

------------
Approach:
Think in terms of index(odd even change hoe jawa index e)

There are 2 cases 
1.1 mid is even and next element is same, then answer lies in right, so l = m
1.2 Same way, mid is odd and previous element is same, then answer lies in right, so l = m

2. Else answer always lies in left, so r = m;

------------
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1, m;
        while(l<=r){
            m = (l+r)>>1;
            if( ( !(m&1) && m+1<n && arr[m]==arr[m+1]) || ( m&1 && m-1>=0 && arr[m-1]==arr[m]) ) l = m + 1;
            else r = m - 1;
        }
        return arr[l];
    }
};

//Another one (l+1<r)
Invariant: 1111100000 - > first 0 is the answer

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = -1, r = n - 1, m;
        while(l+1<r){
            m = (l+r)>>1;
            if( ( !(m&1) && m+1<n && arr[m]==arr[m+1]) || ( m&1 && m-1>=0 && arr[m-1]==arr[m]) ) l = m;
            else r = m;
        }
        return arr[r];
    }
};

//#######################################################################
//#######-------BS-9. Find Peak Element--------########
//Tutorial: https://takeuforward.org/data-structure/peak-element-in-array/
//Problem: https://leetcode.com/problems/find-peak-element/description/

assuming 1 2 2 1 erokom nai
There will always be a peak according to question
------------
Approach:
Think in slope graph
1. if mid-1 < mid > mid+1 then return mid 
2. if mid-1 < mid answer will be in left (l=m+1)
3. else answer will be in right ( r = m - 1)
------------
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int l = 1, r = n - 2, m;
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n - 1;
        while(l<=r){
            m = (l+r)>>1;
            if( arr[m] > arr[m-1] && arr[m] > arr[m+1] ){
                return m;
            }
            else if( arr[m] > arr[m-1] ) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//###################-------BS on Answers--------########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------BS-10. Finding Sqrt of a number using Binary Search--------########
//Tutorial: https://takeuforward.org/binary-search/finding-sqrt-of-a-number-using-binary-search/
//Problem: https://leetcode.com/problems/sqrtx/description/

Monotony works here 
Invariant of sqrt: 1111100000

------------
Approach:
1. if(m*m<=n) move left = m, else move right = m;
------------
class Solution {
public:
    int mySqrt(int n) {
        long long l = 0, r = n, m;
        r++;
        while(l+1<r){
            m = (l+r)>>1;
            if(m*m<=n) l = m;
            else r = m;
        }
        return l;
    }
};

//#######################################################################
//#######-------BS-11. Find the Nth root of an Integer--------########
//Tutorial: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
//Problem: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

------------
Approach:
1. if pow(mid, n) == m then mid is our answer
2. if pow(mid, n) < m move left to mid 
3. else move right to mid
------------

class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    long long l = 0, r = 1e9, mid;
	    while(l+1<r){
	        mid = (l+r)>>1;
	        if(pow(mid, n) == m) return mid;
	        if( pow(mid, n) <= m ) l = mid;
	        else r = mid;
	    }
	    return -1;
	}  
};

//#######################################################################
//#######-------BS-12. Koko Eating Bananas--------########
//Tutorial: https://takeuforward.org/binary-search/koko-eating-bananas/
//Problem: https://leetcode.com/problems/koko-eating-bananas/description/

Q: Find the minimum banana to eat in every hour to complete in h hours

Invariant: 0000011111
------------
Approach:
1. traverse the array in binary search 
2. if( v <= h ) return r = m, else l = m 

------------
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = 1e9, m;
        int n = piles.size();
        while(l+1<r){
            m = l + (r-l)/2;
            long long v = 0;
            for(int i=0;i<n;i++){
                v += ((piles[i] + m - 1 ) / m);
            }
            if( v <= h ) r = m;
            else l = m;//l boro kora mane aro beshi khabe
        }
        return r;
    }
};

//#######################################################################
//#######-------BS-13. Minimum days to make M bouquets--------########
//Tutorial: https://takeuforward.org/arrays/minimum-days-to-make-m-bouquets/
//Problem: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

Q: Minimum days to make m bouquets with k adjacent flower

Invariant: 0000011111
------------
Approach:
1. if bloom(i) <= mid then ct++, else ct = 0
    if( ct == k) increase v++, ct=0;
    if(v>=m) then it is true, else false
2. only for if( n < m*k ) return -1;, else it is always possible
------------

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long l = 0, r = LONG_MAX , mid;
        int n = bloomDay.size();
        if( n/k < m ) return -1;//for overflow don't use n < m*k

        while(l+1<r){
            mid = l+(r-l)/2;
            int ct = 0, v = 0;
            for(int i=0;i<n;i++){
                if( bloomDay[i]<=mid) ct++;
                else ct = 0;
                if(ct==k)v++, ct = 0;
            }
            if( v>=m ) r = mid;
            else l = mid;
        }
        return r;
    }   
};

//#######################################################################
//#######-------BS-14. Find the Smallest Divisor Given a Threshold--------########
//Tutorial: https://takeuforward.org/arrays/find-the-smallest-divisor-given-a-threshold/
//Problem: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

Q: after dividing every value, calculate the ceil of the division, Get the smallest divisors that satisfies <=k 
Invariant: 0000011111

------------
Approach:
1. if(v<=k) r = m; else l = m;
Time complexity: O(Log2(1e9) * n)
------------

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int k) {
        int l = 0, r = 1e9, m, n = nums.size();
        while(l+1<r){
            m = (l+r)>>1;
            int v = 0;
            for(int i=0;i<n;i++){
                v+= ( nums[i] + m - 1)/m;//using this to get the ceil value
            }
            if(v<=k) r = m;
            else l = m;
        }
        return r;
    }
};

//#######################################################################
//#######-------BS-15. Capacity to Ship Packages within D Days--------########
//Tutorial: https://takeuforward.org/arrays/capacity-to-ship-packages-within-d-days/
//Problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

Invariant: 0000011111
Q: Least amount of product to ship within D days 

------------
Approach:
1. if( min_days<=days && ok) r = m; else l = m;

answer should be in: [MAX ELEMENT, SUMMATION OF THE ARRAY]
------------
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 1e9, m, n = weights.size();
        while(l+1<r){
            m = (l+r)>>1;
            int s = 0, min_days = 1;
            bool ok = true;
            for(int i=0;i<n;i++){
                if( s + weights[i] > m){
                    min_days++;
                    s = weights[i];
                    if(s>m){
                        ok = false;//starting max element theke korle eta korte hobe na
                        break;
                    }
                }
                else s+=weights[i];
            }
            if( min_days<=days && ok) r = m;
            else l = m;
        }
        return r;
    }
};

//#######################################################################
//#######-------BS-16. Kth Missing Positive Number | Maths + Binary Search--------########
//Tutorial: https://takeuforward.org/arrays/kth-missing-positive-number/
//Problem: https://leetcode.com/problems/kth-missing-positive-number/description/

------------
Approach:
1. if(arr[i]<=k) k++;else break, k is the answer
------------
//brute
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
    }
};

//binary search
------------
Approach:
" Think number of missing numbers "

1. if k is lesser than in the range of number of missing then l = m, else r = m

missing = arr[m] - (m+1)
------------
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = -1, r = n, m;
        while(l+1<r){
            m = (l+r)>>1;
            if(arr[m] - (m+1) < k ) l = m;
            else r = m;
        }
        return k+l+1;
    }
};

//#######################################################################
//#######-------BS-17. Aggressive Cows--------########
//Tutorial: https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
//Problem: https://www.geeksforgeeks.org/problems/aggressive-cows/1
//Problem2: https://leetcode.com/problems/magnetic-force-between-two-balls/

striver approach: while(l<=r), changing polarity, r would be answer there

Invariant: 1111100000
Q: place all k cow in a maximum distance 

minimum of maximum

------------
Approach:
1. now distance - last distance, ct++
2. if ct>=k that is more than what we need, l = m, else r = m;

------------
class Solution {
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int l = 0, r = 1e9+1, m;
        while(l+1<r){
            m = (l+r)/2;
            int ct = 1;//already placed 1 cow in stall 0
            int la = stalls[0];
            for(int i=1;i<n;i++){
                if( (stalls[i] - la) >=m )ct++, la = stalls[i];
            }
            if(ct>=k) l = m;
            else r = m;
        }
        return l;
    }
};

//#######################################################################
//#######-------BS-18. Allocate Books or Book Allocation--------########
//Tutorial: https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
//Problem: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

Invariant: 0000011111
Q: allot all m student in a minimum number of page page book

------------
Approach:
1. similar to aggrocow
------------
class Solution {
  public:
    long long findPages(int n, int arr[], int k) {
        if(n<k) return -1;
        int l = *max_element(arr,arr+n)-1, r = 1e9, m;//answer always right side e rakhbo, that is why l = -1, not possible state theke
        while(l+1<r){
            m = (l+r)>>1;
            int student = 1, s = 0;
            for(int i=0;i<n;i++){
                if( s + arr[i] > m){
                    student++;
                    s = arr[i];
                }
                else s+=arr[i];
            }
            if(student<=k) r = m;
            else l = m;
        }
        return r;
    }
};

//#######################################################################
//#######-------BS 19. Painter's Partition--------########
//Tutorial: https://takeuforward.org/arrays/painters-partition-problem/
//Problem: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
(Painters Partition)

Invariant: 000000111111
Q: split in k partition with such where maximum sum of the the partition is minimum

------------
Approach:
1. similar to BS-18. Allocate Books
------------

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        int l = *max_element(arr,arr+n)-1, r = 1e9, m;
        while(l+1<r){
            m = (l+r)>>1;
            int v = 1, s = 0;
            for(int i=0;i<n;i++){
                if( s + arr[i] > m){
                    v++;
                    s = arr[i];
                }
                else s+=arr[i];
            }
            if( v <= k ) r = m;
            else l = m;
        }
        return r;
    }
};

//#######################################################################
//#######-------BS 19.2 Split Array - Largest Sum--------########
//Tutorial: https://takeuforward.org/arrays/split-array-largest-sum/
//Problem: https://leetcode.com/problems/split-array-largest-sum/description/

(Split Array - Largest Sum)

Invariant: 000000111111
Q: split in k segment with such maximum value is minimum

------------
(Maximum of minimum)
Approach:
1. similar to BS-18. Allocate Books
------------
class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(),arr.end())-1, r = 1e9, m;//max - 1, cause mx can be our answer, it is in right
        int n = arr.size();
        while(l+1<r){
            m = (l+r)>>1;
            int v = 1, s = 0;
            for(int i=0;i<n;i++){
                if( s + arr[i] > m){
                    v++;
                    s = arr[i];
                }
                else s+=arr[i];
            }
            if( v <= k ) r = m;
            else l = m;
        }
        return r;
    }
};

//#######################################################################
//#######-------BS-20. Minimise Maximum Distance between Gas Stations | 3 Approaches | Heap | Binary Search--------########
//Tutorial: https://takeuforward.org/arrays/minimise-maximum-distance-between-gas-stations/
//Problem: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

Invariant: 
Q: setting up gas stations such that maximum distance between any two station is minimum
Thought of priority queue 

------------
Approach:
1. 
------------

//#######################################################################
//#######-------BS 21: Median of two Sorted Arrays of Different Sizes--------########
//Tutorial: https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
//Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

------------
Bruteforce Approach(AC in leetcode):
1. if odd print the mid 
2. else both mid / 2

Time complexity: O(n+m) + (n+m)log(n+m)
------------

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        if(n & 1) return nums1[n/2];
        return (nums1[n/2] + nums1[n/2 - 1]) / 2.00 ;
    }
};

//#######################################################################
//#######-------BS-21.2 Median of two Sorted Arrays of Different Sizes--------########
//Tutorial: https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
//Problem: https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1

//Binary search approach
Symmetry

------------
Approach:
1. 
------------

//#######################################################################
//#######-------Bs-22. K-th element of two sorted arrays--------########
//Tutorial: https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/
//Problem: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

Q: Finding kth element of two sorted arrays

------------
Approach:
1. 
------------
//Brute Force
Time Complexity: O(m+n) + O(nlogn)
Space Complexity: O(n+m)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        for(int i=0;i<arr2.size();i++)arr1.push_back(arr2[i]);
        sort(arr1.begin(),arr1.end());
        return arr1[k-1];
    }
};

//Better
Time Complexity: O(m+n)
Space Complexity: O(1)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int ct = 0, ans = 0;
        int i,j;
        for(i=0, j = 0;i<n && j<m;){
            if(arr1[i]>=arr2[j]){
                ct++;
                if(ct==k){
                    ans = arr2[j];
                    break;
                }
                j++;
            }
            else{
                ct++;
                if(ct==k){
                    ans = arr1[i];
                    break;
                }
                i++;
            }
        }
        while(i<n){
            ct++;
            if(ct==k){
                ans = arr1[i];
                break;
            }
            i++;
        }
        
        while(j<m){
            ct++;
            if(ct==k){
                ans = arr2[j];
                break;
            }
            j++;
        }
        return ans;
    }
};

//Optimal


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#################-------BS on 2D Arrays--------########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------BS 23. Row with maximum number of 1s | Binary Search on 2D Arrays--------########
//Tutorial: https://takeuforward.org/arrays/find-the-row-with-maximum-number-of-1s/
//Problem: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

------------
Approach:
1. go through every rows(this cannot be optimized)
2. optimize going to each column to O(logm) using lowerbound or binary searching
------------

//lowerbound
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size(), m = arr[0].size(), mx = 0, index = -1;
        for(int i=0;i<n;i++){
            int lw = lower_bound(arr[i].begin(),arr[i].end(), 1) - arr[i].begin();
            if(mx < m - lw){
                index = i;
                mx = m - lw;
            }
        }
        return index;
    }   
};

//custom binary search
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size(), m = arr[0].size(), mx = 0, index = -1;
        for(int i=0;i<n;i++){
            int l = -1, r = m, mid;
            while(l+1<r){
                mid = (l+r)>>1;
                if(arr[i][mid]==0) l = mid;
                else r = mid;
            }
            if(mx < m - r){
                index = i;
                mx = m - r;
            }
        }
        return index;
    }   
};

//#######################################################################
//#######-------BS-24. Search in a 2D Matrix - I | Binary Search of 2D--------########
//Tutorial: https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
//Problem: https://leetcode.com/problems/search-a-2d-matrix/description/

//Approach
------------
Approach:
1. search using lowerbound 
2. if lw == m or matrix[i][lw] != target then false, else true;
Time Complexity: O(N + logM)//logM ekbar hobe shejnno
------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]<target)continue;//i greater move to next index
            int lw = lower_bound(matrix[i].begin(),matrix[i].end(), target) - matrix[i].begin();
            if(lw==m || matrix[i][lw]!=target) return false;
            else return true;
        }
        return false;
    }
};

//Another Approach
------------
Approach2:
1. Hypotheically, change the 2d array to 1D array
Time Complexity: O(logN*M)
------------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = -1, r = (n*m) - 1, mid = 0;
        while(l+1<r){
            mid = (l+r)>>1;
            int row = mid/m, col = mid%m;
            if( matrix[row][col]<target) l = mid;
            else r = mid;
        }
        return matrix[r/m][r%m]==target?true:false;
    }
};


//#######################################################################
//#######-------BS-25. Search in a 2D Matrix - II | Binary Search on 2D--------########
//Tutorial: https://takeuforward.org/arrays/search-in-a-row-and-column-wise-sorted-matrix/
//Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

//Approach
------------
Approach:
1. if inside a matrix[i] then do lowerbound in that index
Time Complexity: O(N*logM)//*logM cause onekbar lowerbound khujte pare
------------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
                int lw = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
                if( lw!=m && matrix[i][lw]==target) return true;
            }
        }
        return false;
    }
};

//Another Approach
------------
Approach2:
1. mat[i][m-1] theke niche or side e jawa 
Time Complexity: O(N+M)
------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c = m-1;
        while(r < n  && c>=0){
            if( matrix[r][c] == target) return true;

            if(matrix[r][c] < target ) r++;//matrix[r][c] kom hole niche namo
            else c--;// matrix[r][c] beshi hoi gele pashe jao
        }
        return false;
    }
};

//#######################################################################
//#######-------BS-26. Find Peak Element-II--------########
//Tutorial: https://takeuforward.org/binary-search/find-peak-element-ii
//Problem: https://leetcode.com/problems/find-a-peak-element-ii/description/

skipping element using binary search 

------------
Approach:
1. 
------------

//#######################################################################
//#######-------BS-27. Median in a Row Wise Sorted Matrix--------########
//Tutorial: https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/
//Problem: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

------------
Approach:
1. Get the least value where (n*m)/2 < value  
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