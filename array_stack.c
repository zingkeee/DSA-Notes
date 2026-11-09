#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 8

typedef struct{
    int elems[MAX];
    int top;
}arrStack;

void init(arrStack* S);
bool isEmpty(arrStack S);
bool isFull(arrStack S);
void push(arrStack* S, int x);
void pop(arrStack* S);
int peek(arrStack S);

int main(){
    arrStack S;
    init(&S);

    printf("Is empty? %s\n", isEmpty(S) ? "yes" : "no");

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);

    printf("Top after pushes: %d\n", peek(S));
    printf("Is empty? %s\n", isEmpty(S) ? "yes" : "no");
    printf("Is full? %s\n", isFull(S) ? "yes" : "no");

    pop(&S);
    printf("Top after one pop: %d\n", peek(S));

    // Fill the stack completely to test isFull
    for(int i = 0; i < MAX; i++){
        push(&S, i * 100);
    }
    printf("Is full? %s\n", isFull(S) ? "yes" : "no");

    // Try pushing past capacity (should be ignored by push's guard)
    push(&S, 999);
    printf("Top after overflow attempt: %d\n", peek(S));

    // Pop everything
    while(!isEmpty(S)){
        printf("Popping: %d\n", peek(S));
        pop(&S);
    }
    printf("Is empty? %s\n", isEmpty(S) ? "yes" : "no");

    return 0;
}

void init(arrStack* S){
    S->top = -1;
}

bool isEmpty(arrStack S){
    return (S.top == -1)? true: false;
}

bool isFull(arrStack S){
    return (S.top == MAX - 1)? true: false;
}

void push(arrStack* S, int x){
    if(S->top != MAX - 1){
        S->elems[++S->top] = x;
    }
}

void pop(arrStack* S){
    if(S->top != -1){
        --S->top;
    }
}

int peek(arrStack S){
    return (S.top != -1)? S.elems[S.top]: '\0';
}