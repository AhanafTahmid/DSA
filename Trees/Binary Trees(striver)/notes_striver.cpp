//Tree

- See notion notes / striver notes for details
- 

Confusions:
1. L10 why Memory Limit Exceeded for this , if(node->right) node = node->right;
2. L16. Diameter of Binary Tree - confused bruteforce approach 
3.
why this is not working, not sure
L23. Bottom View of Binary Tree
void b(Node *root, int line, int height, map<int, int>&mp){
        if(root==NULL) return;
        b(root->left, line-1, height+1, mp);
        b(root->right, line+1, height+1, mp);
        if(height>=mp[line]) mp[line] = root->data;
    }
4. 

Questions: 



todo:

---------------------------------------------------------------------------------------------------------
Striver Tree Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
Resource: 
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//###########-------Binary Trees - Traversals--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-1. Introduction to Graph | Types | Different Conventions Used--------########
//Tutorial: https://takeuforward.org/binary-tree/introduction-to-trees/
//Problem: https://www.geeksforgeeks.org/problems/introduction-to-trees/1


------------------------Theory----------------------------------
Root Node: Root Node is the topmost node of a binary tree
Children Node: Children Nodes are the nodes directly connected to a parent node.
Leaf Node: Leaf Nodes are the nodes that do not have any children.
Ancestors: Ancestors in a Binary Tree are those nodes that lie on the 'same path' from a particular node to the root node


Full Binary Tree: 
A Full Binary Tree, also known as a Strict Binary Tree, 
adheres to the structural property where every node has either 0 or 2 children.

Complete Binary Tree:
A Complete Binary Tree is a specialised form of Binary Tree where all levels 
are filled completely except possibly the last level(left), which is filled from left to right.
Altough it is similar to a full binary tree, a complete binary tree doesnot require all nodes to have two children; 
- Complete binary te last level e left e shob filled thakte hobe must, or kichui thakbe na leaf e 

Perfect Binary Tree:
- All leaf node are at same level

Balanced Binary Tree:
- height can be at maximum of log2(n)

Degenerate Tree:
It is a tree where the nodes are arranged in a single path leaning to the right or left. 
The tree resembles a linked list in its structure where each node points to the next node in a linear fashion.

//Problem
The maximum number of nodes at level L of a binary tree is 2L
class Solution {
  public:
    int countNodes(int i) {
        return 1<<(i-1);
    }
};

//#######################################################################
//#######-------L2. Binary Tree Representation in C++--------########
//Tutorial: https://takeuforward.org/binary-tree/binary-tree-representation-in-c/

//Using struct create custom data type
#include <iostream>
struct Node {
    int data;        
    Node* left;      
    Node* right;      
    Node(int val) {
        data = val;   
        left = right = NULL;  
    }
};

int main() {
    // Creating a new node for the root of the 
    // binary tree using dynamic allocation
    Node* root = new Node(1);
    // Creating left and right child nodes for the root node
    root->left = new Node(2);
    root->right = new Node(3);
    // Creating a right child node for the left child node of the root
    root->left->right = new Node(5);
}

//Problem: https://www.geeksforgeeks.org/problems/binary-tree-representation/1
class Solution{
public:
    void create_tree(node* root, vector<int> &vec){
        root->left = newNode(vec[1]);
        root->right = newNode(vec[2]);
        root->left->left = newNode(vec[3]);
        root->left->right = newNode(vec[4]);
        root->right->left = newNode(vec[5]);
        root->right->right = newNode(vec[6]);
    }
};


//#######################################################################
//#######-------L3. Binary Tree Representation in Java--------########
//Tutorial: https://takeuforward.org/binary-tree/binary-tree-representation-in-java/


//#######################################################################
//#######-------L4. Binary Tree Traversals in Binary Tree | BFS | DFS--------########
//Tutorial: https://takeuforward.org/binary-tree/binary-tree-traversal-inorder-preorder-postorder/
//Problem: https://www.naukri.com/code360/problems/tree-traversal_981269
//Problem2: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

2 types of traversal: 1. DFS(preorder, inorder,postorder) 2. BFS(level order traversal)

Preorder Traversal : Root -> Left  -> Right (RLR)
Inorder Traversal  : Left -> Root  -> Right (LRR)
Postorder Traversal: Left -> Right -> Root  (LRR)

- Go to extreme root or left, or right
- Go to subtree and apply the formula

//#######################################################################
//#######-------L5. Preorder Traversal of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

------------
DFS
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) where N is the number of nodes in the binary tree. 
------------

class Solution {
public:
    void p(TreeNode *root, vector<int>&ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        p(root->left, ans);
        p(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        p(root, ans);
        return ans;
    }
};

//#######################################################################
//#######-------L6. Inorder Traversal of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

------------
DFS
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) where N is the number of nodes in the binary tree. 
------------

class Solution {
public:
    void i(TreeNode *root, vector<int>&ans){
        if(root==NULL) return;
        i(root->left, ans);
        ans.push_back(root->val);
        i(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        i(root, ans);
        return ans;
    }
};

//#######################################################################
//#######-------L7. Postorder Traversal of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

------------
DFS
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) where N is the number of nodes in the binary tree. 
------------

class Solution {
public:
    void ps(TreeNode *root, vector<int>&ans){
        if(root == NULL) return;
        ps(root->left, ans);
        ps(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        ps(root, ans);
        return ans;
    }
};

//#######################################################################
//#######-------L8. Level Order Traversal of Binary Tree | BFS--------########
//Tutorial: https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

------------
BFS
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) where N is the number of nodes in the binary tree. 
------------

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                TreeNode *node = q.front(); 
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

//#######################################################################
//#######-------L9. Iterative Preorder Traversal in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/iterative-preorder-traversal-of-binary-tree
//Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

------------
Using Stack
Approach: Put right node and then left node in the stack, print the top of stack everytime
------------

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
    }
};

//#######################################################################
//#######-------L10. Iterative Inorder Traversal in Binary Tree | Stack--------########
//Tutorial: https://takeuforward.org/data-structure/iterative-inorder-traversal-of-binary-tree
//Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

------------
Using Stack
Approach: 
1. Go to the extreme left node, keep pushing the node in the stack 
2. after that print the value of the extreme left node, then move right 
3. Run the loop until the stack is empty 
------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack< TreeNode* > st;
        TreeNode* node = root;
        while(1){
            while(node!=NULL){
                st.push(node);
                node = node->left;
            }
            if(st.empty())break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
    }
};

//#######################################################################
//#######-------L11. Iterative Postorder Traversal using 2 Stack--------########
//Tutorial: https://takeuforward.org/data-structure/iterative-postorder-traversal-of-binary-tree-using-2-stack
//Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

------------
Using 2 Stack
Approach: 
1. create 2 stacks, one for holding nodes and another for storing the final postorder traversal
2. Push the root node to the first stack
3. push the left or right node(if not null) in the stack1, and push node->data in the stack2 
4. process until empty
5. stack 2 is the answer
------------
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;//rememeber this edge case
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
            st2.push(node);
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        
        return ans;
    }
};

//#######################################################################
//#######-------L12. Iterative Postorder Traversal using 1 Stack--------########
//Tutorial: https://takeuforward.org/data-structure/iterative-postorder-traversal-of-binary-tree-using-1-stack
//Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

------------
Using 1 Stack
Approach: 
1. Go to extreme left, the move right, again go to extreme left, last value jekhane pointer null thakbe sheta add kora
Time Complexity: O(2N) 
Space Complexity: O(N) 
------------

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        while( !st.empty() || root ){
            while(root){
                st.push(root);
                root = root->left;
            }
            TreeNode* tmp = st.top()->right;
            if(tmp == NULL){
                tmp = st.top();
                st.pop();
                ans.push_back(tmp->val);
                while( !st.empty() && tmp == st.top()->right ){//if this is true means left e kono value nai
                    tmp = st.top();
                    st.pop();
                    ans.push_back(tmp->val);
                }
            }
            else root = tmp;
        }
        
        return ans;
    }
};


//#######################################################################
//#######-------L13. Preorder Inorder Postorder Traversals in One Traversal | Stack--------########
//Tutorial: https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/
//Problem: https://www.naukri.com/code360/problems/tree-traversals_981269

------------
Using 1 Stack
Approach: 
add in the list if 1 == preorder, 2==inorder, 3 == postorder
Time Complexity: O(3N)
Space Complexity: O(3N) 
------------
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans(3);
    stack< pair<TreeNode *, int>> st;//node, steps
    st.push({root, 1});
    while(!st.empty() ){
        TreeNode *node = st.top().first;
        int steps = st.top().second;
        st.pop();
        if(steps==1){
            //root -> left -> right
            ans[1].push_back(node->data);
            st.push({node, ++steps});//steps 2 kore dewa
            if(node->left!=NULL) st.push({node->left, 1});//left e new node paile steps 1 e hobe
        }
        else if(steps==2){
            //left -> root -> right
            ans[0].push_back(node->data);
            st.push({node, ++steps});
            if(node->right!=NULL) st.push({node->right, 1});
        }
        else if(steps==3){
            //left -> right -> root
            ans[2].push_back(node->data);
        }
    }
    return ans;
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Binary Trees - Medium Problems--------################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L14. Maximum Depth in Binary Tree | Height of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/
//Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution{
  public:
    int depth(Node *root){
        if(root == NULL) return 0;
        int ct = 0;
        ct = max( ct, 1 + depth(root->left));
        ct = max( ct, 1 + depth(root->right));
        return ct;
    }
    int maxDepth(Node *root) {
        return depth(root);
    }
};

//#######################################################################
//#######-------L15. Check for Balanced Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree/
//Problem: https://leetcode.com/problems/balanced-binary-tree/description/

------------
Approach:
1. Find the diameter of left side and right side, if any case it is more than -1 , keep returning -1
Time Complexity: O(N)
------------

class Solution {
public:
    int b(TreeNode *root){
        if(root==NULL) return 0;
        int l = b(root->left);
        int r = b(root->right);

        if(l==-1 || r==-1) return -1;//if l and r is -1 for anycase then keep returning -1 alltime
        if( abs(l-r) > 1) return -1;

        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return (b(root)==-1?0:1);
    }
};

//#######################################################################
//#######-------L16. Diameter of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
//Problem: https://leetcode.com/problems/diameter-of-binary-tree/description/
Diameter: longest distance between any two nodes of a node, and does not necessarily need to pass via root

------------
Approach:
1. Find the diameter of left side and right side, keep taking the max(l+r, ans) as the answer
Time Complexity: O(N)
------------

class Solution {
public:
    int ans = 0;
    int d(TreeNode* root){
        if(root == NULL) return 0;
        int l = d(root->left);
        int r = d(root->right);
        ans = max(ans, l+r);
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        d(root);
        return ans;
    }
};

//#######################################################################
//#######-------L17. Maximum Path Sum in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

Prerequisite: Finding the diameter
------------
The curve path has the answer
Approach:
1. Finding the diameter different version
Time Complexity: O(N)
------------

class Solution {
public:
    int ans = INT_MIN;
    int f(TreeNode* root){
        if(root == NULL) return 0;
        int l = max(0, f(root->left));//do not consider negative
        int r = max(0, f(root->right));
        ans = max(root->val + l + r , ans);//take the curve path as the answer
        return root->val + max(l,r);//it makes sure that it follows in one order
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};

//#######################################################################
//#######-------L18. Check it two trees are Identical or Not--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
//Problem: https://leetcode.com/problems/same-tree/description/

------------
Approach:
1. Just traverse the node of both the trees simultaneously
Time Complexity: O(N)
------------

class Solution {
public:
    bool check(TreeNode *r1, TreeNode *r2){
        if(r1 == NULL && r2 == NULL) return 1;//both null then ok
        if(r1 == NULL || r2 == NULL) return 0;//one of them null, then no
        int l = check(r1->left, r2->left);
        int r = check(r1->right, r2->right);
        
        if(l==0 || r == 0) return 0;//if any time l and r is 0, then return 0 for all nodes, return false
        if( r1->val != r2->val ) return 0;
        return 1;
    }
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        return check(r1, r2);
    }
};


//#######################################################################
//#######-------L19. Zig-Zag or Spiral Traversal in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

------------
Approach:
1. Complete level order traversal
2. Maintain a flag variable, to reverse the array to make it zigzag
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) where N is the number of nodes in the binary tree.
------------ 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue< TreeNode* > q;
        q.push(root);
        bool ok = 0;//0==right to left 1==left to right
        while(!q.empty()){
            int sz = q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            if(!ok) ans.push_back(level);
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            ok = !ok;
            
        }
        return ans;
    }
};

//#######################################################################
//#######-------L20. Boundary Traversal in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

The boundary traversal is the process of visiting the boundary nodes of the binary tree 
in the anticlockwise direction, starting from the root.

left -> leaf -> right traversal

------------
Approach:
1. 
------------ 


//#######################################################################
//#######-------L21. Vertical Order Traversal of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

------------
Approach:
map< vertical < map< level, set of values >> 
vertical, level, node 

level: this is needed to sort the same order e valuegula sort rakhar jnno

Steps:
1. left e gele vertical -1 hobe, right e gele +1 
2. niche namle level +1, in both sides
3. same level er seperate list er jnno multiset create korsi(for minheap)

------------ 

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        map<int, map<int, multiset<int> > > mp;
        //vertical, level, node
        queue< tuple<int, int, TreeNode* > > q;
        q.push({0, 0, root});
        while( !q.empty() ){
            auto [vertical, level, node] = q.front();
            mp[vertical][level].insert(node->val);
            q.pop();
            if(node->left!=NULL)  q.push({vertical-1, level+1, node->left});
            if(node->right!=NULL) q.push({vertical+1, level+1, node->right});
        }

        for(auto [x,y]: mp){
            vector<int>lv;
            for(auto p: y){
                lv.insert(lv.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(lv);
        }
        return ans;
    }
};

//#######################################################################
//#######-------L22. Top View of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/top-view-of-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Prerequisite: L21. Vertical Order Traversal of Binary Tree
------------
Approach:
1. Use vertical order traversal method 
2. Take the first value that was added in the traversal in vertical wise 
3. put (level, node) in the queue, keep taking the values->data where level == unique for the first time

------------ 


class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int, int> mp;
        queue< pair<int, Node*> > q;
        q.push({0, root});
        while(!q.empty()){
            int level = q.front().first;
            Node *node = q.front().second;
            q.pop();
            if(mp[level]==0) mp[level] = node->data;//taking the first value if it was not added
            if(node->left!=NULL)  q.push({level-1, node->left});
            if(node->right!=NULL) q.push({level+1, node->right});
        }
        
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

//#######################################################################
//#######-------L23. Bottom View of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Use the line concept
Prerequisite: L21. Vertical Order Traversal of Binary Tree
------------
Approach:
1. same as Top View of Binary Tree, just a slight difference

------------ 

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int, int> mp;
        queue< pair<int, Node*> > q;
        q.push({0, root});
        while(!q.empty()){
            int level = q.front().first;
            Node *node = q.front().second;
            q.pop();
            mp[level] = node->data;//last node will keep updating 
            if(node->left!=NULL)  q.push({level-1, node->left});
            if(node->right!=NULL) q.push({level+1, node->right});
        }
        
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

//Recursive
- height beshi hoile map upate kora just

class Solution {
  public:
    void b(Node *root, int line, int height, map<int, pair<int, int>>&mp){
        if(root==NULL) return;
        b(root->left, line-1, height+1, mp);
        b(root->right, line+1, height+1, mp);
        if(height>=mp[line].second) mp[line] = {root->data, height};
    }
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int, pair<int, int>>mp;
        b(root, 0, 0, mp);
        for(auto x: mp) ans.push_back(x.second.first);
        return ans;
    }
};

//#######################################################################
//#######-------L24. Right/Left View of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-right-side-view/description/

------------
Approach:
1. visit all left node then all right node, and keep updating the answer is map

------------ 
Right View

class Solution {
public:
    void r(TreeNode* root, int height, map<int, int>&mp){
        if(root == NULL) return;
        r(root->left, height+1, mp);
        r(root->right,height+1, mp);
        mp[height] = root->val;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        map<int, int> mp;
        r(root, 0, mp);
        for(auto x: mp)ans.push_back(x.second);
        return ans;
    }
};

--------------------
Right View Iterative
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        //node, height
        queue< TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                if(i==sz-1)ans.push_back(node->val);//take the last element in the answer
                q.pop();
                if(node->left!=NULL)  q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        return ans;
    }
};

------------------------------------------------------------------
------------------------------------------------------------------
Left View
//https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
void l(Node* root, int height, map<int, int>&mp){
    if(root == NULL) return;
    l(root->right,height+1, mp);
    l(root->left, height+1, mp);
    mp[height] = root->data;
}
vector<int> leftView(Node *root)
{
    vector<int>ans;
    map<int, int> mp;
    l(root, 0, mp);
    for(auto x: mp)ans.push_back(x.second);
    return ans;
}


//#######################################################################
//#######-------L25. Check for Symmetrical Binary Trees--------########
//Tutorial: https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/
//Problem: https://leetcode.com/problems/symmetric-tree/description/

------------
Approach:

Condition:
root1->right == root2->left
root1->left == root2->right

root1->right->data == root2->left->data 
root1->left->data  == root2->right->data 

1. Move through left and right, keep checking the root1->val==root2->val, if not matched then false for all cases
2. otherwise move to left and right, 

------------ 

class Solution {
public:
    bool s(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 != NULL && root2 == NULL) return false;
        if(root1 == NULL && root2 != NULL) return false;
        
        bool l = s(root1->left,  root2->right);
        bool r = s(root1->right, root2->left);

        if(l==false || r==false) return false;//if l, and r is left one time it is false for all cases
        if(root1->val  == root2->val ) return true;
        return false;
    }

    bool isSymmetric(TreeNode* root){
        if(root==NULL) return true;
        return s(root->left,root->right);
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Binary Trees - Hard Problems--------##################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L26. Print Root to Node Path in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/print-root-to-node-path-in-a-binary-tree/

//Problem: https://leetcode.com/problems/binary-tree-paths/description/

------------
Approach:
1. Use take not take approach of recursion and print the path

------------ 

class Solution {
public:
    void b(TreeNode* root, string s, vector<string>&ans){
        if(root==NULL) return;
        s+=to_string( root->val );
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
        }
        s+= "->";
        b(root->left, s, ans);
        b(root->right, s, ans);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        b(root, s, ans);
        return ans;
    }
};

//https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution {
  public:
    vector<int>s;
    void b(Node* root, vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        s.push_back(root->data);
        if(root->left==NULL && root->right==NULL)ans.push_back(s);
        b(root->left, ans);
        b(root->right, ans);
        s.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        b(root, ans);
        return ans;
    }
};

//#######################################################################
//#######-------L27. Lowest Common Ancestor in Binary Tree | LCA--------########
//Tutorial: https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
//Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Prerequisite: L26. Print Root to Node Path in Binary Tree
------------
Approach1:
1. Use take not take approach of recursion and print the path
2. Collect both the paths in the tree 
3. The last value to match the path is the answer(LCA)
------------
Approach2:
1. Keep moving left or right, if one of them is null return right or left
2. if both are not null we found our answer

------------ 
class Solution {
public:
    TreeNode* lca(TreeNode *root,TreeNode *p, TreeNode *q){
        if(root==NULL || root==p || root == q) return root;
        TreeNode* l = lca(root->left ,p, q);
        TreeNode* r = lca(root->right,p, q);
        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};

------------------------
//https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
------------------------
class Solution
{
    public:
    Node* lc(Node *root,int p,int q){
        if(root==NULL || root->data==p || root->data == q) return root;
        Node* l = lc(root->left ,p, q);
        Node* r = lc(root->right,p, q);
        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }
    
    Node* lca(Node* root ,int p ,int q )
    {
       return lc(root, p, q);
    }
};

//#######################################################################
//#######-------L28. Maximum Width of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/
//Problem: https://leetcode.com/problems/maximum-width-of-binary-tree/description/
https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1





//#######################################################################
//#######-------L29. Children Sum Property in Binary Tree | O(N) Approach--------########
//Tutorial: https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/children-sum-parent/1
https://www.geeksforgeeks.org/problems/children-sum-parent/1

//#######################################################################
//#######-------L30. Print all the Nodes at a distance of K in Binary Tree--------########
//Tutorial: https://takeuforward.org/binary-tree/print-nodes-at-distance-k-in-a-binary-tree/
//Problem: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
https://www.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

//#######################################################################
//#######-------L31. Minimum time taken to BURN the Binary Tree from a Node--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/burning-tree/1

//#######################################################################
//#######-------L32. Count total Nodes in a COMPLETE Binary Tree | O(Log^2 N) Approach--------########
//Tutorial: https://takeuforward.org/binary-tree/count-number-of-nodes-in-a-binary-tree/
//Problem: https://leetcode.com/problems/count-complete-tree-nodes/description/
https://www.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/0

//#######################################################################
//#######-------L33. Requirements needed to construct a Unique Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/requirements-needed-to-construct-a-unique-binary-tree-theory
//Problem: https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

//#######################################################################
//#######-------L34. Construct a Binary Tree from Preorder and Inorder Traversal--------########
//Tutorial: https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal/
//Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
https://www.geeksforgeeks.org/problems/construct-tree-1/1

//#######################################################################
//#######-------L35. Construct the Binary Tree from Postorder and Inorder Traversal--------########
//Tutorial: https://takeuforward.org/data-structure/construct-binary-tree-from-inorder-and-postorder-traversal/
//Problem: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
https://www.geeksforgeeks.org/problems/construct-tree-1/1

//#######################################################################
//#######-------L36. Serialize and De-serialize Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree/
//Problem: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

//#######################################################################
//#######-------L37. Morris Traversal | Preorder | Inorder--------########
//Tutorial: https://takeuforward.org/data-structure/morris-preorder-traversal-of-a-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

//#######################################################################
//#######-------L37.2 - Morris Inorder Traversal of a Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

//#######################################################################
//#######-------L38. Flatten a Binary Tree to Linked List | 3 Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
//Problem: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######-------Binary Search Trees [Concept and Problems]--------#######
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L39. Introduction to Binary Search Tree | BST--------########
//Tutorial: https://takeuforward.org/binary-search-tree/introduction-to-binary-search-trees/
//Problem: https://www.geeksforgeeks.org/problems/binary-search-trees/1

//#######################################################################
//#######-------L40. Search in a Binary Search Tree | BST--------########
//Tutorial: https://takeuforward.org/data-structure/search-in-a-binary-search-tree-2/
//Problem: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1
https://www.geeksforgeeks.org/problems/binary-search-trees/0
https://www.geeksforgeeks.org/problems/check-for-bst/1

//#######################################################################
//#######-------Find Min/Max in BST--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Binary Search Trees - Practice Problems--------########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L41. Ceil in a Binary Search Tree | BST--------########
//Tutorial: https://takeuforward.org/binary-search-tree/ceil-in-a-binary-search-tree/
//Problem: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/

//#######################################################################
//#######-------L42. Floor in a Binary Search Tree | BST--------########
//Tutorial: https://takeuforward.org/binary-search-tree/floor-in-a-binary-search-tree/
//Problem: https://www.geeksforgeeks.org/problems/floor-in-bst/1


//#######################################################################
//#######-------L43. Insert a given Node in Binary Search Tree | BST--------########
//Tutorial: https://takeuforward.org/binary-search-tree/insert-a-given-node-in-binary-search-tree/
//Problem: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

//#######################################################################
//#######-------L44. Delete a Node in Binary Search Tree | BST--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/delete-node-in-a-bst/description/
https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1

//#######################################################################
//#######-------L45. K-th Smallest/Largest Element in BST--------########
//Tutorial: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
//Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

//#######################################################################
//#######-------L46. Check if a tree is a BST or BT | Validate a BST--------########
//Tutorial: https://takeuforward.org/binary-search-tree/check-if-a-tree-is-a-binary-search-tree-or-binary-tree/
//Problem: https://leetcode.com/problems/validate-binary-search-tree/description/
https://www.geeksforgeeks.org/problems/check-for-bst/1

//#######################################################################
//#######-------L47. LCA in Binary Search Tree--------########
//Tutorial: https://takeuforward.org/binary-search-tree/lca-in-binary-search-tree/
//Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

//#######################################################################
//#######-------L48. Construct a BST from a preorder traversal | 3 Methods--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

//#######################################################################
//#######-------L49. Inorder Successor/Predecessor in BST | 3 Methods--------########
//Tutorial: https://takeuforward.org/data-structure/inorder-successor-predecessor-in-bst
//Problem: https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

//#######################################################################
//#######-------L50. Binary Search Tree Iterator | BST | O(H) Space--------########
//Tutorial: https://takeuforward.org/data-structure/binary-search-tree-iterator
//Problem: https://leetcode.com/problems/binary-search-tree-iterator/description/

//#######################################################################
//#######-------L51. Two Sum In BST | Check if there exists a pair with Sum K--------########
//Tutorial: https://takeuforward.org/data-structure/two-sum-in-bst-check-if-there-exists-a-pair-with-sum-k
//Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

//#######################################################################
//#######-------L52. Recover BST | Correct BST with two nodes swapped--------########
//Tutorial: https://takeuforward.org/data-structure/recover-bst-correct-bst-with-two-nodes-swapped
//Problem: https://leetcode.com/problems/recover-binary-search-tree/description/
https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

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
