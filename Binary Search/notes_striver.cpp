always applicable in sorted area

Iterative:
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

recursive binary search:
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

time complexity of binary search: O(log2n)
for overflow use: m = l + (r-l)/2;
