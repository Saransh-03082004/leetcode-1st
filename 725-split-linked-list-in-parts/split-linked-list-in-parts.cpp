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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> nodes;

        ListNode* temp=head;

        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        int n=nodes.size();
        int partSize=n/k;
        int extra=n%k;

        vector<ListNode*> ans(k,NULL);

        int index=0;

        for(int i=0;i<k;i++){
            if(index >= n) break;
            ans[i]=nodes[index];
            int currentSize=partSize + (extra > 0 ? 1 : 0);
            extra--;

            index+=currentSize;

            if(index <= n){
                nodes[index-1]->next=NULL;
            }
        }
        return ans;
    }
};