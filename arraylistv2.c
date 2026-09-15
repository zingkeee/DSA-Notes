#include <stdio.h>

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main() {
    EPtr L = malloc(sizeof(Etype));
    initialize(L);
 
    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);
    printf("After inserts: ");
    display(L);   // expect: 1 3 2 5
 
    insertPos(L, 4, 2);
    printf("After insertPos(4, 2): ");
    display(L);   // expect: 1 3 4 2 5
 
    deletePos(L, 1);
    printf("After deletePos(1): ");
    display(L);   // expect: 1 4 2 5
 
    int pos = locate(L, 4);
    printf("locate(4) = %d\n", pos);   // expect: 1
 
    int val = retrieve(L, 2);
    printf("retrieve(2) = %d\n", val);   // expect: 2
 
    insertSorted(L, 8);
    printf("insertSorted(8): ");
    display(L);
 
    makeNULL(L);
    L = NULL;
 
    return 0;
}


void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    // your code here
    if(position < 0 || position > L->count){
        return;
    }
    if(L->count == MAX){
        return;
    }

    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;

}

void deletePos(EPtr L, int position){
    if(position >= L->count){
        return;
    }

    for(int i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;

}

int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }

    return -1;
}

void insertSorted(EPtr L, int data){
    if(L->count == MAX){
        return;
    }

    int position = 0;

    while(position < L->count && L->elem[position] < data){
        position++;
    }

    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;
}

void display(EPtr L){
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

int retrieve(EPtr L, int position){
    if(position >= L->count){
        return -1;
    }

    return L->elem[position];
}

void makeNULL(EPtr L){
    free(L);
}




















