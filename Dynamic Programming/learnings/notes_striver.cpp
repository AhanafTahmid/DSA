- Every types first video is the most important
- Learn to write bottom up table
- Learn to draw solving recursively, ==  f(idx, val) diye

How to think in recursion: 
1. Play with indexes, find the base case(destination, or out of bound cases). Always write the out of bounds first
2. explore all paths / Try out all possible choices at a given index.
3. Find minimum, maximum based on the problem statement

Steps to Memoise(DP):
    1. declare dp array 
    2. store value in dp[n]== somthing 
    3. find it previously solved dp[n]! =n(check if subproblems has been previously solved)

////
- we write tabulation method to reduce the stackspace
- In 2d array, solve the position and previous positions with recursion
- Memoization code will not give TLE if both the strings are passed by reference in the function... 
  as no copies will be generated which will limit the memory and Time
  if no passed by reference it will create a new copy everytime and will take a lot of space
- Always send parameters in dp function by pass by reference
- Both 2 rowr kaj at the same time thakle one 1d array te convert korte pari na
- Make the dp of changing parameters
- write changing parameter in opposite fashion in tabulation(when converting recursive to tabulation)
- FOR ALL THE COUNT PROBLEMS: if the condition is satisfied return 1, else return 0

Space optimization:
converting:
1d DP -> two variables
2d DP -> 1d DP 
3d DP -> 2d DP 


1. In grid take x,y as dp[x][y]
2. in subsequences, take dp[ind][target]

Confusions:
1. 
Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences
for(int i=0;i<=k;i++){//Getting WA for k/2 on top down approach.
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
2. DP 17. Counts Subsets with Sum K | Dp on Subsequences, handling 0 case in bottom up
3. DP 27. Longest Common Substring . Why memoization code does not work here? https://www.geeksforgeeks.org/longest-common-substring-dp-29/, solve this dp problem in memoization also
4. DP 33. Edit Distance | Recursive to 1D Array Optimised Solution draw the recursive tree
5. draw and learn the tabulation of bottom up : DP 37. Buy and Sell Stocks III , gettting WA
6. DP 47. Number of Longest Increasing Subsequences intuition bujhtesi na??
7. DP 48. Matrix Chain Multiplication 

---------------------------------------------------------------------------------------------------------
Stiver DP Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
Tutorials: https://takeuforward.org/dynamic-programming/striver-dp-series-dynamic-programming-problems/
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//###################-------Introduction to DP--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 1. Introduction to Dynamic Programming--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-introduction/


//Top Down approach Fibonacci
int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}
// Bottom Up approach Fibonacci
int fib() {

    int n=5;
    vector<int> dp(n+1,-1);
    
    dp[0]= 0;
    dp[1]= 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    cout<<dp[n];
}

//Bottom Up approach Fibonacci With O(1) space complexity
int fib() {
    int n=5;
    
    int prev2 = 0;
    int prev = 1;
    
    for(int i=2; i<=n; i++){
        int cur_i = prev2+ prev;
        prev2 = prev;
        prev= cur_i;
    }
    cout<<prev;
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------1D DP--------##############################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

1D DP Code: 
//Top Down
#include <bits/stdc++.h> 
int rec(int i, vector<int>&heights, vector<int>&dp){
    if(i==0) return 0;
    //n-1 to 1
    if(dp[i]!=-1) return dp[i];
    int f1 = rec(i-1, heights,dp) + abs(heights[i]-heights[i-1]);
    int f2 = INT_MAX;
    if(i>1) f2 = rec(i-2, heights,dp) + abs(heights[i]-heights[i-2]);

    return dp[i] = min(f1,f2);
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n+1,-1);
    return rec(n-1, heights,dp);
}
//Bottom Up
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(1000000,-1);
    dp[0] = 0;
    for(int i=1;i<heights.size();i++){
        int jump1 = dp[i-1] + abs(heights[i-1]-heights[i]);
        int jump2 = INT_MAX;
        if(i>1) jump2 = dp[i-2] + abs(heights[i]-heights[i-2]);//dp[i-2] will not always be valid, so i>1 condition
        dp[i] = min(jump1,jump2);
    }
    return dp[n-1];
}



//#######################################################################
//#######-------DP 2. Climbing Stairs--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
//Problem: https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

#include <bits/stdc++.h> 
int countDistinctWays(long long nStairs) {
    vector<int> dp(nStairs+1,-1);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=nStairs;i++){
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }
    return dp[nStairs];
}

//#######################################################################
//#######-------DP 3. Frog Jump | Dynamic Programming | Learn to write 1D DP--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
//Problem: https://www.naukri.com/code360/problems/frog-jump_3621012

//solve from the beginning, the cost of jumping each in minimum
//bottom to up
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(1000000,-1);
    dp[0] = 0;
    for(int i=1;i<heights.size();i++){
        int jump1 = dp[i-1] + abs(heights[i-1]-heights[i]);
        int jump2 = INT_MAX;
        if(i>1) jump2 = dp[i-2] + abs(heights[i]-heights[i-2]);//dp[i-2] will not always be valid, so i>1 condition
        dp[i] = min(jump1,jump2);
    }
    return dp[n-1];
}


// rec(i-1) is same as dp[i-1] in bottom up

//up to bottom

#include <bits/stdc++.h> 
int rec(int i, vector<int>&heights, vector<int>&dp){
    if(i==0) return 0;
    //n-1 to 1
    if(dp[i]!=-1) return dp[i];
    int f1 = rec(i-1, heights,dp) + abs(heights[i]-heights[i-1]);
    int f2 = INT_MAX;
    if(i>1) f2 = rec(i-2, heights,dp) + abs(heights[i]-heights[i-2]);

    return dp[i] = min(f1,f2);
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n+1,-1);
    return rec(n-1, heights,dp);
}

//bottom to up with (space optimization)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int pr = 0, pr2 = 0;
    for(int i=1;i<heights.size();i++){
        int jump1 = pr + abs(heights[i-1]-heights[i]);
        int jump2 = INT_MAX;
        if(i>1) jump2 = pr2 + abs(heights[i]-heights[i-2]);
        
        int v = min(jump1,jump2);
        pr2 = pr;
        pr = v;
    }
    return pr;
}


//#######################################################################
//#######-------DP 4. Frog Jump with K Distance--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/
//Problem: https://www.naukri.com/code360/problems/minimal-cost_8180930

//Top Down
int rec(int i, int k, vector<int> &dp, vector<int> &height ){
    if(i==0)return 0;
    int v = INT_MAX;
    if(dp[i]!=-1)return dp[i];
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int jump = rec(i-j, k, dp, height) + abs(height[i]-height[i-j]);
            v = min(v, jump);
        }
        
    }
    return dp[i] = v;
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    return rec(n-1, k, dp, height);
}

//Bottom Up
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){//2nd step theke shuru kora, tahole minimum ekbar holeo i-j>=0 loop er vitor jabe
        int v = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j] + abs(height[i]-height[i-j]);
                v = min(v, jump);
            }
        }
        dp[i] = v;
    }
    return dp[n-1];
}

//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


//recursion on subsequences - prerequisite for this problem
void rec(int i, int n, vector<int>&a, vector<int>&li){
	if(i==n){
		//print all the subsequences
		for(auto x: li)cout<< x <<' ';
		cout<<endl;
		return;
	}
	//take 
	li.push_back(a[i]);
	rec(i+1, n, a, li);
	//not take
	li.pop_back();
	rec(i+1, n, a, li);
}

void solve(){
    vector<int> a = {3,1,2};
	vector<int> li;
	rec(0,a.size(), a, li);
}

//Problem solution
//Top Down -> Recursive version 1(kind of bottom up)
#include <bits/stdc++.h> 
int rec(int i, vector<int>&nums, vector<int>&dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int pick = nums[i] + rec(i+2, nums, dp);
    int notpick = 0 + rec(i+1, nums, dp);
    return dp[i] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return rec(0, nums, dp);
}


//Top Down -> Recursive version 2
#include <bits/stdc++.h> 
int rec(int i, vector<int>&nums, vector<int>&dp){
    if(dp[i]!=-1) return dp[i];
    if(i==0) return nums[i];
    if(i<0) return 0;
   
    int pick = nums[i] + rec(i-2, nums, dp);
    int notpick = 0 + rec(i-1, nums, dp);
    return dp[i] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return rec(nums.size()-1, nums, dp);
}


//Bottom Up
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
        int notpick = 0 + dp[i-1];
        int pick = nums[i];
        if(i>1) pick += dp[i-2];
        dp[i] = max(pick, notpick);
    }
    return dp[n-1];
}

//Bottom Up(with space optimized)
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //vector<int> dp(n,-1);
    int prv = nums[0], prv2 = 0, mx;
    for(int i=1;i<n;i++){//starting from 1, cause we know the answer for 0th index
        int notpick = 0 + prv;
        int pick = nums[i];
        if(i>1) pick += prv2;
        mx = max(pick, notpick);
        prv2 = prv;
        prv = mx;
    }
    return prv;
}

//#######################################################################
//#######-------DP 6. House Robber 2 | 1D DP | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
//Problem: https://www.naukri.com/code360/problems/house-robber_839733

//Top Down
//Use long long for dp array to pass testcase 6/8
#include <bits/stdc++.h>
long long rob(int i, vector<int>&valueInHouse, vector<long long>&dp){
    if(i>=valueInHouse.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    long long pick = valueInHouse[i] + rob(i+2, valueInHouse, dp);
    long long notpick = 0 + rob(i+1, valueInHouse, dp);
    return dp[i] = max(pick, notpick);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<long long> dp(n-1, -1), dp2(n-1,-1);
    vector<int> ar,ar2;
    for(int i=1;i<n;i++)ar.push_back(valueInHouse[i]);
    for(int i=0;i<n-1;i++)ar2.push_back(valueInHouse[i]);
    long long v1 = rob(0, ar, dp);
    long long v2 = rob(0, ar2, dp2);
    return max(v1,v2);
}


//Bottom Up
#include <bits/stdc++.h> 
long long rob(vector<int> &valueInHouse){
    int n = valueInHouse.size();
    long long prv = valueInHouse[0], prv2 = 0;
    for(int i=1;i<n;i++){
        long long pick = valueInHouse[i];
        if(i>1)pick+=prv2;
        long long notpick = 0 + prv;
        long long mx = max(pick, notpick);
        prv2 = prv;
        prv = mx;
    }
    return prv;
}
long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size(); 
    if(n==1)return valueInHouse[0];
    else{
        vector<int> ar,ar2;
        for(int i=1;i<n;i++)ar.push_back(valueInHouse[i]);
        for(int i=0;i<n-1;i++)ar2.push_back(valueInHouse[i]);
        n--;
        long long v1 = rob(ar);
        long long v2 = rob(ar2);
        return max(v1,v2);
    }
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Grids(2d,3d)--------#################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

DP on Grids(2d,3d) Code: 
//Top Down
- for day = 0, donot write the condition extra, just write day<0 return 0

int rec(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last]!=-1)return dp[day][last];
    if(day==0){
        int mx = 0;
        for(int j=0;j<=2;j++){
            if(j!=last){
                mx = max(mx, points[0][j]);
            }
        }
        return dp[0][last] = mx;
    }
    int mx = 0;
    for(int j=0;j<=2;j++){
        if(j!=last){
            int activity = points[day][j] + rec(day-1, j, points, dp);
            mx = max(mx, activity);
        }
    }
    return dp[day][last] = mx;
}
//Bottom Up 
int asTraining(int n, vector<vector<int>> &points)
{
    vector< vector<int> > dp(n, vector<int>(4,-1));
    //for every value, removing each position see which one is maximum, compute the first
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(max(points[0][1],points[0][1]),points[0][2]);

    for(int day = 1;day<n;day++){
        for(int last=0;last<4;last++){
            int mx = 0;
            for(int t=0;t<3;t++){
                if(last!=t){
                    mx = max(mx, points[day][t]+dp[day-1][t]);
                    dp[day][last] = mx;
                }
            }
        }
    }
    return dp[n-1][3];
}


//#######################################################################
/////////REVISITTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
//#######-------DP 7. Ninja's Training | MUST WATCH for 2D CONCEPTS--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
//Problem: https://www.naukri.com/code360/problems/ninja-s-training_3621003

//Top Down
int rec(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last]!=-1)return dp[day][last];
    if(day==0){
        int mx = 0;
        for(int j=0;j<=2;j++){
            if(j!=last){
                mx = max(mx, points[0][j]);
            }
        }
        return dp[0][last] = mx;
    }
    int mx = 0;
    for(int j=0;j<=2;j++){
        if(j!=last){
            int activity = points[day][j] + rec(day-1, j, points, dp);
            mx = max(mx, activity);
        }
    }
    return dp[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //day, points, dp
    vector< vector<int> > dp(n, vector<int>(4,-1));
    return rec(n-1, 3, points, dp);
}

//bottom up
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector< vector<int> > dp(n, vector<int>(4,-1));
    //for every value, removing each position see which one is maximum, compute the first
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(max(points[0][1],points[0][1]),points[0][2]);

    for(int day = 1;day<n;day++){
        for(int last=0;last<4;last++){
            int mx = 0;
            for(int t=0;t<3;t++){
                if(last!=t){
                    mx = max(mx, points[day][t]+dp[day-1][t]);
                    dp[day][last] = mx;
                }
            }
        }
    }
    return dp[n-1][3];
}

//bottom up (space optimization)
// time complexity : n*3*4
// space complexity: O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>dp(4,0);
    //for every value, removing each position see which one is maximum, compute the first
    dp[0] = max(points[0][1],points[0][2]);
    dp[1] = max(points[0][0],points[0][2]);
    dp[2] = max(points[0][0],points[0][1]);
    dp[3] = max(max(points[0][1],points[0][1]),points[0][2]);

    for(int day = 1;day<n;day++){
        vector<int>tmp(4,0);
        for(int last=0;last<4;last++){
            for(int t=0;t<3;t++){
                if(last!=t){
                    tmp[last] = max(tmp[last], points[day][t]+dp[t]);
                }
            }
        }
        dp = tmp;
    }
    return dp[3];
}



//#######################################################################
//#######-------DP 8. Grid Unique Paths | Learn Everything about DP on Grids--------########
//Tutorial: https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/
//Problem: https://www.naukri.com/code360/problems/total-unique-paths_1081470

//Top Down
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>&dp){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int up = f(i-1,j,dp);
	int right = f(i,j-1,dp);
	return dp[i][j] = up + right;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m, vector<int>(n,-1));
	return f(m-1,n-1,dp);
}

//Bottom Up
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m, vector<int>(n,-1));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
                dp[0][0] = 1;
				continue;
			}
			int up = 0, right = 0;
			if(i>0) up = dp[i-1][j];
			if(j>0) right = dp[i][j-1];
			dp[i][j] = up+right;
		}
	}
	return dp[m-1][n-1];
}

//Bottom Up(Space optimized)
//rowwise compute kora
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<int>dp(n,0);
	for(int i=0;i<m;i++){
		vector<int>tmp(n,0);
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
				tmp[0] = 1;
				continue;
			}
			int up = 0, right = 0;
			if(i>0) up = dp[j];
			if(j>0) right = tmp[j-1];
			tmp[j] = up+right;
		}
		dp = tmp;
	}
	return dp[n-1];
}


//#######################################################################
//#######-------DP 9. Unique Paths 2 | DP on Grid with Maze Obstacles--------########
//Tutorial: https://takeuforward.org/data-structure/grid-unique-paths-2-dp-9/
//Problem: https://www.naukri.com/code360/problems/maze-obstacles_977241

//Top Down
const int md = 1e9+7;
int f(int i, int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(i<0 || j<0 || mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int up = f(i-1,j,mat,dp);
    int left = f(i,j-1,mat,dp);
    return dp[i][j] = (up+left)%md;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n, vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}

//Bottom UP
const int md = 1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(mat[i][j]==-1)continue;

            if(i>0) up = dp[i-1][j]; 
            if(j>0) left = dp[i][j-1];
            dp[i][j] = (up+left)%md; 
        }
    }
    return dp[n-1][m-1];
}

//Bottom UP(Space Optimizatoin) - space -> O(number of colums)
//rowwise kaj kora space optimization er somoy
const int md = 1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int>dp(m,0);
    for(int i=0;i<n;i++){
        vector<int>tmp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                tmp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(mat[i][j]==-1)continue;

            if(i>0) up = dp[j]; 
            if(j>0) left = tmp[j-1];
            tmp[j] = (up+left)%md; 
        }
        dp = tmp;
    }
    return dp[m-1];
}


//#######################################################################
//#######-------DP 10. Minimum Path Sum in Grid--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-path-sum-in-a-grid-dp-10/
//Problem: https://www.naukri.com/code360/problems/minimum-path-sum_985349

//Top Down
//up and left er moddhe jeta minimum sheta choose kora
//dp te all possible ways try kortesi

#include <bits/stdc++.h> 
int inf = 1e8;
int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return inf;
    if(dp[i][j]!=-1) return dp[i][j];

    //solve grid, and bakita recursion e solve korar jnno pathano
    int up = grid[i][j] + f(i-1,j,grid,dp);
    int left = grid[i][j] + f(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}


//Bottom Up
#include <bits/stdc++.h> 
int inf = 1e8;
int minSumPath(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = 0,left = 0;
            if(i>0) up = grid[i][j] + dp[i-1][j];
            else up = inf;
            if(j>0) left = grid[i][j] + dp[i][j-1];
            else left = inf;
            dp[i][j] = min(up,left);
        }
    }
    return dp[n-1][m-1];
}

//Bottom Up(space optimized)
#include <bits/stdc++.h> 
int inf = 1e8;
int minSumPath(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        vector<int> tmp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                tmp[j] = grid[i][j];
                continue;
            }
            int up = 0,left = 0;
            if(i>0) up = grid[i][j] + dp[j];//first loop e dhukbe na
            else up = inf;
            if(j>0) left = grid[i][j] + tmp[j-1];
            else left = inf;
            tmp[j] = min(up,left);
        }
        dp = tmp;
    }
    return dp[m-1];
}


//#######################################################################
//#######-------DP 11. Triangle | Fixed Starting Point and Variable Ending Point | DP on GRIDS--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-path-sum-in-triangular-grid-dp-11/
//Problem: https://www.naukri.com/code360/problems/triangle_1229398


// ***** This problem has Variable Starting and Ending Points ***** ///


//Top Down (but go from down to top, it is always top down, not bottom up) -> 
//recursion is always top down

#include <bits/stdc++.h> 
int f(int i,int j,int n, vector<vector<int>>& triangle, vector<vector<int>>&dp){
	if(i==n-1) return triangle[i][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int up = triangle[i][j] + f(i+1, j,n,triangle, dp);//take current + find the rest answer in vertically
	int diagonal =  triangle[i][j] + f(i+1,j+1,n,triangle,dp);
	return dp[i][j] = min(up,diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int> > dp(n, vector<int>(n,-1));
	return f(0, 0, n, triangle,dp);
}

//Bottom Up(Tabulation) ->(but do in like top down in loop) / nich theke upore uthbo
//space complexity: O(N*N)
1. solve the last index first
2. solve the rest of the index -> i+1, i+1 and j+1 indexes
3. find the minimum of places traveled
4. dp[0][0] is the answer

#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int> > dp(n, vector<int>(n,-1));
	for(int i=n-1;i>=0;i--){
		dp[n-1][i] = triangle[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int up = triangle[i][j] + dp[i+1][j];
			int diagonal = triangle[i][j] + dp[i+1][j+1];//solve the position and previous positions
			dp[i][j] = min(up,diagonal);
		}
	}
	return dp[0][0];
}

//Bottom Up(Tabulation) -> space optimized

#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> dp(n, -1);
	for(int i=n-1;i>=0;i--){
		dp[i] = triangle[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		vector<int> tmp(n, -1);
		for(int j=i;j>=0;j--){
			int up = triangle[i][j] + dp[j];
			int diagonal = triangle[i][j] + dp[j+1]; //solve the position and previous positions
			tmp[j] = min(up,diagonal);
		}
		dp = tmp;
	}
	return dp[0];
}


//#######################################################################
//#######-------DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points--------########
//Question Type: 1. DP on 2d grid
//Tutorial: https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/
//Problem: https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998

//Time complexity: 3^n without dp, cause 3 recursion
//Top Down - 1
#include <bits/stdc++.h> 
int f(int i, int j, int n, int m,vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j==m) return -1e9;
    if(i==0)return matrix[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    //solve the position and previous positions
    int up = matrix[i][j] + f(i-1,j,n, m, matrix, dp);
    int ld = matrix[i][j] + f(i-1,j-1,n,m,matrix,dp);
    int rd = matrix[i][j] + f(i-1,j+1,n,m,matrix,dp);
    return dp[i][j] = max({up,ld,rd});
}
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans = -1e9;
    //all answer is in 1st row
    for(int i=0;i<m;i++){
        //Calculate the maximum path sum for each column of row 0
        ans = max(ans,f(n-1,i,n,m,matrix,dp));
    }
    return ans;
}

//Top Down - 2
#include <bits/stdc++.h> 
int f(int i, int j, int n, int m,vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j>=m) return -1e9;
    if(i==n-1)return matrix[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    //solve the position and next positions
    int down = matrix[i][j] + f(i+1,j,n, m, matrix, dp);
    int ld = matrix[i][j] + f(i+1,j-1,n,m,matrix,dp);
    int rd = matrix[i][j] + f(i+1,j+1,n,m,matrix,dp);
    return dp[i][j] = max({down,ld,rd});
}
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans = -1e9;
    for(int i=0;i<m;i++){
        ans = max(ans, f(0,i,n,m,matrix,dp) );
    }
    return ans;
}

//Bottom Up
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<m;i++){
        dp[0][i] = matrix[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int down = matrix[i][j], ld = matrix[i][j], rd = matrix[i][j];
            down += dp[i-1][j];
            if(j+1<m) ld +=dp[i-1][j+1];
            //outof bounds index recursion-eo same kaj korsi 
            //down jaite parbo, but diagonal gele out of bounds hoe jabe tai large negative disi
            else ld = -1e9;
            if(j)rd +=dp[i-1][j-1];
            else rd = -1e9;
            dp[i][j] = max({down,ld,rd});
        }
    }
        
    int ans = -1e9;
    for(int i=0;i<m;i++){
        ans = max(ans, dp[n-1][i]);//last ghorer prottekta column e answer thakbe, find the max one
    }
    return ans;
}

//Bottom Up(space optimized)
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>dp(m,0);
    //first row manually set kora
    for(int i=0;i<m;i++){
        dp[i] = matrix[0][i];
    }
    //do dp for rest of the rows
    for(int i=1;i<n;i++){
        vector<int>tmp(m,0);
        for(int j=0;j<m;j++){
            int down = matrix[i][j], ld = matrix[i][j], rd = matrix[i][j];
            if(i) down += dp[j];
            else down = -1e9;
            if(j+1<m) ld +=dp[j+1];
            else ld = -1e9;
            if(j)rd +=dp[j-1];
            else rd = -1e9;
            tmp[j] = max({down,ld,rd});
        }
        dp = tmp;
    }
    int ans = -1e9;
    //last ghorer prottekta column e answer thakbe
    for(int i=0;i<m;i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}


//#######################################################################
//#######-------DP 13. Cherry Pickup II | 3D DP Made Easy | DP On Grids--------########
//Question Type: 1. fixed starting point, variable ending point 2. DP on 3d grid
//Tutorial: https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/
//Problem:  https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885

//Top Down
#include <bits/stdc++.h> 
int f(int i, int j1, int j2, int n,int m,vector<vector<int>> &grid, vector<vector<vector<int>>>&dp ){
    if(j1<0 || j2<0 || j1>=m || j2>=m ) return -1e9; 
    if(i==n-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int mx = -1e9;
    for(int p=-1;p<=1;p++){
        for(int q=-1;q<=1;q++){
            int v = 0;
            if(j1==j2) v =  grid[i][j1];
            else v = grid[i][j1] + grid[i][j2];
            v+=f(i+1, j1+p, j2+q,n, m, grid, dp);//solve the rest 
            mx = max(mx, v);
        }
    }
    return dp[i][j1][j2] = mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0, 0, c-1, r, c, grid, dp);
}

//Bottom Up(a little confused)
#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c,vector<int>(c,-1)));

    int n = r, m = c;

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j1] =  grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int mx = -1e9;
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        int v = 0;
                        if(j1==j2) v =  grid[i][j1];
                        else v = grid[i][j1] + grid[i][j2];

                        if(j1+p>=m || j1+p<0 || j2+q>=m || j2+q<0 ) v = -1e8;
                        else v+=dp[i+1][j1+p][j2+q];
                        mx = max(mx, v);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][m-1];//confused ?????
}


//Bottom Up(Space optimized)
#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>>dp(c, vector<int>(c,0));
    int n = r, m = c;

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[j1][j1] =  grid[n-1][j1];
            else dp[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        vector<vector<int>>tmp(c, vector<int>(c,0));
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int mx = -1e9;
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        int v = 0;
                        if(j1==j2) v =  grid[i][j1];
                        else v = grid[i][j1] + grid[i][j2];

                        if(j1+p>=m || j1+p<0 || j2+q>=m || j2+q<0 ) v = -1e8;
                        else v+=dp[j1+p][j2+q];//get the solved dp
                        mx = max(mx, v);
                    }
                }
                tmp[j1][j2] = mx;
            }
        }
        dp = tmp;
    }
    return dp[0][m-1];
}
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Subsequences/Subsets--------#########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

- Either take it or not take it concept

int f(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(i==0){

    }
    int not_taken = 
    int taken = 
    if(){
        taken = 
    }
    return 
}
DP on Subsequences/Subsets Code: 
//Top Down 
#include <bits/stdc++.h> 
bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp ){
    if(target==0)return true;
    if(i==0)return (arr[0]==target);//same hoe jabe or 0 hoe jabe target
    if(dp[i][target]!=-1)return dp[i][target];
    bool not_taken = f(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i]<=target){
        taken = f(i-1, target-arr[i],arr,dp);
    }
    return dp[i][target] = taken || not_taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, -1));
    return f(n-1,k, arr, dp);
}
//Bottom Up
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, 0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    //Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    //if target is lesser than first value
    //example out of bound: if n=1,k=5,arr[0]=10, it will be out of bounds 
    if (arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool not_taken = dp[i-1][target];
            bool taken = false;
            if(target>=arr[i]) taken = dp[i-1][target-arr[i]];
            dp[i][target] = taken || not_taken;
        }
    }
    return dp[n-1][k];
}

//#######################################################################
//#######-------DP 14. Subset Sum Equals to Target | Identify DP on Subsequences and Ways to Solve them--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/
//Tushar  : https://youtu.be/s6FhG--P7z0
//Problem:  https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

//--------
//Top Down
//--------
#include <bits/stdc++.h> 
bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp ){
    if(target==0)return true;
    if(i==0)return (arr[0]==target);//same hoe jabe or 0 hoe jabe target
    if(dp[i][target]!=-1)return dp[i][target];
    bool not_taken = f(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i]<=target){
        taken = f(i-1, target-arr[i],arr,dp);
    }
    return dp[i][target] = taken || not_taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, -1));
    return f(n-1,k, arr, dp);
}
//--------
//Bottom Up
//--------
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, 0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    //Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    //if target is lesser than first value
    //example out of bound: if n=1,k=5,arr[0]=10, it will be out of bounds 
    if (arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool not_taken = dp[i-1][target];
            bool taken = false;
            if(target>=arr[i]) taken = dp[i-1][target-arr[i]];
            dp[i][target] = taken || not_taken;
        }
    }
    return dp[n-1][k];
}
//--------
//Bottom Up(space optimized)
//--------
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int>prev(k+1,0);
    prev[0] = true;
    //k is the target, prev and cur is working with target only here
    if (arr[0] <= k)prev[arr[0]] = true;
    for(int i=1;i<n;i++){
        vector<int>cur(k+1,0);
        cur[0] = true;
        for(int target=1;target<=k;target++){
            bool not_taken = prev[target];
            bool taken = false;
            if(target>=arr[i]) taken = prev[target-arr[i]];
            cur[target] = taken || not_taken;
        }
        prev = cur;
    }
    return prev[k];
}


//#######################################################################
//#######-------DP 15. Partition Equal Subset Sum | DP on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/partition-equal-subset-sum-dp-15/
//Problem:  https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980

//--------
//Top Down
//--------
bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
	if(target==0) return true;
	if(ind == 0) return arr[ind] == target;
	if(dp[ind][target]!=-1) return dp[ind][target];

	bool not_taken = f(ind-1, target, arr,dp);
	bool taken = false;
	if(arr[ind]<=target){
		taken = f(ind-1, target-arr[ind], arr, dp);
	}
	return dp[ind][target] = taken || not_taken;
}

bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	if(sum%2) return false;
	else{
		int target = sum/2;
		vector<vector<int>> dp(n, vector<int>(target+1, -1));
		return f(n-1, target, arr, dp);
	}
}

//--------
//Bottom Up
//--------
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	if(sum%2) return false;
	else{
		int target = sum/2;
		vector<vector<int>> dp(n, vector<int>(target+1, 0));
		for(int ind=0;ind<n;ind++){
			dp[ind][0] = true;
		}
        if (arr[0] <= target) dp[0][arr[0]] = true;

		for(int ind=1;ind<n;ind++){
			for(int t=1;t<=target;t++){
				bool not_taken = dp[ind-1][t];
				bool taken = false;
				if(arr[ind]<=t){
					taken = dp[ind-1][t-arr[ind]];
				}
				dp[ind][t] = taken || not_taken;
			}
		}
		return dp[n-1][target];
	}
}



//--------
//Bottom Up(Space optimized)
//--------
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	if(sum%2) return false;
	else{
		int target = sum/2;
		vector<int> prev(target+1, 0), cur(target+1,0);
		prev[0] = true;
		cur[0] = true;
        if (arr[0] <= target) prev[arr[0]] = true;

		for(int ind=1;ind<n;ind++){
			for(int t=1;t<=target;t++){
				bool not_taken = prev[t];
				bool taken = false;
				if(arr[ind]<=t){
					taken = prev[t-arr[ind]];
				}
				cur[t] = taken || not_taken;
			}
			prev = cur;
		}
		return cur[target];
	}
}


//#######################################################################
//#######-------Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/partition-set-into-2-subsets-with-min-absolute-sum-diff-dp-16/
//Problem:  https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

Steps:
1. Generate the whole dp from dp[0][0] to dp[n-1][target] (target sum concept)
2. The answer lies in dp[n-1][0] to dp[n-1][target], get the minimum from there, Going till half is enough

//--------
//Top Down
//--------

bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp ){
    if(target==0)return true;
    if(i==0)return (arr[0]==target);
    if(dp[i][target]!=-1)return dp[i][target];
    bool not_taken = f(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i]<=target){
        taken = f(i-1, target-arr[i],arr,dp);
    }
    return dp[i][target] = taken || not_taken;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	int k = sum;

	vector<vector<int>>dp(n,vector<int>(k+1, -1));
	//solve the answer for all 0 to target values
	for(int i=0;i<=k;i++) f(n-1,i, arr, dp);
	
	int ans = 1e9;
	for(int i=0;i<=k;i++){//Getting WA for k/2 on top down approach.
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
	return ans;

}


//--------
//Bottom Up
//--------
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	int k = sum;
	vector<vector<int>>dp(n,vector<int>(k+1, 0));
	for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

	if (arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool not_taken = dp[i-1][target];
            bool taken = false;
            if(target>=arr[i]) taken = dp[i-1][target-arr[i]];
            dp[i][target] = taken || not_taken;
        }
    }

	int ans = 1e9;
	for(int i=0;i<=k/2;i++){
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
	return ans;
}

//--------
//Bottom Up(Space optimized)
//--------
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	int target = sum;
	vector<int> prev(target+1, 0), cur(target+1,0);
	prev[0] = true;
	cur[0] = true;
	if (arr[0] <= target) prev[arr[0]] = true;

	for(int ind=1;ind<n;ind++){
		for(int t=1;t<=target;t++){
			bool not_taken = prev[t];
			bool taken = false;
			if(arr[ind]<=t){
				taken = prev[t-arr[ind]];
			}
			cur[t] = taken || not_taken;
		}
		prev = cur;
	}

    //this is the main part of this problem
	int ans = 1e9;
	for(int i=0;i<=target/2;i++){
		if(prev[i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
	return ans;
}


//#######################################################################
//#######-------DP 17. Counts Subsets with Sum K | Dp on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/count-subsets-with-sum-k-dp-17/
//Problem:  https://www.naukri.com/code360/problems/number-of-subsets_3952532

FOR ALL THE COUNT PROBLEMS:
if the condition is satisfied return 1, else return 0
- To explore all the paths, best way is to do recursion, that is why we are using recursion
------
for handling the cases in which the array contains 0 --> 
use only one base condition -->
if(ind < 0) return tar == 0;

or you can use--> 
if(ind == 0){
         if(num[0] == 0 && tar == 0) return 2;
         if(num[0] == tar || tar == 0) return 1;
         return 0;
   }
-----

//--------
//Top Down(HANDLE 0 case, getting wa)
//--------

const int md = 1e9+7;
int f(int i, int target,vector<int>& arr,  vector<vector<int>>&dp){
	if(i==0){
		if(target==0 && arr[i]==0) return 2;
		else if(target==arr[i] || target==0) return 1;
		else return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int not_taken = f(i-1, target, arr, dp);
	int taken = 0;
	if(arr[i]<=target){
		taken = f(i-1, target-arr[i], arr, dp);
	}
	return dp[i][target] = (taken + not_taken)%md;
}
int findWays(vector<int>& arr, int k)
{	
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}


//---------
//Bottom Up
//---------

const int md = 1e9+7;
int findWays(vector<int>& arr, int k)
{	
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, 0));
	if(arr[0] == 0) dp[0][0] = 2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1;  // 1 case -pick

	for(int i=1;i<n;i++){
		for(int t=0;t<=k;t++){
			int not_taken = dp[i-1][t];
			int taken = 0;
			if(arr[i]<=t){
				taken = dp[i-1][t-arr[i]];
			}
			dp[i][t] = (taken + not_taken)%md;
		}
	}
	return dp[n-1][k];
}

//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 18. Count Partitions With Given Difference | Dp on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/count-partitions-with-given-difference-dp-18/
//Problem:  https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628

Steps:
(this is just dp 17 with modified target)
1. count the subsets where sum is equal to , s2 = (tot - d)/2;
2. 2 ta ghor fillup kora first row er(what if there is 0 in arr[0])

//---------
//Top Down
//---------

const int md = 1e9+7;
int f(int i, int target,vector<int> &arr, vector<vector<int>>&dp ){
    if(i==0){
		if(target==0 && arr[i]==0) return 2;
		else if(target==arr[i] || target==0) return 1;
		else return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int not_taken = f(i-1, target, arr, dp);
	int taken = 0;
	if(arr[i]<=target){
		taken = f(i-1, target-arr[i], arr, dp);
	}
	return dp[i][target] = (taken + not_taken)%md;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    //target%2 -> s2/target er value decimal hoite parbe na
    if(target<0 || target%2) return 0;
    target/=2;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    return f(n-1,target, arr,dp);
}

//---------
//Bottom Up
//---------
const int md = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    if(target<0 || target%2) return 0;
    target/=2;
    vector<vector<int>>dp(n, vector<int>(target+1,0));
    
    //2 ta ghor fillup kora first row er
    if(arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int not_taken = dp[i-1][t];
            int taken = 0;
            if(arr[i]<=t){
                taken = dp[i-1][t-arr[i]];
            }
            dp[i][t] = (taken + not_taken)%md;
        }
    }

    return dp[n-1][target];
}
//---------
//Bottom Up(Space optimized)
//---------
const int md = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    if(target<0 || target%2) return 0;
    target/=2;
    vector<int>prev(target+1),cur(target+1);

    if(arr[0]==0) prev[0] = 2;
    else prev[0] = 1;
    if(arr[0]!=0 && arr[0]<=target) prev[arr[0]] = 1;


    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int not_taken = prev[t];
            int taken = 0;
            if(arr[i]<=t){
                taken = prev[t-arr[i]];
            }
            cur[t] = (taken + not_taken)%md;
        }
        prev = cur;
    }

    return prev[target];
}

//#######################################################################
//#######-------DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/0-1-knapsack-dp-19/
//Problem:  https://www.naukri.com/code360/problems/0-1-knapsack_920542
- When there is no uniformity, you cannot apply greedy
- Think base case as a single element

//---------
//Top Down
//---------
#include <bits/stdc++.h> 
int f(int i, int w, vector<int> wg, vector<int> vl, vector<vector<int>>&dp){
	if(i==0){
		if(wg[i]<=w) return vl[i];
		else return 0;
	}
	if(dp[i][w]!=-1) return dp[i][w];
	int not_taken = 0 + f(i-1, w, wg, vl, dp);
	int taken = 0;
	if(wg[i]<=w){
		taken = vl[i]+ f(i-1, w-wg[i], wg, vl, dp);
	}
	return dp[i][w] = max(taken , not_taken);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	return f(n-1, maxWeight, weight, value, dp);
}

//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,0));
	for(int i=0;i<n;i++) dp[i][0] = 0;
	for(int i=1;i<=maxWeight;i++){
		if(i>=weight[0]) dp[0][i] = value[0];
		else dp[0][i] = 0;
	}

	for(int i=1;i<n;i++){
		for(int w=1;w<=maxWeight;w++){
			int not_taken = 0 + dp[i-1][w];
			int taken = 0;
			if(weight[i]<=w){
				taken = value[i]+ dp[i-1][w-weight[i]];
			}
			dp[i][w] = max(taken , not_taken);
		}
	}
	return dp[n-1][maxWeight];
}


//---------
//Bottom Up(Space optimized)
//---------
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>prev(maxWeight+1,0), cur(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}

	for(int i=1;i<n;i++){
		for(int w=1;w<=maxWeight;w++){
			int not_taken = 0 + prev[w];
			int taken = 0;
			if(weight[i]<=w){
				taken = value[i]+ prev[w-weight[i]];
			}
			cur[w] = max(taken , not_taken);
		}
		prev = cur;
	}
	return prev[maxWeight];
}

//---------
//Bottom Up(Space optimized, without cur array, 1 array optimization)
//---------

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}

	for(int i=1;i<n;i++){
		for(int w=maxWeight;w>=1;w--){
			int not_taken = 0 + prev[w];
			int taken = 0;
			if(weight[i]<=w){
				taken = value[i]+ prev[w-weight[i]];
			}
			prev[w] = max(taken , not_taken);
		}
	}
	return prev[maxWeight];
}

//#######################################################################
//#######-------DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/minimum-coins-dp-20/
//Problem:  https://www.naukri.com/code360/problems/minimum-elements_3843091
- when find minimum apply INT_MAX to not consider it
- when find maximum apply INT_MIN to not consider it
- Infinite supply, multiple use -> take is always will be in that index
- Time complexity in recursion - >>O(2^n)

//---------
//Top Down
//---------

#include <bits/stdc++.h> 
int f(int i, int target, vector<int> &num, vector<vector<int>>&dp ){
    if(i==0){
        if(target%num[i]==0) return target/num[i];
        else return 1e9;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int not_taken = f(i-1, target, num, dp);
    int taken = 1e9;//confuse
    if(num[i]<=target){
        taken = 1 + f(i, target-num[i], num, dp);//confuse
    }
    return dp[i][target] = min(not_taken , taken);
}
int minimumElements(vector<int> &num, int x)
{  
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1,-1));
    int ans = f(n-1, x, num, dp);
    if(ans>=1e9) return -1;
    return ans;
}

//---------
//Bottom Up
//---------
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{  
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1,0));

    for(int i=1;i<=x;i++){
        if(i%num[0]==0)dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=x;t++){
            int not_taken = dp[i-1][t];//uporer ta
            int taken = 1e9;//current row ta
            if(num[i]<=t){
                taken = 1 + dp[i][t-num[i]];
            }
            dp[i][t] = min(taken, not_taken);
        }
    }
    int ans = dp[n-1][x];
    if(ans>=1e9) return -1;
    return ans;
}

//---------
//Bottom Up(Space optimized)
//---------
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{  
    int n = num.size();
    vector<int>prev(x+1,0),cur(x+1,0);

    for(int i=1;i<=x;i++){
        if(i%num[0]==0)prev[i] = i/num[0];
        else prev[i] = 1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=x;t++){
            int not_taken = prev[t];
            int taken = 1e9;
            if(num[i]<=t){
                taken = 1 + cur[t-num[i]];
            }
            cur[t] = min(taken, not_taken);
        }
        prev = cur;
    }
    int ans = prev[x];
    if(ans>=1e9) return -1;
    return ans;
}

//#######################################################################
//#######-------DP 21. Target Sum | DP on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/target-sum-dp-21/
//Problem:  https://www.naukri.com/code360/problems/target-sum_4127362

Same as DP 18. Count Partitions With Given Difference

//---------
//Top Down
//---------
#include <bits/stdc++.h> 

int f(int i, int target,vector<int> &arr, vector<vector<int>>&dp ){
    if(i==0){
		if(target==0 && arr[i]==0) return 2;
		else if(target==arr[i] || target==0) return 1;
		else return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int not_taken = f(i-1, target, arr, dp);
	int taken = 0;
	if(arr[i]<=target){
		taken = f(i-1, target-arr[i], arr, dp);
	}
	return dp[i][target] = (taken + not_taken);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    if(target<0 || target%2) return 0;
    target/=2;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    return f(n-1,target, arr,dp);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}

//---------
//Bottom Up
//---------
Same as DP 18.
//---------
//Bottom Up(Space optimized)
//---------
Same as DP 18.

//#######################################################################
//#######-------DP 22. Coin Change 2 | Infinite Supply Problems--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/coin-change-2-dp-22/
//Problem:  https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471

Recursion time complexity for this: more than 2^n

//---------
//Top Down
//---------
#include <bits/stdc++.h> 
long f(int i, int target, int *arr, vector<vector<long>>&dp){
    if(i==0){
        if(target%arr[0]==0) return 1;//last e jodi 1 or emn value thake
        else return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    long not_taken = f(i-1,target,arr,dp);
    long taken = 0;
    if(arr[i]<=target){
        taken = f(i, target-arr[i],arr, dp);
    }
    return dp[i][target] = taken + not_taken;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n, vector<long>(value+1, -1));
    return f(n-1, value,denominations, dp);
}
//---------
//Bottom Up
//---------
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n, vector<long>(value+1, 0));
    for(int i=1;i<=value;i++) if(i%denominations[0]==0)dp[0][i] = 1;
    //if cannot select any that is one way
    for(int i=0;i<n;i++)dp[i][0] = 1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=value;t++){
            long not_taken = dp[i-1][t];
            long taken = 0;
            if(denominations[i]<=t){
                taken = dp[i][t-denominations[i]];
            }
            dp[i][t] = taken + not_taken;
        }
    }
    return dp[n-1][value];
}

//---------
//Bottom Up(Space optimized)
//---------
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long>prev(value+1, 0), cur(value+1,0);
    for(int i=1;i<=value;i++) if(i%denominations[0]==0)prev[i] = 1;
    //if cannot select any that is one way
    prev[0] = cur[0] = 1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=value;t++){
            long not_taken = prev[t];
            long taken = 0;
            if(denominations[i]<=t){
                taken = cur[t-denominations[i]];
            }
            cur[t] = taken + not_taken;
        }
        prev = cur;
    }
    return prev[value];
}


//---------
//Bottom Up(Space optimized) - 1d array
//---------
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long>prev(value+1, 0);
    for(int i=1;i<=value;i++) if(i%denominations[0]==0)prev[i] = 1;
    //if cannot select any that is one way
    prev[0] = 1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=value;t++){
            long not_taken = prev[t];
            long taken = 0;
            if(denominations[i]<=t){
                taken = prev[t-denominations[i]];
            }
            prev[t] = taken + not_taken;
        }
    }
    return prev[value];
}



//#######################################################################
//#######-------DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/unbounded-knapsack-dp-23/
//Problem:  https://www.naukri.com/code360/problems/unbounded-knapsack_1215029

Unbounded - multiple time taking allowed(infinite supply)
bounded - multiple time taking not allowed
- when there is infinite supply it will always be in that index

//---------
//Top Down
//---------

int f(int i, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
    if(i==0){
        return (w/weight[i])*profit[i];
    }
    if(dp[i][w]!=-1) return dp[i][w];
    int not_taken = f(i-1, w, profit, weight,dp);
    int taken = 0;
    if(weight[i]<=w){
        taken = profit[i] + f(i, w-weight[i], profit, weight,dp);
    }
    return dp[i][w] = max(not_taken, taken);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n, vector<int>(w+1,-1));
    return f(n-1, w, profit, weight,dp);
}

//---------
//Bottom Up
//---------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n, vector<int>(w+1,0));
    for(int i=0;i<=w;i++) dp[0][i] = (i/weight[0])*profit[0];
    for(int i=1;i<n;i++){
        for(int wg=1;wg<=w;wg++){
            int not_taken = dp[i-1][wg];
            int taken = 0;
            if(weight[i]<=wg){
                taken = profit[i] + dp[i][wg-weight[i]];
            }
            dp[i][wg] = max(not_taken, taken);
        }
    }
    return dp[n-1][w];
}
//---------
//Bottom Up(Space optimized)
//---------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1,0), cur(w+1,0);
    for(int i=0;i<=w;i++) prev[i] = (i/weight[0])*profit[0];
    for(int i=1;i<n;i++){
        for(int wg=1;wg<=w;wg++){
            int not_taken = prev[wg];
            int taken = 0;
            if(weight[i]<=wg){
                taken = profit[i] + cur[wg-weight[i]];
            }
            cur[wg] = max(not_taken, taken);
        }
        prev = cur;
    }
    return prev[w];
}

//---------
//Bottom Up(Space optimized) - one 1d array
- Because we only need current top element, and current-thatelement value
//---------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1,0);
    for(int i=0;i<=w;i++) prev[i] = (i/weight[0])*profit[0];
    for(int i=1;i<n;i++){
        for(int wg=1;wg<=w;wg++){
            int not_taken = prev[wg];
            int taken = 0;
            if(weight[i]<=wg){
                taken = profit[i] + prev[wg-weight[i]];
            }
            prev[wg] = max(not_taken, taken);
        }
    }
    return prev[w];
}

//#######################################################################
//#######-------DP 24. Rod Cutting Problem | 1D Array Space Optimised Approach--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/rod-cutting-problem-dp-24/
//Problem:  https://www.naukri.com/code360/problems/rod-cutting-problem_800284

//---------
//Top Down
//---------
int f(int i, int target, vector<int> &price,vector<vector<int>>&dp){
	if(i==0){
		return target*price[0];
	}
	if(dp[i][target]!=-1) return dp[i][target];
	int not_taken = f(i-1,target, price, dp);
	int taken = 0;
	int rd = i+1;
	if(rd<=target){
		taken = price[i] + f(i,target-rd, price, dp);
	}
	return dp[i][target] = max(taken, not_taken);
}
int cutRod(vector<int> &price, int n)
{	
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1, n, price,dp);
}

//---------
//Bottom Up
//---------
int cutRod(vector<int> &price, int n)
{	
	vector<vector<int>>dp(n,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i] = i*price[0];
	}
	for(int i=1;i<n;i++){
		for(int t=1;t<=n;t++){
			int not_taken = dp[i-1][t];
			int taken = 0;
			int rd = i+1;
			if(rd<=t){
				taken = price[i] + dp[i][t-rd];
			}
			dp[i][t] = max(taken, not_taken);
		}
	}
	return dp[n-1][n];
}
//---------
//Bottom Up(Space optimized) - one 1d array
//---------

- We donot need 2 array in unbounded knapsack type problems, we can space optimize with 1 array only

int cutRod(vector<int> &price, int n)
{	
	vector<int>prev(n+1,0);
	for(int i=0;i<=n;i++){
		prev[i] = i*price[0];
	}
	for(int i=1;i<n;i++){
		for(int t=1;t<=n;t++){
			int not_taken = prev[t];
			int taken = 0;
			int rd = i+1;
			if(rd<=t){
				taken = price[i] + prev[t-rd];
			}
			prev[t] = max(taken, not_taken);
		}
	}
	return prev[n];
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Strings--------######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

Problems on this 
- Comparision 
- Replacement 
- edit

DP on strings concepts: Dp 25. Longest Common Subsequence, DP 32. Distinct Subsequences[Those 2 videos are most important]

- There is not dp[-1] index, not possible in c++
- For string related dp problem, when doing tabulation think about empty sequence also

DP ON Strings Code:

//Top Down
#include<bits/stdc++.h>
int f(int i, int j, string&s, string&t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

//Bottom Up
#include<bits/stdc++.h>
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

//#######################################################################
//#######-------Dp 25. Longest Common Subsequence --------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
//BOTTOM UP: https://youtu.be/NnD96abizww?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
//Problem:  https://www.naukri.com/code360/problems/longest-common-subsequence_624879

Sequence: maintains order

//---------
//Top Down
//---------

#include<bits/stdc++.h>
int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}


////////Both if else statement in return 
#include<bits/stdc++.h>
int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    else return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

//---------
//Bottom Up(Space optimized)
//---------
#include<bits/stdc++.h>
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}


//#######################################################################
//#######-------DP 26. Print Longest Common Subsequence | Dp on Strings--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/print-longest-common-subsequence-dp-26/
//Problem:  https://www.naukri.com/code360/problems/longest-common-subsequence_624879

- If there are multiple answers, you cannot apply using a dp table, but for this you can

//---------
//Bottom Up(just prints the sequence)
//---------

adebc
dcadb
->adb 

Time complexity: worst case O(n+m), best case O(n)

//Full Code Printing Longest Common Subsequence 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int index = dp[n][m];
	vector<char>ans(index, 0);

    int i = n, j = m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index-1] = s[i-1];
            i--;
            j--;
            index--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    for(auto x: ans) cout<<x;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)lcs("adebc","dcadb");
    return 0;
}

//#######################################################################
//#######-------DP 27. Longest Common Substring | DP on Strings--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-common-substring-dp-27/
//Tutorial 2: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
//Problem:  https://www.naukri.com/code360/problems/longest-common-substring_1235207

- Since, this is consecutive you are not dependant on the previous guy

//---------
//Top Down
//---------

NOT SURE??????

//---------
//Bottom Up
//---------
int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}
//---------
//Bottom Up(Space optimized)
//---------

int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<int>prev(m+1), cur(m+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
            else cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}

//---------
//Bottom Up(Space optimized) - 1d array only ones
//---------

int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<int>prev(m+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>0;j--){
            if(str1[i-1]==str2[j-1]){
                prev[j] = 1 + prev[j-1];
                ans = max(ans, prev[j]);
            }
            else prev[j] = 0;
        }
    }
    return ans;
}

//#######################################################################
//#######-------DP 28. Longest Palindromic Subsequence--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-palindromic-subsequence-dp-28/
//Problem:  https://www.naukri.com/code360/problems/longest-palindromic-subsequence_842787

- This is just an extension of longtest common subsequence
- Just reverse the string and find the longest common subsequence

string s1 = "bbabcbcab";
string s2 = s1;
reverse(s2.begin(),s2.end());
while(t--) lcs(s1,s2);



//---------
//Top Down
//---------

Top down approach of longest common subsequence where s1 = string and s2 = reverse(s1);

#include <bits/stdc++.h> 
int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}

//---------
//Bottom Up
//---------

Bottom Up approach of longest common subsequence where s1 = string and s2 = reverse(s1); 

#include <bits/stdc++.h> 
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}


//---------
//Bottom Up(Space optimized)
//---------
Bottom Up(Space optimized) approach of longest common subsequence where s1 = string and s2 = reverse(s1);

#include <bits/stdc++.h> 
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}

//FULL CODE - Printing Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int index = dp[n][m];
	vector<char>ans(index, 0);

    int i = n, j = m;
    while(i>0 && j>0){
        //If same diagonally then only go!
        if(s[i-1]==t[j-1]){
            ans[index-1] = s[i-1];
            i--;
            j--;
            index--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    for(auto x: ans) cout<<x;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    string s1 = "bbabcbcab";
    string s2 = s1;
    reverse(s2.begin(),s2.end());

    while(t--)lcs(s1,s2);
    return 0;
}

//#######################################################################
//#######-------DP 29. Minimum Insertions to Make String Palindrome--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/minimum-insertions-to-make-string-palindrome-dp-29/
//Problem:  https://www.naukri.com/code360/problems/minimum-insertions-to-make-palindrome_985293

Steps:
Longest Palindromic Subsequence and n - Longest Palindromic Subsequence

//---------
//Top Down
//---------

Top Down of Longest Palindromic Subsequence and n - Longest Palindromic Subsequence;

int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minimumInsertions(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}

//---------
//Bottom Up
//---------

Bottom Up of Longest Palindromic Subsequence and n - Longest Palindromic Subsequence;

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minimumInsertions(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}


//---------
//Bottom Up(Space optimized)
//---------

Bottom Up(Space optimized) of Longest Palindromic Subsequence and n - Longest Palindromic Subsequence;

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minimumInsertions(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}


//#######################################################################
//#######-------DP 30. Minimum Insertions/Deletions to Convert String A to String B--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/minimum-insertions-deletions-to-convert-string-dp-30/
//Problem:  https://www.naukri.com/code360/problems/can-you-make_4244510

Steps:
(n - lcs(s1,s2)) + (m - lcs(s1,s2))

//---------
//Top Down
//---------

int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

int canYouMake(string &s1, string &s2){
    int n = s1.size(), m = s2.size();
    return (n - lcs(s1,s2)) + (m - lcs(s1,s2));
}

//---------
//Bottom Up
//---------
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}
int canYouMake(string &s1, string &s2){
    int n = s1.size(), m = s2.size();
    return (n - lcs(s1,s2)) + (m - lcs(s1,s2));
}

//---------
//Bottom Up(Space optimized)
//---------

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}

int canYouMake(string &s1, string &s2){
    int n = s1.size(), m = s2.size();
    return (n - lcs(s1,s2)) + (m - lcs(s1,s2));
}


//#######################################################################
//#######-------DP 31. Shortest Common Supersequence | DP on Strings--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/
//Problem:  https://www.naukri.com/code360/problems/shortest-supersequence_4244493

The length is n + m - lcs(n,m)
Steps:
1. Apply LCS 
2. Add string part of that is same(diagonal) + that is getting reduced(vertical or horizontal)


//---------
//Top Down
//---------

Just apply the steps portion

//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 

string lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

	string ans = "";

    int i = n, j = m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans+= s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]<dp[i-1][j]){
				ans+=s[i-1];
                i--;
            }
            else{
				ans+=t[j-1];
                j--;
            }
        }
    }

	while(i>0) ans+=s[i-1],i--;
	while(j>0) ans+=t[j-1],j--;
	reverse(ans.begin(),ans.end());
	return ans;
}

string shortestSupersequence(string a, string b)
{
	return lcs(a,b);
}


//---------
//Bottom Up(Space optimized)
//---------

Just apply the steps portion


//#######################################################################
//#######-------DP 32. Distinct Subsequences | 1D Array Optimisation Technique--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/distinct-subsequences-dp-32/
//Problem:  https://www.naukri.com/code360/problems/subsequence-counting_3755256


Steps:
1. j == -1 means j has passed all, so return 1, and if i==-1 means i has passed all and did not matched, so return 0
2. if(s1[i]==s2[j]) check in above and above left, else check only above

//---------
//Top Down
//---------

//0 base indexing
const int md = 1e9+7;
int f(int i, int j,string &s1,string &s2,vector<vector<int>>&dp ){
	if(j<0) return 1;
	if(i<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i]==s2[j]){
		return dp[i][j] = (f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp))%md;
	}
	else return dp[i][j] = f(i-1,j,s1,s2,dp)%md;
}
int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1,m-1,str,sub,dp);
}

//1 base indexing
const int md = 1e9+7;
int f(int i, int j,string &s1,string &s2,vector<vector<int>>&dp ){
	if(j==0) return 1;
	if(i==0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i-1]==s2[j-1]){
		return dp[i][j] = (f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp))%md;
	}
	else return dp[i][j] = f(i-1,j,s1,s2,dp)%md;
}
int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
	return f(n,m,str,sub,dp);
}

//---------
//Bottom Up
//---------
- If matched take both diagonal and upor else take only upor

const int md = 1e9+7;
int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<vector<int>>dp(n+1, vector<int>(m+1,0));
	for(int i=0;i<=m;i++)dp[0][i] = 0;
	for(int i=0;i<=n;i++) dp[i][0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str[i-1]==sub[j-1]){
				dp[i][j] = (dp[i-1][j-1] +dp[i-1][j])%md;
			}
			else dp[i][j] = dp[i-1][j]%md;
		}
	}
	return dp[n][m];
}

//---------
//Bottom Up(Space optimized)
//---------

const int md = 1e9+7;

int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<int>prev(m+1,0), cur(m+1);
	prev[0] = 1, cur[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str[i-1]==sub[j-1]){
				cur[j] = (prev[j-1] + prev[j])%md;
			}
			else cur[j] = prev[j]%md;
		}
		prev = cur;
	}
	return prev[m];
}

//---------
//Bottom Up(Space optimized) - one 1d array
//---------

const int md = 1e9+7;

int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<int>prev(m+1,0);
	prev[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			//don't need the last index after computing, just override that
			if(str[i-1]==sub[j-1]){
				prev[j] = (prev[j-1] + prev[j])%md;
			}
			else prev[j] = prev[j]%md;
		}
	}
	return prev[m];
}

//#######################################################################
//#######-------DP 33. Edit Distance | Recursive to 1D Array Optimised Solution--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/edit-distance-dp-33/
//Problem:  https://www.naukri.com/code360/problems/edit-distance_630420

if same -> diagonal side 
else -> minimum of the 3 side + 1


Delete,Replace,Insert

Step:
1. If same then move ahead
2. If not same, do one of (Delete,Replace,Insert)



//---------
//Top Down
//---------

//0 base indexing
int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    if(i<0) return j+1;//add all j
    if(j<0) return i+1;//delete all i
    if(dp[i][j]!=-1)return dp[i][j];

    //If same then move ahead
    if(s1[i]==s2[j]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }
    //insert, delete, replace
    int ins = 1 + f(i, j-1,s1,s2,dp);//insert
    int del = 1 + f(i-1,j,s1,s2,dp);//delete
    int rep = 1 + f(i-1,j-1,s1,s2,dp);//replace
    return dp[i][j] = min(min(ins,del), rep);//minimum of all
}
int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    return f(n-1, m-1, str1, str2, dp);
}

//1 base indexing
int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    if(i==0) return j;//add all j
    if(j==0) return i;//delete all i
    if(dp[i][j]!=-1)return dp[i][j];

    //If same then move ahead
    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }
    //insert, delete, replace
    int ins = 1 + f(i, j-1,s1,s2,dp);
    int del = 1 + f(i-1,j,s1,s2,dp);
    int rep = 1 + f(i-1,j-1,s1,s2,dp);
    return dp[i][j] = min(min(ins,del), rep);
}
int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
    return f(n, m, str1, str2, dp);
}

//---------
//Bottom Up
//---------

int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
    //for empty sequence matching
    for(int i=0;i<=n;i++) dp[i][0] = i;//for deleting extra sequence from s2
    for(int i=0;i<=m;i++) dp[0][i] = i;//for adding  

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int ins = 1 + dp[i][j-1];//insert
                int del = 1 + dp[i-1][j];//delete
                int rep = 1 + dp[i-1][j-1];//replace
                dp[i][j] = min(min(ins,del), rep);
            }           
        }
    }
    return dp[n][m];
}

//---------
//Bottom Up(Space optimized) 
//---------

int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<int>prev(m+1,0), cur(m+1,0);

    for(int i=0;i<=m;i++) prev[i] = i;
    for(int i=1;i<=n;i++){
        cur[0] = i;
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]) cur[j] = prev[j-1];
            else{
                int ins = 1 + cur[j-1];//insert
                int del = 1 + prev[j];//delete
                int rep = 1 + prev[j-1];//replace
                cur[j] = min(min(ins,del), rep);
            }           
        }
        prev = cur;
    }
    return prev[m];
}


//#######################################################################
//#######-------DP 34. Wildcard Matching | Recursive to 1D Array Optimisation--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/wildcard-matching-dp-34/
//Problem:  https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650

Steps:
1. if both are exhausted then it is true
   if i is exhausted and j is still remaining then it is never possible
   if j is exhausted and i is still remaining then all remaining in i must be '*'
2. if both index has same value or '?' then shrink the string, f(i-1,j-1)
3. if s1[i]=='*' then apply take or not take condition 
4. else it is false(the both indices have different values)

//---------
//Top Down
//---------

//0 base indexing
#include<bits/stdc++.h>
bool f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
   if(i<0 && j<0) return true;
   if(i<0 && j>=0)return false;
   if(i>=0 && j<0){
      //rest should be * only
      for(int k=0;k<=i;k++){
         if(s1[k]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];

   if(s1[i]==s2[j] || s1[i]=='?'){
      return dp[i][j] = f(i-1,j-1,s1,s2,dp);
   }
   else if(s1[i]=='*'){
      //take or not take
      return dp[i][j] = f(i,j-1,s1,s2,dp) || f(i-1,j,s1,s2,dp);
   }
   else false;
}
bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>>dp(n, vector<int>(m,-1));
   return f(n-1, m-1, pattern, text, dp);
}

//1 base indexing
#include<bits/stdc++.h>
bool f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
   if(i==0 && j==0) return true;
   if(i==0 && j>0)return false;
   if(i>0 && j==0){
      //rest should be * only
      for(int k=0;k<i;k++){
         if(s1[k]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];

   if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
      return dp[i][j] = f(i-1,j-1,s1,s2,dp);
   }
   else if(s1[i-1]=='*'){
      //take or not take
      return dp[i][j] = f(i,j-1,s1,s2,dp) || f(i-1,j,s1,s2,dp);
   }
   else false;
}
bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
   return f(n, m, pattern, text, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   string s1 = pattern;
   string s2 = text;
   
   vector<vector<int>>dp(n+1, vector<int>(m+1,0));
   dp[0][0] = 1;
   for(int i=1;i<=m;i++) dp[0][i] = 0;
   for(int i=1;i<=n;i++){
      bool ok = 1;
      for(int k=0;k<i;k++){
         if(pattern[k] != '*'){
            ok = 0;
            break;
         }
         if(ok)dp[i][0] = 1;
      }
   }

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
            dp[i][j] = dp[i-1][j-1];
         }
         else if(s1[i-1]=='*'){
            dp[i][j] = dp[i][j-1] || dp[i-1][j];
         }
         else dp[i][j] = 0;
      }
   }

   return dp[n][m];
}

//---------
//Bottom Up(Space optimized)
//---------

#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   string s1 = pattern;
   string s2 = text;
   
   vector<int>prev(m+1,0), cur(m+1,0);
   prev[0] = 1;
   for(int i=1;i<=m;i++) prev[i] = 0;
   
   for(int i=1;i<=n;i++){
      bool ok = 1;
      for(int k=0;k<i;k++){
         if(pattern[k] != '*'){
            ok = 0;
            break;
         }
      }
      cur[0] = ok;

      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
            cur[j] = prev[j-1];
         }
         else if(s1[i-1]=='*'){
            cur[j] = cur[j-1] || prev[j];
         }
         else cur[j] = 0;
      }
      prev = cur;
   }

   return prev[m];
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Stocks--------#######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


DP 35. Best Time to Buy and Sell Stock          - 1 transaction
DP 36. Buy and Sell Stock - II                  - unlimited transaction
DP 37. Buy and Sell Stocks III                  - 2 transaction
DP 38. Buy and Stock Sell IV                    - k transaction
DP 39. Buy and Sell Stocks With Cooldown        - cannot buy and sell consecutive day, (after selling there is atleast 1 day gap)
DP 40. Buy and Sell Stocks With Transaction Fee - with transaction fee

DP ON Stocks Code:
#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{   
    vector<vector<long>>dp(n+1, vector<long>(2,0));

    dp[n][1]=dp[n][0] = 0;
    for(int i=n-1;i>=0;i--){
        for(buy : {0,1}){
            long prof = 0;
            if(buy){
                prof = max(-values[i] + dp[i+1][0], dp[i+1][1]);//kine felle values kombe, barbe, then take or not take
            }
            else prof = max(values[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][buy] = prof;
        }
    }
    return dp[0][1];
}

//#######################################################################
//#######-------DP 35. Best Time to Buy and Sell Stock | DP on Stocks--------########
//Tutorial: https://takeuforward.org/data-structure/stock-buy-and-sell-dp-35/
//Problem:  https://www.naukri.com/code360/problems/stocks-are-profitable_893405

We are solving smaller problems to solve bigger problems, this is why this is dp problem
- It is also a constructive algorithm problem
first buy, then sell

Steps:
1. first minimum is the first value and initially the answer is 0
2. keep the minimum prices and keep the mamxium answer possible

//---------
//Top Down
//---------


//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mn = prices[0], ans = 0;
    for(int i=1;i<prices.size();i++){
        mn = min(mn, prices[i]);
        ans = max(ans, prices[i] - mn);
    }
    return ans;
}


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 36. Buy and Sell Stock - II | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stock-ii-dp-36/
//Problem:  https://www.naukri.com/code360/problems/selling-stock_630282

BSBSBSBS is allowed but BBBSSS not allowed

Steps:
1. On that day, kinle/sell krle profit kombe or barbe[this is take case]
2. On that day, na kinle/sell krle profit kombe na or barbe na[this is not take case]

//---------
//Top Down
//---------

#include<bits/stdc++.h>
long f(int i, int buy, int n, long *values,vector<vector<long>>&dp ){
    if(i==n) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    long prof = 0;
    if(buy){
        prof = max(-values[i] + f(i+1,0,n,values, dp), f(i+1,1,n,values, dp));//kine felle values kombe, barbe, then take or not take
    }
    else prof = max(values[i] + f(i+1,1,n,values, dp), f(i+1,0,n,values, dp));

    return dp[i][buy] = prof;
}
long getMaximumProfit(long *values, int n)
{   
    vector<vector<long>>dp(n, vector<long>(2,-1));
    return f(0,1,n,values, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{   
    vector<vector<long>>dp(n+1, vector<long>(2,0));

    dp[n][1]=dp[n][0] = 0;
    for(int i=n-1;i>=0;i--){
        for(buy : {0,1}){
            long prof = 0;
            if(buy){
                prof = max(-values[i] + dp[i+1][0], dp[i+1][1]);//kine felle values kombe, barbe, then take or not take
            }
            else prof = max(values[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][buy] = prof;
        }
    }
    return dp[0][1];
}

//---------
//Bottom Up(Space optimized)
//---------

#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{   
    vector<long> prev(2, 0), cur(2,0);
    for(int i=n-1;i>=0;i--){
        for(buy : {0,1}){
            long prof = 0;
            if(buy){
                prof = max(-values[i] + prev[0], prev[1]);
            }
            else prof = max(values[i] + prev[1], prev[0]);
            cur[buy] = prof;
        }
        prev = cur;
    }
    return prev[1];
}


//#######################################################################
//#######-------DP 37. Buy and Sell Stocks III | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stock-iii-dp-37/
//Problem:  https://www.naukri.com/code360/problems/buy-and-sell-stock_1071012

only when buy + sell done a transaction is completed
There are 3 changing states in this problem: index, total transactions, buy or not buy

Steps:
1. 


//---------
//Top Down(Partially Accepted)
//---------

long f(int i, int buy, int k, int n, vector<int>&values,vector<vector<vector<int>>>&dp){
    if(k==0) return 0;
    if(i==n) return 0;
    if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    long prof = 0;
    if(buy){
        prof = max(-values[i] + f(i+1,0,k, n,values, dp), f(i+1,1,k,n,values, dp));
    }
    else prof = max(values[i] + f(i+1,1,k-1, n,values, dp), f(i+1,0,k, n,values, dp));
    //only when buy + sell done a transaction is completed

    return dp[i][buy][k] = prof;
}
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    return f(0, 1, 2,n, prices, dp);
}

//---------
//Bottom Up
//---------
draw the tabulation of bottom up
WA
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=2;k++){
                long prof = 0;
                if(buy){
                    prof = max(-prices[i] + dp[i+1][1][k], dp[i+1][0][k]);
                }
                else prof = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                dp[i][buy][k] = prof;
            }
        }
    }
   return dp[0][1][2];
}

//---------
//Bottom Up(Space optimized)
//---------


////////////////////////////////////////////////////////////////////////////////////////////////
//Using 2 changing parameters
//---------
//Top Down
//---------

1. there are only 2 transaction, so BSBS, hence k is 0123 

int f(int i, int k, int n,vector<int>& prices,vector<vector<int>>&dp){
    if(i==n || k==4)return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    int profit = 0;
    if(k%2==0){
        profit = max(-prices[i] + f(i+1, k+1, n, prices, dp), f(i+1, k, n, prices, dp));
    }
    else {
        profit = max(prices[i] + f(i+1, k+1, n, prices, dp), f(i+1, k, n, prices, dp));
    }
    return dp[i][k] = profit;
}

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(4,-1));
    return f(0, 0, n, prices, dp);
}


//---------
//Bottom Up
//---------
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>>dp(n+1, vector<int>(4,0));

    for(int i=n-1;i>=0;i--){
        for(int k=0;k<4;k++){
            int profit = 0;
            if(k%2==0){
                profit = max(-prices[i] + dp[i+1][k+1], dp[i+1][k]);
            }
            else {
                profit = max(prices[i] + dp[i+1][k+1], dp[i+1][k]);
            }
            dp[i][k] = profit;
        }
    }
    return dp[0][0];
}

//---------
//Bottom Up(Space optimized) - one 1d array
//---------

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<int>prev(4,0);

    for(int i=n-1;i>=0;i--){
        for(int k=0;k<4;k++){
            int profit = 0;
            if(k%2==0){
                profit = max(-prices[i] + prev[k+1], prev[k]);
            }
            else {
                profit = max(prices[i] + prev[k+1], prev[k]);
            }
            prev[k] = profit;
        }
    }
    return prev[0];
}



//#######################################################################
//#######-------DP 38. Buy and Stock Sell IV | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stock-iv-dp-38/
//Problem:  https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_1080698

Steps:
1. apply k in the transaction part, instead of 2(previous question)

//---------
//Top Down
//---------

#include <bits/stdc++.h> 
long f(int i, int buy, int k, int n, vector<int>&values,vector<vector<vector<int>>>&dp){
    if(k==0) return 0;
    if(i==n) return 0;
    if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    long prof = 0;
    if(buy){
        prof = max(-values[i] + f(i+1,0,k, n,values, dp), f(i+1,1,k,n,values, dp));
    }
    else prof = max(values[i] + f(i+1,1,k-1, n,values, dp), f(i+1,0,k, n,values, dp));
    return dp[i][buy][k] = prof;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
    return f(0, 1, k,n, prices, dp);
}


//---------
//Bottom Up - 3d dp
//---------

#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int t)
{
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(t+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=t;k++){
                long prof = 0;
                if(buy){
                    prof = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                }
                else prof = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                dp[i][buy][k] = prof;
            }
        }
    }
    
    return dp[0][1][t];
}


//---------
//Bottom Up(Space optimized) - 2d dp
//---------
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int t)
{
    vector<vector<int>>dp(2, vector<int>(t+1,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=t;k++){
                long prof = 0;
                if(buy){
                    prof = max(-prices[i] + dp[0][k], dp[1][k]);
                }
                else prof = max(prices[i] + dp[1][k-1], dp[0][k]);
                dp[buy][k] = prof;
            }
        }
    }
    
    return dp[1][t];
}

//---------
//Bottom Up(Space optimized) - 1d dp
//---------
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int t)
{
    vector<int>prev(2*t+1),cur(2*t+1);
    for(int i=n-1;i>=0;i--){
       for(int k=2*t-1;k>=0;k--){
            long prof = 0;
            if(k%2==0){
                prof = max(-prices[i] + prev[k+1], cur[k]);
            }
            else prof = max(prices[i] + prev[k+1], cur[k]);
            cur[k] = prof;
        } 
        prev = cur;
    }
    return prev[0];
}


//#######################################################################
//#######-------DP 39. Buy and Sell Stocks With Cooldown | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stocks-with-cooldown-dp-39/
//Problem:  https://www.naukri.com/code360/problems/highway-billboards_3125969

Steps:
1. just apply i+2 on the selling day

//---------
//Top Down
//---------

long f(int i, int buy, int n,vector<int> &prices,vector<vector<int>>&dp ){
    if(i==n || i==n+1) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    long prof = 0;
    if(buy){
        prof = max(-prices[i] + f(i+1,0,n,prices, dp), f(i+1,1,n,prices, dp));
    }
    else prof = max(prices[i] + f(i+2,1,n,prices, dp), f(i+1,0,n,prices, dp));

    return dp[i][buy] = prof;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2,-1));
    return f(0, 1, n, prices, dp);
}

//---------
//Bottom Up
//---------

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(n+2, vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy:{0,1}){
            long prof = 0;
            if(buy){
                prof = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            }
            else prof = max(prices[i] + dp[i+2][1], dp[i+1][0]);
            dp[i][buy] = prof;
        }
    }
    return dp[0][1];
}

//Omitting buy portion, explicitly writing it
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(n+2, vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
    }
    return dp[0][1];
}

//---------
//Bottom Up(Space optimized) - 3 1d array
//---------
- Here, we need 3 rows, so keep the 3 rows 

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<int> cur(2, 0); 
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);    
    for(int i=n-1;i>=0;i--){
        cur[1] = max(-prices[i] + front1[0], front1[1]);
        cur[0] = max(prices[i] + front2[1], front1[0]);
        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}

//#######################################################################
//#######-------DP 40. Buy and Sell Stocks With Transaction Fee | Recursion to Space Optimisation--------########
//Tutorial:https://takeuforward.org/data-structure/buy-and-sell-stocks-with-transaction-fees-dp-40/
//Problem:  https://www.naukri.com/code360/problems/rahul-and-his-chocolates_3118974

Steps:
1. Just delete fee everytime you buy or sell, [delete only 1 time]

//---------
//Top Down
//---------
long f(int i, int buy, int n,vector<int> &prices,int fee, vector<vector<int>>&dp ){
    if(i==n) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    long prof = 0;
    if(buy){
        prof = max(-prices[i] + f(i+1,0,n,prices, fee, dp), f(i+1,1,n,prices, fee, dp));
    }
    else prof = max(prices[i]-fee + f(i+1,1,n,prices,fee, dp), f(i+1,0,n,prices,fee, dp));

    return dp[i][buy] = prof;
}

int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<vector<int>>dp(n, vector<int>(2,-1));
	return f(0, 1, n, prices,fee, dp);
}

//---------
//Bottom Up
//---------
int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<vector<int>>dp(n+1, vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i]-fee + dp[i+1][1], dp[i+1][0]);
    }
    return dp[0][1];
}

//---------
//Bottom Up(Space optimized)
//---------
int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<int> ahead(2, 0); 
    vector<int> cur(2, 0);
    for(int i=n-1;i>=0;i--){
        cur[1] = max(-prices[i] + ahead[0], ahead[1]);
        cur[0] = max(prices[i]-fee + ahead[1], ahead[0]);
        ahead = cur;
    }
    return ahead[1];
}
//a little different
int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<int> ahead(2, 0); 
    vector<int> cur(2, 0);
    for(int i=n-1;i>=0;i--){
        cur[1] = max(-prices[i] + ahead[0], cur[1]);
        cur[0] = max(prices[i]-fee + ahead[1], cur[0]);
        ahead = cur;
    }
    return ahead[1];
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on LIS--------##########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

LIS CODE: 
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(1+dp[j], dp[i]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    return ans;
}

//#######################################################################
//#######-------DP 41. Longest Increasing Subsequence | Memoization--------########
//Tutorial: https://takeuforward.org/data-structure/longest-increasing-subsequence-dp-41/
//Problem:  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

Steps:
1. At first set previous anything -1,-100 anything
2. if taken, previous would be that index and move main index to index + 1    
   if not taken, previous would be same, index+1 would go on 


//---------
//Top Down(Runtime error because of constraints)
//---------
#include<bits/stdc++.h>
int f(int i, int j, int n,int arr[], vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    int taken = 0;
    int not_taken = f(i+1,j,n,arr,dp);
    if(j==-1 || arr[i]>arr[j]){
        taken = 1 + f(i+1,i,n,arr,dp);
    }
    return dp[i][j+1] = max(not_taken, taken);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n, vector<int>(n+1,-1));
    return f(0, -1, n, arr,dp);
}


//#######################################################################
//#######-------DP 42. Printing Longest Increasing Subsequence | Tabulation | Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/printing-longest-increasing-subsequence-dp-42/
//Problem:  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

Steps:
1. by backtracking print the array

//---------
//Bottom Up(TLE cause of constraints)
//---------

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(1+dp[j], dp[i]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    return ans;
}

//---------
//Bottom Up(Print the full increasing sequence by backtrack)
//---------

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1), hash(n,1);
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && 1+dp[j]>dp[i] ){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
    }
    int ans = 0, last = -1;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans = dp[i];
            last = i;
        }
    }
    vector<int>tmp;
    tmp.push_back(arr[last]);
    while(hash[last] != last){
        last = hash[last];
        tmp.push_back(arr[last]);    
    }
    reverse(tmp.begin(),tmp.end());
    for(auto x: tmp)cout<< x << ' ';

    return ans;
}


//#######################################################################
//#######-------DP 43. Longest Increasing Subsequence | Binary Search | Intuition--------########
//Tutorial: https://takeuforward.org/data-structure/longest-increasing-subsequence-binary-search-dp-43/
//Problem:  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

To regenerate the sequence you have to do a lot more things, but doing binary search you can get the length
Steps:
1. if the element is greater than the last element add it in the array 
   else change the value with arr[index]



//---------
//Binary Search Approach(nlogn)
//---------

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>v;
    for(int i=0;i<n;i++){
        int lw = lower_bound(v.begin(),v.end(),arr[i]) - v.begin();
        if(v.size()==lw) v.push_back(arr[i]);
        else v[lw] = arr[i];
    }
    return v.size();
}

//#######################################################################
//#######-------DP 44. Largest Divisible Subset | Longest Increasing Subsequence--------########
//Tutorial: https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
//Problem:  https://www.naukri.com/code360/problems/divisible-set_3754960

Steps:
1. sort the array (and apply lIS)
2. 1 -> 4 -> 8 -> 16 (to become divisible 16 must be 16%4==0, 8%4==0, previous should be divisible) 

//---------
//Bottom Up
//---------
vector<int> divisibleSet(vector<int> &arr)
{   
    int n = arr.size();
    vector<int>dp(n,1), hash(n);
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
    }
    
    int ans = 0, last = -1;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans = dp[i];
            last = i;
        }
    }
    vector<int>tmp;
    tmp.push_back(arr[last]);
    while(hash[last] != last){
        last = hash[last];
        tmp.push_back(arr[last]);    
    }
    reverse(tmp.begin(),tmp.end());

    return tmp;
}



//#######################################################################
//#######-------DP 45. Longest String Chain | Longest Increasing Subsequence | LIS--------########
//Tutorial: https://takeuforward.org/data-structure/longest-string-chain-dp-45/
//Problem:  https://www.naukri.com/code360/problems/longest-string-chain_3752111

Steps:
1. Apply LIS 
2. sort the string array in terms of size
3. write a check function and see if the s1.size() == s2.size() + 1 and all except 1 is different
*****before comparing it must be sorted(missed in the video)
//---------
//Bottom Up
//---------
bool check(string &s1, string &s2){
    //s1 is greater in size than s2
    if(s1.size()!=s2.size()+1) return false;
    int f = 0, l = 0;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    while(f<s1.size()){
        if(s2.size()>l && s1[f]==s2[l]){
            f++;
            l++;
        }
        else f++;
    }
    if(f==s1.size() && l==s2.size()) return true;
    else return false;
}

int longestStrChain(vector<string> &arr){
    sort(arr.begin(),arr.end(), 
        [](string &s1,string &s2){
            return s1.size()<s2.size();
    });
    int n = arr.size();
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(check(arr[i],arr[j]) && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    return ans;
}

//#######################################################################
//#######-------DP 46. Longest Bitonic Subsequence | LIS--------########
//Tutorial: https://takeuforward.org/data-structure/longest-bitonic-subsequence-dp-46/
//        : https://youtu.be/TWHytKnOPaQ?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
//Problem:  https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688

bitonic: first increases then decreases

Steps:
1. Find LIS from front and from back, 
2. the answer is max(front[i] + back[i] - 1)

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(1+dp[j], dp[i]);
            }
        }
    }

	reverse(arr.begin(),arr.end());
	vector<int>dp2(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp2[i] = max(1+dp2[j], dp2[i]);
            }
        }
    }
	reverse(dp2.begin(),dp2.end());

	int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]+dp2[i]-1);
    return ans;

}

//#######################################################################
//#######-------DP 47. Number of Longest Increasing Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-longest-increasing-subsequences-dp-47/
//Problem:  https://www.naukri.com/code360/problems/number-of-longest-increasing-subsequence_3751627

If you want to verify, this is how the solution should look:
array:  1 5 4 3 2 6 7 10 8 9 
length: 1 2 2 2 2 3 4 5 5 6 
count:  1 1 1 1 1 4 4 4 4 4


Steps:
1. manage a max length(dp) and count of the sequences 
2. at the end if found the max length count the total max 

//---------
//Bottom Up
//---------

confused


//---------
//Bottom Up(DO THE BELOW DRY RUN FOR BETTER UNDERSTANDING)
//---------
#include <bits/stdc++.h>
using namespace std;

// Function to find the count of Longest Increasing Subsequences (LIS)
void findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

    int maxi = 1; // Initialize the maximum length as 1

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i]) {
                dp[i] = dp[prev_index] + 1;
                // Inherit count
                ct[i] = ct[prev_index];
            } else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i]) {
                // Increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int numberOfLIS = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            numberOfLIS += ct[i];
        }
    }

    for(int i=0;i<n;i++){
        cout<< arr[i] << ' ';
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<< dp[i] << ' ';
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<< ct[i] << ' ';
    }
    cout<<endl;

    cout<< numberOfLIS <<endl;

    //return numberOfLIS;
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 10, 8 , 9};
    findNumberOfLIS(arr);

    //cout << "The count of Longest Increasing Subsequences (LIS) is " << findNumberOfLIS(arr) << endl;

    return 0;
}



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##################-------MCM DP/Partition DP--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

- When there are multiple ways to solve it is partition dp 
- solve portion and return  


Steps:
1. Start with entire block
2. Try all partitions 
3. Return the best possible 2 partition

MCM DP/Partition DP CODE:

#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = 1e9;
    for(int k=i;k<j;k++){
        int v = f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1] *arr[k] *arr[j];
        //i, k should be different, that is why i-1
        mn = min(mn, v);
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int i = 1;
    int j = N-1;
    vector<vector<int>>dp(N, vector<int>(N,-1));
    return f(i, j, arr,dp);
}

//#######################################################################
//#######-------DP 48. Matrix Chain Multiplication | MCM | Partition DP Starts--------########
//Tutorial: https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/
//Tutorial2: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
//Problem:  https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344

- col1, row2 must be same to multiply two matrices 

Steps:
1. the matrix is from 0 to n-1 index, multiply with any 3 index and find the minimum, i must be lesser than k, so start with 1


//---------
//Top Down
//---------
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = 1e9;
    for(int k=i;k<j;k++){
        int v = f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1] *arr[k] *arr[j];
        //i, k should be different, that is why i-1
        mn = min(mn, v);
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int i = 1;
    int j = N-1;
    vector<vector<int>>dp(N, vector<int>(N,-1));
    return f(i, j, arr,dp);
}

//#######################################################################
//#######-------DP 49. Matrix Chain Multiplication | Bottom-Up | Tabulation--------########
//Tutorial: https://takeuforward.org/data-structure/matrix-chain-multiplication-tabulation-method-dp-49/
//Problem:  https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344

Steps:
1. 

//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N)
{
    int ii = 1;
    int jj = N-1;
    vector<vector<int>>dp(N, vector<int>(N,0));
    for(int i=N-1;i>=1;i--){
        //j is always right side of i
        for(int j=i+1;j<N;j++){
            int mn = 1e9;
            for(int k=i;k<j;k++){
                int v = dp[i][k] + dp[k+1][j] + arr[i-1] *arr[k] *arr[j];
                mn = min(mn, v);
            }
            dp[i][j] = mn;
        }
    }
    return dp[ii][jj];
}


//#######################################################################
//#######-------DP 50. Minimum Cost to Cut the Stick--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-cost-to-cut-the-stick-dp-50/
//Problem:  https://www.naukri.com/code360/problems/cost-to-cut-a-chocolate_3208460

Steps:
1. 


Confused??? DRAW tabulation to understand

//---------
//Top Down
//---------


//---------
//Bottom Up
//---------


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 51. Burst Balloons | Partition DP--------########
//Tutorial: https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/
//Problem:  https://www.naukri.com/code360/problems/mining-diamonds_4244494

Steps:
1. 

Confused??

//---------
//Top Down
//---------


//---------
//Bottom Up
//---------


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 52. Evaluate Boolean Expression to True | Partition DP--------########
//Tutorial: https://takeuforward.org/data-structure/evaluate-boolean-expression-to-true-partition-dp-dp-52/
//Problem:  https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650

Steps:
1. 

//---------
//Top Down
//---------
Confused??

//---------
//Bottom Up
//---------


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 53. Palindrome Partitioning - II | Front Partition--------########
//Tutorial: https://takeuforward.org/data-structure/palindrome-partitioning-ii-front-partition-dp-53/
//Problem:  https://www.naukri.com/code360/problems/palindrome-partitioning_873266

Steps:
1. 

//---------
//Top Down
//---------

int pal(int i, int j, string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}
int f(int i, string &str, vector<int>&dp){
    if(i==str.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int mn = 1e19;
    for(int j=i;j<str.size();j++){
        if( pal(i, j, str) ){
            int v = 1 + f(j+1, str, dp);//+1 and solve for other length
            mn = min(mn, v);
        }
    }
    return dp[i] = mn;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int>dp(n, -1);
    return f(0, str, dp)-1;
}


//---------
//Bottom Up
//---------
int pal(int i, int j, string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int>dp(n+1, -1);
    for(int i=n-1;i>=0;i--){
        int mn = 1e19;
        for(int j=i;j<str.size();j++){
            if( pal(i, j, str) ){
                int v = 1 + dp[j+1];
                mn = min(mn, v);
            }
        }
        dp[i] = mn;
    }
    return dp[0];
}


draw tabulation for this


//#######################################################################
//#######-------DP 54. Partition Array for Maximum Sum | Front Partition--------########
//Tutorial: https://takeuforward.org/data-structure/partition-array-for-maximum-sum-front-partition-dp-54/
//Problem:  https://www.naukri.com/code360/problems/maximum-subarray_3755255

Steps:
1. 

//---------
//Top Down
//---------

#include<bits/stdc++.h>
int f(int i, int k,vector<int> &arr, vector<int> &dp ){
    int n = arr.size();
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mx = INT_MIN, l = 0,mxsum = INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        l++;
        mx = max(mx, arr[j]);
        int v = mx * l + f(j+1, k, arr,dp);//solve rest
        mxsum = max(v, mxsum);
    }
    return dp[i] = mxsum;
}
int maximumSubarray(vector<int> &arr, int k){
    vector<int>dp(arr.size(),-1);
    return f(0, k, arr, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int maximumSubarray(vector<int> &arr, int k){
    int n = arr.size();
    vector<int>dp(n+1,0);

    for(int i=n-1;i>=0;i--){
        int mx = INT_MIN, l = 0,mxsum = INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            l++;
            mx = max(mx, arr[j]);
            int v = mx * l + dp[j+1];
            mxsum = max(v, mxsum);
        }
        dp[i] = mxsum;
    }
    return dp[0];
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP On Squares--------######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 55. Maximum Rectangle Area with all 1's | DP on Rectangles--------########
//Histogram problem: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
//Tutorial: https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55/
//Problem:  https://www.naukri.com/code360/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017

Steps:
1. Get the Histogram problem function 
2. for every row run the Histogram problem function  and get the maximum rectangle


//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int largestRectangleArea(vector < int > & histo) {
	stack < int > st;
	int maxA = 0;
	int n = histo.size();
	for (int i = 0; i <= n; i++) {
	while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
		int height = histo[st.top()];
		st.pop();
		int width;
		if (st.empty()) width = i;
		else width = i - st.top() - 1;
		maxA = max(maxA, width * height);
	}
	st.push(i);
	}
	return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int ans = 0;
	vector<int>tmp(m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0)tmp[j] = 0;
			else tmp[j]++;
		}
		ans = max(ans, largestRectangleArea(tmp));
	}
	return ans;
}

//#######################################################################
//#######-------DP 56. Count Square Submatrices with All Ones | DP on Rectangles--------########
//Tutorial: https://takeuforward.org/data-structure/count-square-submatrices-with-all-1s-dp-on-rectangles-dp-56/
//Problem:  https://www.naukri.com/code360/problems/count-square-submatrices-with-all-ones_3751502

Steps:
1. get the minimum from above, above left and left + 1 in the dp-th box if it is 1, else leave it as 0

//---------
//Bottom Up
//---------

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>>dp(n, vector<int>(m,0));
    //fill the 0th row and 0th column
    for(int i=0;i<m;i++) dp[0][i] = arr[0][i] == 1;
    for(int i=0;i<n;i++) dp[i][0] = arr[i][0] == 1;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int mn = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
            if(arr[i][j]) dp[i][j] = mn;
            else dp[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) ans+=dp[i][j];
    }

    return ans;
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------FINISHED--------###########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################