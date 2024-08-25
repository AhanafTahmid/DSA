#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<string,int> , int> mp,mp2;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int sz = s.size();
            mp[{s,i}] = 1;
            for(int j=0;j<sz-1;j++){
                for(int k=j+1;k<sz;k++){
                    string t = s;
                    string pt = "";
                    swap(t[k],t[j]);
                    int tt = 0;
                    while( tt < sz && t[tt]=='0') tt++;
                    while(tt<sz)pt.push_back(t[tt]),tt++;
                    
                    mp[ {pt, i} ] = 1;
                    //cout<< pt << ' ' << i <<endl;
                }
            }
        }

        for(auto [x,y]:mp){
           mp2[x]++;
           cout<< x.first << ' ' << x.second << ' ' << y << endl;
        }

        int ans = 0;
        for(auto [x,y]:mp2){
            ans+= (y * (y-1))/2;
        }
        return ans;
    }
};

int32_t main() {
   Solution obj;
   vector < int > nums = {3, 12, 30, 17, 21};
   int ans = obj.countPairs(nums);
   cout<< ans <<endl;
   return 0;
}