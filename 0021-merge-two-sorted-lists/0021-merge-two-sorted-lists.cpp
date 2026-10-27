
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        // SC = O(m+n)
        // ListNode* tempA=list1;
        // ListNode* tempB=list2;
        // ListNode* c=new ListNode(100);
        // ListNode* tempC=c;
        // while(tempA!=NULL && tempB!=NULL){
        //     if(tempA->val <= tempB->val){
        //         ListNode* t =new ListNode(tempA->val);
        //         tempC->next=t;
        //         tempC=t;
        //         tempA=tempA->next;
        //     }else{
        //          ListNode* t=new ListNode(tempB->val);
        //         tempC->next=t;
        //         tempC=t;
        //         tempB=tempB->next;
        //     }
        // }
        // if(tempA==NULL){
        //     tempC->next=tempB;
        // }
        // else{ // if tempB==NULL
        //     tempC->next=tempA;
        // }
        // return c->next;

        // Better Method with SC=O(1)
        ListNode* c=new ListNode(100);
        ListNode* temp=c;
        while(a!=NULL && b!=NULL){
            if(a->val <=b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;
            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if(a==NULL)temp->next=b;
        else temp->next=a;
        return c->next;
    }
};