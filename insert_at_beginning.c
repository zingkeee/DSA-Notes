#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node, NodePtr*;

NodePtr add_beg(NodePtr head, int data);

int main(){

    NodePtr head = malloc(sizeof(Node));
    head->data = 45;
    head->next = NULL;

    NodePtr ptr = malloc(sizeof(Node));
    ptr->data = 98;
    ptr->next = NULL;

    head->next = ptr;

    int data = 3;

    head = add_beg(head, data);
    
    ptr = head;
    
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

NodePtr add_beg(NodePtr head, int data){
    NodePtr ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;
    return head;
}w

