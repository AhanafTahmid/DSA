//Greedy

- sorting is a common feature in most greedy problems

---------------------------------------------------------------------------------------------------------
Striver Greedy Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea
Resource: https://takeuforward.org/blogs/greedy
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Greedy Algorithms[Easy]--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------1. Assign Cookies--------########
//Tutorial: https://takeuforward.org/Greedy/assign-cookies
//Problem: https://leetcode.com/problems/assign-cookies/

------------
Approach:
greedily try to assign the smallest values
1. Take two pointer, move the pointer if candy[j] >= greed[i]
Time Complexity: O(N logN + M logM + M) where N is the length of the greedy array, M is the length of the cookies array. To sort the greedy and cookies array, the complexity is O(N logN) and O(M logM). 
Space Complexity: O(1) 
------------

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int ans = 0;
        for(int i=0,j=0;i<n && j<m;i++){
            if(g[i]<=s[j]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------2. Fractional Knapsack Problem--------########
//Tutorial: https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/
//Problem: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

------------
Approach:
1. Push per unit weight value and total weight
2. sort in decreasing order 
3. calculate the answer for given weight 
------------

class Solution {
  public:
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector< pair<double, int> > v;
        for(int i=0;i<n;i++){
            v.push_back({ arr[i].value/(arr[i].weight*1.00), arr[i].weight });//1.00 gun kora to convert into double
        }
        sort(v.rbegin(),v.rend());
        double ans = 0;
        for(int i=0;i<n;i++){
            ans+= v[i].first * min(v[i].second, w);
            w-=min(v[i].second, w);
        }
        return ans;
    }
};

//#######################################################################
//#######-------3. Greedy algorithm to find minimum number of coins--------########
//Tutorial: https://takeuforward.org/data-structure/find-minimum-number-of-coins/
//Problem: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

Greedy algorithm works here because if you add up two coins it will not exceed any coins 
eg: 1 5 6 9 , adding 5 + 6 will exceed 9, so greedy will not work here

------------
Approach:
1. Take the previous valid value * times(jotobar kora jai)
2. Keep doing it until N becomes 0

eg: 
49 -> take 20 2 times == 9
9 -> take 5 1 times   == 4
4 -> take 2 2 times   == 0
20 20 5 2 2 is our answer
------------
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>coins{1,2,5,10,20,50,100,200,500,2000};
        int cn = coins.size();
        vector<int>ans;
        while(1){
            int val = 0;
            for(int i=0;i<cn;i++){
                if(N>=coins[i]) val = coins[i];
                else break;
            }
            int times = N / val;
            N -= (times * val);
            
            for(int i=0;i<times;i++) ans.push_back(val);
            if(N==0) break;
        }
        return ans;
    }
};

//#######################################################################
//#######-------4. Lemonade Change--------########
//Tutorial: https://takeuforward.org/Greedy/lemonade-change
//Problem: https://leetcode.com/problems/lemonade-change/description/

------------
Approach:
1. Keep track of five and ten, and do optimally 
for case 5, increase 5
for case 10, check if I have 1 five, if have decrease that,  if not return false
for case 20, check if I have 1 ten and 1 five, or 3 five, if have, decrease those,  if not return false
------------

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                if(!five) return false;
                five--;
                ten++;
            }
            else if(bills[i]==20){
                if(ten>=1 && five) ten--, five--;
                else if(ten==0 && five>=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};

//#######################################################################
//#######-------5. Valid Paranthesis Checker--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/valid-parenthesis-string/description/
https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

in parentheses problem think +1 and -1

solve using dp, 3 possible ways

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
//##########-------Greedy Algorithms[Medium/Hard]--------##############
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------6. N meetings in one room--------########
//Tutorial: https://takeuforward.org/data-structure/n-meetings-in-one-room/
//Problem: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

------------
Approach:
1. sort according to endings 
2. compare prev < v[i].second
3. change prev =   v[i].first; (upperbound of the meeting time)

------------
class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        vector< pair<int, int> >v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int last = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(last < v[i].second){
                ans++;
                last = v[i].first;//select the upper bound if satisfied
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------7. Jump Game 1--------########
//Tutorial: https://takeuforward.org/Greedy/jump-game-i
//Problem: https://leetcode.com/problems/jump-game/description/

greedy choice of reaching the farthest

------------
Approach:
1. check every index's' i + nums[i].
2. If max_length < index , then answer is no 
Time Complexity: O(N)
Space Complexity: O(1)
------------
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i=0;i<n;i++){
            if(i>mx) return false;
            mx = max(mx, nums[i]+i);
        }
        return true;
    }
};

//#######################################################################
//#######-------8. Jump Game 2--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/jump-game-ii/description/

------------
Approach:
1. solve as you go, using dp
2. State: dp[j] = min(dp[i] + 1, dp[j]);
------------

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1e9);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<min(nums[i]+i+1, n);j++){
                dp[j] = min(dp[i] + 1, dp[j]);
            }
        }
        return dp[n-1];
    }
};

//Another
Think in range, koibar range update hocche
1. Go in the range and keep upading answer
2. L will go L R+1 step, R will go to the farthest

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, jump = 0;
        while(r<n-1){
            int far = 0;
            for(int i=l;i<=r;i++){
                far = max(far, nums[i]+i);
            }
            jump++;
            l = r + 1;
            r = far;
        }
        return jump;
    }
};


//#######################################################################
//#######-------9. Minimum number of platforms required for a railway--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
//Problem: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

------------
Approach:
1. sort both
2. use two pointer if arr[i]<=dep[j] ct++, else ct--
3. max ct would be the answer

------------
class Solution{
    public:        
    int findPlatform(int arr[], int dep[], int n)
    {   
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans = 0, ct = 0;
    	int l1 = 0, l2 = 0;
    	while(l1<n && l2<n){
    	    if(arr[l1] <= dep[l2] ) ct++, l1++;//duita same thakle arrive one age pathabo
    	    else ct--,l2++;
    	    ans = max(ans, ct);
    	}
    	return ans;
    }
};

//#######################################################################
//#######-------10. Job sequencing Problem--------########
//Tutorial: https://takeuforward.org/data-structure/job-sequencing-problem/
//Problem: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

kono ekta kaj time er age finish hoite pare, but pore kokhono finish hobe na
------------
Approach:
1. Max te niye fill the previous table 
2. Keep doing it until you cannot do it anymore

------------

class Solution 
{
    public:
    bool static comp(Job j1, Job j2){
        return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int total_job = 0, sum = 0;
        vector<int> table(1e5+10, -1);
        
        //this loop Time Complexity: O(N * max_dead_line)
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(table[j]==-1){
                    int val = arr[i].profit;
                    table[j] = val;
                    total_job++;
                    sum+=val;
                    break;
                }
            }
        }
        return {total_job, sum};
    } 
};

//#######################################################################
//#######-------11. Candy--------########
//Tutorial: https://www.geeksforgeeks.org/minimum-number-of-candies-required-to-distribute-among-children-based-on-given-conditions/
//Problem: https://leetcode.com/problems/candy/description/

build an algorithm on the way
------------
Approach:
1. make 2 array left and right 
2. keep updating or decreasing, take the ans+= max(right[i], left[i]);
3. print ans
------------

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left{1}, right{1};
        int ct = 1;
        for(int i=1;i<n;i++){
            if(ratings[i-1] >= ratings[i]) ct = 1;
            else ct++;
            left.push_back(ct);
        }
        ct = 1;
        for(int i=n-2;i>=0;i--){
            if( ratings[i] > ratings[i+1] ) ct++;
            else ct = 1;
            right.push_back(ct);
        }
        reverse(right.begin(),right.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+= max(right[i], left[i]);
        }
        return ans;
    }
};

//slop approach
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int peak = 0, down = 0,i=1, sum = 1;
        while(i<n){
            if(i<n && ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            peak = down = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak+=1;
                sum+= peak;
                i++;
            }
            while(i<n && ratings[i]<ratings[i-1]){
                sum+= down;
                down+=1;
                i++;
            }
            if(down>peak) sum+= (down-peak);
        }
        return sum;
    }
};

//#######################################################################
//#######-------12. Program for Shortest Job First (or SJF) CPU Scheduling--------########
//Tutorial: https://takeuforward.org/Greedy/shortest-job-first-or-sjf-cpu-scheduling
//Problem: https://www.geeksforgeeks.org/problems/shortest-job-first/1

------------
Approach:
1. sort and keep adding summation + bt[i]
2. in the end sum/n is the average time

Time Complexity: O(N logN + N)
------------
class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int n = bt.size();
        int s = 0, ss = 0;
        for(int i=0;i<n-1;i++){
            s = s + bt[i];
            ss+=s;
        }
        return ss/n;
    }
};

//#######################################################################
//#######-------13. Program for Least Recently Used (LRU) Page Replacement Algorithm--------########
//Tutorial: https://www.geeksforgeeks.org/program-for-least-recently-used-lru-page-replacement-algorithm/
//Problem: https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

------------
Approach:
1. value khujhte thakbo, thakle remove that value from that index and add in back 
2. na thakle ans++, and begin element remove korbo, and last e pages[i] push korbo

2 2 alreay thakle ans++ hobe na
------------

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int ans = 0;
        vector<int>lru;
        for(int i=0;i<N;i++){
            auto it = find(lru.begin(),lru.end(), pages[i]);
            if(it==lru.end()){
                ans++;
                if (lru.size() == C) lru.erase(lru.begin());//value nai, and c er size tahole remove 
            }
            else lru.erase( it );//value thakle value remove and last e push kora
            lru.push_back(pages[i]);
        }
        return ans;
    }
};

//Another way
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int ans = 0;
        vector<int>lru;
        for(int i=0;i<N;i++){
            bool ok = 0;
            for(int j=0;j<lru.size();j++){
                if(lru[j]==pages[i]){
                    ok = 1;
                    lru.erase( lru.begin() + j );
                    break;
                }
            }
            if(!ok){
                ans++;
                if(lru.size()==C) lru.erase( lru.begin() );
            }
            lru.push_back(pages[i]);
        }
        return ans;
    }
};


//#######################################################################
//#######-------14. Insert Interval--------########
//Tutorial: https://takeuforward.org/data-structure/insert-new-interval/
//Problem: https://leetcode.com/problems/insert-interval/description/
https://www.geeksforgeeks.org/problems/insert-interval-1666733333/0

------------
Approach:
1. 
------------

//#######################################################################
//#######-------15. Merge Intervals--------########
//Tutorial: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
//Problem: https://leetcode.com/problems/merge-intervals/description/
https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------16. Non-overlapping Intervals--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/non-overlapping-intervals/description/

Prerequisite: 6. N meetings in one room
------------
Approach:
1. apply the lesson of 6. N meetings in one room
------------

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size(), last = -1e9;
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            if( last <= v[i].second ){
                last = v[i].first;
            }
            else ans++;
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