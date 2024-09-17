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
//4.
