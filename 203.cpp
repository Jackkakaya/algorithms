#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cul = head;
        while(cul->next){
            if(cul->next->val == val){
                cul->next = cul->next->next;
            }
            cul = cul->next;
        }
        return head;
    }
};
