#include <stdio.h>

#define MAX 4

typedef struct{
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int CList;

void initialize(VHeap* V);
void initializeList(CList* L);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertPos(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap V, int elem);
void delete(int* L, VHeap V, int elem);
void deleteAllOccurrence(int* L, VHeap V, int elem);
void display(int L, VHeap V);

int main(){



}

void initialize(VHeap* V){
    V->avail = 0;                               //first available node is 0
    int i;
    for (i = V->avail; i < MAX - 1; ++i){       
        V->H[i].next = i + 1;                   //linking nodes to the next node
    }
    V->H[i].next = -1;                  //last node always -1
}

void initializeList(CList* L){
    *L = -1;                        //always hold the index of the first node in the list;
}                                   //we are initializing the list to be empty;

int allocSpace(VHeap* V){
    int index = V->avail;                   //check for avail space           
    if(index != -1){                        //checker if full
        V->avail = V->H[index].next;        //set the avail to the next of the current index (index has been set to the current avail)
    } 
    return index;
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;            //set the next of the deallocated cell to the current avail index
    V->avail = index;                       //update avail to point to the newly deallocated cell
}

void insertFirst(int* L, VHeap* V, int elem){
    if(V->avail != -1){                     //always check if full
        int temp = allocSpace(V);               //alloc space for the new cell
        if(temp != -1){                             //always check if full
            V->H[temp].data = elem;                 //assign the data
            V->H[temp].next = *L;                   //assign the next of that temporary cell to the current head(L)
            *L = temp;                              //update the head(L) to the new cell
        }
    }
}

void insertLast(int* L, VHeap* V, int elem){
    int trav = *L;                              //use for traversal to the last cell
    if(V->avail != -1){                     //checker if full
        int temp = allocSpace(V);               //new cell
        if(temp != -1){                     //checker
            V->H[temp].elem = elem;             //assign the data
            V->H[temp].next = -1;                   //set the next of the new cell to -1 indicating last

            if(*L == -1){                   //checker to see if list is empty
                *L = temp;                  //if empty assign the new cell as head of list
            } else {
                while(V->H[trav].next != -1){       //condition to make trav move forward until trav is last cell
                    trav = V->H[trav].next;         //move trav to the next cell
                }
                V->H[trav].next = temp;     //link old last cell to the new cell

            }
        }
    }
}

void insertPos(int* L, VHeap* V, int elem){

}

void insertSorted(int* L, VHeap V, int elem){

}

void delete(int* L, VHeap V, int elem){

}

void deleteAllOccurrence(int* L, VHeap V, int elem){

}

void display(int L, VHeap V){

}