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
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Lec 4: Medium Problems of DLL--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------Used--------########
//Tutorial: 
//Problem: 


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
//#######-------Used--------########
//Tutorial: 
//Problem: 



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