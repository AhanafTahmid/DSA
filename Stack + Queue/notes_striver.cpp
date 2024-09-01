//Stack + Queue

- 

Confusions:
1. 

Questions: 


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
1. 
------------


//#######################################################################
//#######-------1.2 Implement Queue using Arrays--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-array/
//Problem: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

------------
Approach:
1. 
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
//Tutorial: 
//Problem: https://leetcode.com/problems/sum-of-subarray-minimums/description/
https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

get previous greater element
get next greater element

(number of previous greater element * number of next greater element) * that number
------------
Approach:
1. 
------------
Time Complexity: O(2N) + O(2N) + O(N)
Space Complexity: O(2N) + O(2N) + O(N)


//#######################################################################
//#######-------12. Sum of subarray ranges--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/sum-of-subarray-ranges/description/
https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------13. Aestroid Collisions--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/asteroid-collision/description/
https://www.geeksforgeeks.org/problems/asteroid-collision/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------14. Remove K Digits--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/remove-k-digits/description/
https://www.geeksforgeeks.org/problems/remove-k-digits/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------15. Largest Rectangle in Histogram--------########
//Tutorial: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
//Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------16. Maximal Rectangle--------########
//Tutorial: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
//Problem:https://leetcode.com/problems/maximal-rectangle/description/
https://www.geeksforgeeks.org/problems/max-rectangle/1

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
https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------18. Stock Span Problem--------########
//Tutorial: https://www.geeksforgeeks.org/the-stock-span-problem/
//Problem: https://leetcode.com/problems/online-stock-span/description/
https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

------------
Approach:
1. 
------------

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