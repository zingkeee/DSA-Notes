#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node, NodePtr*;

Node 

int main(){

    Node* head = malloc(sizeof(Node));
    head->data = 45;
    head->next = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    int data = 67, position 3;

    add_at_pos(head, data, position);
    Node* ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }


    return 0;
}

