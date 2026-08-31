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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> cp;
        ListNode* prev=head;
        ListNode* curr=head->next;

        int pos=2;

        while(curr->next!=nullptr)
        {
            ListNode* next=curr->next;
            if((curr->val>next->val && curr->val>prev->val)|| (curr->val<next->val && curr->val<prev->val))
            {
                cp.push_back(pos);
            }
            prev=curr;
            curr=next;
            pos++;
        }
        if(cp.size()<2)
        {
            return {-1,-1};
        }

        int mind = INT_MAX;
        for(int i=1;i<cp.size();i++)
        {
            mind=min(mind,cp[i]-cp[i-1]);
        }

        int maxd=cp.back()-cp.front();

        return {mind,maxd};

    }
};