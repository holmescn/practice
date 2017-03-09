struct ListNode* newNode() {
    return (struct ListNode*)malloc(sizeof(struct ListNode));
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode listnode_t;
    listnode_t *root = newNode();
    listnode_t *p = root, *pp = NULL;
    int carry = 0;
    while(l1 || l2) {
        int lhs = l1 ? l1->val : 0;
        int rhs = l2 ? l2->val : 0;

        p->val = lhs + rhs + carry;
        if (p->val >= 10) {
            p->val -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        p->next = newNode();
        pp = p;

        p = p->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    if (carry) {
        p->val = carry;
        p->next = NULL;
    } else {
        pp->next = NULL;
        free(p);
    }

    return root;
}

int main(int argc, char** argv) {

    return 0;
}
