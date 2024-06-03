#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* createLinkedList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* current = dummyHead;
    int carry = 0;
    
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    
    if (carry > 0) {
        current->next = createNode(carry);
    }
    
    struct ListNode* result = dummyHead->next;
    free(dummyHead); 
    return result;
}
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    int l1Arr[] = {2, 4, 3};
    int l2Arr[] = {5, 6, 4};
    
    struct ListNode* l1 = createLinkedList(l1Arr, 3);
    struct ListNode* l2 = createLinkedList(l2Arr, 3);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printf("Result: ");
    printLinkedList(result);
    return 0;
}

