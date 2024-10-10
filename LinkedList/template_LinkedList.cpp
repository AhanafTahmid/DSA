-----------------------------
//1. Reverse singly linked list(for even the 2th middle is the middle)
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
-----------------------------
//2. Get middle Element(Tortoise and Hare)

//1st Version(Node before Middle reach)
ListNode* middleNode(ListNode* head) {
    if(head == NULL || head->next==NULL) return head;
    ListNode *slow = head, *fast = head->next;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}

//2nd Version(exact middle reach)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//3rd Version(returns first middle for even numbers)
ListNode* middleNode(ListNode* head) {
    if(head == NULL || head->next==NULL) return head;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

-----------------------------
//3. Cycle Detection(Tortoise and Hare)
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
-----------------------------
//4. Merge Two List 
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
-----------------------------
//5. Flatten Two list(same as mergeTwoLists)
Node *flattenTwoLists(Node *list1, Node*list2){
    Node *list3= new Node(-1), *head = list3;
    while(list1 || list2){
        if(list1 && list2){
            if(list1->data < list2->data){
                list3->child = list1;
                list1 = list1->child;
            }
            else{
                list3->child = list2;
                list2 = list2->child;
            }
        }
        else if(list1){
            list3->child = list1;
            list1 = list1->child;
            break;
        }
        else if(list2){
            list3->child = list2;
            list2 = list2->child;
            break;
        }
        list3 = list3->child;
    }
    return head->child;
}
-----------------------------
