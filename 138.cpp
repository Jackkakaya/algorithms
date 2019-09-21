#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;

        Node* cul = head;
        // 处理成oldNode->newNode->oldNode1->newNode1
        // 这样可以通过OldNode直接找到新的
        // node，这样处理random的时候可以方便找到新的random
        while(cul){
            Node* tmp = new Node(cul->val,cul->next,cul->random);
            Node* c = cul->next;
            cul->next = tmp;
            cul = c;
        }

        // 处理random
        cul = head;
        while(cul){
            if(cul->next->random)
                cul->next->random = cul->random->next;
            cul = cul->next->next;
        }

        // 生成最后结果
        Node* ret=head->next;
        cul = head;
        while(cul->next){
            Node* t = cul->next;
            cul->next = cul->next->next;
            cul = t;
        }

        return ret;
    }

};
