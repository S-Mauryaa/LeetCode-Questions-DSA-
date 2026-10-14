class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Normal method
        // int len=0;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     len++;
        //     temp=temp->next;    
        // }
        // if(n==len){
        //     head=head->next;
        //     return head;
        // }
        // // nth node from the end=(len-n+1)th from the start
        // int m=len-n+1;
        // int idx=m-1; // the idx of the node to be deleted
        // temp=head;
        // for(int i=1;i<=idx-1;i++){
        //     temp=temp->next;
        // }
        // temp->next=temp->next->next;
        // return head;

    // Using slow and fast method
        ListNode* slow=head;
        ListNode* fast=head;
        int len=0;
        for(int i=1;i<=n+1;i++){
            if(fast==NULL)return head->next;
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};