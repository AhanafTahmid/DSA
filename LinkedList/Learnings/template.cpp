-----------------------------
//1. Reverse singly linked list
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
ListNode* middleNode(ListNode* head) {
    if(head == NULL || head->next==NULL) return head;
    ListNode *slow = head, *fast = head->next;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}
-----------------------------
//3. 