#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;


Node* insertAtBegin(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = head;

    return newNode;
}


void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}


void freeList(Node* head) {
    Node* temp = NULL;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);

    print(head);
    freeList(head);

    return 0;
}