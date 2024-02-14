//Sliding windows comes under dynamic programming, cause we are solving sub-problems
//https://youtu.be/SaI2PHJNNVU

//it's a pattern when you need to find something in the contiguous sub-array.



//When given 'contiguos' then we should only be using sliding window
//Elements should be continuous

//Possible Questions: maximum sum, minimun sum, finding longest something, shortest something, sum of perfect square

//Steps: we are calculating values in a window



/*
//

Find Maximum sum of an array in range k, where n=6 and k=3, and a[i] to a[n] is given

6 3
1 2 3 4 5 6
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];

    int sum = 0;
    for(int i=0;i<k;i++)sum+=ar[i];

    for(int i=k;i<n;i++){
        sum = max(sum + ar[i] - ar[i-k],sum);
    }
    cout<< sum <<endl;
    
}


int main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<k)return {0};
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //max will always be in front
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k)dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;

    }
};