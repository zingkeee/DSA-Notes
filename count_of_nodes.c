#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}Node;

void count_of_nodes(Node* head);

int main() {
    
    Node* head = malloc(sizeof(Node));
    head->data = 10;
    head->link = NULL;

    Node* current = malloc(sizeof(Node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(Node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;

    count_of_nodes(head);

    return 0;
}

void count_of_nodes(Node* head){
    int count = 0;
    if(head == NULL){
        printf("Empty");
    }

    Node* ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("%d", count);
}
























