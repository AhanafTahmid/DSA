//Stack + Queue

- 

Confusions:
1. why below next and previous greater and smaller template is same ???


---------------------------------------------------------------------------------------------------------
Striver Stack + Queue Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c
Resource: https://takeuforward.org/blogs/stack
Resource: https://takeuforward.org/blogs/queue
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//####################-------Learning--------############################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------1. Introduction to Stack and Queue | Implementation using Data Structures--------########

------------------------Theory----------------------------------

Stack follows LIFO
Functions: push(), pop(), top(), size()

Queue follows LIFO
Functions: push(), pop(), top(), size()

Implementing stack using array is not dynamic, space complexity would be the defined array size

Implementing stack using array [variables: top, size]
Implementing queue using array [variables: start, end, current_size]
            
//#######################################################################
//#######-------1.1 Implement Stack using Arrays--------########
//Tutorial: https://takeuforward.org/data-structure/implement-stack-using-array/
//Problem: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

------------
Approach:
1. move the top++ when pushing and top-- when popping
2. printing value = arr[top];
------------
Time Complexity: O(1) for every operation
Space Complexity: O(N) - for defining a particular array size 

#include <bits/stdc++.h>

using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
};
int main()
{

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}

//#######################################################################
//#######-------1.2 Implement Queue using Arrays--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-array/
//Problem: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

------------
Approach:
1. move the end++ when pushing and start++ when popping
2. 
------------


//#######################################################################
//#######-------1.3 Implement Stack using Queue--------########
//Tutorial: https://takeuforward.org/data-structure/implement-stack-using-single-queue/
//Problem: https://leetcode.com/problems/implement-stack-using-queues/description/
https://www.geeksforgeeks.org/problems/stack-using-two-queues/1

//#######################################################################
//#######-------1.4 Implement Queue using Stack--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-stack/
//Problem: https://leetcode.com/problems/implement-queue-using-stacks/description/
https://www.geeksforgeeks.org/problems/queue-using-stack/1

//#######################################################################
//#######-------1.5 Implement stack using Linkedlist--------########
//Tutorial: https://takeuforward.org/data-structure/implement-stack-using-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

//#######################################################################
//#######-------1.6 Implement queue using Linkedlist--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

//#######################################################################
//#######-------2. Check for Balanced Parentheses | Stack and Queue--------########
//Tutorial: https://takeuforward.org/data-structure/check-for-balanced-parentheses/
//Problem: https://leetcode.com/problems/valid-parentheses/description/

should have same corresponding in the same order
------------
Approach:
1. Last opening bracket er opposite bracket na ashle no, else yes 
------------
Time Complexity: O(n)
Space Complexity: O(n) - when all are opening brackets

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch: s){
            if( ch=='(' || ch=='[' || ch=='{' ) st.push(ch);
            else {
                if(st.empty()) return false;
                if(st.top()=='(' && ch!=')' ) return false;
                if(st.top()=='[' && ch!=']' ) return false;
                if(st.top()=='{' && ch!='}' ) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

//#######################################################################
//#######-------3. Implement Min Stack--------########
//Tutorial: https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/
//Problem: https://leetcode.com/problems/min-stack/description/
https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

formula: 2 x val - prev_min = new_minimum - this is modified minimum

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####-------Prefix, Infix, PostFix Conversion Problems--------#########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------4. Prefix, Infix, and Postfix Conversion--------########

Infix - bracket er vitor operator gula, (+)
prefix - operators before the operand, + pq - used in lisp
prefix - operators after the operand, pq + 

//#######################################################################
//#######-------4.1 Infix to Postfix Conversion using Stack--------########
//Tutorial: https://takeuforward.org/data-structure/infix-to-postfix/
//Problem: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

- operand answer e add kora 
- operator stack e add kora 

Steps:
https://www.youtube.com/watch?v=92TmPsNRjwk
1. Two operators of the same priority cannot stay together
2. lowest priority ashle highest priority operator shob jabe ga, ulta hole push hobe stack e
3. parenthese close hoile all operand e add kora

//#######################################################################
//#######-------4.2 Prefix to Infix Conversion--------########
//Tutorial: https://www.geeksforgeeks.org/prefix-postfix-conversion/
//Problem: https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

//#######################################################################
//#######-------4.3 Prefix to Postfix Conversion--------########
//Tutorial: https://www.geeksforgeeks.org/prefix-postfix-conversion/
//Problem: https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

//#######################################################################
//#######-------4.4 Postfix to Prefix Conversion--------########
//Tutorial: https://www.geeksforgeeks.org/postfix-prefix-conversion/
//Problem: https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

//#######################################################################
//#######-------4.5 Postfix to Infix--------########
//Tutorial: https://www.geeksforgeeks.org/postfix-to-infix/
//Problem: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

//#######################################################################
//#######-------4.6 Convert Infix To Prefix Notation--------########
//Tutorial: https://takeuforward.org/data-structure/infix-to-prefix/
//Problem: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####-------Monotonic Stack/Queue Problems [VVV. Imp]--------##########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

monotonic stack: Putting element in specific order
                 Boro theke choto or choto theke boro akare stack sajano according to question


//Template for next and previous greater
int n = arr.size();
stack<int>st;
//next greater
vector<int>left(n);
for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
    left[i] = st.empty() ? n: st.top();
    st.push(i);
}
while(!st.empty())st.pop();

//previous greater
vector<int>right(n);
for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()]>arr[i])st.pop();
    right[i] = st.empty() ? -1: st.top();
    st.push(i);
}


------------------------------------------------------------------------
//Template for next and previous smaller
int n = arr.size();
stack<int>st;
//next smaller
vector<int>left(n);
for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
    left[i] = st.empty() ? n: st.top();
    st.push(i);
}
while(!st.empty())st.pop();

//previous smaller
vector<int>right(n);
for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
    right[i] = st.empty() ? -1: st.top();
    st.push(i);
}

//#######################################################################
//#######-------5. Next Greater Element--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

- Here we are putting value in increasing order
- boro kono value ashle order distort hoe jabe, and stack empty kre dibo

------------
Approach:
1. Move from the back and keep adding values in the stack 
2. condition to add element in the stack: st.top() > arr[i], else keep popping
------------


----------------------------------------------------------------------
Time Complexity: O(2N)
Space Complexity: O(2N)
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        vector<long long>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i] ) st.pop();
            ans[i] = st.empty() ? -1: st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};


----------------------------------------------------------------------
Another way 
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        st.push(arr[n-1]);
        vector<long long>ans(n, -1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()){
                if( st.top() > arr[i] ){
                    ans[i] = st.top();
                    break;
                }
                st.pop();
            } 
            st.push(arr[i]);
        }
        return ans;
    }
};

----------------------------------------------------------------------
//Problem: https://leetcode.com/problems/next-greater-element-i/description/

Same concept, a little different problem
Q: next greater element subset akare thakbe

------------
Approach:
1. Same approach as Next Greater Element
2. Just maintain a hashing to keep the track of the changed element
------------

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        st.push(arr[n-1]);
        map<int, int> mp;
        vector<int>ans(nums1.size());
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            if(st.empty()) mp[arr[i]] = -1;
            else mp[arr[i]] = st.top();
            st.push(arr[i]);
        }

        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]) ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

//#######################################################################
//#######-------6. Next Greater Element - II--------########
//Tutorial: https://takeuforward.org/data-structure/next-greater-element-using-stack/
//Problem: https://leetcode.com/problems/next-greater-element-ii/description/

prerequisite: 5. Next Greater Element

------------
Approach:
- Hypothetically add another array with the existing array

1. solve 5. Next Greater Element [2 times]
------------
Time Complexity: O(4N)
Space Complexity: O(3N) [stack size = 2N, ans = N]


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        st.push(arr[n-1]);
        vector<int>ans(n, -1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()){
                if( st.top() > arr[i] ){
                    break;
                }
                st.pop();
            } 
            st.push(arr[i]);
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if( st.top() > arr[i] ){
                    ans[i] = st.top();
                    break;
                }
                st.pop();
            } 
            st.push(arr[i]);
        }

        return ans;

    }
};

//#######################################################################
//#######-------7. Previous Smaller Element--------########
//Tutorial: 
//Problem: https://www.interviewbit.com/problems/nearest-smaller-element/

prerequisite: 5. Next Greater Element

------------
Approach:
1. Top e small rakhbo, increasing order e stack building
2. if st.top()>=arr[i] keep destroying stack until this condition holds

------------
Time Complexity: O(2N)
Space Complexity: O(2N)

vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i])st.pop();
        ans[i] = st.empty() ? -1: st.top();
        st.push(arr[i]);
    }
    return ans;
}

//#######################################################################
//#######-------8. Next Smaller Element--------########
//Tutorial: 
//Problem: https://www.naukri.com/code360/problems/next-smaller-element_1112581

prerequisite: 5. Next Greater Element

------------
Approach:
1. just maintain this, st.top()>=arr[i]
------------
Time Complexity: O(2N)
Space Complexity: O(2N)

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i])st.pop();
        ans[i] = st.empty() ? -1: st.top();
        st.push(arr[i]);
    }
    return ans;
}

//#######################################################################
//#######-------9. Number of NGEs to the right--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------10. Trapping Rainwater | 2 Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/trapping-rainwater/
//Problem: https://leetcode.com/problems/trapping-rain-water/description/
https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------11. Sum of Subarray Minimum--------########
//Tutorial: https://www.geeksforgeeks.org/sum-of-minimum-elements-of-all-subarrays/
//Problem: https://leetcode.com/problems/sum-of-subarray-minimums/description/

Gfg approach is simpler than striver
------------
Formula: (number of previous greater element * number of next greater element) * that number
Approach:
1. get previous greater element
2. get next greater element
3. Apply the formula and solve
------------
Time Complexity: O(2N) + O(2N) + O(N)
Space Complexity: O(2N) + O(2N)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mod = 1e9 + 7;

        //next greater
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous greater
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            int lft = left[i] - i;
            int rght = i - right[i];
            sum= (sum + (lft * rght * 1LL * arr[i])%mod)%mod ;
        }
        return sum;
    }
};

//#######################################################################
//#######-------12. Sum of subarray ranges--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/sum-of-subarray-ranges/description/

Prerequisite: 11. Sum of Subarray Minimum

------------
Approach:
Formula: Sum of subarray maximum - Sum of subarray minimum
1. Just apply the formula
------------
Time Complexity: O(5N) + O(5N) = O(10N) [better than N*N]
Space Complexity: O(4N) + O(4N) = O(8N)

class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mod = 1e9 + 7;

        //next greater
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous greater
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            int lft = left[i] - i;
            int rght = i - right[i];
            sum= sum + (lft * rght * 1LL * arr[i]) ;
        }
        return sum;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mod = 1e9 + 7;

        //next greater
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous greater
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            int lft = left[i] - i;
            int rght = i - right[i];
            sum= sum + (lft * rght * 1LL * arr[i]) ;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};

//#######################################################################
//#######-------13. Aestroid Collisions--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/asteroid-collision/description/

------------
Approach:
positive er jnno jhamela nai, negative er jnno jhamela 

1. if positive put in stack 
2. if negative maintain the colliding condition 
       2.1 st.top()>0 to popping up elements 
       2.2 if stack is not empty and st.top == last element st.pop 
       2.3 else if stack is empty and st.top()<0 put in stack
------------
Time Complexity: O(2N) + O(N) + O(N) [for reverse]
Space Complexity: O(N) + O(N) [stack and ans array]

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            // all negatives
            if(asteroids[i]<0){
                while(!st.empty() && st.top()>0 && st.top()< abs(asteroids[i]) ){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i]))st.pop();
                else if ( st.empty() || st.top()<0 ) st.push(asteroids[i]);
            }
            else {
                //all positives
                st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//#######################################################################
//#######-------14. Remove K Digits--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/remove-k-digits/description/

------------
Approach:
1. Maintain increasing order in stack

3 edge cases 
1. k>=N, return "0"
2. number becomes 00001000, return "1000"
3. after performing stack - k remains, so remove the top elements , n = 123456, k = 3 return "123"
------------
Time Complexity: O(4N) + O(K)
Space Complexity: O(N) + O(N) [stack and ans array]

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size(), ind = n;
        string ans = "";
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>s[i] && k>0){
                k--;
                st.pop();
            }
            st.push(s[i]);
        }
        
        //edge case 3
        while(!st.empty() && k-->0){
            st.pop();
        }
        
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        //edge case 2
        while(ans.size()>0 && ans[ans.size()-1]=='0') ans.pop_back();
        
        reverse(ans.begin(), ans.end());
        
        if(ans.empty()) return "0";
        return ans;
    }
};

//#######################################################################
//#######-------15. Largest Rectangle in Histogram--------########
//Tutorial: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
//Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

get the 'index' of both pse and nse
------------
Formula: area = arr[i] * (nse - pse - 1)

Approach:
1. Get the nse and pse
2. apply the formula and solve it 

note:
previous smaller index na thakle set -1
next smaller na thakle set n
------------
Time Complexity: O(5N) 
Space Complexity: O(4N)

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        //next smaller
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous smaller
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, (left[i]-right[i]-1) * arr[i] );
        }
        return mx;
    }
};

//Another Approach
Time Complexity: O(2N) 
Space Complexity: O(4N)

------------
Formula: area = arr[i] * (nse - pse - 1)

Approach:
1. Keep maintain increasing 'index' order in stack 
2. if arr[st.top()]>arr[i], then nse = i, pse = st.top()

3. Get the nse and pse
4. apply the formula and solve it 

note:
previous smaller index na thakle set -1
next smaller na thakle set n
------------
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mx = 0, pse, nse;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ind = st.top();
                st.pop();
                pse = (st.empty()?-1:st.top());
                nse = i;
                mx = max(mx, (nse - pse - 1) * arr[ind]);
            }
            st.push(i);
        }
        //if still elements left, for increasing order array te erokom hobe -> 2 4 6 
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            nse = n;
            pse = (st.empty()?-1:st.top());
            mx = max(mx, (nse - pse - 1) * arr[ind]);
        }
        return mx;
    }
};

//#######################################################################
//#######-------16. Maximal Rectangle--------########
//Tutorial: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
//Problem:https://leetcode.com/problems/maximal-rectangle/description/

Prerequisite: 15. Largest Rectangle in Histogram

------------
Approach:
1. apply prefix sum in the matrix 
2. Use 15. Largest Rectangle in Histogram concept to solve every prefix[row] 
------------
Time Complexity: O(MxN) + O(Nx2M) 
Space Complexity: O(MxN) + O(M)

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mx = 0, pse, nse;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ind = st.top();
                st.pop();
                pse = (st.empty()?-1:st.top());
                nse = i;
                mx = max(mx, (nse - pse - 1) * arr[ind]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            nse = n;
            pse = (st.empty()?-1:st.top());
            mx = max(mx, (nse - pse - 1) * arr[ind]);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n+1, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') prefix[i+1][j] = 0;
                else prefix[i+1][j] = prefix[i][j] + 1;

            }
        }

        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, largestRectangleArea(prefix[i+1]));
        }
        return mx;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#############-------Implementation Problems--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------17. Sliding Window Maximum--------########
//Tutorial: https://takeuforward.org/data-structure/sliding-window-maximum/
//Problem: https://leetcode.com/problems/sliding-window-maximum/description/

------------
Approach:
1. Create a deque to store first K elements. Add the greatest element index in deque(add in decreasing order)
2. Run loop for rest of the window
   a. Remove out of all window indices from deque
   b. pop_back the dq elements that is not maintaining increasing order with the current value nums[i]
   c. Add the current val indices in the dequeue(add in decreasing order)
   d. nums[dq.front()] will be maximum element
------------
Time Complexity: O(2N) 
Space Complexity: O(K) + O(N-K)

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

//#######################################################################
//#######-------18. Stock Span Problem--------########
//Tutorial: https://www.geeksforgeeks.org/the-stock-span-problem/
//Problem: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

------------
Approach:
1. maintain the stack < value, index > st;
2. and just apply the formula: ans[i] = that index - last greater element index 

note: 
last greater element index na thakle -1 diye subtraction
------------
Time Complexity: O(2N) 
Space Complexity: O(2N) 

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n);
        
        //{val, index}
        stack< pair<int, int> > st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<=price[i]){
                st.pop();
            }
            int span = i;
            if(st.empty()) span -= -1;
            else span-= st.top().second;
            
            st.push({price[i], i});
            
            ans[i] = span;
        }
        return ans;
    }
};

//#######################################################################
//#######-------19. The Celebrity Problem--------########
//Tutorial: https://www.geeksforgeeks.org/the-celebrity-problem/
//Problem: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------20. Implement LRU Cache--------########
//Tutorial: https://takeuforward.org/data-structure/implement-lru-cache/
//Problem: https://leetcode.com/problems/lru-cache/description/
https://www.geeksforgeeks.org/problems/lru-cache/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------21. Implement LFU cache | Leetcode(Hard)--------########
//Tutorial: https://www.geeksforgeeks.org/least-frequently-used-lfu-cache-implementation/
//Problem: https://leetcode.com/problems/lfu-cache/description/
https://www.geeksforgeeks.org/problems/lfu-cache-1665050355/0

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