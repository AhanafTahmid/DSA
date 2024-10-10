//Merge sort algorithm
-----------------------------
//1. Using Array
void mergeSort(int arr[], int l, int r)
{
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    int low = l, high = m + 1;
    
    vector<int>tmp;
    while(low<=m && high<=r){
        if(arr[low]<arr[high]){
            tmp.push_back(arr[low]);
            low++;
        }
        else{
            tmp.push_back(arr[high]);
            high++;
        }
    }
    while(low<=m){
        tmp.push_back(arr[low]);
        low++;
    }
    
    while(high<=r){
        tmp.push_back(arr[high]);
        high++;
    }
        
    for(int i=l;i<=r;i++){
        arr[i] = tmp[i-l];
    }
    
    
}

void merge_sort(int ar[], int l,int h){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    merge_sort(ar,l,m);
    merge_sort(ar,m+1,h);

    merge(ar,l,m,h);
}

-------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;


void merge(int ar[],int l,int m, int h){
    vector<int> temp;

    //low...mid
    //mid+1...high
    int i = l;      // Initial index of left subarray
    int j = m + 1;  // Initial index of right subarray

    // Merging the two arrays
    while (i <= m && j <= h) {
        if (ar[i] <= ar[j]) {
            temp.push_back(ar[i]);
            i++;//oi position er kaj shesh, tai ++
        } else {
            temp.push_back(ar[j]);
            j++;
        }
    }

    //if there are elements on the left still remains
    while (i <= m) {
        temp.push_back(ar[i]);
        i++;
    }

    //if there are elements on the right still remains
    while (j <= h) {
        temp.push_back(ar[j]);
        j++;
    }

    // moving all elements to an array / Copy elements from temp back to ar[]
    for (int k = l; k <= h; k++) {
        ar[k] = temp[k-l];//
    }


}


void merge_sort(int ar[], int l,int h){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    merge_sort(ar,l,m);//left half
    merge_sort(ar,m+1,h);//right half
    
    //function to merge and sort the array
    merge(ar,l,m,h);
   
}


int main(){

    int t=1;
    //cin >> t;
    while(t--){
        int ar[100]={2,1,23,45,22,3,6};
        int n = 7;
        int l = 0;
        int h = 6;
        int mid = (l+h)/2;

        merge_sort(ar,0,n-1); //high and low
        for(int i=0;i<n;i++){
            cout<<ar[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

---------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------
//2. Using LinkedList
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