
class Solution {
public:
// we will use it for the merge fuction
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
        ListNode* mergeKLists(vector<ListNode*> & arr) {
            if (arr.size() == 0)
                return NULL;
            while (arr.size() > 1) {
                ListNode* a = arr[0];
                arr.erase(arr.begin());
                ListNode* b = arr[0];
                arr.erase(arr.begin());
                ListNode* c = merge(a, b); // calling merge function
                arr.push_back(c);
            }
            return arr[0];
        }
    };