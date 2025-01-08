#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 两数相加函数
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* head = NULL;
    Node* tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int n1 = (l1 != NULL) ? l1->data : 0;
        int n2 = (l2 != NULL) ? l2->data : 0;
        int sum = n1 + n2 + carry;

        Node* newNode = createNode(sum % 10);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        carry = sum / 10;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return head;
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    if (current == NULL) printf("NULL\n");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    // 创建链表 l1: 2 -> 3 -> 4
    Node* l1 = createNode(2);
    l1->next = createNode(3);
    l1->next->next = createNode(4);

    // 创建链表 l2: 5 -> 6 -> 4
    Node* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // 打印输入链表
    printf("Input List 1: ");
    printList(l1);
    printf("Input List 2: ");
    printList(l2);

    // 计算两链表之和
    Node* result = addTwoNumbers(l1, l2);

    // 打印结果链表
    printf("Result List: ");
    printList(result);

    // 释放链表内存
    Node* temp;
    while (l1 != NULL) {
        temp = l1;
        l1 = l1->next;
        free(temp);
    }
    while (l2 != NULL) {
        temp = l2;
        l2 = l2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}

