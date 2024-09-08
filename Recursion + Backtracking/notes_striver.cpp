//Recursion + Backtracking

*** Draw the recursive tree to understand in depth Everything ***

- Recursion: Try every possible combination
- If constraints are very low think in recursion, backtracking

- Thinking depth wise a little bit tougher than breadth wise 

---------------------------------------------------------------------------------------------------------
Striver Recursion + Backtracking Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9
Resource: https://takeuforward.org/blogs/recursion
---------------------------------------------------------------------------------------------------------


Template - Take not take approach for all subsequence 

void f(vector<int>arr, int index,int n,vector<int> &subarr, vector<vector<int>>&ans){
    if (index == n){
        ans.insert(subarr);
        return;
    }
    //pick
    subarr.push_back(arr[index]);
    f(arr, index+1,n,subarr, ans);
    subarr.pop_back();
    //not_pick
    f(arr, index + 1,n,subarr, ans);
}


void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
    if (index == n){
        ans.push_back(s);
        return;
    }
    //take
    f(arr, index+1,n,s + arr[index],ans);
    //not take
    f(arr, index+1,n,s,ans);
}

//backtracking template

bool possible(){

}
bool f(){
    //traverse and check if possible
    //do backtrack here
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------Recursion--------##########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------1. Introduction to Recursion | Recursion Tree | Stack Space--------########
//Tutorial: https://takeuforward.org/recursion/what-is-recursion/

------------------------Theory----------------------------------

Recursion: When a function calls itself until a specified condition is met
Stack overflow: if no condition met than it is an infinite recursion. It is called stack overflow
Segmentation fault:stackoverflow hoile hoy
base condition: condition to stop
backtracking: call call call, went back went back, went back

Learn to draw recursive tree effectively


//#######################################################################
//#######-------2. Problems on Recursion--------########

In recursion while going, things happen 
while in backtracking, in coming back things happen, thats why the term backtracking.

//#######-------2.1 Print names N time using recursion--------########
//Tutorial: https://takeuforward.org/recursion/print-name-n-times-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-gfg-n-times/0

void f(int i, int n){
   if(i>n) return;
   cout<<"Raj"<<endl;
   f(i+1,n);
}

//#######-------2.2 Printing 1 to N--------########
//Tutorial: https://takeuforward.org/recursion/print-1-to-n-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1

void f(int i, int n){
   if(i>n) return;
   cout<<i<<endl;
   f(i+1,n);
}

//#######-------2.3 Printing N to 1--------########
//Tutorial: https://takeuforward.org/data-structure/print-n-to-1-and-1-to-n-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1

void f(int i, int n){
   if(i>n) return;
   f(i+1,n);
   cout<<i<<endl;
}
//#######-------2.4 Printing 1 to N using backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/print-n-to-1-and-1-to-n-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1

f(1,n)
void f(int i, int n){
    if(i>n) return;
    cout<<i<< endl;
    f(i+1,n);
}

//#######-------2.5 Printing N to 1 using backtracking--------########
//Tutorial: https://takeuforward.org/recursion/print-n-to-1-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1

f(n,n);
void f(int i, int n){
   if(i<1) return;
   cout<<i<<endl;
   f(i-1,n);
}

//#######################################################################
//#######-------3. Parameterised and Functional Recursion--------########

Parameterised and Functional Recursion: Doing everything in the parameter
Function recursion: returing something recursion

//#######-------3.1 Factorial--------########
//Tutorial: https://takeuforward.org/data-structure/factorial-of-a-number-iterative-and-recursive/
//Problem: https://www.geeksforgeeks.org/problems/factorial5739/1

f(n);
int f(int s){
    if(s<=1) return 1;
    return s * f(s-1);
}

//#######-------3.2 Sum of first N--------########
//Tutorial: https://takeuforward.org/data-structure/sum-of-first-n-natural-numbers/
//Problem:  https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1

Time Complexity: O(N)
Space Complexity: O(N) - for auxilary space 

f(n,0);
void f(int i, int sum){
   if(i<1)
   {
       cout<<sum<<endl;
       return;
   }
   f(i-1,sum+i);
}

//Another One - Sum of first N
f(n);
void f(int i){
   if(i==0) return 0;
   return i + f(i-1);
}

//#######################################################################
//#######-------4. Problems on Functional Recursion--------########


//#######-------4.1 Reverse an Array--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-given-array/
//Problem: 
------------
Approach:
1. swap and move l and r
------------
Time Complexity: O(N/2)
Space Complexity: O(N/2) - for auxilary space 

void f(int arr[], int start, int end) {
    if(start>=end) return;
    swap(arr[start], arr[end]);
    f(arr, start + 1, end - 1);   
}

//#######-------4.2 Checking if a string is Palindrome--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/palindrome-string0817/1

Note: If after reversing they are same, then it is a palindrome
------------
Approach:
1. same as reversing array
2. Just check if s[l] == s[r], if not return false
------------
Time Complexity: O(N/2)
Space Complexity: O(N/2) - for auxilary space 


palindrome(0,s);
bool palindrome(int i, string& s){
    if(i>=s.length()/2) return true;
    if(s[i]!=s[s.length()-i-1]) return false;//will not move ahead if this ever executes
    return palindrome(i+1,s);
}

//#######################################################################
//#######-------5. Multiple Recursion Calls--------########
//Tutorial: https://takeuforward.org/arrays/print-fibonacci-series-up-to-nth-term/
//Problem: https://www.naukri.com/code360/problems/print-fibonacci-series_7421617

Note: Fibonacci is the best example to learn multiple recursion calls

1 will happen, come back
2 will happen, come back
3 will happen, come back

int f(int n){
    if(n<=1) return n;
    return f(n-1) + f(n-2);
}

//#######################################################################
//#######-------6. Recursion on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
//Problem: https://leetcode.com/problems/subsets/

------------
Approach:
1. use take, not take method
------------
Time Complexity: O(2^N x N)
Space Complexity: O(N) [for auxilary space, maximum the depth can go upto N, then it will release]

class Solution {
public:
    void printSubsequences(vector<int>arr, int index, vector<int> &subarr,int n, vector<vector<int>>&ans){
        if (index == n){
            ans.push_back(subarr);
            return;
        }
        //take
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr,n, ans);
        //not take
        subarr.pop_back();
        printSubsequences(arr, index + 1, subarr,n, ans);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int>sub;
        printSubsequences(a, 0, sub, a.size() , ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//#######################################################################
//#######-------7. All Kind of Patterns in Recursion | Print All | Print one | Count--------########

------------
Approach:
1. Just use take, not take approach for the below 3 problems
------------
Time Complexity: O(2^N)
Space Complexity: O(N)

//#######-------7.1 Print All the Subsequence where sum is K--------########

#include <bits/stdc++.h>
using namespace std;
void f(vector<int>arr, int index, int n, vector<int> &subarr,int s, int sum){
    if (index == n){
        if(s == sum){
            for(auto x: subarr) cout<< x << ' ';
            cout<<endl;
        }
        return;
    }
    //take
    subarr.push_back(arr[index]);
    s+=arr[index];
    f(arr, index + 1, n, subarr, s, sum);
    //not take
    subarr.pop_back();
    s-=arr[index];
    f(arr, index + 1, n, subarr,s, sum);
}

int main(){
    int n = 4;
    vector<int> ar{1,2,4,6};
    vector<int> sub;
    f(ar,0,n, sub, 0, 6);

    return 0;
}

//#######-------7.2 Print one Subsequence where sum is K--------########

Note: bool function if one time true then it is always true
    - Ekbar true hoilei hbe, ar kichu return hobe na 

#include <bits/stdc++.h>
using namespace std;
bool f(vector<int>arr, int index, int n, vector<int> &subarr,int s, int sum){
    if (index == n){
        if(s == sum){
            for(auto x: subarr) cout<< x << ' ';
            cout<<endl;
            return true;
        }
        else return false;
    }
    //take
    subarr.push_back(arr[index]);
    s+=arr[index];
    if( f(arr, index + 1, n, subarr, s, sum) ) return true;
    //not take
    subarr.pop_back();
    s-=arr[index];
    if( f(arr, index + 1, n, subarr, s, sum) ) return true;
    return false;
}

int main() {
    int n = 4;
    vector<int> ar{1,2,4,6};
    vector<int> sub;
    f(ar,0,n, sub, 0, 6);
    return 0;
}

//#######-------7.3 Print count of all Subsequence where sum is K(retun 0 or 1 in count problem)--------########

******** This problem is V.V.Imp. ********

#include <bits/stdc++.h>
using namespace std;
int f(vector<int>arr, int index,int n, vector<int> &subarr,int s, int sum){
    if (index == n){
        if(s == sum){
            return 1;
        }
        else return 0;
    }
    //take
    subarr.push_back(arr[index]);
    s+=arr[index];
    int take = f(arr, index + 1,n, subarr, s, sum);
    //not take
    subarr.pop_back();
    s-=arr[index];
    int not_take = f(arr, index + 1, n, subarr,s, sum);

    return take + not_take;
}

int main() {
    int n = 4;
    vector<int> ar{1,2,4,6};
    vector<int> sub;
    cout<< f(ar,0,n, sub, 0, 6) << endl;
    return 0;
}

//#######-------7.4 Count all subsequences with sum K--------########
//Problem: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

------------
Approach:
1. s > sum hole, out of bounds hobe, So return 0
2. For rest use take and not take approach and use a dp array
------------
class Solution{
	public:
	int md = 1e9+7;
	int f(int arr[], int index,int n,int s, int sum,
	 vector<vector<int>>&dp){
        if (index == n){
            if(s == sum) return 1;
            return 0;
        }
        if(s>sum) return 0;
        if(dp[index][s] != -1) return dp[index][s];
        int take = f(arr, index + 1,n, s + arr[index], sum, dp);
        int not_take = f(arr, index + 1, n,s, sum, dp);
        return dp[index][s] = (take + not_take)%md;
    }
    
	int perfectSum(int arr[], int n, int sum)
	{   
	    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return f(arr,0,n, 0LL, sum, dp)%md;
	}
};

//#######-------7.5 Check if there exists a subsequence with sum K--------########
//Problem: https://www.naukri.com/code360/problems/subset-sum_630213

------------
Approach:
If one time true always true 
1. Use the take and not_take approach
------------
bool f(vector<int>arr, int index, int n,int s, int sum){
    if (index == n){
        if(s == sum) return true;
        else return false;
    }
    if(s>sum) return false;
    if( f(arr, index + 1, n, s + arr[index], sum) ) return true;
    if( f(arr, index + 1, n, s, sum) ) return true;
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return f(a, 0, n, 0, k);
}

//#######################################################################
//#######-------8. Merge Sort--------########
//Tutorial: https://takeuforward.org/data-structure/merge-sort-algorithm/
//Tutorial2: https://www.geeksforgeeks.org/merge-sort/
//Problem: https://www.geeksforgeeks.org/problems/merge-sort/1

------------
Approach:
1. Divide and merge
2. Instead of dividing the arrays, divide the indexes
3. After dividing, merge the array by using a temp variable
------------
Time Complexity: O(N * log2N)
Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

//merge function takes O(N) time
void merge(int ar[],int l,int m, int h){
    vector<int> temp;

    //low...mid
    //mid+1...high
    int i = l;      // Initial index of left subarray
    int j = m + 1;  // Initial index of right subarray

    // Merging the two arrays
    while (i <= m && j <= h) {
        if (ar[i] <= ar[j]) {
            temp.push_back(ar[i]);
            i++;//oi position er kaj shesh, tai ++
        } else {
            temp.push_back(ar[j]);
            j++;
        }
    }

    //if there are elements on the left still remains
    while (i <= m) {
        temp.push_back(ar[i]);
        i++;
    }

    //if there are elements on the right still remains
    while (j <= h) {
        temp.push_back(ar[j]);
        j++;
    }

    // moving all elements to an array / Copy elements from temp back to ar[]
    for (int k = l; k <= h; k++) {
        ar[k] = temp[k-l];//
    }

}

void merge_sort(int ar[], int l,int h){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    merge_sort(ar,l,m);//left half
    merge_sort(ar,m+1,h);//right half

    //function to merge and sort the array
    merge(ar,l,m,h);
}


int main(){

    int t=1;
    //cin >> t;
    while(t--){
        int ar[100]={2,1,23,45,22,3,6};
        int n = 7;
        int l = 0;
        int h = 6;

        merge_sort(ar,0,n-1); //high and low
        for(int i=0;i<n;i++){
            cout<<ar[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

//#######################################################################
//#######-------9. Quick Sort--------########
//Tutorial: https://takeuforward.org/data-structure/quick-sort-algorithm/
//Tutorial2: https://www.geeksforgeeks.org/quick-sort-algorithm/
//Problem: https://www.geeksforgeeks.org/problems/quick-sort/1

------------
Approach:
Way to do quick sort: select pivot, place element in its correct position

1. selects pivot, smaller than it goes left, larger than it goes right
------------

Time Complexity: O(N * log2N)
Space Complexity: O(1) [except the recursion stack, it does not use any temporary array]

#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[high];//pivot is the last element
    int i=(low-1);//start the loop from the low
    
    for(int j=low;j<=high-1;j++){
        //If current element is smaller than the pivot
        if(arr[j]<pivot){
        //Increment index of smaller element
        i++;
        swap(arr[i],arr[j]);}
    }
    swap(arr[i+1],arr[high]);//swap pivot with the lowest+1 index
    return (i+1);
}
           
void quickSort(int arr[],int low,int high){
    // when low is less than high
    if(low>=high) return;
        
    int pi=partition(arr,low,high);
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
             
int main() {
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

//Another one - Clean Code
class Solution {
public:
    int partition(vector<int>&arr,int low,int high){
        int pivot=arr[high];
        int i=(low-1);
        
        for(int j=low;j<=high-1;j++){
            if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);}
        }
        swap(arr[i+1],arr[high]);
        return (i+1);
    }
    void quickSort(vector<int>&arr,int low,int high){
        if(low>=high) return;
            
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {

        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

//#######################################################################
//#######-------10. Combination Sum--------########
//Tutorial: https://takeuforward.org/data-structure/combination-sum-1/
//Problem: https://leetcode.com/problems/combination-sum/description/

------------
Approach:
1. Use take, not take approach
Draw the recursive tree to understand in depth
------------
Time Complexity: O(2^t * K)
Space Complexity: O(k*x) [hypothetical]

class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, int s, int sum, vector<vector<int>>&ans){
        if(s == sum){
            ans.push_back(subarr);
            return;
        }
        if (index == n || s>sum){
            return;
        }
        //pick
        subarr.push_back(arr[index]);
        s+=arr[index];
        f(arr, index ,n,subarr, s, sum, ans);
        //not_pick
        subarr.pop_back();
        s-=arr[index];
        f(arr, index + 1,n,subarr,s, sum, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int>sub;
        f(arr, 0, arr.size(), sub, 0, target, ans);
        return ans;
    }
};

//#######################################################################
//#######-------11. Combination Sum II--------########
//Tutorial: https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
//Problem: https://leetcode.com/problems/combination-sum-ii/description/

*** V V important technique ***
------------
Approach:
1. Donot Use take, not take approach, always take in this problem 
Draw the recursive tree to understand in depth
------------
class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, int s, int sum, vector<vector<int>>&ans){
        if(s == sum){
            ans.push_back(subarr);
            return;
        }
        if (s>sum){
            return;
        }
        for(int i=index;i<n;i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            subarr.push_back(arr[i]);
            f(arr, i+1,n,subarr, s + arr[i], sum, ans);
            subarr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int>sub;
        sort(arr.begin(),arr.end());
        f(arr, 0, arr.size(), sub, 0, target, ans);
        return ans;
    }
};

//#######################################################################
//#######-------12. Combination Sum - III--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/combination-sum-iii/description/

Prerequisite: 11. Combination Sum II
------------
Approach:
1. Use the same approach for  Combination Sum - II
------------
class Solution {
public:
    void f(int index, int sz,vector<int>&arr, vector<int>&subarr, int s, 
        int target, vector<vector<int>>&ans){
        if(subarr.size() == sz && s == target){
            ans.push_back(subarr);
            return;
        }
        if(s>target) return;
        for(int i=index;i<9;i++){
            subarr.push_back( arr[i] );
            f(i+1, sz, arr, subarr, s+arr[i], target, ans);
            subarr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int sz, int target) {
        vector<vector<int>> ans;
        vector<int>sub, arr{1,2,3,4,5,6,7,8,9};
        f(0, sz, arr, sub, 0, target, ans);
        return ans;
    }
};

//#######################################################################
//#######-------13. Subset Sum I--------########
//Tutorial: https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
//Problem: https://www.geeksforgeeks.org/problems/subset-sums2234/1

------------
Approach:
1. Use take, not take approach
*** Draw the recursive tree to understand in depth ***
------------
Time Complexity: O(2^N)
Space Complexity: O(2^N) [ 2^N subset ase bole ]

class Solution {
  public:
    void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
        if (index == n){
            ans.push_back(s);
            return;
        }
        s+=arr[index];
        f(arr, index+1,n,s,ans);
        s-=arr[index];
        f(arr, index+1,n,s,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int> ans;
        f(arr, 0, n, 0, ans);
        return ans;
    }
};

//Another
class Solution {
  public:
    void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
        if (index == n){
            ans.push_back(s);
            return;
        }
        //take
        f(arr, index+1,n,s + arr[index],ans);
        //not take
        f(arr, index+1,n,s,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int> ans;
        f(arr, 0, n, 0, ans);
        return ans;
    }
};

//#######################################################################
//#######-------14. Subset Sum II--------########
//Tutorial: https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
//Problem: https://leetcode.com/problems/subsets-ii/description/

------------
Approach:
1. Use take, not take approach
*** Draw the recursive tree to understand in depth ***
------------
Time Complexity: O(2^N x N) [N for copying in the answer list]
Space Complexity: O(2^N) x O(K)

//Approach
class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, set<vector<int>>&ans){
        if (index == n){
            ans.insert(subarr);
            return;
        }
        //pick
        subarr.push_back(arr[index]);
        f(arr, index+1,n,subarr, ans);
        //not_pick
        subarr.pop_back();
        f(arr, index + 1,n,subarr, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        set<vector<int>> ans;
        vector<vector<int>> ans2;
        vector<int>sub;
        sort(arr.begin(),arr.end());
        f(arr, 0, arr.size(), sub, ans);
        
        for(auto x: ans)ans2.push_back(x);
        return ans2;
    }
};

//Approach 2 - Optimized Version
class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, vector<vector<int>>&ans){
        ans.push_back(subarr);
        for(int i=index;i<n;i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            subarr.push_back(arr[i]);
            f(arr, i+1,n,subarr, ans);
            subarr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int>sub;
        sort(arr.begin(),arr.end());
        f(arr, 0, arr.size(), sub, ans);
        return ans;
    }
};

//#######################################################################
//#######-------15. Print all Permutations of a String/Array | Recursion | Approach - 1--------########
//Tutorial: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
//Problem: https://leetcode.com/problems/permutations/description/

*** Draw the recursive tree to understand in depth ***

------------
Approach:
1. Take a map and Use take, not take approach
------------
Time Complexity: O(N! x N)
Space Complexity: O(N) + O(N)

class Solution {
public:
    void f(vector<int>&arr, int index, int n, vector<int>&subarr, 
    map<int, int>&mp, vector<vector<int>>&ans){
        if(subarr.size() == n){
            ans.push_back( subarr );
            return;
        }        
        for(int i=0;i<n;i++){
            if(mp[i]==0){
                mp[i] = 1;
                subarr.push_back(arr[i]);

                f(arr, i, n, subarr, mp, ans);

                //backtrack
                mp[i] = 0;
                subarr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        map<int, int>mp;
        f(nums, 0, nums.size(), sub, mp, ans);
        return ans;
    }
};

//#######################################################################
//#######-------16. Print all Permutations of a String/Array | Recursion | Approach - 2--------########
//Tutorial: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
//Problem: https://leetcode.com/problems/permutations/description/

Donot need extra map for this approach

------------
Approach:
1. Use the swapping approach(see striver notes for details)
------------
Time Complexity: O(N! x N)
Space Complexity: O(1) [except the recursion stack space this is the space complexity]

class Solution {
public:
    void f(vector<int>&arr, int index, int n, vector<vector<int>>&ans){
        if(index == n){
            ans.push_back( arr );
            return;
        }        
        for(int i=index;i<n;i++){
            swap(arr[index], arr[i]);
            f(arr, index+1, n, ans);
            swap(arr[index], arr[i]);//backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums, 0, nums.size(), ans);
        return ans;
    }
};

//#######################################################################
//#######-------17. N-Queens | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/
//Problem: https://leetcode.com/problems/n-queens/description/

------------
Approach:
1. Place queen in each grid 
2. After that check the next valid ghor by going rowwise, columnnwise, diagonalwise
3. if total i == board row size , then answer is found, add answer and return 
------------
Time Complexity: O(N! * N) nearly.
Space Complexity: O(N^2)

//Approach
class Solution {
public:
    bool ok(int r, int c, int n, vector<string>&board ){
        int tmpr = r;
        int tmpc = c;
        //rowwise
        while(tmpr>=0){
            if(board[tmpr][tmpc]=='Q') return false;
            tmpr--;
        }
        tmpr = r;
        tmpc = c;
        //diagonalwise upore
        while(tmpr>=0 && tmpc>=0){
            if(board[tmpr][tmpc]=='Q') return false;
            tmpr--;tmpc--;
        }
        tmpr = r;
        tmpc = c;
        //diagonalwise niche
        while(tmpr>=0 && tmpc<n){
            if(board[tmpr][tmpc]=='Q') return false;
            tmpr--;tmpc++;
        }
        return true;
    }
    void nqueen(int i, int n,vector<string>&board, vector<vector<string>>&ans){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int cc=0;cc<n;cc++){
            if(ok(i, cc, n, board)){
                board[i][cc] = 'Q';
                nqueen(i+1, n, board, ans);
                board[i][cc] = '.';//backtrack
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        nqueen(0, n, board, ans);
        return ans;
    }
};

//Another Approach
Time Complexity: O(N!)
Space Complexity: O(N^2)

- This approach is slightly better cause uses hashing 

class Solution {
public:
    void nqueen(int col, int n,vector<string>&board, vector<vector<string>>&ans, 
    vector<int>&leftrow, vector<int>&updiagonal, vector<int>&downdiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if( leftrow[row]==0 &&  updiagonal[row + col]==0 && downdiagonal[n-1 + col - row]==0){
                leftrow[row] = 1;
                updiagonal[row + col] = 1;
                downdiagonal[n-1 + col - row] = 1;
                board[col][row] = 'Q';
                nqueen(col+1, n, board, ans, leftrow, updiagonal, downdiagonal);
                //backtrack
                board[col][row] = '.';
                leftrow[row] = 0;
                updiagonal[row + col] = 0;
                downdiagonal[n-1 + col - row] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        vector<int> leftrow(n,0), updiagonal(2*n - 1, 0), downdiagonal(2*n - 1 , 0);
        nqueen(0, n, board, ans, leftrow, updiagonal, downdiagonal);
        return ans;
    }
};

//#######################################################################
//#######-------18. Sudoko Solver | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/sudoku-solver/
//Problem: https://leetcode.com/problems/sudoku-solver/description/

Similar to N Queen
------------
Approach:
1. check if it is valid box for number 0 to 9
2. if so run the recursion 
3. If ulmately the recursion completes all the numbers, keep returning true 
------------

class Solution {
public:
    bool ok(vector<vector<char>>&board, int r, int c, char ch){
        for(int i=0;i<9;i++){
            if(board[i][c]==ch) return false;
            if(board[r][i]==ch) return false;
            if(board[ 3 * (r/3) + i/3 ][3 * (c/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool f(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( board[i][j] == '.'){
                    for(int k='1';k<='9';k++){
                        if( ok(board, i, j, k) ){
                            board[i][j] = k;
                            if( f(board) == true ) return true;//if anytime this is false then backtracking
                            else board[i][j] = '.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};

//#######################################################################
//#######-------19. M-Coloring Problem | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/m-coloring-problem/
//Problem: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

------------
Approach:
1. 
------------
Time Complexity: O(M^N)
Space Complexity: O(N^2)

//#######################################################################
//#######-------20. Palindrome Partitioning--------########
//Tutorial: https://takeuforward.org/data-structure/palindrome-partitioning/
//Problem: https://leetcode.com/problems/palindrome-partitioning/description/

------------
Approach:
instead of take and not_take use 1 ghor, some ghor cutting approach:

1. 1 ghor and some ghor vag kora jodi palindrome hoi 
2. if index == n tahole push the answer
------------
class Solution {
public:
    bool check_pal(string s, int l, int r){
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void f(int index, int n,vector<string>subarr, string original,vector<vector<string>>&ans){
        if(index == n){
            ans.push_back(subarr);
            return;
        }
        
        for(int i=index;i<n;i++){
            string s = original.substr(index, i-index+1);
            if( check_pal(s, 0, s.size()-1) ){
                subarr.push_back(s);
                f(i+1, n, subarr, original,ans);
                //ek part e divide korar jnno i+1, dicchi everytime
                //na parle i er man berei jabe
                //eg: acaded, ["aca","ded"] is a valid answer
                subarr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string original) {
        vector<vector<string>> ans;
        int n = original.size();
        vector<string>sub;
        f(0, n, sub, original, ans);
        return ans;
    }
};

//#######################################################################
//#######-------21. Rat in A Maze | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/rat-in-a-maze/
//Problem: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

- Did similar problems in Dynamic Programming
------------
Approach:
1. Move L, R, U, D and keep adding answer if it is a valid ghor 
2.1 After reaching n-1 and m==1 backtrack,
2.2 remove direction and visited cell while backtracking
------------
Time Complexity: O(3^(m*n)), because on every cell we need to try 3 different directions. 1 cell is eliminated because we came from that
Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).

class Solution {
  public:
    bool isValid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
    void f(int i, int j, int n, int m,string sub, vector<vector<int>> &mat,
    vector<vector<int>> &visited, vector<string>&ans){
        if(i==n-1 && j==m-1){
            ans.push_back(sub);
            return;
        }
        vector<int>dx={0, 0, -1, 1};
        vector<int>dy={-1, 1, 0, 0};
        vector<char>dir={'L', 'R', 'U', 'D'};
        visited[i][j] = 1;
        for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            char d = dir[k];
            if( isValid(x,y,n,m) && !visited[x][y] && mat[x][y]==1){
                sub+=d;
                f(x, y,n, m, sub, mat, visited, ans);
                sub.pop_back();
            }
        }
        visited[i][j] = 0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<string> ans;
        string sub = "";
        vector<vector<int>>visited(n, vector<int>(m, 0));
        f(0, 0, n, m, sub, mat, visited, ans);
        if( mat[0][0] == 0 ) return {"-1"};
        if( !ans.empty() ) return ans;
        else return {"-1"};
    }
};

//#######################################################################
//#######-------22. K-th Permutation Sequence--------########
//Tutorial: https://takeuforward.org/data-structure/find-k-th-permutation-sequence/
//Problem: https://leetcode.com/problems/permutation-sequence/description/

------------
Approach:
1. 
------------

//#######################################################################
//#######-------23. Count Inversions in an Array--------########
//Tutorial: https://takeuforward.org/data-structure/count-inversions-in-an-array/

//Problem: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

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
    
        //low...mid
        //mid+1...high
        long long i = l;      // Initial index of left subarray
        long long j = m + 1;  // Initial index of right subarray
    
        // Merging the two arrays
        while (i <= m && j <= h) {
            if (ar[i] <= ar[j]) {
                temp.push_back(ar[i]);
                i++;//oi position er kaj shesh, tai ++
            } else {
                temp.push_back(ar[j]);
                cnt+= (m + 1 - i);
                j++;
            }
        }
    
        //if there are elements on the left still remains
        while (i <= m) {
            temp.push_back(ar[i]);
            i++;
        }
    
        //if there are elements on the right still remains
        while (j <= h) {
            temp.push_back(ar[j]);
            j++;
        }
    
        // moving all elements to an array / Copy elements from temp back to ar[]
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
        cnt+=merge_sort(ar,l,m);//left half
        cnt+=merge_sort(ar,m+1,h);//right half
    
        //function to merge and sort the array
        cnt+=merge(ar,l,m,h);
        return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
        return merge_sort(arr, 0LL, n-1);
    }
};
--------------------------------------------
--------------------------------------------
//Problem: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/



//###############################################################################################
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
//###############################################################################################



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------More Problems - Not On Video --------#################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

- Below are the problems available in the tuf website, but not in the videos

//#######################################################################
//#######-------Lec1 - Get a strong hold--------########


//#######################################################################
//#######-------Lec1.1 Recursive Implementation of atoi()--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/string-to-integer-atoi/description/
https://www.geeksforgeeks.org/problems/implement-atoi/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------Lec1.2 Pow(x, n)--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/powx-n/description/

------------
Approach:
1. Use Binary Exponentiation 
2. When it is negative number gets reduced by half, so 1/number
------------
class Solution {
public:
    double pows(double A, int b){
        long long B = b;
        if(B==0){
            return 1;
        }
        if(B<0){
            B = 1LL * -B;
            A = 1/A;
        }
        double v = pows(A , B/2);
        v = (v * v);
        if( B%2 ) v = ( v * A);
        return v;
    }

    double myPow(double x, int n) {
        return pows(x, n);
    }
};

//#######################################################################
//#######-------Lec1.3 Count Good numbers--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/count-good-numbers/description/
https://www.geeksforgeeks.org/problems/count-good-numbers/0
------------
Approach:
1. 
------------

//#######################################################################
//#######-------Lec1.4 Sort a stack using recursion--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/sort-a-stack/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------Lec1.5 Reverse a stack using recursion--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/reverse-a-stack/1

------------
Approach:
1. 
------------


-------------------------------------------------------------------------
-------------------------------------------------------------------------
//#######################################################################
//#######-------Lec2 - Subsequences Pattern--------########


//#######################################################################
//#######-------Lec2.1 Generate all binary strings--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

------------
Approach:
1. 0 thakle 2 ta option, 0 or 1 add korbo 
1. 1 thakle 1 ta option, add 0

NOTE: for num == 1, ans, '0' and '1'
------------
class Solution{
public:
    void f(int index, int num, string sub, vector<string>&ans){
        //cout<< sub << ' ' << index << endl;
        if(index==num){
            ans.push_back(sub);
            return;
        }

        if(sub.back()=='0'){
            sub+='0';
            f(index+1, num, sub, ans);
            sub.pop_back();
            sub+='1';
            f(index+1, num, sub, ans);
        }
        else if(sub.back()=='1') {
            sub+='0';
            f(index+1, num, sub, ans);
        }
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        f(1, num, "0",ans);
        f(1, num, "1",ans);
        return ans;
    }
};

//#######################################################################
//#######-------Lec2.2 Generate Paranthesis--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/generate-parentheses/description

------------
Approach:
4 Cases
1. if '(' count == n/2, then need only ')'
2.1 if '(' count == ')' count, then need only '('
2.2 else need both '(' and ')' 
------------

class Solution {
public:
    void f(int cnt,int cnt2, int n, string subarr, vector<string>&ans){
        if(cnt+cnt2==n*2){
            ans.push_back(subarr);
            return;
        }

        if(cnt == n){
            f(cnt, cnt2+1, n, subarr+')', ans);
        }
        else{
            if( cnt == cnt2 ) f(cnt+1, cnt2, n, subarr+'(', ans);
            else{
                f(cnt+1, cnt2, n, subarr+'(', ans);
                f(cnt, cnt2+1, n, subarr+')', ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string sub = "(";
        f(1,0, n, sub, ans);
        return ans;
    }
};

//#######################################################################
//#######-------Lec2.3 Letter Combinations of a Phone number--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

------------
Approach:
1. Just generate all subsets using all the digits using recursion
------------
class Solution {
public:
    void f(int index, int n, string subarr,string digits, vector<string>list, vector<string>&ans){
        if(index == n){
            ans.push_back(subarr);
            return;
        }
        int indices = digits[index] - '0';
        for(int i=0;i<list[indices].size();i++){
            f(index+1, n, subarr + list[indices][i],digits, list, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> list{"","","abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int n = digits.size();
        string sub = "";
        if(digits.empty()) return ans;
        f( 0, n, sub, digits, list, ans);// A little confused on why loop is not used here
        return ans;
    }
};

-------------------------------------------------------------------------
-------------------------------------------------------------------------
//#######################################################################
//#######-------Lec 3 - Trying out all Combos / Hard--------########


//#######################################################################
//#######-------Lec3.1 Word Search--------########
//Tutorial: https://takeuforward.org/data-structure/word-search-leetcode/
//Problem: https://leetcode.com/problems/word-search/description/

Prerequisite: Lec3.2 Word Break

------------
Approach:
1. Start from i,j every cell where i,j is board[i][j] == original[0]
2. From there keep building the string, and keep increasing index+1 with it whenever matches with original
3. if index == original.size() keep returning answer
------------

class Solution {
public:
    bool isValid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }

    bool f(int xx, int yy, int index, int ln, string original,int n, int m,
        vector<vector<char>>& board, vector<vector<int>>&visited){
        if(index==ln) return true;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};

        visited[xx][yy] = true;
        for(int k = 0;k<4;k++){
            int x = xx + dx[k];
            int y = yy + dy[k];
            if( isValid(x,y,n,m) && !visited[x][y] && board[x][y] == original[index] ){
                if( f(x, y, index+1, ln, original, n,m, board, visited) ) return true;
            }
        }
        visited[xx][yy] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string original) {
        int n = board.size();
        int m = board[0].size();
        int ln = original.size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        //start from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == original[0]) {
                    if( f(i, j, 1, ln, original, n, m, board,visited) == true )
                    return true;
                }
            }
        }
        return false;
    }
};

//#######################################################################
//#######-------Lec3.2 Word Break--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/word-break/description/

------------
Approach:
Think of substr of original word concept 

1. Run recursion for every word in the list
2. update the size only if it is inside the original word
3. word thakle sz == original.size() ekbar hobei
------------
class Solution {
public:
    bool f(int sz, string original, int n,vector<string>& wordDict,
        vector<int>&dp){
        if(sz==original.size()) return true;
        if(dp[sz]!=-1) return dp[sz];

        for(int i=0;i<n;i++){
            int ln = wordDict[i].size();
            //make sure the size if always below original size and the word is a substr of original
            if( sz+ln <= original.size() && original.substr(sz, ln) == wordDict[i] ){
                if( f(sz+ln, original, n, wordDict,dp) ) return dp[sz] = true;
            }
            
        }
        return dp[sz] = false;
    }
    bool wordBreak(string original, vector<string>& wordDict){
        vector<string>sub;
        int n = wordDict.size();
        int ln = original.size();
        vector<int>dp(ln+1, -1);
        return f(0, original, n, wordDict,dp);
    }
};

//#######################################################################
//#######-------Lec3.3 Expression Add Operators--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/expression-add-operators/description/
https://www.geeksforgeeks.org/problems/expression-add-operators/0

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