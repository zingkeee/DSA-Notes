#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node, NodePtr*;

void add_at_end(Node head, int data);

int main(){






    return 0;
}

void add_at_end(NodePtr head, int data){
    NodePtr ptr, temp;
    ptr = head;
    temp = malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    while(ptr->link != NULL){
        ptr = ptr->next;
    }

    ptr->next = temp;
}