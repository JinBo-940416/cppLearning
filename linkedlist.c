#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    int index;
    struct node *next;
};


struct node *head = NULL;
struct node *tail = NULL;

void generateList(){

    
    head = (struct node *)malloc(sizeof(struct node));
    head->value = 0;
    head->index = 0;
    head->next = tail;


    tail = (struct node *)malloc(sizeof(struct node));
    tail->value = 0;
    tail->index = -1;
    tail->next = NULL;

    return;
}

// current -> inserted -> tail
void insertToList(int val){
    struct node *current = head;

    while (current->next-> index != -1){
        current = current->next;
    }
    struct node *tail = current -> next;
    // current -> tail

    struct node *inserted;
    inserted -> value = val;
    inserted -> index = (current -> index)+1;
    inserted -> next = tail;

    current -> next = inserted;

    return;
}

void printList(){
    printf("\n[");
    printf("debug 5\n");
    struct node *current = head;
    printf("debug 6\n");
    int data;
    while (current->next->index != -1){
        data = current -> value;
        printf("%d \n", data);
        current = current->next;
    }
    printf("debug 7\n");
    printf("]\n");
    return;
}

int main(){
    printf("debug 1\n");
    generateList();
    printf("debug 2\n");
    printList();
    printf("debug 3\n");

    insertToList(8);
    printf("debug 4\n");
    insertToList(7);
    insertToList(5);
    insertToList(2);
    insertToList(11);

    printList();


    return 0;
}