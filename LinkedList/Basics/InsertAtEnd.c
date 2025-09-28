#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;


Node* insertAtEnd(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(!newNode) {
        perror("Memory Not Allocated");
        exit(EXIT_FAILURE);
    }

    newNode->val = val;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void freeList(Node* head) {
    Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    print(head);
    freeList(head);

}