//Binary Search

- Binary search always applicable in sorted area
- In searching kind of things, think of using binary search

Confusions:
1. 

Questions: 


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
https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1


//#######################################################################
//#######-------BS-5. Search Element in Rotated Sorted Array II--------########
//Tutorial: https://takeuforward.org/arrays/search-element-in-rotated-sorted-array-ii/
//Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

//#######################################################################
//#######-------BS-6. Minimum in Rotated Sorted Array--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/
//Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

//#######################################################################
//#######-------BS-7. Find out how many times array has been rotated--------########
//Tutorial: https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated/
//Problem: https://www.geeksforgeeks.org/problems/rotation4723/1

//#######################################################################
//#######-------BS-8. Single Element in Sorted Array--------########
//Tutorial: https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
//Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1

//#######################################################################
//#######-------BS-9. Find Peak Element--------########
//Tutorial: https://takeuforward.org/data-structure/peak-element-in-array/
//Problem: https://leetcode.com/problems/find-peak-element/description/
https://www.geeksforgeeks.org/problems/peak-element/1

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
https://www.geeksforgeeks.org/problems/square-root/0

//#######################################################################
//#######-------BS-11. Find the Nth root of an Integer--------########
//Tutorial: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
//Problem: 
https://leetcode.com/problems/powx-n/description/
https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1


//#######################################################################
//#######-------BS-12. Koko Eating Bananas--------########
//Tutorial: https://takeuforward.org/binary-search/koko-eating-bananas/
//Problem: https://leetcode.com/problems/koko-eating-bananas/description/
https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

//#######################################################################
//#######-------BS-13. Minimum days to make M bouquets--------########
//Tutorial: https://takeuforward.org/arrays/minimum-days-to-make-m-bouquets/
//Problem: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

//#######################################################################
//#######-------BS-14. Find the Smallest Divisor Given a Threshold--------########
//Tutorial: https://takeuforward.org/arrays/find-the-smallest-divisor-given-a-threshold/
//Problem: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
https://www.geeksforgeeks.org/problems/smallest-divisor/1

//#######################################################################
//#######-------BS-15. Capacity to Ship Packages within D Days--------########
//Tutorial: https://takeuforward.org/arrays/capacity-to-ship-packages-within-d-days/
//Problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

//#######################################################################
//#######-------BS-16. Kth Missing Positive Number | Maths + Binary Search--------########
//Tutorial: https://takeuforward.org/arrays/kth-missing-positive-number/
//Problem: https://leetcode.com/problems/kth-missing-positive-number/description/
https://www.geeksforgeeks.org/problems/find-k-th-missing-element2556/0

//#######################################################################
//#######-------BS-17. Aggressive Cows--------########
//Tutorial: https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
//Problem: https://www.geeksforgeeks.org/problems/aggressive-cows/1
https://leetcode.com/problems/magnetic-force-between-two-balls/description/

//#######################################################################
//#######-------BS-18. Allocate Books or Book Allocation--------########
//Tutorial: https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
//Problem: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
https://www.naukri.com/code360/problems/allocate-books_1090540

//#######################################################################
//#######-------BS 19. Painter's Partition and Split Array - Largest Sum--------########
//Tutorial: https://takeuforward.org/arrays/painters-partition-problem/
//Problem: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
(Painters Partition)

//#######################################################################
//#######-------BS 19.2 Painter's Partition and Split Array - Largest Sum--------########
//Tutorial: https://takeuforward.org/arrays/split-array-largest-sum/
//Problem: https://leetcode.com/problems/split-array-largest-sum/description/
https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/0
https://www.geeksforgeeks.org/problems/split-the-array0238/1
(Split Array - Largest Sum)

//#######################################################################
//#######-------BS-20. Minimise Maximum Distance between Gas Stations | 3 Approaches | Heap | Binary Search--------########
//Tutorial: https://takeuforward.org/arrays/minimise-maximum-distance-between-gas-stations/
//Problem: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

//#######################################################################
//#######-------BS 21: Median of two Sorted Arrays of Different Sizes--------########
//Tutorial: https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
//Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

//#######################################################################
//#######-------BS-21.2 Median of two Sorted Arrays of Different Sizes--------########
//Tutorial: https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
//Problem: https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1

//#######################################################################
//#######-------Bs-22. K-th element of two sorted arrays--------########
//Tutorial: https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/
//Problem: 
https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/

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
//Problem: https://leetcode.com/problems/row-with-maximum-ones/description/
https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

//#######################################################################
//#######-------BS-24. Search in a 2D Matrix - I | Binary Search of 2D--------########
//Tutorial: https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
//Problem: https://leetcode.com/problems/search-a-2d-matrix/description/

//#######################################################################
//#######-------BS-25. Search in a 2D Matrix - II | Binary Search on 2D--------########
//Tutorial: https://takeuforward.org/arrays/search-in-a-row-and-column-wise-sorted-matrix/
//Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

//#######################################################################
//#######-------BS-26. Find Peak Element-II--------########
//Tutorial: https://takeuforward.org/binary-search/find-peak-element-ii
//Problem: https://leetcode.com/problems/find-a-peak-element-ii/description/

//#######################################################################
//#######-------BS-27. Median in a Row Wise Sorted Matrix--------########
//Tutorial: https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/
//Problem: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

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