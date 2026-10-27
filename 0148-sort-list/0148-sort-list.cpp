/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* merge(ListNode* list1, ListNode* list2) {
     ListNode* c=new ListNode(100);
        ListNode* temp=c;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <=list2->val){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
            }
        }
        if(list1==NULL)temp->next=list2;
        else temp->next=list1;
        return c->next;
    }
    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;
        // to find the left middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow is at left middle
        ListNode* a = head;
        ListNode* b = slow->next;
        slow -> next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode* c = merge(a, b);
        return c;
    }
};