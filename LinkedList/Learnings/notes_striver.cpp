//LinkedList

- See notion notes 
- All you have to do is the linking in linkedlist
- never ever change/temper your head, use a temporary node before traversing or manipulating it
- be sure where to start and where to stop in linked list 
- connect other nodes, then untie the tmp node, then delete tmp

Confusions:
1. 


---------------------------------------------------------------------------------------------------------
Stiver Linkedlist Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU
Tutorials: https://takeuforward.org/blogs/linked-list
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
//#######-------L4. Reverse a DLL | Multiple Approaches  --------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()



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
https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L6. Odd Even Linked List | Multiple Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/segregate-even-and-odd-nodes-in-linkedlist
//Problem: https://leetcode.com/problems/odd-even-linked-list/description/
https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1


------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L7. Sort a LinkedList of 0's, 1's and 2's--------########
//Tutorial: https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/
//Problem: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L8. Remove Nth Node from the end of the LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
//Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L9. Reverse a LinkedList | Iterative and Recursive--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-linked-list/
//Problem: https://leetcode.com/problems/reverse-linked-list/description/
https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L10. Check if a LinkedList is Palindrome or Not--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
//Problem: https://leetcode.com/problems/palindrome-linked-list/description/
https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L11. Add 1 to a number represented by LinkedList--------########
//Tutorial: https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L12. Find the intersection point of Y LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
//Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L13. Find the middle element of the LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
//Problem: https://leetcode.com/problems/middle-of-the-linked-list/description/
https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L14. Detect a loop or cycle in LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
//Problem: https://leetcode.com/problems/linked-list-cycle/description/
https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L15. Find the length of the Loop in LinkedList--------########
//Tutorial: https://takeuforward.org/linked-list/length-of-loop-in-linked-list
//Problem: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L16. Delete the middle node of the LinkedList--------########
//Tutorial: https://takeuforward.org/linked-list/delete-the-middle-node-of-the-linked-list
//Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L17. Find the starting point of the Loop/Cycle in LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
//Problem: https://leetcode.com/problems/linked-list-cycle-ii/description/
https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


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
https://leetcode.com/problems/remove-linked-list-elements/description/

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L19. Find all Pairs with given Sum in DLL--------########
//Tutorial: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L20. Remove duplicates from sorted DLL--------########
//Tutorial: https://www.geeksforgeeks.org/remove-duplicates-sorted-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


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
https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L23. Merge two sorted Linked Lists--------########
//Tutorial: https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
//Problem: https://leetcode.com/problems/merge-two-sorted-lists/description/
https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L24. Flattening a LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/flattening-a-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L25. Merge K Sorted Lists--------########
//Tutorial: https://takeuforward.org/linked-list/merge-k-sorted-linked-lists
//Problem: https://leetcode.com/problems/merge-k-sorted-lists/description/
https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L26. Sort a Linked List | Merge Sort and Brute Force--------########
//Tutorial: https://takeuforward.org/linked-list/sort-a-linked-list
//Problem: https://leetcode.com/problems/sort-list/description/
https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L27. Clone a LinkedList with Next and Random Pointers | Copy List with Random Pointers--------########
//Tutorial: https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/
//Problem: https://leetcode.com/problems/copy-list-with-random-pointer/description/
https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

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
https://www.geeksforgeeks.org/problems/design-browser-history/0

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


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