class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;    
        }
        if(n==len){
            head=head->next;
            return head;
        }
        // nth node from the end=(len-n+1)th from the start
        int m=len-n+1;
        int idx=m-1; // the idx of the node to be deleted
        temp=head;
        for(int i=1;i<=idx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;

    }
};