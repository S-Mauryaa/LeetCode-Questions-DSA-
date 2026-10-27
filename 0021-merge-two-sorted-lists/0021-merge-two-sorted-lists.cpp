
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};