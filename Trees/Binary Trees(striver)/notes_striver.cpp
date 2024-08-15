//Tree

- See notion notes / striver notes for details
- 

Confusions:
1. L10 why Memory Limit Exceeded for this , if(node->right) node = node->right;

Questions: 


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
//Problem: https://www.geeksforgeeks.org/problems/binary-tree-representation/1

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



//#######################################################################
//#######-------L13. Preorder Inorder Postorder Traversals in One Traversal | Stack--------########
//Tutorial: https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/
//Problem: https://www.naukri.com/code360/problems/tree-traversals_981269



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
https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

//#######################################################################
//#######-------L16. Diameter of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
//Problem: https://leetcode.com/problems/diameter-of-binary-tree/description/
https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
Diameter: longest distance between any two nodes of a node, and does not need to pass via root


//#######################################################################
//#######-------L17. Maximum Path Sum in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

//#######################################################################
//#######-------L18. Check it two trees are Identical or Not--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
//Problem: https://leetcode.com/problems/same-tree/description/
https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

//#######################################################################
//#######-------L19. Zig-Zag or Spiral Traversal in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//#######################################################################
//#######-------L20. Boundary Traversal in Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


//#######################################################################
//#######-------L21. Vertical Order Traversal of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/
//Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

//#######################################################################
//#######-------L22. Top View of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/top-view-of-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1


//#######################################################################
//#######-------L23. Bottom View of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree/
//Problem: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


//#######################################################################
//#######-------L24. Right/Left View of Binary Tree--------########
//Tutorial: https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
//Problem: https://leetcode.com/problems/binary-tree-right-side-view/description/
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1


//#######################################################################
//#######-------L25. Check for Symmetrical Binary Trees--------########
//Tutorial: https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/
//Problem: https://leetcode.com/problems/symmetric-tree/description/
https://www.geeksforgeeks.org/problems/symmetric-tree/1


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
https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

//#######################################################################
//#######-------L27. Lowest Common Ancestor in Binary Tree | LCA--------########
//Tutorial: https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
//Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

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
