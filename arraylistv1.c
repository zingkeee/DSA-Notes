#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L;
    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    printf("After inserts: ");
    display(L);   // expect: 1 3 2 5

    L = insertPos(L, 4, 2);
    printf("After insertPos(4, 2): ");
    display(L);   // expect: 1 3 4 2 5

    L = deletePos(L, 1);
    printf("After deletePos(1): ");
    display(L);   // expect: 1 4 2 5

    int pos = locate(L, 4);
    printf("locate(4) = %d\n", pos);   // expect: 1

    L = insertSorted(L, 8);
    printf("Note: array isn't actually sorted here, just testing the function: ");
    display(L);

    return 0;
}

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    // Step 1: validate position
    if (position < 0 || position > L.count) {
        printf("Invalid position\n");
        return L;
    }

    // Step 2: check if full
    if (L.count == MAX) {
        printf("List is full\n");
        return L;
    }

    // Step 3: shift everything from 'position' onward one slot right
    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    // Step 4: drop the new value into the now-empty slot
    L.elem[position] = data;

    // Step 5: one more element exists now
    L.count++;

    return L;
}

List deletePos(List L, int position) {
    if (position >= L.count) {
        printf("Not Valid");
        return L;
    }

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;
        }
    }

    printf("Not found.");
    return -1;
}

List insertSorted(List L, int data) {
    // Step 1: check if full — you've done this pattern before in insertPos
    if(L.count == MAX){
        printf("List is full.");
        return L;
    }

    // Step 2: find the correct position for 'data'

    int position = 0;
    while (position < L.count && L.elem[position] < data) {
        position++;
        } 
    // ... how do you find where 'data' belongs?


    // Step 3: shift + insert at 'position' — this is identical to insertPos's shift loop
    for(int i = L.count; i > position; i--){
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position] = data;
    L.count++;

    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}