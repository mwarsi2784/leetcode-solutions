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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;
        if(k==0 || head==nullptr){
            return head;
        }
        
        ListNode* last=nullptr;
        while(curr!=nullptr){
            n++;
            last=curr;
            curr=curr->next;
        }
        k=k%n;
        last->next=head;
        curr=head;
        int i=1;
        int brea=n-k;
        ListNode* newHead;
        while(i<=brea){
            if(i==brea){
                newHead=curr->next;
                curr->next=nullptr;
                return newHead;
            }
            curr=curr->next;
            i++;
        }
        return newHead;
    }
};