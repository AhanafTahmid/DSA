

---------------------------------------------------------------------------------------------------------
Stiver DP Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
---------------------------------------------------------------------------------------------------------
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


