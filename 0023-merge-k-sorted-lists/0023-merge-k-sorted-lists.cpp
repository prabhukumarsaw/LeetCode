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

    int length(ListNode* h){
        ListNode* l=h;
        int c=0;
        while(l){
            c+=1;
            l=l->next;
        }
        return c;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* h1=l1,*h2=l2;
        ListNode* ll=new ListNode(0);
        ListNode* ans=ll;
        while(h1 and h2){
            if(h1->val <=h2->val){
                ans->next=h1;
                h1=h1->next;
            } else{
                ans->next=h2;
                h2=h2->next;
            }
            ans=ans->next;
        }

        if(h1)
        ans->next=h1;
        if(h2)
        ans->next=h2;

        return ll->next;
        
    }

    ListNode* mergeKLists(vector<ListNode*>& a) {
        ListNode* st,temp;
        if(a.size()==0)
        return NULL;
        ListNode* l1=a[0];
        for(int i=1;i<a.size();i+=1){
            
            ListNode* l2=a[i];
            if(length(l1)<length(l2)){
            l1=merge(l2,l1);
        } else
            l1=merge(l1,l2);

        }
        return l1;
        
        
    }
};