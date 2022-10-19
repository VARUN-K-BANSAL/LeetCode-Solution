/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *insert(struct ListNode *head, int data) {
    if(head == NULL) {
        head = (struct ListNode *) malloc(sizeof(struct ListNode));
        head->val = data;
        head->next = NULL;
    } else {
        struct ListNode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = data;
        node->next = NULL;
        temp->next = node;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = NULL;
    int temp = 0;
    while(l1 != NULL || l2 != NULL || temp) {
        int sum = 0;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += temp;
        temp = sum / 10;
        result = insert(result, sum%10);
    }
    return result;
}