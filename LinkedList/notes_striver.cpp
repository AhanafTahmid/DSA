//LinkedList

- See notion notes 
- All you have to do is the linking in linkedlist
- never ever change/temper your head, use a temporary node before traversing or manipulating it
- be sure where to start and where to stop in linked list 
- connect other nodes, then untie the tmp node, then delete tmp
- Know where to link and where to not link
- Concept of dummy nodes, when returning own head as answer

Confusions:
1. Intution of L17. Find the starting point of the Loop/Cycle in LinkedList 
2. 
L18. Delete all occurrences of a Key in DLL
//confused on this part
if(curr == *head){
    *head = (*head)->next;
}
3. https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
not sure how to solve it
4.
L10. Check if a LinkedList is Palindrome or Not
???? Where is wrong bujhtesi na optimal approach e
5. L9. Reverse a LinkedList | Iterative and Recursive
recursive approach bujhi nai
6. 
L4. Reverse a DLL

---------------------------------------------------------------------------------------------------------
Stiver LinkedList Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU
Resource: https://takeuforward.org/linked-list/top-linkedlist-interview-questions-structured-path-with-video-solutions/
Resource2: https://takeuforward.org/blogs/linked-list
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Singly LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L1. Introduction to LinkedList | Traversal | Length | Search an Element--------########
//Tutorial: https://www.geeksforgeeks.org/what-is-linked-list/


//Introduction to LinkedList, array to linkedist
//Problem1: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1
Node* constructLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);
    Node *move = head;//first address is the head itself
    for(int i=1;i<arr.size();i++){
        Node *tmp = new Node(arr[i]);
        move->next = tmp;//link the address
        move = tmp;//change the new link with new address
    }
    return head;
}

//Find the length of the linkedlist
//Problem2: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
//Function to count nodes of a linked list.
int getCount(struct Node* head){
    int ct = 0;
    Node *tmp = head;
    while(tmp != NULL){
        ct++;
        tmp = tmp->next;
    }
    return ct;
}
//Search an element in the LL
//Problem3: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node *tmp = head;
        while(tmp){
            if(tmp->data == key) return true;
            tmp = tmp->next;
        }
        return false;
    }
};



//#######################################################################
//#######-------L2. Deletion and Insertion in LL | 8 Problems--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


//8 Problems
Delete, insert -> at head, at last, at a position, value wise (Total 8 problems)

-------------------------------------------------------------------------
//Delete
Tutorial: https://www.geeksforgeeks.org/deletion-in-linked-list/

1. https://www.geeksforgeeks.org/remove-first-node-of-the-linked-list/
2. https://www.geeksforgeeks.org/remove-last-node-of-the-linked-list/
3. https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
4. Delete node with a value (same as 3 no)
delete any node: keep a track of previous and target->next->next er sathe link kora

//delete node at a position
Node* deleteNode(Node *head,int x)
{   
    if(head == NULL) return NULL;
    Node *tmp = head, *prev = NULL;
    if(x==1){
        head = head->next;
        delete tmp;
        return head;
    }
    int ct = 0;
    while(tmp){
        ct++;
        if(ct==x){
            prev->next = prev->next->next;//linking
            delete tmp;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

-------------------------------------------------------------------------
//Insert
Tutorial: https://www.geeksforgeeks.org/insertion-in-linked-list/
https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0

//Insert in linkedlist
class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node *tmp = new Node(x);
       tmp->next = head;
       return tmp;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node *tmp = head;
       Node *ins = new Node(x);
       if(head==NULL){
           return ins;
       }
       while(tmp->next){//tmp->next stop at the last element not the after last element
           tmp = tmp->next;
       }
       tmp->next = ins;
       return head;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Double LinkedList (Basics)--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L3. Introduction to Doubly LinkedList | Insertions and Deletions--------########

//Tutorial: https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/

8 variation: 
Deletion and insertion(front, back, kth, at a node)

//Delete
Delete head: https://takeuforward.org/data-structure/delete-head-of-a-doubly-linked-list/
Delete last node/tail: https://takeuforward.org/data-structure/delete-last-node-of-a-doubly-linked-list/
Delete kth: https://takeuforward.org/doubly-linked-list/delete-the-kth-node-of-a-doubly-linked-list/
Delete node: https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/


//Insert
Before head: https://takeuforward.org/doubly-linked-list/insertion-at-the-head-of-a-doubly-linked-list/
Before tail: https://takeuforward.org/doubly-linked-list/insert-before-the-tail-of-a-doubly-linked-list/
Before kth: https://takeuforward.org/doubly-linked-list/insert-before-the-kth-node-of-a-doubly-linked-list/
Before a node: https://takeuforward.org/doubly-linked-list/insert-before-a-given-node-of-a-dll/


//**after the node(do it yourself) */




//////////////////////////////////////////////////////////////

problems:
-------------------------------------------------------------------------
Convert Array to DLL: https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413
Node* constructDLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);//cause we cannot temper head
    Node *mv = head;
    for(int i=1;i<arr.size();i++){
        Node *tmp = new Node(arr[i], nullptr, mv);//Node(value, next, prev)
        mv->next = tmp;//connect the next
        mv = tmp;
    }
    return head;
}

//Delete
-------------------------------------------------------------------------
Deletion of head of the DLL: https://www.naukri.com/code360/problems/insert-before-the-given-node-of-a-doubly-linked-list_9719100
Node * deleteHead(Node *head) {
    if(head->next == NULL){
        return NULL;
    }
    Node *tmp = head;
    head = head->next;
    tmp->next = head->prev = NULL;
    free(tmp);
    return head;
}
-------------------------------------------------------------------------
Deletion of tail of the DLL: https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469
Node * deleteLastNode(Node *head) {
    if(head->next == NULL) return nullptr;
    Node *move = head;
    while(move->next){//last er tate thama
        move = move->next;
    }
    move->prev->next = move->prev = NULL;
    delete move;
    return head;
}
-------------------------------------------------------------------------
Deletion of the Kth node of the DLL: https://www.naukri.com/code360/problems/delete-k-th-node-from-doubly-linked-list_9723679
- connect other nodes, then untie the tmp node, then delete 
Node *deleteNode(Node *head, int k){
    if(k==1){
        return head->next;
    }
    int ct = 0;
    Node *tmp = head;
    while(head->next){
        ct++;
        if(ct==k)break;
        tmp = tmp->next;
    }
    Node *previous = tmp->prev;
    Node *front = tmp->next;
    
    if(front==NULL){
        previous->next = nullptr;
        tmp->prev = nullptr;
        delete tmp;
        return head;
    }
    
    previous->next = front;//this will give segmeneted fault when front is null, so handle it correctly
    front->prev = previous;

    tmp->prev = tmp->next = nullptr;
    delete tmp;
    return head;
}
-------------------------------------------------------------------------
Deletion of a given node(!head): https://www.naukri.com/code360/problems/non-head-node-deletion_9719173
void deleteNode(Node* node) {
    Node *previous = node->prev;
    Node *front = node->next;
    if(front == NULL){
        previous->next = node->prev = NULL;
        delete node;
        return;
    }

    //linking
    previous->next = front;
    front->prev = previous;

    node->prev = node->next = NULL;
    delete node;
    return;
}

//INSERT
-------------------------------------------------------------------------
Insert at end: https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464
Node * insertAtTail(Node *head, int k) {
    if(head==NULL){
        return new Node(k);
    }
    Node *tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    Node *newnode = new Node(k);
    newnode->prev = tmp;
    tmp->next = newnode;
    return head;
}

-------------------------------------------------------------------------
Insert at a position: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
void addNode(Node *head, int pos, int data)
{
   Node *tmp = head;
   pos++;
   int ct = 0;
   while(tmp){
       ct++;
       if(ct==pos)break;
       tmp = tmp->next;
   }
    Node *front = tmp->next;
    Node *back = tmp;
    if(front==NULL){
       Node *newnode = new Node(data);
       back->next = newnode;
       newnode->prev = back;
       return;
    }
    Node *newnode = new Node(data);
    newnode->next = front;
    newnode->prev = back;
    back->next = newnode;
    front->prev = newnode;
    return;
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
FIX linkedlist above

Lec 2: Learn Doubly LinkedList


//#######################################################################
//#######-------L4. Reverse a DLL | Multiple Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

------------
Approach:
1. Keep swapping, swap(curr->prev, curr->next);
2. at the end, return curr->prev->prev;
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        if(head == NULL || head->next==NULL) return head;
        DLLNode* curr = head, *ans;
        while(curr){
            swap(curr->prev, curr->next);
            ans = curr;
            curr = curr->prev;//due to swap it is the next node actually
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
//#########-------Lec 3: Medium Problems of LL--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L5. Add 2 numbers in LinkedList | Dummy Node Approach--------########
//Tutorial: https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/
//Problem: https://leetcode.com/problems/add-two-numbers/description/

- Prefer the concept of dummy node when you have to create a new list
------------
Approach:
1. Create a dummy node which is the head of new linked list.
2. Create a node curr, initialise it with dummy
3. Initialize carry to 0.
4. Loop through lists l1 and l2, Keep calculating sum and carry on the way

Note: if carry remains at the end, create another node for that and move the curr
------------
Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively
Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int sum = 0, carry = 0;
        while(l1 || l2){
            sum = 0;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            sum = sum + carry;
            ListNode* node = new ListNode( sum%10 );
            curr->next = node;
            curr = curr->next;
            carry = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry){
            ListNode* node = new ListNode( carry );
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};

//#######################################################################
//#######-------L6. Odd Even Linked List | Multiple Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/segregate-even-and-odd-nodes-in-linkedlist
//Problem: https://leetcode.com/problems/odd-even-linked-list/description/
https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1


------------
Approach:
1. Even indices always odd indices er theke agai thakbe, (so even indices check kora)
2. Move odd->next = odd->next->next; and even->next = even->next->next;
3. After that, update even node 
4. Last odd Node er sathe first even Node linkup kora 
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL  || head->next==NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

//#######################################################################
//#######-------L7. Sort a LinkedList of 0's, 1's and 2's--------########
//Tutorial: https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/
//Problem: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

//Better Approach
------------
Approach:
1. count the frequency of the ones , zeros, twos 
2. Make a new node, keep updating the node according to frequency
------------
Time Complexity: O(2N)
Space Complexity: O(1) [not creating any extra space to solve the problem]

class Solution {
  public:
    Node* segregate(Node* head) {
        int z = 0, o = 0, t = 0;
        Node *cur = head;
        Node *ans = head;
        if(cur==NULL) return NULL;
        
        while(cur){
            if(cur->data==0)z++;
            else if(cur->data==1)o++;
            else if(cur->data==2)t++;
            cur=cur->next;
        }
        
        while(z--){
            ans->data = 0;
            ans = ans->next;
        }
        while(o--){
            ans->data = 1;
            ans = ans->next;
        }
        while(t--){
            ans->data = 2;
            ans = ans->next;
        }
        
        return head;
    }
};


//Optimal Approach
------------
Approach:
1. Take 3 node for 0, 1, 2, and move the nodes when 0, 1, 2 found
2. Link all of them after traversing the full array
3. return the zeroHead->next; as answer
------------
Time Complexity: O(N)
Space Complexity: O(1) [using the same nodes]
class Solution {
  public:
    Node* segregate(Node* head) {
        Node *cur = head;
        
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        
        if(cur==NULL) return NULL;
        
        while(cur){
            if(cur->data==0){
                zero->next = cur;
                zero = zero->next;
            }
            else if(cur->data==1){
                one->next = cur;
                one = one->next;
            }
            else if(cur->data==2){
                two->next = cur;
                two = two->next;
            }
            cur=cur->next;
        }

        zero->next = oneHead->next?oneHead->next: twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        Node *ans = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return ans;
    }
};

//#######################################################################
//#######-------L8. Remove Nth Node from the end of the LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
//Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

//Better Approach
------------
Approach:
1. You will have to delete the length - k + 1 node 
2. Calculate length, and find out the index to delete 
3. after that delete that index and connect the pointers

Note: keep a prev to connect prev ->next = delIndex->next;

3 point deletion:
a.first 
b.middle
c. last
------------
Time Complexity: O(2N)
Space Complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int ct = 0, ln = 0;
        ListNode *curr = head;
        if(curr==NULL) return curr;

        while(curr){
            curr = curr->next;
            ln++;
        }
        curr = head;
        int delIndex = ln - k + 1;
        ListNode *delnode, *prev = NULL;
        if(delIndex<0) return curr;//if delIndex > total length

        while(curr){
            if( delIndex == ++ct){
                delnode = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        //first
        if(prev == NULL){
            //delete 
            return delnode->next;
        }
        //last
        else if(delnode->next==NULL){
            prev->next = NULL;
            delete delnode;
            return head;
        }
        //middle
        else{
            prev->next = delnode->next;
            delete delnode;
            return head;
        }
    }
};

//Optimal Approach
------------
Approach:
1. Keep a fast pointer and keep a slow pointer, make slow pointer to be deleted inex
2. Move fast and slow pointer simultaneouly
3. at the end, remove the slow->next pointer

------------
Time Complexity: O(N)
Space Complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        //if(head==NULL) return head;

        for(int i=0;i<k;i++) fast = fast->next;

        //removing the first node
        if(fast==NULL){
            return head->next;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return head;
    }
};

//#######################################################################
//#######-------L9. Reverse a LinkedList | Iterative and Recursive--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-linked-list/
//Problem: https://leetcode.com/problems/reverse-linked-list/description/


//Better Approach

------------
Approach:
1. Put all elements in the stack
2. change the links from st.top(), and move next 
------------
Time Complexity: O(2N)
Space Complexity: O(N) [for using the stack]

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        if(curr==NULL) return NULL;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        
        head = st.top();
        curr = head;
        st.pop();
        while(!st.empty()){
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        curr->next = NULL;
        return head;
    }
};

//Optimal Approach
------------
Approach:
1. reverse the linking
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *front = head;
        if(curr==NULL) return NULL;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};

//Recursive Approach
------------
Approach:
1. reverse the linking
------------
Time Complexity: O(N)
Space Complexity: O(N)

???????


//#######################################################################
//#######-------L10. Check if a LinkedList is Palindrome or Not--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
//Problem: https://leetcode.com/problems/palindrome-linked-list/description/

//Better Approach
------------
Approach:
1. Keep a stack of the elements 
2. cur->val == st.top(), if not equal then false, else true
------------
Time Complexity: O(2N)
Space Complexity: O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        if(curr==NULL) return NULL;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        while(!st.empty()){
            if (curr->val!=st.top()->val) return false;
            st.pop();
            curr = curr->next;
        }
        return true;
    }
};

//Optimal Approach
Using Tortoise and Hare Algorithm
- Slow pointer goes 1 step 
- Fast pointer goes 2 step

------------
Approach:
1. Compare half of the list
2. 
- Slow pointer goes 1 step 
- Fast pointer goes 2 step

slow pointer is your middle element 
after that compare head->data == slow->data and move 

if head->data != slow->data then false, else true

------------
Time Complexity: O(N/2 + N/2 + N/2)
Space Complexity: O(1)

???? Where is wrong bujhtesi na

//#######################################################################
//#######-------L11. Add 1 to a number represented by LinkedList--------########
//Tutorial: https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

//Better Approach
------------
Approach:
1. Reverse the linked list 
2. Add 1 to the elements in the list, Keep taking carry 
3. If carry is 0, then break from the linked list and return the newhead as answer
------------
Time Complexity: O(N) + O(2N) [for reversing] = O(3N)
Space Complexity: O(1)

class Solution{
  public:
    Node* reverseList(Node* head) {
        Node *curr = head, *prev = NULL, *front = head;
        if(curr==NULL) return NULL;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        Node *curr = head;
        if(curr==NULL) return curr;
        
        Node* rev = reverseList(curr);
        Node* newHead = rev;
        if(rev->data!=9){
            newHead->data = newHead->data + 1;// eg: 4 5 == 46 is the answer 
            return reverseList(newHead);
        }
        
        int carry = 0;
        Node *prev = NULL;
        while(rev){
            if(rev->data == 9){
                rev->data = 0;
                carry = 1;
            }
            else{
                rev->data = rev->data + carry;
                carry = 0;//make carry as 0, and return: eg : 4 9 9 == 500 is the answer
                break;
            }
            prev = rev;
            rev = rev->next;
        }
        if(carry){//eg: 9 9 9 == 1000 is the answer
            Node *node = new Node(1);
            prev->next = node;
        }
        return reverseList(newHead);
    }
};


//Optimal Approach
------------
Approach:
1. while backtracking keep adding the carry 
2. if carry remains, add a new node
------------
Time Complexity:  O(N) - Using recursion
Space Complexity: O(N) [stack space of recursion]

class Solution {
  public:
    int add(Node* head) {
        if(head==NULL) return 1;
        int carryNow = head->data + add(head->next);
        head->data = carryNow;
        carryNow/=10;
        return carryNow;
    }
    
    Node* addOne(Node* head) {
        Node *curr = head;
        int carry = add(curr);
        if(carry){
            Node *node = new Node(1);
            node->next = head;
            return node;
        }
        return head;
    }
};

//#######################################################################
//#######-------L12. Find the intersection point of Y LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
//Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

//Better Approach(Using Hashing)
------------
Using Hashing
Approach:
1. Put the addressed of headA by traversing headA 
2. Search for headA in unordered map while traversing headB
------------
Time Complexity: O(N*1) + O(N*1) [unordered set time complexity == O(1)] 
Space Complexity: O(N)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> us;
        while(headA){
            us.insert(headA);
            headA = headA->next;
        }

        while(headB){
            if( us.find(headB)!=us.end() ) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

//Better Approach(Using Length Difference)
------------
Approach:
1. Find the length of both lists.
2. move the list of which length are bigger
3. Move both list simultaneously, if the both list length is similar after some time
------------
Time Complexity: O(max(a_len, b_len)) + O(till intersion point)
Space Complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;
        int a_len = 0, b_len = 0; 
        while(currA || currB){
            if(currA){
                a_len++;
                currA = currA->next;
            }
            if(currB){
                b_len++;
                currB = currB->next;
            }
        }

        currA = headA, currB = headB;
        while(currA || currB){
            if(currA == currB) return currA;
            if(a_len == b_len){//both length is similar so move both simultaneouly
                currA = currA->next;
                currB = currB->next;
            }
            else if(a_len>b_len){
                currA = currA->next;
                a_len--;
            }
            else if(a_len<b_len){
                currB = currB->next;
                b_len--;
            }
        }
        return NULL;
    }
};

//Optimal Approach(Moving both list simultaneously)
------------
Approach:
duitar length different holeo ekbar traverse korar porei length soman howe jabe

1. Take two dummy nodes for each list. Point each to the head of the lists.
2. Iterate over them. If anyone becomes null, point them to the head of the opposite lists 
   and continue iterating until they collide.
3. Handle the case for both become null, if both become null donot move further

Important Oberservations: 
a. For not intersecting nodes, If both of them are at there last node donot move, answer would be null in this case
b. For intersecting nodes, If both of them are at the same node, answer would be that node
------------
Time Complexity: O(a_len + b_len)
Space Complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;

        while(currA != currB){
            currA = currA->next;
            currB = currB->next;
            if(currA==currB) return currA;
            if(currA==NULL) currA = headB;
            if(currB==NULL) currB = headA;
        }
        return currA;
    }
};

//#######################################################################
//#######-------L13. Find the middle element of the LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
//Problem: https://leetcode.com/problems/middle-of-the-linked-list/description/

Use Hare and Tortoise Algorithm

------------
Approach:
1. Move slow pointer one time and fast pointer two times 
2. ultimately slow->next is the middle element 
------------
Time Complexity: O(N/2)
Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }
};

//#######################################################################
//#######-------L14. Detect a loop or cycle in LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
//Problem: https://leetcode.com/problems/linked-list-cycle/description/

Hare and Tortoise Algorithm

------------
Approach:
1. Move slow pointer one time and fast pointer two times 
2. slow == fast hobe if there is a cycle, else fast exhaused hoi jabe 

Observation: 
a. In case of loops, there will never be a last node
------------
Time Complexity: O(N) [Depends on the testcase]
Space Complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

//#######################################################################
//#######-------L15. Find the length of the Loop in LinkedList--------########
//Tutorial: https://takeuforward.org/linked-list/length-of-loop-in-linked-list
//Problem: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

Hare and Tortoise Algorithm

------------
Approach:
1. Apply Hare and Tortoise Algorithm to find out cycle
2. If a cycle found, keep moving one of the pointer until matches again
   Keep increasing answer while on the way 
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int countNodesinLoop(Node *head) {
        if(head==NULL) return 0;
        Node *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                int ans = 1;
                fast = fast->next;
                while(slow!=fast){
                    ans++;
                    fast = fast->next;
                }
                return ans;
            }
        }
        return 0;
    }
};

//#######################################################################
//#######-------L16. Delete the middle node of the LinkedList--------########
//Tutorial: https://takeuforward.org/linked-list/delete-the-middle-node-of-the-linked-list
//Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

Hare and Tortoise Algorithm

------------
Approach:
1. Apply Hare and Tortoise Algorithm to get middle element
2.1 Link Before and after middle element
2.2 Delete the middle element
------------
Time Complexity: O(N/2)
Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next==NULL) return NULL;//0 or 1 element
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* deleteme = slow->next;
        slow->next = slow->next->next;//next element porer element theke nibo
        delete deleteme;
        return head;
    }
};

//#######################################################################
//#######-------L17. Find the starting point of the Loop/Cycle in LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
//Problem: https://leetcode.com/problems/linked-list-cycle-ii/description/

Hare and Tortoise Algorithm

------------
Approach:
1. Apply Hare and Tortoise Algorithm to detect the cycle 
2. If cycle exits, Find the move slow = head, 
3. Now, move both slow and fast, when they are equal that is our starting poin

Intuition:
Slow D distance par kore cycle e before meeting
Fast 2D distance par kore cycle e before meeting

After that head theke arekta pathaile oitao D distance por starting e collide korbe

------------
Time Complexity: O()
Space Complexity: O()
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Lec 4: Medium Problems of DLL--------##################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L18. Delete all occurrences of a Key in DLL--------########
//Tutorial: https://www.geeksforgeeks.org/delete-occurrences-given-key-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

------------
Approach:
1. If values matches, keep deleting the current pointer and set the links correctly 

Observation:
a. head ei key thakle head->next e point kor
b. Last node er previous thakbe na
c. First node er next thakbe na
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int key) {
        Node *curr = *head;
        while(curr){
            if(curr->data == key){
                //confused on this part
                if(curr == *head){
                    *head = (*head)->next;
                }
                
                Node *nextNode = curr->next;
                Node *prevNode = curr->prev;
                
                if(nextNode) nextNode->prev = prevNode;//last node er previous thakbe na
                if(prevNode) prevNode->next = nextNode;//first node er next thakbe na
                delete curr;
                curr = nextNode;
            }
            else{
                curr = curr->next;
            }
        }
    }
};

//#######################################################################
//#######-------L19. Find all Pairs with given Sum in DLL--------########
//Tutorial: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

------------
Approach:
1. Get the head and tail of the list 
2. As the array is sorted, Apply two pointer to solve the problem
------------
Time Complexity: O(2N)
Space Complexity: O(1)

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        Node *curr = head;
        while(curr->next){
            curr = curr->next;
        }
        
        //another condition: while(head->data < curr->data)
        while(head!=curr && head->prev!=curr){//crossing each other
            int s = head->data + curr->data;
            if(s>target) curr = curr->prev;
            else if(s<target) head = head->next;
            else if(s==target){
                ans.push_back({head->data, curr->data});
                curr = curr->prev;
                head = head->next;
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------L20.1 Remove duplicates from sorted DLL--------########
//Tutorial: https://www.geeksforgeeks.org/remove-duplicates-sorted-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

------------
Approach:
1. if curr->data == previous_node->data link properly and delete current node 
Do step 1 until the current pointer is exhausted
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {   
        if(head==NULL ||head->next==NULL) return head;
        Node *curr = head->next;
        
        while(curr){
            Node *prevNode = curr->prev;
            if(curr->data == prevNode->data){
                Node *nextNode = curr->next;
                if(nextNode) nextNode->prev = prevNode;//last element does not have previous, that is why
                prevNode->next = nextNode;
                delete curr;
                curr = nextNode;
            }
            else curr = curr->next;
        }
        return head;
    }
};


//#######-------L20.2 Remove duplicates from sorted LL--------########
//Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
------------
Approach:
1. if curr->data == previous_node->data link properly and delete current node 
Do step 1 until the current pointer is exhausted
------------
Time Complexity: O(N)
Space Complexity: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL ||head->next==NULL) return head;
        ListNode *curr = head->next, *prev = head;
        
        while(curr){
            if(curr->val == prev->val){
                ListNode *nextNode = curr->next;
                prev->next = nextNode;
                delete curr;
                curr = nextNode;
            }
            else prev = curr, curr = curr->next;
        }
        return head;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Lec 5: Hard Problems of LL--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L21. Reverse Nodes in K Group Size of LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
//Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L22. Rotate a LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/rotate-a-linked-list/
//Problem: https://leetcode.com/problems/rotate-list/description/

------------
Approach:
1. Calculate the length of the list.
2.1 Link the last node with first node
2.2 make the modified kth node point to null
2.3 make the modified k+1th node as your new head 

modified k = total_length - actual k
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL  || k==0) return head;

        ListNode *curr = head;
        int len = 1;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        k = k%len;
        if(k == 0) return head;
        k = len - k;

        //last one link with first one 
        curr->next = head;

        curr = head;
        while(--k){
            curr = curr->next;
        }

        //link thik kora, jekhane rotation hoise
        ListNode *newhead = curr->next;
        curr->next = NULL;
        curr = newhead;

        return newhead;
    }
};

//#######################################################################
//#######-------L23. Merge two sorted Linked Lists--------########
//Tutorial: https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
//Problem: https://leetcode.com/problems/merge-two-sorted-lists/description/

------------
Approach:
1. Create a dummy node, and point head to the dummy node 
2. Move either of the pointer in which it has smaller value 
Keep doing it until the both list1 and list2 gets exhausted

3. Return dummynode->node as this is our head

Note: Dummy node create kora v v important, nahole head empty value niyei boshe thakbe, we will never get head
------------
Time Complexity: O(N+M)
Space Complexity: O(1) [for storing in list3, we are not creating any space]


Q: Why Time complexity is not O(min(n1 + n2)) ?
A:
example:
list1 = {1, 3, 5, 7, 9}
list2 = {2, 4, 6, 8, 10}

For this case, we would have to travel (n+m) times. Hence, time complexity would be O(n+m)
----------

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3= new ListNode(-1), *head = list3;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val < list2->val){
                    list3->next = list1;
                    list1 = list1->next;
                }
                else{
                    list3->next = list2;
                    list2 = list2->next;
                }
            }
            else if(list1){
                list3->next = list1;
                list1 = list1->next;
                break;//link rest and get out of the while loop
            }
            else if(list2){
                list3->next = list2;
                list2 = list2->next;
                break;//link rest and get out of the while loop
            }

            list3 = list3->next;
        }
        return head->next;
    }
};

//#######################################################################
//#######-------L24. Flattening a LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/flattening-a-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

------------
Approach:
1. Apply flattenTwoLists algo(same as mergeTwoLists) 
2. Keep solving the flattenTwoLists(head,head->next) until it gets exhausted
------------
Time Complexity: O( N*(2M) ) ~ O(2 N*M) where N is the length of the linked list 
along the next pointer and M is the length of the linked list along the child pointers.
Space Complexity: O(1)

class Solution {
  public:
    Node *flattenTwoLists(Node *list1, Node*list2){
        Node *list3= new Node(-1), *head = list3;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->data < list2->data){
                    list3->bottom = list1;
                    list1 = list1->bottom;
                }
                else{
                    list3->bottom = list2;
                    list2 = list2->bottom;
                }
            }
            else if(list1){
                list3->bottom = list1;
                list1 = list1->bottom;
                break;
            }
            else if(list2){
                list3->bottom = list2;
                list2 = list2->bottom;
                break;
            }
            list3 = list3->bottom;
        }
        return head->bottom;
    }
    
    Node *flatten(Node *head) {
        Node *curr = head;
        while(curr->next){
            head = flattenTwoLists(head, curr->next);
            curr = curr->next;
        }
        return head;
    }
};

//#######################################################################
//#######-------L25. Merge K Sorted Lists--------########
//Tutorial: https://takeuforward.org/linked-list/merge-k-sorted-linked-lists
//Problem: https://leetcode.com/problems/merge-k-sorted-lists/description/

//Better Approach(Taking minimum in every k steps)
------------
Approach:
1. From the head of all the kth node, choose the one with the least value 
2. After that, move that element of the least value 
------------
Time Complexity: O( (N1 + N2 + .... + N*k) * k) ~ O(N * k^2)
Space Complexity: O(1) [As no additional data structures or space is allocated for storing data]

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *lis= new ListNode(-1), *headd = lis;
        while(1){
            ListNode *curr = NULL;
            int ind = -1;//least node index
            for(int i=0;i<k;i++){
                ListNode *head = lists[i];
                if(head){
                    if(curr==NULL || curr && head->val < curr->val){
                        curr = head;
                        //head = head->next; this is not moving, move the actual lists[ind], 
                        //not some temporary thing 
                        ind = i;
                    }
                }
            }
            if(curr==NULL)break;
            lis->next = curr;
            lis = lis->next;

            lists[ind] = lists[ind]->next;//move the least index value, use this for moving
        }
        return headd->next;
    }
};

//Optimal Approach(Using Min Heap)
------------
Approach:
1. If head is true in the kth node, push them in the priority queue
2.1 After that, maintain the priority queue 
2.2 update lis->next to current element in priority queue 
2.3 if current head is not null push current element in the priority queue
2.4 update lis until priority queue is empty
------------
Time Complexity: O(K log K) + O(N*K*(3*log K)) [first for loop, then for the priority queue list]
Space Complexity: O(K) [at max k element priority queue te ase]

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *lis= new ListNode(-1), *head = lis;
        priority_queue< pair<int, ListNode*> , vector< pair<int, ListNode*> > , greater< pair<int, ListNode*> > > pq;
        for(int i=0;i<k;i++){
            if(lists[i])pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto [v, curr] = pq.top();
            pq.pop();
            
            lis->next = curr;
            lis = lis->next;

            curr = curr->next;
            if(curr) pq.push({curr->val, curr});
        }
        return head->next;
    }
};

//#######################################################################
//#######-------L26. Sort a Linked List | Merge Sort and Brute Force--------########
//Tutorial: https://takeuforward.org/linked-list/sort-a-linked-list
//Problem: https://leetcode.com/problems/sort-list/description/

------------
Approach:
1. Apply merge sort in the linked list 
2. to get the middle element apply Hare and tortoise algo 
------------
Time Complexity: O(logN x (N + N/2)) ~ O(NlogN)
Space Complexity: O(1 * logN) [1 = memory space, Recursive stack space]

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3= new ListNode(-1), *head = list3;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val < list2->val){
                    list3->next = list1;
                    list1 = list1->next;
                }
                else{
                    list3->next = list2;
                    list2 = list2->next;
                }
            }
            else if(list1){
                list3->next = list1;
                list1 = list1->next;
                break;
            }
            else if(list2){
                list3->next = list2;
                list2 = list2->next;
                break;
            }

            list3 = list3->next;
        }
        return head->next;
    }
    
    //O(N/2) for finding middle
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge_sort(ListNode *head){
        if(head==NULL || head->next == NULL) return head;
        
        ListNode* middle = middleNode(head);
        ListNode* left = head, *right = middle->next;
        middle->next = NULL;//unlink the middle node, make it a seperate linkedlist
        
        ListNode* l = merge_sort(left);
        ListNode* r = merge_sort(right);
        return mergeTwoLists(l, r);
    }

    ListNode* sortList(ListNode* head) {
        ListNode *h = merge_sort(head);
        return h;
    }
};

//#######################################################################
//#######-------L27. Clone a LinkedList with Next and Random Pointers | Copy List with Random Pointers--------########
//Tutorial: https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/
//Problem: https://leetcode.com/problems/copy-list-with-random-pointer/description/
https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

//Better Approach(Hashing)
------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//Optimal Approach
------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L28. Design a Browser History | LinkedList Implementation--------########
//Tutorial: https://takeuforward.org/linked-list/design-a-browser-history
//Problem: https://leetcode.com/problems/design-browser-history/description/

------------
Approach:
1. Create a Custom Node for the problem
2.1 BrowserHistory() : create a Node 
2.2 visit() : create a Node, and link with preiovus and next 
2.3 back() : move to back until the min(steps, first element) 
2.4 forward() : move to forward until the min(steps, last element) 
------------

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string x) : data(x), next(nullptr), prev(nullptr) {};
};

class BrowserHistory {
public:
    Node *curr = NULL;
    //Time Complexity: O(1)
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    //Time Complexity: O(1)
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;

        curr = curr->next;//move to current
    }

    //Time Complexity: O( min(steps, remaining nodes) )
    string back(int steps) {
        while(steps-- && curr->prev){
            curr = curr->prev;
        }
        return curr->data;
    }
    //Time Complexity: O( min(steps, remaining nodes) )
    string forward(int steps) {
        while(steps-- && curr->next){
            curr = curr->next;
        }
        return curr->data;
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