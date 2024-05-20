- Every types first video is the most important
- Learn to write bottom up table
- Learn to draw solving recursively

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


Space optimization:
converting:
1d DP -> two variables
2d DP -> 1d DP 
3d DP -> 2d DP 


FOR ALL THE COUNT PROBLEMS:
if the condition is satisfied return 1, else return 0


1. In grid take x,y as dp[x][y]
2. in subsequences, take dp[ind][target]

Confusions:
1. 
Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences
for(int i=0;i<=k;i++){//Getting WA for k/2 on top down approach.
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
2. DP 17. Counts Subsets with Sum K | Dp on Subsequences, handling 0 case in bottom up


---------------------------------------------------------------------------------------------------------
Stiver DP Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
Tutorials: https://takeuforward.org/dynamic-programming/striver-dp-series-dynamic-programming-problems/
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
//Bottom Up(Space optimized) - 1d array
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
//Bottom Up(Space optimized) - 1d array
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
//#####################-------DP on Strings--------#########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------Dp 25. Longest Common Subsequence --------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
//Problem:  https://www.naukri.com/code360/problems/longest-common-subsequence_624879

//Top Down

//Bottom Up

//Bottom Up(Space optimized)
